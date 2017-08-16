#include <bits/stdc++.h>
#define forit(i, a) for( __typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define f first
#define s second
using namespace std;
void srt(string &s)
{
    vector<string>v;
    string x;
    stringstream ss;
    ss<<s;
    while(ss>>x)v.push_back(x);
    sort(v.begin(),v.end());
    x="";
    for(int i=0;i<v.size();i++)
    {
        x+=v[i];
        if(i!=v.size()-1)x+=' ';
    }
    s=x;
}
bool can(string &a,string &b)
{
    map<string,int>m;
    stringstream ss;
    string x;
    ss<<a;
    while(ss>>x)m[x]++;
    ss.clear();
    ss<<b;
    while(ss>>x)m[x]++;
    int cnt=0;
    forit(i,m)if(i->s>=2)cnt++;
    return cnt>=2;
}
string combine(string &a,string &b)
{
    set<string>m;
    stringstream ss;
    string x;
    ss<<a;
    while(ss>>x)m.insert(x);
    ss.clear();
    ss<<b;
    while(ss>>x)m.insert(x);
    x="";
    forit(i,m)x+=" "+*i;
    return x.substr(1);
}
class Thesaurus {
public:
	vector <string> edit(vector <string> a) {
        for(int i=0;i<a.size();i++)srt(a[i]);
        bool f=1;
        while(f)
        {
            sort(a.begin(),a.end());
            f=0;
            for(int i=0;i<a.size()&&!f;i++)
            {
                for(int j=0;j<a.size()&&!f;j++)
                {
                    if(i==j)continue;
                    if(can(a[i],a[j]))
                    {
                        a[i]=combine(a[i],a[j]);
                        a.erase(a.begin()+j);
                        f=1;
                    }
                }
            }
        }
        sort(a.begin(),a.end());
        return a;
	}
};
