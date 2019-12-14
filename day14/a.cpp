#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


unordered_map<string, pair<ll, vector<pair<string, ll> > > > arr;
unordered_map<string, ll> elems;
ll result = 0;
void read()
{
    string str;
    while(getline(cin, str)){
        stringstream ss;
        ss << str;
        vector<pair<string, ll> > part;
        bool flag = true;
        while(flag){
            ll a;
            string r;
            ss >> a >> r;
            if(r[r.size()-1] == ','){
                r.pop_back();
            }
            else{
                flag = false;
            }
            part.push_back(make_pair(r, a));
        }
        string other;
        ss >> other;
        ll a;
        string r;
        ss >> a >> r;
        arr[r] = make_pair(a, part);
        
    }
}

void dfs(string key, ll count)
{
    if(key == "ORE"){
        result += count;
        return;
    }
    ll need = count;
    ll mns = min(elems[key], need);
    need -= mns;
    elems[key] -= mns;
    if(!need)
        return;
    ll c = (need-1)/arr[key].first+1;
    elems[key] += c * arr[key].first - need;
    
    for(auto &it : arr[key].second){
        dfs(it.first, it.second * c);
    }
    
}

int main()
{
    read();
    
    int mn = 1, mx = 10000000, md;
    ll MX = 1E12;
    ll res = 0;
    
    dfs("FUEL", 1);
    
    // Part 1
    cout << result << endl;
        
    while(mn <= mx){
        md = (mn+mx)/2;
        result = 0;
        elems.clear();
        dfs("FUEL", md);
        if(result > MX){
            mx = md-1;
        }
        else{
            res = md;
            mn = md+1;
        }
    }
    
    // Part 2
    cout << res << endl;
    
    return 0;
}