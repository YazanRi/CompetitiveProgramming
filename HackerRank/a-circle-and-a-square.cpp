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
double d,mnx,mxx,mny,mxy;
vector<point>v;
int w,h,x,y,r;
void build(point a, point b)
{
    mnx=w-1,mny=h-1;
    v.push_back(a);
    point cc=(a+b); cc/=2;
    point dd=(a-b); dd/=2;
    v.push_back(point(cc.X-dd.Y,cc.Y+dd.X));
    v.push_back(b);
    v.push_back(point(cc.X+dd.Y,cc.Y-dd.X));
}
double triangleArea(point a, point b, point c)
{
	return abs((c.X-a.X)*(b.Y-a.Y)-(c.Y-a.Y)*(b.X-a.X))/2;
}
bool S(point a)
{
    bool z1=!dcmp(triangleArea(a,v[0],v[1])+triangleArea(a,v[1],v[2])+triangleArea(a,v[0],v[2]),triangleArea(v[0],v[1],v[2]));
    bool z2=!dcmp(triangleArea(a,v[0],v[3])+triangleArea(a,v[3],v[2])+triangleArea(a,v[0],v[2]),triangleArea(v[0],v[3],v[2]));
    return (z1|z2);
}
int main()
{
    int x1,y1,x3,y3;
    cin>>w>>h>>x>>y>>r>>x1>>y1>>x3>>y3;
    build(point(x1,y1),point(x3,y3));
    for(int j=0;j<h;j++)
    {
        for(int i=0;i<w;i++)
        {
            if(dcmp(length(point(i,j)-point(x,y)),r)<=0)cout<<'#';
            else if(S(point(i,j)))cout<<'#';
            else cout<<'.';
        }
        cout<<'\n';
    }
}
