#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;


vector<int> arr;
int pattern[] = {0, 1, 0, -1};

void read()
{
    char c;
    while(cin >> c){
        arr.push_back(c-'0');
    }
}

vector<int> proceed(vector<int>& arr)
{
    vector<int> res;
    vector<int> sums(arr.size());
    for(int i=0;i<arr.size();i++){
        int sm = arr[i];
        if(i){
            sm += sums[i-1];
        }
        sums[i] = sm;
    }
    
    for(int i=0;i<arr.size();i++){
        int mult = 1;
        int sum = 0;
        int a = (i+1)*2;
        for(int j=i;j<arr.size();j+=a){
            int subsum = sums[min(j+i,(int)arr.size()-1)];
            if(j>0)
                subsum -= sums[j-1];
            sum += subsum*mult;
            mult = -mult;
        }
        res.push_back(abs(sum)%10);
    }
    return res;
}

int main()
{
    read();
    
    vector<int> cp(arr.begin(), arr.end());
    
    for(int i=0;i<100;i++){
        cp = proceed(cp);
    }
    for(int i=0;i<8;i++){
        cout << cp[i];
    }
    cout << endl;
    
    //////////////////////////
    
    vector<int> scp;
    for(int i=0;i<10000;i++){
        for(int j=0;j<arr.size();j++){
            scp.push_back(arr[j]);
        }
    }
    cout << "Second part will take near 2 minutes to be completed:" << endl;
    
    for(int i=0;i<100;i++){
        scp = proceed(scp);
        if(i%25 == 0)
            cout << endl;
        cout << "|";
    }
    cout << endl;
    int nxt = 0;
    for(int i=0;i<7;i++)
        nxt = nxt*10 + arr[i];
    
    for(int i=nxt;i<nxt+8;i++){
        cout << scp[i];
    }
    cout << endl;
    
    
    return 0;
}