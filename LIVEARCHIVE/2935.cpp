#include <bits/stdc++.h>
#define LL unsigned long long
using namespace std;
const int N=1550;
vector<vector<int> >g[2];
LL h[2*N];
string s;
void build(int idx)
{
    g[idx].clear();
    g[idx].resize(N);
    stack<int>st;
    st.push(0);
    int cur=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            g[idx][st.top()].push_back(cur);
            st.push(cur++);
        }
        else st.pop();
    }
}
LL val(int idx,int cur)
{
    LL ans=1;
    vector<LL>v;
    for(auto i:g[idx][cur])v.push_back(val(idx,i));
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        ans+=(h[i]*v[i]);
    return ans;
}
int main()
{
    for(int i=0;i<2*N;i++)
        h[i]=rand();
    int t; cin>>t;
    while(t--)
    {
        cin>>s; build(0);
        cin>>s; build(1);
        cout<<((val(0,0)==val(1,0))?"same\n":"different\n");
    }
}
