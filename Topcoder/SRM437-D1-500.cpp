#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n[50],m;
LL ans;
vector<int>v;
bool solve(int i,int k,int mask,bool can)
{
    if(k<0||k>m-i)return 0;
    if(i==m)
    {
        if(k)return 0;
        LL x=0;
        for(int j=0;j<m;j++)x=(x*10+n[j]);
        if(x<ans||ans==-1)ans=x;
        return 1;
    }
    for(int j=0;j<10;j++)
    {
        n[i]=j;
        if(can&&solve(i+1,k-(!(mask&(1<<j))),mask|1<<j,1))return 1;
        else if(j>=v[i]&&solve(i+1,k-(!(mask&(1<<j))),mask|1<<j,(j>v[i])))return 1;
    }
    return 0;
}
class TheInteger {
public:
	LL find(long long n, int k)
	{
        v.clear();
        LL N=n;
        while(N)v.push_back(N%10),N/=10;
        reverse(v.begin(),v.end());
        while(1)
        {
            m=v.size();
            ans=-1;
            solve(0,k,0,0);
            if(ans!=-1)return ans;
            for(auto &i:v)i=0;
            v.insert(v.begin(),1);
        }
	}
};
