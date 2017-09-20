#include <bits/stdc++.h>
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )
#define cp(a,b)                 ( (conj(a)*(b)).imag() )
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
#define MP make_pair
#define all(v)     ((v).begin()), ((v).end())
#define sz(v)      ((int)((v).size()))
#define clr(v, d)     memset(v, d, sizeof(v))
#define repa(v)   for(int i=0;i<(sz(v));++i) for(int j=0;j<(sz(v[i]));++j)
#define rep(i, v)      for(int i=0;i<(sz(v));++i)
#define lp(i, cnt)     for(int i=0;i<(cnt);++i)
#define lpi(i, s, cnt) for(int i=(s);i<(cnt);++i)
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const double PI  = acos(-1.0);
const double EPS = 1e-8;
typedef complex<double> point;
int dcmp(double x, double y) {
  return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
int n,cc;
bool vis[50];
vector<vector<int> >adj;
vector<vector<point> >poly;
void dfs(int cur)
{
    vis[cur]=1;
    for(auto i:adj[cur])
        if(!vis[i])dfs(i);
}
bool isPointOnSegment(point a, point b, point c)
{
    double acb = length(a-b), ac = length(a-c), cb = length(b-c);
    return dcmp(acb-(ac+cb), 0) == 0;
}
int isInsidePoly(vector<point> &p, point p0)
{
    int wn = 0;
    for (int i = 0; i < sz(p); i++)
    {
        point cur = p[i], nxt = p[(i + 1) % sz(p)];
        if (isPointOnSegment(cur, nxt, p0))
            return true;
        if (cur.Y <= p0.Y)
        {
            if (nxt.Y > p0.Y && cp(nxt-cur, p0-cur) > EPS)
                ++wn;
        }
        else
        {
            if (nxt.Y <= p0.Y && cp(nxt-cur, p0-cur) < -EPS)
                --wn;
        }
    }
    return wn != 0;
}
bool intersectSegments(point a, point b, point c, point d)
{
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return 0;
    double t1 = d2 / d1, t2 = d3 / d1;
    if (t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
        return 0;
    return 1;
}
bool check(int u,int v)
{
    for(auto i:poly[v])
        if(isInsidePoly(poly[u],i))
            return 1;
    for(auto i:poly[u])
        if(isInsidePoly(poly[v],i))
            return 1;
    for(int i=0;i<poly[u].size()-1;i++)
        for(int j=0;j<poly[v].size()-1;j++)
            if(intersectSegments(poly[u][i],poly[u][i+1],poly[v][j],poly[v][j+1]))
                return 1;
    return 0;
}
int main()
{
    IO;
    string s;
    double x,y;
    while(cin>>n&&n)
    {
        cin.ignore();
        cc=0;
        memset(vis,0,sizeof vis);
        poly.clear();
        adj.clear();
        adj.resize(50);
        for(int i=0;i<n;i++)
        {
            vector<point>p;
            getline(cin,s);
            stringstream ss(s);
            while(ss>>x>>y)
                p.push_back(point(x,y));
            p.push_back(p[0]);
            poly.push_back(p);
        }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(check(i,j))
                    adj[i].push_back(j),
                    adj[j].push_back(i);
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            cc++;
            dfs(i);
        }
        cout<<cc<<'\n';
    }
}
