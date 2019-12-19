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


int grid[1000][1000];
int mxx=49,mxy=49,mnx=0,mny=0;
int posx = 0, posy = 0;
queue<int> q;
int res = 0;
int lastmn = 10000, lastmx;
bool found = false;
bool goodbot = false;
bool goodleft = false;
vector<ll> cp;

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
                case 1:
                    out = '#';
                    break;
                case 0:
                    out = '.';
                    break;
                default:
                    out = grid[i][j];
            }
            cout << out;
        }
        cout << '\n';
    }
}

void reset()
{
    for(int i=0;i<cp.size();i++){
        if(i < arr.size())
            cp[i] = arr[i];
        else
            cp[i] = 0;
    }
}

void clearConsole()
{
    system("CLS");
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
    
    cp.resize(100000);
    
    
    
    for(posx=0;posx<50;posx++){
        for(posy=0;posy<50;posy++){
            reset();
            q.push(posx);
            q.push(posy);
            run(cp, []()->ll{ 
                int t = q.front();
                q.pop();
                return t;
            }, [](ll a){
                grid[posy][posx] = a;
                if(a)
                    res++;
            });
        }
    }
    
    printGrid();
    cout << res << endl;
    
    //////////////////////////////////////////////////////////////
    
    for(int i=0;i<50;i++){
        if(grid[i][30]){
            lastmn = min(lastmn, i);
            lastmx = i;
        }
    }
    //cout << endl;
    
    //cout << lastmn << endl;
    
    //return 0;
    
    for(int i=30;i<10000;i++){
        found = false;
        while(!found){
            reset();
            q.push(i);
            q.push(lastmn);
            //cout << i << " " << lastmn << endl;
            run(cp, []()->ll{ 
                int t = q.front();
                q.pop();
                return t;
            }, [](ll a){
                if(a){
                    found = true;
                }
                else{
                    lastmn++;
                }
            });
        }
        
        //cout << "HERE" << endl;
        
        goodbot = false;
        goodleft = false;
        {
            reset();
            q.push(i);
            q.push(lastmn+99);
            run(cp, []()->ll{ 
                int t = q.front();
                q.pop();
                return t;
            }, [](ll a){
                goodbot = a;
            });
        }
        
        if(goodbot)
        {
            reset();
            q.push(i-99);
            q.push(lastmn+99);
            run(cp, []()->ll{ 
                int t = q.front();
                q.pop();
                return t;
            }, [](ll a){
                goodleft = a;
            });
        }
        
        //cout << i << " " << goodbot << " " << goodleft << endl;
        
        if(goodbot && goodleft){
            cout << ((i-99)*10000 + lastmn) << endl;
            exit(0);
        }
        
    }
    
    
    
    return 0;
}