#include <bits/stdc++.h>
#define LL long long
using namespace std;
int ans[10],sign;
void solve(int x,int i)
{
    if(x==-1)return;
    int a=x/10,b=x%10;
    for(int j=1;j<=b;j++)ans[j]+=sign*i;
    for(int j=0;j<10;j++)ans[j]+=sign*i*a;
    int nn=a;
    while(nn)
    {
        ans[nn%10]+=sign*(b+1)*i;
        nn/=10;
    }
    solve(a-1,i*10);
}
int main()
{
    int a,b;
    while(cin>>a>>b&&(a||b))
    {
        if(a>b)swap(a,b);
        memset(ans,0,sizeof ans);
        sign=1;solve(b,1);
        sign=-1;solve(a-1,1);
        for(int i=0;i<10;i++)cout<<ans[i]<<(i==9?'\n':' ');
    }
}

