#include <bits/stdc++.h>
#define ld long double
using namespace std;
const int N=55;
int n,m,x[N],y[N];
ld f[N][N];
bool vis[N][N];
ld dist(int i,int j){return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));}
bool cmp(ld a,ld b){return a-b>1e-6;}
int main()
{
    while(cin>>n>>m&&(n|m))
    {
        memset(vis,0,sizeof vis);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                f[i][j]=1e15;
            f[i][i]=0;
        }
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        int u,v;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            vis[u][v]=vis[v][u]=1;
            f[u][v]=f[v][u]=dist(u,v);
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(cmp(f[i][j],f[i][k]+f[k][j]))
                        f[i][j]=f[i][k]+f[k][j];
        ld mxc=1,mxd,d,c,dd;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(vis[i][j])continue;
                d=dist(i,j),c=0;
                for(int k=1;k<=n;k++)
                    for(int l=1;l<=n;l++)
                    {
                        dd=f[k][l]-min(f[k][i]+f[j][l]+d,f[k][j]+f[i][l]+d);
                        if(cmp(dd,0))c+=dd;
                    }
                if(cmp(c,mxc))mxc=c,u=i,v=j;
            }

        }
        if(cmp(mxc,1))cout<<u<<" "<<v<<'\n';
        else cout<<"No road required\n";
    }
}

