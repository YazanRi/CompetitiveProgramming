#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
struct edge
{
  int f,t,w,r;
  edge (int f,int t, int w, int r):f(f),t(t),w(w),r(r){}
  bool operator < (const edge & e) const{return ((w > e.w));}
};
map<string,int>c;
map<int,string>cc;
vector<string>r;
vector<vector<edge> >adj(105);
int cost[105];
pair<int,int>par[105];
void djk(int from,int to)
{
    fill(cost,cost+105,1e9);
    cost[from]=0;
    par[from].f=par[from].s=-1;
    priority_queue<edge>q;
    q.push(edge(-1,from,0,0));
    while(q.size())
    {
        edge cur=q.top();
        q.pop();
        if(cost[cur.t]<cur.w)continue;
        for(auto e:adj[cur.t])
        {
            if(e.w+cost[e.f]<cost[e.t])
            {
                cost[e.t]=cost[e.f]+e.w;
                par[e.t]={e.f,e.r};
                q.push(edge(e.f,e.t,cost[e.t],e.r));
            }
        }
    }
}
vector<string>a,b;
void print(int cur)
{
    if(par[cur].f==-1)return;
    print(par[cur].f);
    a.push_back(cc[par[cur].f]);
    b.push_back(r[par[cur].s]);
}
int main()
{
    char s[100];
    string x,u,v,rd;
    int ct,i,cid=1,rid=0,cu,cv;
    while(gets(s))
    {
        if(!strlen(s))break;
        i=ct=0;
        x="";
        while(s[i]!=',')x+=s[i],i++;
        u=x; x=""; i++;
        while(s[i]!=',')x+=s[i],i++;
        v=x; x=""; i++;
        while(s[i]!=',')x+=s[i],i++;
        rd=x; x=""; i++;
        while(i<strlen(s))ct*=10,ct+=s[i]-'0',i++;
        if(!c[u])c[u]=cid++;
        if(!c[v])c[v]=cid++;
        cu=c[u]; cv=c[v];
        cc[cu]=u;
        cc[cv]=v;
        r.push_back(rd);
        adj[cu].push_back(edge(cu,cv,ct,rid));
        adj[cv].push_back(edge(cv,cu,ct,rid));
        rid++;
    }
    while(gets(s))
    {
        i=ct=0;
        x="";
        while(s[i]!=',')x+=s[i],i++;
        u=x; x=""; i++;
        while(i<strlen(s))x+=s[i],i++;
        v=x; x="";
        cu=c[u],cv=c[v];
        djk(cu,cv);
        a.clear();
        b.clear();
        print(cv);
        a.push_back(cc[cv]);
        b.push_back(b.back());
        cout<<"\n\n";
        cout<<"From                 To                   Route      Miles\n";
        cout<<"-------------------- -------------------- ---------- -----\n";
        int last=0,now,ans=0;
        for(int i=0;i<a.size()-1;i++)
        {
            cout<<a[i];
            for(int j=a[i].size();j<21;j++)cout<<" ";
            cout<<a[i+1];
            for(int j=a[i+1].size();j<21;j++)cout<<" ";
            cout<<b[i];
            for(int j=b[i].size();j<11;j++)cout<<" ";
            now=cost[c[a[i+1]]];
            printf("%5d\n",now-last);
            ans+=now-last;
            last=now;
        }
        cout<<"                                                     -----\n";
        cout<<"                                          Total      ";
        printf("%5d\n",ans);
    }
}
