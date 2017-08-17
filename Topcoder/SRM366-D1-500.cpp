#include <bits/stdc++.h>
using namespace std;
int cmp(vector<string> a,vector<string>b)
{
    /// 0 if a = b, 1 if a < b, -1 if b < a
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a.size()!=b.size())return a.size()<b.size()?1:-1;
    for(int i=0;i<a.size();i++)
        if(a[i]<b[i])return 1;
        else if(a[i]>b[i])return -1;
    return 0;
}
vector<string>res,mx,gg,ss;
int n,sn,resx,mxx;
map<string,int>m;
int calc()
{
    bool vs[55];
    memset(vs,0,sizeof vs);
    for(int i=0;i<res.size();i++)
    {
        int c=m[res[i]];
        for(int j=0;j<sn;j++)
            if(ss[c][j]=='Y')vs[j]=1;
    }
    int c=0;
    for(int i=0;i<55;i++)c+=vs[i];
    return c;
}
void solve(int mask,int idx)
{
    if(resx>mxx)
        mx=res,mxx=resx;
    else if(resx==mxx)
    {
        int c=cmp(res,mx);
        if(c==1)mx=res;
    }
    for(int i=idx;i<n;i++)
    {
        if(mask&(1<<i))continue;
        res.push_back(gg[i]);
        int old=resx;
        resx=calc();
        solve(mask|(1<<i),i+1);
        resx=old;
        res.pop_back();
        solve(mask,i+1);
    }
}
class GuitarConcert {
public:
	vector <string> buyGuitars(vector <string> g, vector <string> s) {
		n=g.size();
		sn=s[0].size();
		for(int i=0;i<n;i++)m[g[i]]=i;
        gg=g,ss=s;
        solve(0,0);
        sort(mx.begin(),mx.end());
        return mx;
	}
};
