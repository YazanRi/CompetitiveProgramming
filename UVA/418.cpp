#include <bits/stdc++.h>
using namespace std;
int mx;
void solve(string &vl,string &vr,string &hu,string &hd)
{
    for(int hu1=1;hu1<11;hu1++)
    {
        for(int vl1=1;vl1<11;vl1++)
        {
            if(hu[hu1]!=vl[vl1])continue;
            for(int hu2=hu1+2;hu2<11;hu2++)
            {
                for(int vr1=1;vr1<11;vr1++)
                {
                    if(vr[vr1]!=hu[hu2])continue;
                    for(int vl2=vl1+2;vl2<11;vl2++)
                    {
                        for(int hd1=1;hd1<11;hd1++)
                        {
                            if(vl[vl2]!=hd[hd1])continue;
                            int vr2=vr1+vl2-vl1;
                            int hd2=hd1+hu2-hu1;
                            if(vr2>10||hd2>10)continue;
                            if(vr[vr2]!=hd[hd2])continue;
                            mx=max(mx,(vr2-vr1-1)*(hu2-hu1-1));
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    vector<string>a(4);
    while(cin>>a[0])
    {
        if(a[0]=="Q")break;
        cin>>a[1]>>a[2]>>a[3];
        mx=0;
        vector<int>p;
        for(int i=0;i<4;i++)p.push_back(i);
        do solve(a[p[0]],a[p[1]],a[p[2]],a[p[3]]);
        while(next_permutation(p.begin(),p.end()));
        cout<<mx<<'\n';
    }
}
