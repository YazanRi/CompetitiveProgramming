#include <bits/stdc++.h>
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).Y, (a).X))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).X )	//
#define cp(a,b)                 ( (conj(a)*(b)).Y )
#define length(a)               (hypot((a).Y, (a).X))
using namespace std;
typedef complex<double> point;
const double PI=acos(-1.0);
const double EPS=1e-4;

int dcmp(double x, double y) {
  return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
double fixAngle(double A){
    return A>1?1:(A<-1?-1:A);
}
double getAngle_A_abc(double a, double b, double c){
    return acos(fixAngle((b*b+c*c-a*a)/(2*b*c)));
}
vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {

  if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
    return vector<point>(3, c1);

  double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

  if(isnan(ang2))
    ang2 = 0;

  vector<point> v(1, polar(r1, ang1 + ang2) + c1);


  if(dcmp(dp(v[0]-c1, v[0]-c1), r1*r1) != 0 ||
      dcmp(dp(v[0]-c2, v[0]-c2), r2*r2) != 0 )
    return vector<point>();

  v.push_back(polar(r1, ang1 - ang2) + c1);
  if(same(v[0], v[1]))
    v.pop_back();
  return v;
}
void fix(vector<point>&v)
{
    if(v.size()==1)return;
    if(dcmp(v[1].X,v[0].X)==-1)swap(v[0],v[1]);
    else if(!dcmp(v[1].X,v[0].X)&&dcmp(v[1].Y,v[0].Y)==-1)swap(v[0],v[1]);
}
int main()
{
    double ax,ay,ar,bx,by,br;
    while(cin>>ax>>ay>>ar>>bx>>by>>br)
    {
        auto v=intersectCircleCircle(point(ax,ay),ar,point(bx,by),br);
        if(v.size()==3)
        {
            puts("THE CIRCLES ARE THE SAME");
            continue;
        }
        if(!v.size())
        {
            puts("NO INTERSECTION");
            continue;
        }
        fix(v);
        for(int i=0;i<v.size();i++)
            printf("(%.3f,%.3f)",(!dcmp(v[i].X,0)?0:v[i].X),(!dcmp(v[i].Y,0)?0:v[i].Y));
        puts("");
    }
}
