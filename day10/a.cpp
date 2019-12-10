#include <bits/stdc++.h>


using namespace std;

bool arr[50][50];
int n,m;

void read()
{
    m = 0;
    string s;
    while(cin >> s){
        n = s.size();
        for(int i=0;i<n;i++){
            arr[m][i] = s[i] == '#';
        }
        m++;
    }
    
}

vector<pair<int,int> > get_iteration(int x, int y)
{
    unordered_map<double, pair<int,int> > st[4];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!arr[i][j] || i==x && j==y)
                continue;
            double w = i-x;
            double h = j-y;
            double coof = h != 0 ? w/h : 1000000;
            int ind = 0;
            if(w < 0)
                ind+=2;
            if(h < 0)
                ind++;
            if(!st[ind].count(coof)){
                st[ind][coof] = make_pair(i,j);
            }
            else{
                auto& p = st[ind][coof];
                if(abs(i-x) + abs(j-y) < abs(p.first-x) + abs(p.second-y))
                    st[ind][coof] = make_pair(i,j);
            }
        }
    }
    
    vector<pair<int,int> > res;
    vector<pair<int,int> > part[4];
    for(int i=0;i<4;i++){
        for(auto& it : st[i]){
            part[i].push_back(it.second);
        }
    }
    
    sort(part[2].begin(), part[2].end(), [x,y](auto& left, auto& right){
        return abs( ((double)left.second-y)/((double)left.first-x) ) < abs( ((double)right.second-y)/((double)right.first-x) );
    });
    
    sort(part[0].begin(), part[0].end(), [x,y](auto& left, auto& right){
        return abs( ((double)left.second-y)/((double)left.first-x) ) > abs( ((double)right.second-y)/((double)right.first-x) );
    });
    
    sort(part[1].begin(), part[1].end(), [x,y](auto& left, auto& right){
        return abs( ((double)left.second-y)/((double)left.first-x) ) < abs( ((double)right.second-y)/((double)right.first-x) );
    });
    
    sort(part[3].begin(), part[3].end(), [x,y](auto& left, auto& right){
        return abs( ((double)left.second-y)/((double)left.first-x) ) > abs( ((double)right.second-y)/((double)right.first-x) );
    });
    
    for(auto& it : part[2]){
        res.push_back(it);
    }
    for(auto& it : part[0]){
        res.push_back(it);
    }
    for(auto& it : part[1]){
        res.push_back(it);
    }
    for(auto& it : part[3]){
        res.push_back(it);
    }
    
    return res;
}

int main()
{
    
    read();
    
    int mx = 0;
    int besti, bestj;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!arr[i][j])
                continue;
            int res = get_iteration(i,j).size();
            if(res > mx){
                mx = res;
                besti = i;
                bestj = j;
            }
        }
    }
    
    // Solve first
    cout << mx << endl;
    
    int all = 200;
    int resB;
    
    do{
        vector<pair<int,int> > iter = get_iteration(besti, bestj);
        if(iter.size() >= all){
            resB = iter[all-1].second * 100 + iter[all-1].first;
            break;
        }
        all -= iter.size();
    }while(true);
    
    // Solve second
    cout << resB << endl;
    
    return 0;
}