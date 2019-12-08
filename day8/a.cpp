#include <bits/stdc++.h>

#define W 25
#define H 6

using namespace std;


int main ()
{
    
    vector<int> arr;
    
    char c;
    while(cin >> c){
        arr.push_back(c-'0');
    }
    
    int lc = W*H;
    int count = arr.size()/lc;
    
    vector<int> counts[3];
    for(int i=0;i<3;i++){
        counts[i].resize(count);
        for(int j=0;j<count;j++){
            counts[i][j] = 0;
        }
    }

    for(int i=0;i<arr.size();i++){
        int n = arr[i];
        counts[n][i/lc]++;
    }
    
    int mxi = 0;
    for(int i=1;i<count;i++){
        if(counts[0][i] < counts[0][mxi]){
            mxi = i;
        }
    }
    
    cout << (counts[1][mxi]*counts[2][mxi]) << endl;
    
    vector<int> render(lc,2);
    
    for(int i=arr.size()-1;i>=0;i--){
        int np = arr[i];
        int pos = i%lc;
        int cur = render[pos];
        if(np < 2)
            render[pos] = np;
    }
    
    for(int i=0;i<render.size();i++){
        int n = render[i];
        int p = i%W;
        if(!p)
            cout << endl;
        cout << (n == 0 ? '.' : '#');
    }
    
    return 0;
}