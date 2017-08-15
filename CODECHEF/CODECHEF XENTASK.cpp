#include <bits/stdc++.h>
#define LL long long
#define s(i) scanf("%d",&i)
using namespace std;
int t,n,a[30000],b[30000];
LL s1,s2;
int main()
{
    s(t);
    while(t--)
    {
        s1=s2=0;
        s(n);
        for(int i=0;i<n;i++)s(a[i]);
        for(int i=0;i<n;i++)s(b[i]);
        for(int i=0;i<n;i++)
        {
            if(i%2)s1+=a[i],s2+=b[i];
            else s1+=b[i],s2+=a[i];
        }
        printf("%lld\n",min(s1,s2));
    }
}
