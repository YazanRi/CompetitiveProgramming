#include <bits/stdc++.h>
using namespace std;
set<int>st;
bool v[1000050];
class RightTriangle {
public:
	long long triangleCount(int p, int n, int a, int b, int c) {
	    if(p%2)return 0LL;
        for(int i=0;i<p;i++)st.insert(i);
        for(int i=0;i<n;i++)
        {
            int pos=((1LL*a*i*i)%p+(1LL*b*i)%p+c)%p;
            auto it=st.lower_bound(pos);
            if(it==st.end())it=st.begin();
            v[*it]=1;
            st.erase(it);
        }
        long long ans=0;
        for(int i=0;i<p/2;i++)
            if(v[i]&&v[i+p/2])ans+=n-2;
        return ans;
	}
};
