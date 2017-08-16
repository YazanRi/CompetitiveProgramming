#include <bits/stdc++.h>
using namespace std;
class SmartElevator {
public:
	int timeWaiting(vector <int> a, vector <int> s, vector <int> e) {
	    int n=a.size();
	    vector<int>v;
	    for(int i=0;i<n;i++)
            v.push_back(i),v.push_back(i);
        bool vis[n];
        int mn=2e9,t,cur,c;
        do
        {
            memset(vis,0,sizeof vis);
            t=0;
            cur=1;
            for(int i=0;i<2*n;i++)
            {
                c=v[i];
                if(!vis[c])
                {
                    vis[c]=1;
                    int tmp=abs(s[c]-cur);
                    if(t>a[c])t+=tmp;
                    else t+=max(tmp,a[c]-t);
                    cur=s[c];
                }
                else
                {
                    t+=abs(cur-e[c]);
                    cur=e[c];
                }
            }
            mn=min(t,mn);
        }while(next_permutation(v.begin(),v.end()));
        return mn;
	}
};