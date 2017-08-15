#include <bits/stdc++.h>
#define LL long long
using namespace std;
struct date
{
    int y,m,d,c;
}a[1050];
date nxt(date x)
{
    bool l=(x.y%400==0||(x.y%4==0&&x.y%100!=0));
    int m[]={31,28+l,31,30,31,30,31,31,30,31,30,31};
    x.d++;
    if(x.d>m[x.m-1])x.d=1,x.m++;
    if(x.m==13)x.m=1,x.y++;
    return x;
}
bool equal(date x,date y)
{
    return x.d==y.d&&x.m==y.m&&x.y==y.y;
}
int n,cnt;
LL sum;
int main()
{
    while(scanf("%d",&n)&&n)
    {
        cnt=0,sum=0;
        for(int i=0;i<n;i++)
            scanf("%d%d%d%d",&a[i].d,&a[i].m,&a[i].y,&a[i].c);
        for(int i=0;i<n-1;i++)
        {
            date s=nxt(a[i]);
            if(equal(s,a[i+1]))cnt++,sum+=a[i+1].c-s.c;
        }
        printf("%d %lld\n",cnt,sum);
    }
}
