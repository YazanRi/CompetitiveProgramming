#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    int t; cin>>t;
    LL d,k,a;
    while(t--)
    {
        cin>>d>>k;
        a=0;
        for(LL i=0;i*i<=d;i++)
        {
            LL s=d-i*i;
            LL q=sqrt(s);
            if(q*q==s)a+=(i&&q?4:2);
        }
        cout<<(k>=a?"possible\n":"impossible\n");
    }
}
