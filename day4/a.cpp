#include <bits/stdc++.h>

using namespace std;

bool is_meet(int n, bool part2)
{
    vector<int> num;
    while(n){
        num.push_back(n%10);
        n/=10;
    }
    reverse(num.begin(),num.end());
    for(int i=1;i<num.size();i++){
        if(num[i] < num[i-1])
            return false;
    }
    for(int i=1;i<num.size();i++){
        if( (num[i] == num[i-1]) && (!part2 || ((i-2 < 0 || num[i-2] != num[i]) && (i+1 >= num.size() || num[i+1] != num[i]))) )
            return true;
    }
    return false;
}

int main()
{
    
    int a,b;
    cin >> a >> b;
    int resA = 0;
    int resB = 0;
    for(int i=a;i<=b;i++){
        if(is_meet(i, false)){
            resA++;
        }
        if(is_meet(i,true)){
            resB++;
        }
    }
    
    cout << resA << " " << resB << endl;
    return 0;
}