#include <bits/stdc++.h>

using namespace std;

int calcA(int a)
{
    return a/3-2;
}

int calcB(int a){
    int ts = 0;
    while(calcA(a) > 0){
        a = calcA(a);
        ts += a;
    }
    return ts;
}

int main()
{
    int n;
    string line;
    int resA = 0;
    int resB = 0;
    while(cin >> n){
        resA += calcA(n);
        resB += calcB(n);
    }
    
    cout << resA << " " << resB << endl;
    
}