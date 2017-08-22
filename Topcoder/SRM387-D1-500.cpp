#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int n,dp[55][55];
vector<pair<int,int> >v;
int solve(int i,int j)
{
    if(i>=j)return 0;
    if(i==n)return 1;
    int &x=dp[i][j];
    if(x==-1)
    {
        int k=i+1;
        while(k<n&&v[k].f<=v[i].s)k++;
        x=solve(k,n+5)+solve(i+1,min(j,k));
    }
    return x;
}
class IntervalSubsets {
public:
	int numberOfSubsets(vector <int> s, vector <int> f) {
	    n=s.size();
		v.clear();
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++)
            v.push_back({s[i],f[i]});
        sort(v.begin(),v.end());
        return solve(0,n+5);
	}
};
