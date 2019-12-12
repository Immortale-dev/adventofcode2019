#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int moons[10][3];
int vels[10][3];
int n=0;


ll gcd(ll a, ll b)
{
    if(a%b == 0)
        return b;
    return gcd(b, a%b);
}

void read()
{
    char c;
    int a;
    string s;
    while(getline(cin, s)){
        stringstream ss;
        ss << s;
        ss >> c >> c >> c;      //<x=
        ss >> moons[n][0];
        ss >> c >> c >> c;      // y=
        ss >> moons[n][1];
        ss >> c >> c >> c;      // z=
        ss >> moons[n][2];
        ss >> c;      //>
        vels[n][0] = vels[n][1] = vels[n][2] = 0;
        n++;
    }
}

void calcVels()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j)
                continue;
            for(int k=0;k<3;k++){
                if(moons[j][k] == moons[i][k])
                    continue;
                vels[i][k] += moons[j][k] > moons[i][k] ? 1 : -1;
            }
        }
    }
}

void updateMoons()
{
    for(int i=0;i<n;i++){
        for(int k=0;k<3;k++){
            moons[i][k] += vels[i][k];
        }
    }
}

int calcEnergy()
{
    int sum = 0;
    for(int i=0;i<n;i++){
        int kEn=0, pEn=0;
        for(int k=0;k<3;k++){
            pEn += abs(moons[i][k]);
            kEn += abs(vels[i][k]);
        }
        sum += pEn*kEn;
    }
    return sum;
}

bool is_initial()
{
    for(int i=0;i<n;i++){
        for(int k=0;k<3;k++){
            if(vels[i][k] != 0)
                return false;
        }
    }
    return true;
}

void printMoons()
{
    for(int i=0;i<n;i++){
        for(int k=0;k<3;k++){
            cout << moons[i][k] << " ";
        }
        cout << endl;
    }
}

ll xd=0, yd=0, zd=0;

int main()
{
    read();
    
    for(int i=0;i<1000;i++){
        calcVels();
        updateMoons();
    }
    
    // Part 1
    cout << calcEnergy() << endl;
    
    ////////////////////////////////
    
    ll cc=1000;
    while(++cc){
        if(xd && yd && zd)
            break;
        calcVels();
        updateMoons();
        if(!xd && vels[0][0] == 0 && vels[1][0] == 0 && vels[2][0] == 0 && vels[3][0] == 0)
            xd = cc;
        if(!yd && vels[0][1] == 0 && vels[1][1] == 0 && vels[2][1] == 0 && vels[3][1] == 0)
            yd = cc;
        if(!zd && vels[0][2] == 0 && vels[1][2] == 0 && vels[2][2] == 0 && vels[3][2] == 0)
            zd = cc;
    }
    
    
    ll g = gcd(gcd(xd,yd), zd);
    
    // Part 2
    cout << xd*yd*zd/g << endl;
    
    return 0;
}