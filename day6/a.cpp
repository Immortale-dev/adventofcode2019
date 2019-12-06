#include <bits/stdc++.h>

using namespace std;

int resA = 0;
int resB = 0;
unordered_map <string, int> flt;
vector<int> track;
vector<int> lvls;

bool dfs(int root, vector<vector<int> >& arr, int lvl)
{
    int c = 0;
    for(int i=0;i<arr[root].size();i++){
        c += dfs(arr[root][i], arr, lvl+1);
    }
    
    resA += lvl;
    lvls[root] = lvl;
    
    track[root] = c;
    
    if(root == flt["YOU"] || root == flt["SAN"]){
        track[root]++;
    }
    
    if(track[root] == 2){
        resB = lvls[flt["YOU"]]-lvls[root] + lvls[flt["SAN"]]-lvls[root] - 2;
    }
    
    return track[root];
}

int main()
{

    vector<pair<string,string> > s;
    string a;
    while(cin >> a){
        string l = a.substr(0,3);
        string r = a.substr(4);
        s.push_back(make_pair(l,r));
    }
    
    for(auto& it : s){
        flt.insert(make_pair(it.first,0));
        flt.insert(make_pair(it.second,0));
    }
    
    int cnt = 0;
    for(auto &it : flt){
        it.second = cnt++;
    }
    
    vector< vector<int> > arr(flt.size());
    
    track.resize(flt.size());
    lvls.resize(flt.size());
    for(int i=0;i<flt.size();i++){
        track[i] = 0;
        lvls[i] = 0;
    }
    
    for(auto &it : s){
        int a,b;
        a = flt[it.first];
        b = flt[it.second];
        
        arr[a].push_back(b);
    }
    
    int root = flt["COM"];
    dfs(root, arr, 0);
    
    cout << resA << " " << resB << endl;
    
    return 0;
}