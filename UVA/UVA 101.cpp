#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n,a,b,pos[26];
string s,x;
int main()
{
    cin>>n;
    vector<vector<int> >v(n);
    for(int i=0;i<n;i++)v[i].push_back(i),pos[i]=i;
    while(cin>>s&&s!="quit")
    {
        cin>>a>>x>>b;
        if(pos[a]==pos[b])continue;
        if(s=="move"&&x=="onto")
        {
            bool f=0;
            int p,tmp=pos[a];
            for(int i=0;i<v[tmp].size();i++)
            {
                int cur=v[tmp][i];
                if(f)
                {
                    pos[cur]=cur;
                    v[cur].push_back(cur);
                }
                if(cur==a)f=1,p=i;
            }
            v[tmp].resize(p);

            f=0;
            tmp=pos[b];
            for(int i=0;i<v[tmp].size();i++)
            {
                int cur=v[tmp][i];
                if(f)
                {
                    pos[cur]=cur;
                    v[cur].push_back(cur);
                }
                if(cur==b)f=1,p=i;
            }
            v[tmp].resize(p+1);
            pos[a]=pos[b];
            v[tmp].push_back(a);
        }
        if(s=="move"&&x=="over")
        {
            bool f=0;
            int p,tmp=pos[a];
            for(int i=0;i<v[tmp].size();i++)
            {
                int cur=v[tmp][i];
                if(f)
                {
                    pos[cur]=cur;
                    v[cur].push_back(cur);
                }
                if(cur==a)f=1,p=i;
            }
            v[tmp].resize(p);
            pos[a]=pos[b];
            v[pos[b]].push_back(a);
        }
        if(s=="pile"&&x=="onto")
        {
            bool f=0;
            int p,tmp=pos[b];
            for(int i=0;i<v[tmp].size();i++)
            {
                int cur=v[tmp][i];
                if(f)
                {
                    pos[cur]=cur;
                    v[cur].push_back(cur);
                }
                if(cur==b)f=1,p=i;
            }
            v[tmp].resize(p+1);
            f=0;
            tmp=pos[a];
            for(int i=0;i<v[tmp].size();i++)
            {
                int cur=v[tmp][i];
                if(cur==a)f=1,p=i;
                if(f)
                {
                    pos[cur]=pos[b];
                    v[pos[b]].push_back(cur);
                }
            }
            v[tmp].resize(p);
        }
        if(s=="pile"&&x=="over")
        {
            bool f=0;
            int p,tmp=pos[a];
            for(int i=0;i<v[tmp].size();i++)
            {
                int cur=v[tmp][i];
                if(cur==a)f=1,p=i;
                if(f)
                {
                    pos[cur]=pos[b];
                    v[pos[b]].push_back(cur);
                }
            }
            v[tmp].resize(p);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<":";
        for(int j=0;j<v[i].size();j++)
            cout<<" "<<v[i][j];
        if(i!=n-1)cout<<'\n';
    }
}

