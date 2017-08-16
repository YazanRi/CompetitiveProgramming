#include <bits/stdc++.h>
using namespace std;
struct st
{
    int r,x,y;
    char s;
};
st cnv(string s,int i)
{
    st ret;
    ret.r=i;
    stringstream ss;
    ss<<s;
    ss>>ret.x>>ret.y>>ret.s;
    return ret;
}
class Table {
public:
	vector <string> layout(vector <string> a) {
	    int n=a.size(),cnt=0;
	    vector<string>v;
	    string c="";
	    for(int i=0;i<100;i++)c+='.';
	    for(int i=0;i<n;i++)v.push_back(c);
	    c="";
        st e[300];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a[i].size();j++)
            {
                if(a[i][j]!='('&&a[i][j]!=')')
                {
                    if(a[i][j]!=',')c+=a[i][j];
                    else c+=' ';
                }
                if(a[i][j]==')')e[cnt++]=cnv(c,i),c="";
            }
        }
        int cl=0,rw;
        for(int i=0;i<cnt;i++)
        {
            rw=e[i].r;
            for(int j=0;j<100;j++)
                if(v[rw][j]=='.'){cl=j;break;}
            for(int j=cl;j<cl+e[i].x;j++)
                for(int k=rw;k<rw+e[i].y;k++)
                        v[k][j]=e[i].s;

        }
        int mx=-1;
        for(int j=0;j<v[0].size();j++)
            if(v[0][j]=='.')
            {
                mx=j;
                break;
            }
        for(int i=0;i<n;i++)
            v[i].resize(mx);
        return v;
	}
};
