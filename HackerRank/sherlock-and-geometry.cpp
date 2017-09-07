#include <bits/stdc++.h>
#define X real()
#define Y imag()
#define length(a) (hypot((a).Y, (a).X))
#define dp(a,b) ( (conj(a)*(b)).X )
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef complex<double> point;
const double PI=acos(-1.0);
const double EPS=1e-8;
bool ok;
int dcmp(double x, double y){
  return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
bool out(point c,point a,double r)
{
    double d=length(a-c);
    if(!dcmp(d,r))ok=1;
    return dcmp(d,r)>0;
}
double distToSegment( point p0, point p1, point p2 ) {
	double d1, d2;
	point v1 = p1-p0, v2 = p2-p0;
	if( (d1 = dp(v1, v2) ) <= 0)	return length(p2-p0);
	if( (d2 = dp(v1, v1) ) <= d1)	return length(p2-p1);
	double t = d1/d2;
	return length(p2 - (p0 + v1*t) );
}
int main()
{
    IO;
    int t; cin>>t;
    double x,y,r;
    while(t--)
    {
        ok=0;
        cin>>x>>y>>r;
        point cr(x,y);
        vector<point>v;
        for(int i=0;i<3;i++)
            cin>>x>>y,
            v.push_back(point(x,y));
        int ans=0;
        for(auto i:v)ans+=out(cr,i,r);
        if(ans&&ans<3||ok)cout<<"YES\n";
        else if(!ans)cout<<"NO\n";
        else
        {
            double d=distToSegment(v[0],v[1],cr);
            if(dcmp(d,r)<=0)ok=1;
            d=distToSegment(v[0],v[2],cr);
            if(dcmp(d,r)<=0)ok=1;
            d=distToSegment(v[1],v[2],cr);
            if(dcmp(d,r)<=0)ok=1;
            cout<<(ok?"YES\n":"NO\n");
        }
    }
}
