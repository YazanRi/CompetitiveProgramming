#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,f[4];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        f[x%4]++;
    }
    if(f[0]<f[1]+f[3]+f[2]%2-1)puts("No");
    else puts("Yes");
}
