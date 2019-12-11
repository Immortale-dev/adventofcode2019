#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> arr;

void run(vector<ll>& cp, bool (*ifn)(), void (*ofn)(bool))
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
                cp[a] = ifn() ? 1 : 0;
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


bool panel[1000][1000];
bool used[1000][1000];
int usedc = 0;
int cx,cy;
int px=0;
int py=-1;
bool outt = 0;

void rotate(bool d){
    if(d){
        if(!px){
            swap(px,py);
            px = -px;
        }
        else{
            swap(px,py);
        }
    }
    else{
        if(!px){
            swap(px,py);
        }
        else{
            swap(px,py);
            px = -px;
            py = -py;
        }
    }
}

int main()
{
    ll n;
    char c;
    while(cin >> n){
        arr.push_back(n);
        cin >> c;
    }
    
    memset(panel, 0, 1000000);
    memset(used, 0, 1000000);
    cy = 500;
    cx = 500;
    
    vector<ll> cp(arr.begin(),arr.end());
    cp.resize(1000000);
    
    run(cp, []()->bool{
        return panel[cx][cy];
    }, [](bool a){
        if(!outt){
            panel[cx][cy] = a;
            if(!used[cx][cy])
                usedc++;
            used[cx][cy] = true;
        }
        else{
            rotate(a);
            cx += px;
            cy += py;
        }
        outt = !outt;
    });
    
    cout << usedc << endl;
    
    /////////////////PART2//////////////////////
    
    memset(panel, 0, 1000000);
    cy = 500;
    cx = 500;
    panel[cx][cy] = 1;
    vector<ll> cpf(arr.begin(), arr.end());
    cpf.resize(1000000);
    outt = 0;
    px=0;
    py=-1;
    
    run(cpf, []()->bool{
        return panel[cx][cy];
    }, [](bool a){
        if(!outt){
            panel[cx][cy] = a;
        }
        else{
            rotate(a);
            cx += px;
            cy += py;
        }
        outt = !outt;
    });
    
    int tl=1000,tr=0,tt=1000,tb=0;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(panel[i][j]){
                tl = min(tl, j);
                tt = min(tt, i);
                tr = max(tr, j);
                tb = max(tb, i);
            }
        }
    }

    tl--;
    tt--;
    tr++;
    tb++;
    
    for(int i=tl;i<=tr;i++){
        for(int j=tt;j<=tb;j++){
            cout << (panel[j][i] ? '#' : '.');
        }
        cout << endl;
    }

    return 0;
}