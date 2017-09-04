#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,tc,f[35][35];
int main()
{
    while(cin>>n)
    {
        memset(f,0,sizeof f);
        m=0;
        for(int i=0;i<n;i++)
        {
            cin>>u>>v;
            m=max(m,max(u,v));
            f[u][v]=1;
        }
        for(int k=0;k<=m;k++)
            for(int i=0;i<=m;i++)
                for(int j=0;j<=m;j++)
                    if(f[i][k]&&f[k][j])
                        f[i][j]+=f[i][k]*f[k][j];
        for(int k=0;k<=m;k++)
            if(f[k][k])
                for(int i=0;i<=m;i++)
                    for(int j=0;j<=m;j++)
                        if(f[i][k]&&f[k][j])
                            f[i][j]=-1;
        cout<<"matrix for city "<<tc++<<'\n';
        for(int i=0;i<=m;i++)
            for(int j=0;j<=m;j++)
                cout<<f[i][j]<<(j==m?'\n':' ');
    }
}

