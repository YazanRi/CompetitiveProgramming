#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
int t,n,ci,mi;
vector<vector<int> >g1,g2;
bool v1[105],v2[105];
void BFS()
{
    memset(v1,0,sizeof v1);
    memset(v2,0,sizeof v2);
    queue<pii>q;
    q.push({ci,1});
    q.push({mi,2});
    v1[ci]=1;
    v2[mi]=1;
    while(q.size())
    {
        pii cur=q.front();
        q.pop();
        if(cur.s==1)
        {
            for(auto i:g1[cur.f])
                if(!v1[i])v1[i]=1,q.push({i,1});
        }
        else
        {
            for(auto i:g2[cur.f])
                if(!v2[i])v2[i]=1,q.push({i,2});
        }
    }
}
bool BFS2()
{
    memset(v2,0,sizeof v2);
    queue<int>q;
    q.push(mi);
    bool f=0;
    while(q.size())
    {
        int cur=q.front();
        q.pop();
        if(f&&cur==mi)return 1;
        f=1;
        for(auto i:g2[cur])
            if(!v2[i]&&!v1[i])v2[i]=1,q.push(i);
    }
    return 0;
}
int main()
{
    cin>>t;
    getchar();
    while(t--)
    {
        string ans="N N";
        g1.clear();
        g1.resize(105);
        g2.clear();
        g2.resize(105);
        cin>>n>>ci>>mi;
        int u,v;
        string s;
        while(cin>>u>>v)
        {
            if(u==-1)break;
            g1[u].push_back(v);
        }
        cin.ignore();
        while(getline(cin,s))
        {
            if(s=="")break;
            stringstream ss;
            ss<<s;
            ss>>u>>v;
            g2[u].push_back(v);
        }
        BFS();
        for(int i=1;i<=100;i++)
            if(v1[i]&&v2[i])ans[0]='Y';
        if(BFS2())ans[2]='Y';
        cout<<ans<<'\n';
        if(t)cout<<'\n';
    }
}
