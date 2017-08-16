#include <bits/stdc++.h>
using namespace std;
long long AVG(vector<long long>&v,int &n)
{
    long long r1=0,r2=0;
    for(int i=0;i<n;i++)
        r1+=v[i]/n,r2+=v[i]%n;
    return r1+(r2/n);
}
class TheJackpotDivOne {
public:
	vector <long long> find(vector <long long> a, long long m) {
	    int n=a.size();
	    long long avg,x;
        while(m)
        {
            sort(a.begin(),a.end());
            if(a[0]==a[n-1])
            {
                x=m/n;
                for(int i=0;i<n;i++)a[i]+=x,m-=x;
            }
            avg=AVG(a,n);
            x=avg-a[0]+1;
            x=min(x,m);
            a[0]+=x;
            m-=x;
        }
        sort(a.begin(),a.end());
        return a;
	}
};
