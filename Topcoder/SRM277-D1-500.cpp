#include <bits/stdc++.h>
using namespace std;
vector<string>fix(string &s)
{
    int n=s.size();
    vector<string>v;
    if(n<=50)
        v.push_back(s);
    if(n<=100)
        v.push_back(s.substr(0,50)),
        v.push_back(s.substr(50));
    else
        v.push_back(s.substr(0,50)),
        v.push_back(s.substr(n-50));
    return v;
}
class AirlinerSeats {
public:
	vector <string> mostAisleSeats(int w, int s) {
        int mx=s/2+s%2;
        string x="";
        if(s+mx<=w)
        {
            while(s>=2&&x.size()+3<=w)x+="S.S",s-=2;
            if(s)s--,x+='S';
            while(x.size()<w)x+='.';
            reverse(x.begin(),x.end());
        }
        else
        {
            int a=w-s;
            while(x.size()<w)x+='S';
            for(int i=1;i<w&&a--;i+=3)x[i]='.';
        }
        return fix(x);
	}
};
