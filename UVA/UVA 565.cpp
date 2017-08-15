#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n,mx=(1<<16)-1,m[150],d[150];
string s;
int main()
{
    while(1)
    {
        memset(m,0,sizeof m);
        memset(d,0,sizeof d);
        n=0;
        while(getline(cin,s))
        {
            if(s==".")break;
            for(int i=0;s[i]!=';';i+=2)
            {
                if(s[i]=='+')m[n]|=1<<(s[i+1]-'A');
                else d[n]|=1<<(s[i+1]-'A');
            }
            n++;
        }
        if(!n)break;
        bool ok=0;
        for(int i=0;i<=mx&&!ok;i++)
        {
            bool can;
            for(int j=0;j<n;j++)
            {
                can=0;
                if(m[j]&i)can=1;
                else if((i^mx)&d[j])can=1;
                if(!can)break;
            }
            if(!can)continue;
            ok=1;
            printf("Toppings: ");
            for(int j=0;j<16;j++)
                if(1&i>>j)printf("%c",(j+'A'));
            printf("\n");
        }
        if(!ok)printf("No pizza can satisfy these requests.\n");
    }
}
