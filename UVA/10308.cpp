#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
const int N=1e4+50;
int f;
bool vis[N];
long long d[N];
vector<vector<pii> >adj(N);
long long BFS(int cur=1)
{
    long long mx=0;
    memset(vis,0,sizeof vis);
    memset(d,0,sizeof d);
    queue<int>q;
    q.push(cur);
    vis[cur]=1;
    while(q.size())
    {
        cur=q.front();
        q.pop();
        if(d[cur]>mx)f=cur,mx=d[cur];
        for(auto i:adj[cur])
        {
            if(vis[i.f])continue;
            vis[i.f]=1;
            d[i.f]=d[cur]+i.s;
            q.push(i.f);
        }
    }
    return mx;
}
int main()
{
    char s[50];
    int u,v,c;
    while(gets(s))
    {
        if(s[0]=='\0')
        {
            BFS();
            printf("%lld\n",BFS(f));
            adj.clear();
            adj.resize(N);
        }
        else
        {
            sscanf(s,"%d%d%d",&u,&v,&c);
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
    }
    BFS();
    printf("%lld\n",BFS(f));
}
