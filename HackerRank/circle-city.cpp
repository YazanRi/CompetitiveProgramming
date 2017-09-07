#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main()
{
    int t; cin>>t;
    LL d,k,a,b;
    while(t--)
    {
        a=b=0;
        cin>>d>>k;
        for(LL i=1;i*i<=d;i++)
        {
            if(d%i==0)
            {
                if(i%4==1)a++;
                if(i%4==3)b++;
                if(d/i!=i)
                {
                    if((d/i)%4==1)a++;
                    if((d/i)%4==3)b++;
                }
            }
        }
        cout<<(k>=4*(a-b)?"possible\n":"impossible\n");
    }
}
