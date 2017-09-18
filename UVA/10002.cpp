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
const double EPS = 1e-8;
typedef complex<double> point;

int dcmp(double x, double y) {
  return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}

struct angleCMP{
	point center;
	angleCMP(point c):center(c){}
	bool operator () (const point &p0, const point p1)const{
		if(dcmp(cp(p0-center,p1-center),0)==0){
			if(fabs(p0.Y-p1.Y)<EPS)
				return p0.X<p1.X;
			return p0.Y<p1.Y;
		}
		return cp(p0-center,p1-center)<0;
	}
};
vector<point> ConvexHull(vector<point> points) {
	if(sz(points) <= 1)	return points;

	rep(i, points) if( MP(points[i].Y, points[i].X) < MP(points[0].Y, points[0].X))
		swap(points[0], points[i]);

	sort( points.begin()+1, points.end(), angleCMP(points[0]));

	vector<point> p, ch;

	rep(i, points) {
		while( sz(ch) > 1 && cp(ch[sz(ch)-2]-ch[sz(ch)-1], points[i]-ch[sz(ch)-1]) < 0)
			ch.pop_back();
        ch.push_back(points[i]);
	}
	if(sz(ch) >= 3)
		ch.push_back(ch[0]);
	return ch;
}
point polygonCenteriod(vector<point>points) {
    double x = 0, y = 0, a = 0, c;
    points.push_back(points[0]);
    for(int i = 0; i < points.size()-1; ++i)
    {
        int j = i + 1;
        c = cp(points[i], points[j]), a += c;
        x += (points[i].X + points[j].X) * c;
        y += (points[i].Y + points[j].Y) * c;
    }
    if (dcmp(a, 0) == 0)
        return (points[0] + points.back()) * 0.5;
    a /= 2, x /= 6 * a, y /= 6 * a;

    if (dcmp(x, 0) == 0)	x = 0;
    if (dcmp(y, 0) == 0)	y = 0;
    return point(x, y);
}
int main()
{
    IO;
    int n,x,y;
    while(cin>>n&&n>2)
    {
        vector<point>points;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            points.push_back(point(x,y));
        }
        points=ConvexHull(points);
        point c=polygonCenteriod(points);
        cout<<fixed<<setprecision(3)<<c.X<<" "<<c.Y<<'\n';
    }
}
