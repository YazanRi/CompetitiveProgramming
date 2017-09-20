#include <bits/stdc++.h>
#define LL long long
using namespace std;

//	I found this solution with observation and I have no proof of it

vector<vector<int> >adj;
bool vis[100050];
int cnt,mod=1000000007;
void dfs(int cur)
{
    vis[cur]=1;
    cnt++;
    for(auto i:adj[cur])
        if(!vis[i])dfs(i);
}
LL fast_power(LL base, LL power)
{
    LL res=1;
    while(power)
    {
        if(power%2)res=(res*base)%mod;
        base=(base*base)%mod;
        power/=2;
    }
    return res;
}
int main()
{
    int t,n,m,u,v; scanf("%d",&t);
    vector<int>w;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        adj.clear();
        adj.resize(n+5);
        w.clear();
        memset(vis,0,sizeof vis);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            cnt=0;
            dfs(i);
            w.push_back(cnt);
        }
        int cc=w.size();
        if(cc==1)
        {
            printf("-1\n");
            continue;
        }
        LL ans=1;
        for(auto i:w)
            ans=(ans*i)%mod;
        ans=(ans*(fast_power(n,cc-2)))%mod;
        printf("%lld\n",ans);
    }
}