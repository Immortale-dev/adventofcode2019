#include <bits/stdc++.h>

#define ANIMATE_STEP 25

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



vector<ll> outputs;
int grid[100][100];
int rmem[3],rc=0;
int cc = 0;
int mxx=0,mxy=0,mnx=100,mny=100;
int ballx,bally;
int paddx,paddy;
ll score = 0;
int coutr = 0;
bool readMem(ll a)
{
    bool ret = false;
    rmem[rc] = a;
    if(rc == 2){
        int id = rmem[2];
        int x = rmem[0];
        int y = rmem[1];
        if(x == -1 && y == 0){
            score = id;
        }
        else{
            if(id == 4){
                ballx = x;
                bally = y;
                ret = true;
            }
            if(id == 3){
                paddx = x;
                paddy = y;
            }
            grid[y][x] = id;
            mxx = max(mxx,x);
            mnx = min(mnx,x);
            mxy = max(mxy,y);
            mny = min(mny,y);
        }
    }
    rc = (rc+1)%3;
    return ret;
}

void printGrid()
{
    for(int i=mny;i<=mxy;i++){
        for(int j=mnx;j<=mxx;j++){
            char out;
            switch(grid[i][j]){
                case 0:
                    out = ' ';
                    break;
                case 1:
                    out = '#';
                    break;
                case 2:
                    out = 'x';
                    break;
                case 3:
                    out = '=';
                    break;
                case 4:
                    out = 'o';
                    break;
                default:
                    out = '.';
            }
            cout << out;
        }
        cout << '\n';
    }
}

void clearConsole()
{
    system("CLS");
    /*int bsc = (mxy-mny+1)*(mxx-mnx+2);
    while(bsc--){
        cout << '\b';
    }*/
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
    
    vector<ll> cp(arr.begin(), arr.end());
    cp.resize(1000000);
    run(cp, []()->ll{ return 0; }, [](ll a){
        outputs.push_back(a);
    });
    
    for(int i=0;i<outputs.size();i+=3){
        if(outputs[i+2] == 2)
            cc++;
    }
    
    
    ////////////////////////////////////////////
    
    vector<ll> cps(arr.begin(), arr.end());
    cps.resize(10000000);
    cps[0] = 2;
    run(cps, []()->ll{
        if(paddx < ballx){
            return 1;
        }
        if(paddx > ballx){
            return -1;
        }
        return 0;
    }, [](ll a){
        if(readMem(a) && (coutr%ANIMATE_STEP == 0) ){
            clearConsole();
            printGrid();
            cout.flush();
        }
        coutr++;
    });
    
    clearConsole();
    printGrid();
    
    cout << cc << endl;
    cout << score << endl;

    return 0;
}