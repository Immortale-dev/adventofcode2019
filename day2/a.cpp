#include <bits/stdc++.h>

#define COMPARE 19690720

using namespace std;

vector<int> arr;

int run(int noun, int verb)
{
    vector<int> cp(arr.begin(), arr.end());
    cp[1] = noun;
    cp[2] = verb;
    for(int i=0;i<cp.size();i+=4){
        int op = cp[i];
        
        if(op == 99)
            break;
        
        int a = cp[i+1];
        int b = cp[i+2];
        int c = cp[i+3];
        
        cp[c] = op == 1 ? cp[a]+cp[b] : cp[a]*cp[b];
    }
    return cp[0];
}

int main()
{
    int n;
    char c;
    while(cin >> n){
        arr.push_back(n);
        cin >> c;
    }
    
    cout << run(12,2) << endl;
    
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(run(i,j) == COMPARE){
                cout << (100*i+j) << endl;
                exit(0);
            }
        }
    }
    
    return 0;
}