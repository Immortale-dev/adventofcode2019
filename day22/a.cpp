#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> commands;
const int N = 10007;
int cards[10010];

void deal_into_new_stack()
{
    for(int i=0;i<N/2;i++){
        swap(cards[i], cards[N-i-1]);
    }
}

void cut_cards(int n)
{
    int nc[N];
    int start = (N+n)%N;
    for(int i=0;i<N;i++){
        nc[i] = cards[(start+i)%N];
    }
    for(int i=0;i<N;i++){
        cards[i] = nc[i];
    }
}

void deal_with_increment(int n){
    int nc[N];
    for(int i=0,p=0;i<N;i++,p=(p+n)%N){
        nc[p] = cards[i];
    }
    for(int i=0;i<N;i++){
        cards[i] = nc[i];
    }
}

void print()
{
    for(int i=0;i<N;i++){
        cout << cards[i] << " ";
    }
}

void callCommand(string s)
{
    
}

int main()
{
    string line;
    while(getline(cin, line)){
        stringstream ss;
        ss << line;
        string s;
        ss >> s;
        if(s == "deal"){
            ss >> s;
            if(s == "with"){
                ss >> s;
                int n;
                ss >> n;
                commands.push_back(make_pair(2,n));
                //deal_with_increment(n);
            }
            else{
                //deal_into_new_stack();
                commands.push_back(make_pair(0,0));
            }
        }
        else{
            int n;
            ss >> n;
            commands.push_back(make_pair(1,n));
            //cut_cards(n);
        }
    }
    for(int i=0;i<N;i++){
        cards[i] = i;
    }
    
    for(auto &comm : commands){
        switch(comm.first){
            case 0:
                deal_into_new_stack();
                break;
            case 1:
                cut_cards(comm.second);
                break;
            case 2:
                deal_with_increment(comm.second);
        }
    }
    
    //print();
    
    for(int i=0;i<N;i++){
        if(cards[i] == 2019){
            cout << i << endl;
        }
    }
    
    return 0;
}