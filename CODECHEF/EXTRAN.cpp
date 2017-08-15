#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n,a[100050];
bool BS(int x)
{
    int l=0,r=n-1,mid,f,s;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]==x)f=mid,r=mid-1;
        else if(a[mid]>x)r=mid-1;
        else l=mid+1;
    }
    l=0,r=n-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]==x)s=mid,l=mid+1;
        else if(a[mid]>x)r=mid-1;
        else l=mid+1;
    }
    return f!=s;
}
int mmn(int i)
{
    if(!i)return a[1];
    return a[0];
}
int mmx(int i)
{
    if(i==n-1)return a[n-2];
    return a[n-1];
}
int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;i++)
            if(BS(a[i])||a[i]+1<mmn(i)||a[i]-1>mmx(i))
            {
                printf("%d\n",a[i]);
                break;
            }
    }
}
