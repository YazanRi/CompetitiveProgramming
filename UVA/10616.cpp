#include <bits/stdc++.h>
using namespace std;
int n,q,d,m,id,tc,tt,a[205],dp[201][21][11],vis[201][21][11];
int solve(int i,int s,int t)
{
    if(t==m)return (!s);
    if(i==n)return 0;
    int &x=dp[i][s][t];
    if(vis[i][s][t]==id)return x;
    vis[i][s][t]=id;
    int ss=(s+a[i])%d;
    if(ss<0)ss+=d;
    x=(solve(i+1,ss,t+1)+solve(i+1,s,t));
    return x;
}
int main()
{
    while(scanf("%d%d",&n,&q)&&(n||q))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("SET %d:\n",++tc);
        tt=0;
        while(q--)
        {
            id++;
            scanf("%d%d",&d,&m);
            printf("QUERY %d: %d\n",++tt,solve(0,0,0));
        }
    }
}
