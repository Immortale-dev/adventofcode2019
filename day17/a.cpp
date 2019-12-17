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
int mxx=0,mxy=0,mnx=0,mny=0;
int posx = 0, posy = 0;
int robx, roby;
char robt;
string steps = "";
string A,B,C,res2;
int intstep = 0;
string fnl;
int res2out;

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
                case 35:
                    out = '#';
                    break;
                case 46:
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

void find_rob()
{
    for(int i=0;i<=mxy;i++){
        for(int j=0;j<mxx;j++){
            if(grid[i][j] == '<' || grid[i][j] == '>' || grid[i][j] == '^' || grid[i][j] == 'v'){
                robx = j;
                roby = i;
                robt = grid[i][j];
                return;
            }
        }
    }
}

void clearConsole()
{
    system("CLS");
}

bool move()
{
    switch(robt){
        case '^':
            if(robx-1 >= 0 && grid[roby][robx-1] == '#'){
                robt = '<';
                steps += "L,";
                int sf = 0;
                while(robx-1 >=0 && grid[roby][robx-1] == '#'){
                    grid[roby][robx] = '#';
                    grid[roby][robx-1] = robt;
                    sf++;
                    robx--;
                }
                steps += to_string(sf) + ",";
                return true;
            }
            if(robx+1 <= mxx && grid[roby][robx+1] == '#'){
                robt = '>';
                steps += "R,";
                int sf = 0;
                while(robx+1 <= mxx && grid[roby][robx+1] == '#'){
                    grid[roby][robx] = '#';
                    grid[roby][robx+1] = robt;
                    sf++;
                    robx++;
                }
                steps += to_string(sf) + ",";
                return true;
            }
            return false;
        case 'v':
            if(robx-1 >= 0 && grid[roby][robx-1] == '#'){
                robt = '<';
                steps += "R,";
                int sf = 0;
                while(robx-1 >= 0 && grid[roby][robx-1] == '#'){
                    grid[roby][robx] = '#';
                    grid[roby][robx-1] = robt;
                    sf++;
                    robx--;
                }
                steps += to_string(sf) + ",";
                return true;
            }
            if(robx+1 <= mxx && grid[roby][robx+1] == '#'){
                robt = '>';
                steps += "L,";
                int sf = 0;
                while(robx+1 <= mxx && grid[roby][robx+1] == '#'){
                    grid[roby][robx] = '#';
                    grid[roby][robx+1] = robt;
                    sf++;
                    robx++;
                }
                steps += to_string(sf) + ",";
                return true;
            }
            return false;
        case '<':
            if(roby-1 >= 0 && grid[roby-1][robx] == '#'){
                robt = '^';
                steps += "R,";
                int sf = 0;
                while(roby-1 >= 0 && grid[roby-1][robx] == '#'){
                    grid[roby][robx] = '#';
                    grid[roby-1][robx] = robt;
                    sf++;
                    roby--;
                }
                steps += to_string(sf) + ",";
                return true;
            }
            if(roby+1 <= mxy && grid[roby+1][robx] == '#'){
                robt = 'v';
                steps += "L,";
                int sf = 0;
                while(roby+1 <= mxy && grid[roby+1][robx] == '#'){
                    grid[roby][robx] = '#';
                    grid[roby+1][robx] = robt;
                    sf++;
                    roby++;
                }
                steps += to_string(sf) + ",";
                return true;
            }
            return false;
        case '>':
            if(roby-1 >= 0 && grid[roby-1][robx] == '#'){
                robt = '^';
                steps += "L,";
                int sf = 0;
                while(roby-1 >= 0 && grid[roby-1][robx] == '#'){
                    grid[roby][robx] = '#';
                    grid[roby-1][robx] = robt;
                    sf++;
                    roby--;
                }
                steps += to_string(sf) + ",";
                return true;
            }
            if(roby+1 <= mxy && grid[roby+1][robx] == '#'){
                robt = 'v';
                steps += "R,";
                int sf = 0;
                while(roby+1 <= mxy && grid[roby+1][robx] == '#'){
                    grid[roby][robx] = '#';
                    grid[roby+1][robx] = robt;
                    sf++;
                    roby++;
                }
                steps += to_string(sf) + ",";
                return true;
            }
            return false;
    }
    return false;
}


bool testRes(string& res)
{
    
    bool logs = false;
    
    string st = steps;
    while(st.size() > 1){
        if(st.find(A) == 0){
            res = res+"A,";
            st = st.substr(A.size()+1);
            continue;
        }
        if(st.find(B) == 0){
            res = res+"B,";
            st = st.substr(B.size()+1);
            continue;
        }
        if(st.find(C) == 0){
            res = res+"C,";
            st = st.substr(C.size()+1);
            continue;
        }
        return false;
    }
    res.pop_back();
    return true;
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
        return 0;
    }, [](ll a){
        if(a != 10){
            grid[posy][posx] = a;
            posx++;
        }
        else{
            posx = 0;
            posy++;
        }
        mxx = max(mxx, posx);
        mxy = max(mxy, posy);
    });
    
    int res1 = 0;
    int rc = 0;
    for(int i=1;i<mxy;i++){
        for(int j=1;j<mxx;j++){
            if(grid[i][j] == 35 && grid[i+1][j] == 35 && grid[i-1][j] == 35 && grid[i][j+1] == 35 && grid[i][j-1] == 35){
                rc++;
                res1 += i*j;
            }
        }
    }
    
    printGrid();
    
    cout << res1 << endl;
    
    ///////////////////////////////////////////////////
    
    find_rob();
    while(move());
    
    //cout << steps << endl;
    
    for(int i=0;i<=20;i++){
        if(steps[i] == ','){

            A = steps.substr(0, i);
            
            for(int j=i+1;j<steps.size();j++){
                if(steps[j-1] == ','){
                    for(int jj=j;jj-j<=20 && jj<steps.size();jj++){
                        if(steps[jj] == ','){
                            
                            B = steps.substr(j, jj-j);
                            
                            for(int k=jj+1;k<steps.size();k++){
                                if(steps[k-1] == ','){
                                    for(int kk=k;kk-k<=20 && kk<steps.size();kk++){
                                        if(steps[kk] == ','){
                                            
                                            C = steps.substr(k, kk-k);
                                            
                                            res2 = "";
                                            if(testRes(res2)){
                                                
                                                /*
                                                cout << "Main routine: " << res2 << endl;
                                                cout << "A: " << A << endl;
                                                cout << "B: " << B << endl;
                                                cout << "C: " << C << endl;
                                                */
                                                
                                                fnl = res2 + "\n" + A + "\n" + B + "\n" + C + "\n" + "n";
                                                
                                                vector<ll> scp(arr.begin(), arr.end());
                                                scp.resize(1000000);
                                                
                                                scp[0] = 2;
                                                
                                                run(scp, []()->ll{ 
                                                    return fnl[intstep++];
                                                }, [](ll a){
                                                    res2out = a;
                                                });
                                                
                                                cout << res2out << endl;
                                                
                                                return 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << "Something went wrongm sorry :(" << endl;

    return 0;
}