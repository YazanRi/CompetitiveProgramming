#include <bits/stdc++.h>
using namespace std;
int n,m,c,x,a[105][105],i,j,l;
int main()
{
    cin>>n>>m>>c;
    for(int k=1;k<=c;k++)
    {
        cin>>x;
        while(x--)
        {
            a[i][j]=k;
            j+=(l?-1:1);
            if(l&&j==-1)l=0,i++,j=0;
            else if(!l&&j==m)l=1,i++,j=m-1;
        }
    }
    for(i=0;i<n;i++,cout<<'\n')
        for(j=0;j<m;j++)
            cout<<a[i][j]<<" ";
}
