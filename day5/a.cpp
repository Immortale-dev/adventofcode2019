#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

void run(int dc)
{
    vector<int> cp(arr.begin(), arr.end());
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
        
        int a,b,c;
        
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
                cp[a] = dc;
                break;
            case 4:
                vals = 2;
                a = cp[i+1];
                a = par[0] ? a : cp[a];
                cout << a << " ";
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
    int n;
    char c;
    while(cin >> n){
        arr.push_back(n);
        cin >> c;
    }
    
    run(1);
    cout << endl;
    run(5);
    
    return 0;
}