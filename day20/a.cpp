#include <bits/stdc++.h>
#include <cassert>

using namespace std;


struct pt{
    int r,c;
};

vector<string> grid;
vector<vector<int> > arr[100];
unordered_map<string, vector<pt> > ports;
int n,m,o;

void read()
{
    string s;
    while(getline(cin,s)){
        grid.push_back(s);
    }
    n = grid.size();
    m = grid[0].size();
    o = 100;
    
    for(int k=0;k<o;k++){
        arr[k].resize(n);
        for(int i=0;i<n;i++){
            arr[k][i].resize(m);
            for(int j=0;j<m;j++)
                arr[k][i][j] = 1000000000;
        }
    }
}

bool is_ab(char c)
{
    return c >= 'A' && c <= 'Z';
}

void prepareTeleports()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] != '.')
                continue;
            string tname = "";
            if(is_ab(grid[i-1][j])){
                tname.push_back(grid[i-2][j]);
                tname.push_back(grid[i-1][j]);
                ports[tname].push_back({i,j});
            }
            if(is_ab(grid[i+1][j])){
                tname.push_back(grid[i+1][j]);
                tname.push_back(grid[i+2][j]);
                ports[tname].push_back({i,j});
            }
            if(is_ab(grid[i][j-1])){
                tname.push_back(grid[i][j-2]);
                tname.push_back(grid[i][j-1]);
                ports[tname].push_back({i,j});
            }
            if(is_ab(grid[i][j+1])){
                tname.push_back(grid[i][j+1]);
                tname.push_back(grid[i][j+2]);
                ports[tname].push_back({i,j});
            }
        }
    }
}

string get_tname(int r, int c)
{
    string tname = "";
    if(is_ab(grid[r-1][c])){
        tname.push_back(grid[r-1][c]);
        tname.push_back(grid[r][c]);
    }
    if(is_ab(grid[r+1][c])){
        tname.push_back(grid[r][c]);
        tname.push_back(grid[r+1][c]);
    }
    if(is_ab(grid[r][c-1])){
        tname.push_back(grid[r][c-1]);
        tname.push_back(grid[r][c]);
    }
    if(is_ab(grid[r][c+1])){
        tname.push_back(grid[r][c]);
        tname.push_back(grid[r][c+1]);
    }
    assert(tname.size());
    return tname;
}

bool isOut(int r, int c)
{
    return (r < 5 || c < 5 || r > n-5 || c > n-5);
}

bool hasPath(int r, int c, int l)
{
    if(grid[r][c] == '#')
        return false;
    if(grid[r][c] == '.')
        return true;
    if(is_ab(grid[r][c])){
        l += (isOut(r,c) ? -1 : 1);
        if(l < 0 || l >= o)
            return false;
        string tname = get_tname(r,c);
        if(tname != "AA" && tname != "ZZ")
            return true;
    }
    return false;
}

pt getCoords(int r, int c)
{
    if(!is_ab(grid[r][c]))
        return {r,c};
    string tname = get_tname(r,c);
    assert(ports[tname].size() == 2);
    if(abs(ports[tname][0].r-r)+abs(ports[tname][0].c-c) < 2)
        return ports[tname][1];
    return ports[tname][0];
}

pt getCoords(string tname)
{
    assert(ports.count(tname));
    return ports[tname][0];
}

int getLvl(int r, int c, int l)
{
    if(is_ab(grid[r][c])){
        if(isOut(r,c))
            return l-1;
        return l+1;
    }
    return l;
}

void dfs(pt p)
{
    queue<tuple<pt,int,int> > q;
    q.push(make_tuple(p, 0, 0));
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        pt p = get<0>(cur);
        int st = get<1>(cur);
        int lvl = get<2>(cur);
        
        if(arr[lvl][p.r][p.c] < st)
            continue;
        
        arr[lvl][p.r][p.c] = st;
        
        if(hasPath(p.r-1, p.c, lvl)){
            q.push(make_tuple(getCoords(p.r-1, p.c), st+1, getLvl(p.r-1,p.c,lvl)));
        }
        if(hasPath(p.r+1, p.c, lvl)){
            q.push(make_tuple(getCoords(p.r+1, p.c), st+1, getLvl(p.r+1,p.c,lvl)));
        }
        if(hasPath(p.r, p.c-1, lvl)){
            q.push(make_tuple(getCoords(p.r, p.c-1), st+1, getLvl(p.r,p.c-1,lvl)));
        }
        if(hasPath(p.r, p.c+1, lvl)){
            q.push(make_tuple(getCoords(p.r, p.c+1), st+1, getLvl(p.r,p.c+1,lvl)));
        }
    }
}

int main()
{
    read();
    
    prepareTeleports();
    
    dfs(getCoords("AA"));
    
    pt zz = getCoords("ZZ");
    
    int mn = 1000000000;
    for(int i=0;i<o;i++){
        mn = min(mn, arr[i][zz.r][zz.c]);
    }
    
    cout << mn << endl;
    cout << arr[0][zz.r][zz.c] << endl;
    
    return 0;
}