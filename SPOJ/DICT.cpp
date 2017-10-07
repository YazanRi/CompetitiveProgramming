#include <bits/stdc++.h>
#define f first
#define s second
#define LL long long
#define ld long double
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n,k;
string s,a[25050];
map<string,bool>vis;
map<string,vector<int> >mp;
int main()
{
    IO;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(vis.find(a[i])!=vis.end())continue;
        vis[a[i]]=1;
        string x="";
        for(int j=0;j<a[i].size()-1;j++)
        {
            x+=a[i][j];
            mp[x].push_back(i);
        }
    }
    cin>>k;
    for(int tc=1;tc<=k;tc++)
    {
        cin>>s;
        cout<<"Case #"<<tc<<":\n";
        auto it=mp.find(s);
        if(it==mp.end())cout<<"No match.\n";
        else for(int i=0;i<(it->s.size());i++)
                cout<<a[(it->s)[i]]<<'\n';
    }
}
