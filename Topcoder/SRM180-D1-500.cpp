#include <bits/stdc++.h>
#define emp vector<string>()
using namespace std;
vector<string>rot(vector<string>&v)
{
    int n=v.size();
    vector<string>b;
    string x;
    for(int j=0;j<n;j++)
    {
        x="";
        for(int i=0;i<n;i++)
            x+=v[i][j];
        reverse(x.begin(),x.end());
        b.push_back(x);
    }
    return b;
}
class SquareCode {
public:
	vector <string> completeIt(vector <string> a) {
	    int n=a.size();
	    bool vis[50][50];
	    memset(vis,0,sizeof vis);
	    for(int k=0;k<4;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]=='.')
                    {
                        if(vis[i][j])return emp;
                        vis[i][j]=1;
                    }
                }
            }
            a=rot(a);
        }
        bool ok=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ok&=vis[i][j];
	    if(ok)return a;
        for(int i=0;i<n/2;i++)
            for(int j=0;j<n/2;j++)
                if(!vis[i][j])a[i][j]='.';
        memset(vis,0,sizeof vis);
	    for(int k=0;k<4;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]=='.')
                    {
                        if(vis[i][j])return emp;
                        vis[i][j]=1;
                    }
                }
            }
            a=rot(a);
        }
        ok=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ok&=vis[i][j];
        if(ok)return a;
        return emp;
	}
};
