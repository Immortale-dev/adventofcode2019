#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
int n,m;
int posx, posy;
int **arr;
//vector<vector<int> >dp(1<<26, vector<int>(30, -1));
unordered_map<int, int> dp[30];

void read()
{
    string line;
    while(cin >> line){
        grid.push_back(line);
    }
    n = grid.size();
    m = grid[0].size();
}

void clear()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = 1000000000;
        }
    }
}

void find_pos()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '@'){
                posx = j;
                posy = i;
            }
        }
    }
}

int convertKey(char c)
{
    if(c >= 'a' && c <= 'z'){
        return 1 << (c-'a');
    }
    else{
        return 1 << (c-'A');
    }
}

int dfs(int x, int y, int done)
{
    //cout << "WTF? " << x << " " << y << " " << done << endl; 
    if(grid[y][x] >= 'a' && grid[y][x] <= 'z' && dp[grid[y][x]-'a'].count(done))
        return dp[grid[y][x]-'a'][done];
    clear();
    queue<pair<int,int> > q;
    arr[y][x] = 0;
    q.push(make_pair(x,y));
    vector<pair<int,int> > found;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int nx = it.first;
        int ny = it.second;
        
        //if(grid[ny][nx] >= 'a' && grid[ny][nx] <= 'z')
        //    cout << grid[ny][nx] << " " << convertKey(grid[ny][nx]) << endl;
        
        if(grid[ny][nx] >= 'a' && grid[ny][nx] <= 'z' && ( (done & convertKey(grid[ny][nx])) == 0) ){
            found.push_back(make_pair(nx,ny));
        }
        
        //cout << arr[ny][nx] << " " << grid[ny][nx] << " " << arr[ny][nx]+1 << endl;
        
        
        if( (arr[ny][nx+1] > arr[ny][nx]+1) && (grid[ny][nx+1] == '.' || ( grid[ny][nx+1] >= 'a' && grid[ny][nx+1] <= 'z' ) || (grid[ny][nx+1] >= 'A' &&  grid[ny][nx+1] <= 'Z' && (done & convertKey(grid[ny][nx+1])) ) ) ){
            arr[ny][nx+1] = arr[ny][nx]+1;
            q.push(make_pair(nx+1, ny));
        }
        if( (arr[ny][nx-1] > arr[ny][nx]+1) && (grid[ny][nx-1] == '.' || ( grid[ny][nx-1] >= 'a' && grid[ny][nx-1] <= 'z' ) || (grid[ny][nx-1] >= 'A' && grid[ny][nx-1] <= 'Z' && (done & convertKey(grid[ny][nx-1]))) ) ){
            arr[ny][nx-1] = arr[ny][nx]+1;
            q.push(make_pair(nx-1, ny));
        }
        if( (arr[ny+1][nx] > arr[ny][nx]+1) && (grid[ny+1][nx] == '.' || ( grid[ny+1][nx] >= 'a' && grid[ny+1][nx] <= 'z' ) || (grid[ny+1][nx] >= 'A' && grid[ny+1][nx] <= 'Z' && (done & convertKey(grid[ny+1][nx]))) ) ){
            arr[ny+1][nx] = arr[ny][nx]+1;
            q.push(make_pair(nx, ny+1));
        }
        if( (arr[ny-1][nx] > arr[ny][nx]+1) && (grid[ny-1][nx] == '.' || ( grid[ny-1][nx] >= 'a' && grid[ny-1][nx] <= 'z' ) || (grid[ny-1][nx] >= 'A' && grid[ny-1][nx] <= 'Z' && (done & convertKey(grid[ny-1][nx]))) ) ){
            arr[ny-1][nx] = arr[ny][nx]+1;
            q.push(make_pair(nx, ny-1));
        }
    }
    
    vector<int> sizes;
    for(int i=0;i<found.size();i++){
        sizes.push_back(arr[found[i].second][found[i].first]);
    }
    
    
    if(!found.size())
        return 0;
    
    int mn = 1000000000;
    for(int i=0;i<found.size();i++){
        int nxt = done|convertKey(grid[found[i].second][found[i].first]);
        mn = min( mn, dfs(found[i].first, found[i].second, nxt) + sizes[i] );
    }
    
    if(grid[y][x] >= 'a' && grid[y][x] <= 'z')
        dp[grid[y][x]-'a'][done] = mn;
    
    return mn;
}

int main()
{
    read();
    find_pos();
    arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[m];
    }
    
    grid[posy][posx] = '.';
    
    clear();
    int mn = dfs(posx,posy,0);
    
    cout << mn << endl;
    
    return 0;
}