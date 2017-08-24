#include <bits/stdc++.h>
using namespace std;
int n,m,ans,cc;
map<int,vector<int> >adj;
map<int,bool>vis;
set<int>s;
void dfs(int cur)
{
    vis[cur]=1;
    for(auto i:adj[cur])
        if(!vis[i])dfs(i);
}
int main()
{
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        s.insert(u);
        s.insert(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=n-s.size();
    for(auto i:s)
        if(!vis[i])dfs(i),cc++;
    printf("%d",ans+cc);
}
