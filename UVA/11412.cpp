#include <bits/stdc++.h>
#define forit(i, a) for( __typeof((a).begin())i=(a).begin();i!=(a).end();i++)
using namespace std;
bool valid(string x,string s,int a,int b)
{
    int aa=0,bb=0;
    for(int i=0;i<4;i++)
        aa+=(x[i]==s[i]);
    for(int i=0;i<4;i++)
    {
        bool ok=0;
        for(int j=0;j<4;j++)
            if(s[i]==x[j]&&i!=j)ok=1;
        bb+=ok;
    }
    return(aa==a&&bb==b);
}
int main()
{
    string s="RGBYOV";
    sort(s.begin(),s.end());
    set<string>m;
    do m.insert(s.substr(0,4)); while(next_permutation(s.begin(),s.end()));
    int t; cin>>t;
    string s1,s2;
    int a1,a2,b1,b2;
    while(t--)
    {
        cin>>s1>>a1>>b1>>s2>>a2>>b2;
        bool ok=0;
        forit(x,m)
        {
            if(ok)break;
            ok|=(valid(*x,s1,a1,b1)&&valid(*x,s2,a2,b2));
        }
        printf(ok?"Possible\n":"Cheat\n");
    }
}
