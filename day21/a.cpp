#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> arr;

void run(vector<ll>& cp, function<ll()> ifn, function<void(ll)> ofn)
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


int main()
{
    std::ios_base::sync_with_stdio(false);
    
    ll n;
    char c;
    while(cin >> n){
        arr.push_back(n);
        cin >> c;
    }
    
    {
        vector<ll> cp(arr.begin(), arr.end());
        cp.resize(1000000);
        
        vector<string> instr;
        
        instr.push_back("NOT A T");
        instr.push_back("NOT B J");
        instr.push_back("OR J T");
        instr.push_back("NOT C J");
        instr.push_back("OR J T");
        instr.push_back("AND D T");
        instr.push_back("NOT T J");
        instr.push_back("NOT J J");
        
        string res = "";
        for(auto &it : instr){
            res += it + "\n";
        }
        res += "WALK\n";
        
        int i = 0;
        
        run(cp, [&res, &i]()->ll{ 
            return res[i++];
        }, [](ll a){
            if(a > 255){
                cout << endl << "RES: " << a << endl;
            }
            else{
                cout << ((char)a);
            }
        });
    }
    
    ////////////////////////////////////////////////////
    
    {
        vector<ll> cp(arr.begin(), arr.end());
        cp.resize(1000000);
        
        vector<string> instr;
        
        instr.push_back("NOT A T");
        instr.push_back("NOT B J");
        instr.push_back("OR J T");
        instr.push_back("NOT C J");
        instr.push_back("OR J T");
        instr.push_back("AND D T");
        instr.push_back("NOT H J");
        instr.push_back("NOT J J");
        instr.push_back("OR E J");
        instr.push_back("AND T J");
        
        string res = "";
        for(auto &it : instr){
            res += it + "\n";
        }
        res += "RUN\n";
        
        int i = 0;
        
        run(cp, [&res, &i]()->ll{ 
            return res[i++];
        }, [](ll a){
            if(a > 255){
                cout << endl << "RES: " << a << endl;
            }
            else{
                cout << ((char)a);
            }
        });
    }
    
    
    
    return 0;
}