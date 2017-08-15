#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    string s,x;
    while(getline(cin,s))
    {
        x=s;
        vector<string>v;
        v.push_back(s);
        int c=0;
        while(next_permutation(s.begin(),s.end())&&c++<10)v.push_back(s);
        c=0;
        while(prev_permutation(x.begin(),x.end())&&c++<10)v.push_back(x);
        int a[v.size()+5],mxi=0;
        for(int i=0;i<v.size();i++)
        {
            int mn=1e9;
            for(int j=0;j<v[i].size()-1;j++)
                mn=min(mn,abs(v[i][j]-v[i][j+1]));
            a[i]=mn;
            if(a[i]>a[mxi])mxi=i;
            else if(a[i]==a[mxi]&&v[i]<v[mxi])mxi=i;
        }
        cout<<v[mxi]<<a[mxi]<<'\n';
    }
}

