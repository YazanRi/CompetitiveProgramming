#include <bits/stdc++.h>
#define f first
#define s second
#define LL long long
using namespace std;
int n;
LL dp[55],mp,oh;
vector<pair<int,int> >v;
LL solve(int i)
{
    if(i<0)return 0;
    LL &x=dp[i];
    if(x!=-1)return x;
    x=1e18;
    for(int j=0;j<=i;j++)
    {
        LL dif=v[i].s-v[j].f;
        LL p=(dif+mp-1)/mp;
        LL add=dif+p*oh;
        x=min(x,solve(j-1)+add);
    }
    return x;
}
class DeviceProgramming {
public:
	long long minBytes(vector <int> os, vector <int> sz, int mpp, int ohh) {
        v.clear();
        n=sz.size();
        memset(dp,-1,sizeof dp);
        mp=mpp-ohh;
        oh=ohh;
        for(int i=0;i<n;i++)
            v.push_back({os[i],os[i]+sz[i]});
        sort(v.begin(),v.end());
        return solve(n-1);
	}
};
