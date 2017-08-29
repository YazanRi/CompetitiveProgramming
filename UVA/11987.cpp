#include <bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m;
int par[N];
vector<int>s[N];
long long sum[N];
void merge(int x,int y)
{
    x=par[x],y=par[y];
    if(x==y)return;
    if(s[x].size()>=s[y].size())
    {
        for(int &i:s[y])
            s[x].push_back(i),
            par[i]=x;
        sum[x]+=sum[y];
        sum[y]=0;
        s[y].clear();
    }
    else
    {
        for(int &i:s[x])
            s[y].push_back(i),
            par[i]=y;
        sum[y]+=sum[x];
        sum[x]=0;
        s[x].clear();
    }
}
void move(int x,int y)
{
    y=par[y];
    if(par[x]==y)return;
    int xx=par[x];
    auto i=s[xx].begin();
    while(*i!=x)i++;
    s[xx].erase(i);
    s[y].push_back(x);
    par[x]=y;
    sum[xx]-=x;
    sum[y]+=x;
}
int main()
{
    int t,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            sum[i]=par[i]=i;
            s[i].clear();
            s[i].push_back(i);
        }
        while(m--)
        {
            scanf("%d%d",&t,&x);
            if(t==1)
                scanf("%d",&y),
                merge(x,y);
            else if(t==2)
                scanf("%d",&y),
                move(x,y);
            else if(t==3)
                printf("%d %lld\n",s[par[x]].size(),sum[par[x]]);
        }
    }
}
