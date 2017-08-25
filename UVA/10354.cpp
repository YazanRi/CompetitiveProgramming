#include <bits/stdc++.h>
using namespace std;
int n,m,bh,of,yh,ma;
void floyd(int a[105][105])
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}
int f1[105][105],f2[105][105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(cin>>n>>m>>bh>>of>>yh>>ma)
    {
        for(int i=1;i<=100;i++)
        {
            f1[i][i]=f2[i][i]=0;
            for(int j=i+1;j<=100;j++)
                f1[i][j]=f2[i][j]=f2[j][i]=f1[j][i]=1e9;
        }
        int u,v,c;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>c;
            f1[u][v]=f2[u][v]=f1[v][u]=f2[v][u]=c;
        }
        floyd(f1);
        for(int i=1;i<=n;i++)
            if(f1[bh][i]+f1[i][of]==f1[bh][of])
                for(int j=1;j<=n;j++)
                    f2[i][j]=f2[j][i]=1e9;
        floyd(f2);
        if(f2[yh][ma]==1e9)cout<<"MISSION IMPOSSIBLE.\n";
        else cout<<f2[yh][ma]<<'\n';
    }
}
