/**

    idea :
            for each team, we get evaluate the remaining 2 points of every rectangle
            and then we apply convex hull to get the smallest convex polygon that
            contains all the points in it.
            if the 2 new polygons intersect, then we cant build the wall.

**/
#include <bits/stdc++.h>
#define f first
#define s second
#define LL long long
#define ld long double
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(v)      ((int)((v).size()))
#define rep(i, v)      for(int i=0;i<(sz(v));++i)
#define MP make_pair
#define X real()
#define Y imag()
#define dp(a,b)                 ( (conj(a)*(b)).real() )
#define cp(a,b)                 ( (conj(a)*(b)).imag() )
#define length(a)               (hypot((a).imag(), (a).real()))
using namespace std;
typedef complex<double> point;
typedef long long ll;
const double EPS = (1e-8);
/************************************************************/
int dcmp(double a, double b)
{
    return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1;
}
struct angleCMP
{
    point center;
    angleCMP(point c):center(c) {}
    bool operator () (const point &p0, const point p1)const
    {
        if(dcmp(cp(p0-center,p1-center),0)==0)
        {
            if(fabs(p0.Y-p1.Y)<EPS)
                return p0.X<p1.X;
            return p0.Y<p1.Y;
        }
        return cp(p0-center,p1-center)<0;
    }
};

vector<point> ConvexHull(vector<point> &points)
{
    if(sz(points) <= 1)	return points;

    rep(i, points) if( MP(points[i].Y, points[i].X) < MP(points[0].Y, points[0].X))
        swap(points[0], points[i]);

    sort( points.begin()+1, points.end(), angleCMP(points[0]));

    vector<point> p, ch;

    rep(i, points)
    {
        if(sz(p) > 1 && !cp(p.back()-p[0], points[i]-p[0]) )
        {
            if( length(points[0]-p.back()) < length(points[0]-points[i]) )
                p.back() = points[i];
        }
        else
            p.push_back( points[i] );
    }
    points = p;

    rep(i, points)
    {
        while( sz(ch) > 1 && cp(ch[sz(ch)-2]-ch[sz(ch)-1], points[i]-ch[sz(ch)-1]) <= 0)
            ch.pop_back();
        ch.push_back(points[i]);
    }
    if(sz(ch) >= 3)
        ch.push_back(ch[0]);
    return ch;
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
bool isPointOnSegment(point a, point b, point c)
{
    double acb = length(a-b), ac = length(a-c), cb = length(b-c);
    return dcmp(acb-(ac+cb), 0) == 0;
}


int isInsidePoly(vector<point> p, point p0)
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
bool polygonIntersection(vector<point>&u, vector<point>&v)
{
    for(auto i:v)
        if(isInsidePoly(u,i))
            return 1;
    for(auto i:u)
        if(isInsidePoly(v,i))
            return 1;
    u.push_back(u[0]);
    v.push_back(v[0]);
    for(int i=0; i<u.size()-1; i++)
        for(int j=0; j<v.size()-1; j++)
            if(intersectSegments(u[i],u[i+1],v[j],v[j+1]))
                return 1;
    return 0;
}
vector<point>a,b;
int main()
{
    int d,p,x1,y1,x2,y2,tc=1;
    bool f=0;
    while(scanf("%d%d",&d,&p)&&(d||p))
    {
        if(f)puts("");
        f=1;
        a.clear();
        b.clear();
        for(int i=0; i<d; i++)
        {
            cin>>x1>>y1>>x2>>y2;
            a.push_back(point(x1,y1));
            a.push_back(point(x1,y2));
            a.push_back(point(x2,y1));
            a.push_back(point(x2,y2));
        }
        for(int i=0; i<p; i++)
        {
            cin>>x1>>y1>>x2>>y2;
            b.push_back(point(x1,y1));
            b.push_back(point(x1,y2));
            b.push_back(point(x2,y1));
            b.push_back(point(x2,y2));
        }
        vector<point>p1=ConvexHull(a);
        vector<point>p2=ConvexHull(b);
        printf("Case %d: ",tc++);
        if(polygonIntersection(p1,p2))
            puts("It is not possible to separate the two groups of vendors.");
        else
            puts("It is possible to separate the two groups of vendors.");
    }
}
