#include <bits/stdc++.h>
using namespace std;
int n,m,tc,leaf;
vector<vector<int> >adj;
bool vis[105],ok;
void get_leaf(int c)
{
	if(vis[c])return;
	leaf=c;
	vis[c]=1;
	for(int j=0;j<adj[c].size();j++)
		get_leaf(adj[c][j]);
}
void dfs(int c)
{
	if(!ok)return;
	vis[c]=1;
	bool can=1;
	for(int j=0;j<adj[c].size();j++)
	{
	    int i=adj[c][j];
		if(vis[i])continue;
		if(adj[i].size()>1&&can)can=0;
		else if(adj[i].size()>1&&!can){ok=0;break;}
		dfs(i);
	}
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		adj.clear();
		adj.resize(n+5);
		memset(vis,0,sizeof vis);
		ok=1;
		scanf("%d",&m);
		int u,v;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			u--,v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(m!=n-1){printf("Graph %d is not a caterpillar.\n",++tc);continue;}
		get_leaf(u);
		for(int i=0;i<n&&ok;i++)if(!vis[i])ok=0;
		memset(vis,0,sizeof vis);
		dfs(leaf);
		if(!ok)printf("Graph %d is not a caterpillar.\n",++tc);
		else printf("Graph %d is a caterpillar.\n",++tc);
	}
}
