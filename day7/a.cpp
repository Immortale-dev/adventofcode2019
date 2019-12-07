#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> arr;
ll mx = 0;

ll run(vector<ll>& cp, queue<ll> q, int& pos)
{
    for(int i=pos;i<cp.size();){
        
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
                cp[c] = a+b;
                break;
            case 2:
                vals = 4;
                a = cp[i+1];
                b = cp[i+2];
                c = cp[i+3];
                a = par[0] ? a : cp[a];
                b = par[1] ? b : cp[b];
                cp[c] = a*b;
                break;
            case 3:
                vals = 2;
                a = cp[i+1];
                cp[a] = q.front();
                q.pop();
                break;
            case 4:
                vals = 2;
                a = cp[i+1];
                a = par[0] ? a : cp[a];
                pos = i+vals;
                return a;
                break;
            case 5:
                vals = 3;
                a = cp[i+1];
                b = cp[i+2];
                a = par[0] ? a : cp[a];
                b = par[1] ? b : cp[b];
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
                cp[c] = a<b ? 1 : 0;
                break;
            case 8:
                vals = 4;
                a = cp[i+1];
                b = cp[i+2];
                c = cp[i+3];
                a = par[0] ? a : cp[a];
                b = par[1] ? b : cp[b];
                cp[c] = a==b ? 1 : 0;
                break;
            case 99:
                return q.front();
            default:
                cout << i << endl;
                cout << "Error" << endl;
                exit(1);
        }
        
        i+=vals;
    }
    return q.front();
}

void req(vector<int>& v, bool mode)
{
    if(v.size() == 5){
        vector<ll> carr[5];
        int cpos[5];
        for(int i=0;i<5;i++){
            carr[i] = vector<ll>(arr.begin(),arr.end());
            cpos[i] = 0;
        }
        ll last = 0;
        int count = mode ? 500 : 5;
        for(int j=0;j<count;j++){
            queue<ll> q;
            if(j < 5){
                q.push(v[j%5]);
            }
            q.push(last);
            last = run(carr[j%5], q, cpos[j%5]);
            if(j%5 == 4)
                mx = max(mx,last);
        }
        return;
    }
    bool used[10];
    memset(used,0,10);
    int f,t;
    f = mode ? 5 : 0;
    t = mode ? 10 : 5;
    for(int i=0;i<v.size();i++){
        used[v[i]] = 1;
    }
    for(int i=f;i<t;i++){
        if(!used[i]){
            v.push_back(i);
            req(v, mode);
            v.pop_back();
        }
    }
}

int main()
{
    int n;
    char c;
    while(cin >> n){
        arr.push_back(n);
        cin >> c;
    }
    
    vector<int> v;
    v.reserve(5);
    
    req(v, false);
    cout << mx << endl;
    req(v, true);
    cout << mx << endl;
    
    return 0;
}