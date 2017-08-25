#include <bits/stdc++.h>
using namespace std;
int n,tc,x[205],y[205];
double f[205][205];
double dist(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i=0;i<n;i++)
        {
            f[i][i]=0;
            for(int j=i+1;j<n;j++)
                f[i][j]=f[j][i]=dist(i,j);
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    f[i][j]=min(f[i][j],max(f[i][k],f[k][j]));
        printf("Scenario #%d\n",++tc);
        printf("Frog Distance = %.3f\n\n",f[0][1]);
    }
}
