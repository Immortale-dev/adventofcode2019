#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> arr;

void run(vector<ll>& cp, ll (*ifn)(), void (*ofn)(ll))
{
    int rp = 0;
    for(int i=0;i<cp.size();){
        
        int top = cp[i];
        
        int par[3];
        int op = top%100;
        top/=100;
        for(int i=0;i<3;i++){
            par[i] = top%10;
            top/=10;
        }
        
        int vals = 0;
        
        ll a,b,c;
        
        switch(op){
            case 0:
                vals = 1;
                break;
            case 1:
                vals = 4;
                a = cp[i+1];
                b = cp[i+2];
                c = cp[i+3];
                a = par[0] ? a : cp[a];
                b = par[1] ? b : cp[b];
                if(par[0] == 2)
                    a = cp[rp+a];
                if(par[1] == 2)
                    b = cp[rp+b];
                if(par[2] == 2)
                    c = rp+c;
                cp[c] = a+b;
                break;
            case 2:
                vals = 4;
                a = cp[i+1];
                b = cp[i+2];
                c = cp[i+3];
                a = par[0] ? a : cp[a];
                b = par[1] ? b : cp[b];
                if(par[0] == 2)
                    a = cp[rp+a];
                if(par[1] == 2)
                    b = cp[rp+b];
                if(par[2] == 2)
                    c = rp+c;
                cp[c] = a*b;
                break;
            case 3:
                vals = 2;
                a = cp[i+1];
                if(par[0] == 2)
                    a = rp+a;
                cp[a] = ifn();
                break;
            case 4:
                vals = 2;
                a = cp[i+1];
                a = par[0] ? a : cp[a];
                if(par[0] == 2)
                    a = cp[rp+a];
                ofn(a);
                break;
            case 5:
                vals = 3;
                a = cp[i+1];
                b = cp[i+2];
                a = par[0] ? a : cp[a];
                b = par[1] ? b : cp[b];
                if(par[0] == 2)
                    a = cp[rp+a];
                if(par[1] == 2)
                    b = cp[rp+b];
                if(a != 0){
                    i = b;
                    vals = 0;
                }
                break;
            case 6:
                vals = 3;
                a = cp[i+1];
                b = cp[i+2];
                a = par[0] ? a : cp[a];
                b = par[1] ? b : cp[b];
                if(par[0] == 2)
                    a = cp[rp+a];
                if(par[1] == 2)
                    b = cp[rp+b];
                if(a == 0){
                    i = b;
                    vals = 0;
                }
                break;
            case 7:
                vals = 4;
                a = cp[i+1];
                b = cp[i+2];
                c = cp[i+3];
                a = par[0] ? a : cp[a];
                b = par[1] ? b : cp[b];
                if(par[0] == 2)
                    a = cp[rp+a];
                if(par[1] == 2)
                    b = cp[rp+b];
                if(par[2] == 2)
                    c = rp+c;
                cp[c] = a<b ? 1 : 0;
                break;
            case 8:
                vals = 4;
                a = cp[i+1];
                b = cp[i+2];
                c = cp[i+3];
                a = par[0] ? a : cp[a];
                b = par[1] ? b : cp[b];
                if(par[0] == 2)
                    a = cp[rp+a];
                if(par[1] == 2)
                    b = cp[rp+b];
                if(par[2] == 2)
                    c = rp+c;
                cp[c] = a==b ? 1 : 0;
                break;
            case 9:
                vals = 2;
                a = cp[i+1];
                a = par[0] ? a : cp[a];
                if(par[0] == 2)
                    a = cp[rp+a];
                rp += a;
                break;
            case 99:
                return;
            default:
                cout << i << endl;
                cout << "Error" << endl;
                exit(1);
        }
        
        i+=vals;
    }
}


int grid[100][100];
int mxx=0,mxy=0,mnx=100,mny=100;
int posx = 50, posy = 50;
int minopos = 1000;
int minoposx, minoposy;
stack<int> steps;
int res2 = 0;

void printGrid()
{
    for(int i=mny;i<=mxy;i++){
        for(int j=mnx;j<=mxx;j++){
            char out;
            if(i == 50 && j == 50){
                cout << "o";
                continue;
            }
            switch(grid[i][j]){
                case 0:
                    out = '#';
                    break;
                case 1:
                    out = '.';
                    break;
                case 2:
                    out = 'x';
                    break;
                default:
                    out = ' ';
            }
            cout << out;
        }
        cout << '\n';
    }
}

void clearConsole()
{
    system("CLS");
}


void move(int comm)
{
    switch(comm){
        case 1:
            posy++;
            break;
        case 2:
            posy--;
            break;
        case 3:
            posx++;
            break;
        case 4:
            posx--;
            break;
    }
}

void calcLims()
{
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(grid[i][j] > -1){
                mnx = min(mnx,j);
                mny = min(mny,i);
                mxx = max(mxx,j);
                mxy = max(mxy,i);
            }
        }
    }
}


void dfs()
{
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(grid[i][j] == 1){
                grid[i][j] = -1;
            }
        }
    }
    queue<pair<int,int> > q;
    int x = minoposx;
    int y = minoposy;
    q.push(make_pair(y,x));
    grid[y][x] = 0;
    
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;
        if(grid[y+1][x] < 0 || grid[y+1][x] > 0 && grid[y+1][x] > grid[y][x]+1){
            grid[y+1][x] = grid[y][x] + 1;
            q.push(make_pair(y+1,x));
        }
        if(grid[y-1][x] < 0 || grid[y-1][x] > 0 && grid[y-1][x] > grid[y][x]+1){
            grid[y-1][x] = grid[y][x] + 1;
            q.push(make_pair(y-1,x));
        }
        if(grid[y][x+1] < 0 || grid[y][x+1] > 0 && grid[y][x+1] > grid[y][x]+1){
            grid[y][x+1] = grid[y][x] + 1;
            q.push(make_pair(y,x+1));
        }
        if(grid[y][x-1] < 0 || grid[y][x-1] > 0 && grid[y][x-1] > grid[y][x]+1){
            grid[y][x-1] = grid[y][x] + 1;
            q.push(make_pair(y,x-1));
        }
    }
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            res2 = max(res2, grid[i][j]);
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    
    ll n;
    char c;
    while(cin >> n){
        arr.push_back(n);
        cin >> c;
    }
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            grid[i][j] = -1;
        }
    }
    
    vector<ll> cp(arr.begin(), arr.end());
    cp.resize(1000000);
    run(cp, []()->ll{ 
        int comm = 0;
        if(grid[posy+1][posx] < 0){
            comm = 1;
            steps.push(comm);
        }
        else if(grid[posy-1][posx] < 0){
            comm = 2;
            steps.push(comm);
        }
        else if(grid[posy][posx+1] < 0){
            comm = 3;
            steps.push(comm);
        }
        else if(grid[posy][posx-1] < 0){
            comm = 4;
            steps.push(comm);
        }
        else{
            if(steps.empty()){
                calcLims();
                printGrid();
                dfs();
                cout << minopos << endl;
                cout << res2 << endl;
                exit(0);
            }
            comm = steps.top();
            comm = comm%2 ? comm+1 : comm-1;
            steps.pop();
        }
        move(comm);
        return comm;
    }, [](ll a){
        grid[posy][posx] = a;
        if(a == 0){
            int lastpos = steps.top();
            lastpos = lastpos%2 ? lastpos+1 : lastpos-1;
            move(lastpos);
            steps.pop();
        }
        if(a == 2){
            if(minopos > steps.size()){
                minopos = steps.size();
                minoposx = posx;
                minoposy = posy;
            }
        }
    });

    return 0;
}