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
struct c
{
    point p; int r;
    c (point p,int r):p(p),r(r){}
};
bool overlap(c c1,c c2){
    return dcmp(length(c1.p-c2.p),c1.r+c2.r)<=0;
}
int main()
{
    IO;
    int t,n; cin>>t;
    double x,y,r;
    while(t--)
    {
        cin>>n;
        vector<c>v;
        vector<pair<int,int> >o;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y>>r;
            point p(x,y);
            v.push_back(c(p,r));
        }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(overlap(v[i],v[j]))
                    o.push_back({i,j});
        int mx=0,tmp;
        for(int m=0;m<(1<<n);m++)
        {
            bool ok=1;
            for(auto i:o)
                if((m&(1<<i.first))&&(m&(1<<i.second)))ok=0;
            if(!ok)continue;
            tmp=0;
            for(int i=0;i<n;i++)
                if(m&(1<<i))tmp+=v[i].r*v[i].r;
            mx=max(mx,tmp);
        }
        cout<<mx<<'\n';
    }
}
