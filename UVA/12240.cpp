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
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const double PI  = acos(-1.0);
const double EPS = 1e-6;
typedef complex<double> point;
int dcmp(double x, double y) {
  return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
bool intersectSegments(point a, point b, point c, point d, point & intersect) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
    return false;
  return true;
}
pair<double, point> findCircle(point a, point b, point c) {
	point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1+pv1, end2 = m2+pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return make_pair( length(a-center), center );
}
bool isCollinear(point a, point b, point c) {
	return fabs( cp(b-a, c-a) ) < EPS;
}
pair<double,point>c;
bool onBorder(point a)
{
    return !dcmp(length(a-c.second),c.first);
}
int main()
{
    IO;
    int n,x,y;
    while(cin>>n&&n)
    {
        int mx=min(2,n),tmp;
        vector<point>v;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            v.push_back(point(x,y));
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(isCollinear(v[i],v[j],v[k]))continue;
                    tmp=0;
                    c=findCircle(v[i],v[j],v[k]);
                    for(int z=0;z<n;z++)
                        tmp+=onBorder(v[z]);
                    mx=max(mx,tmp);
                }
            }
        }
        cout<<mx<<'\n';
    }
}
