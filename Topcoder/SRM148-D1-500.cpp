#include <bits/stdc++.h>
using namespace std;
set<vector<int> >s;
bool check(vector<int>&v)
{
    int a=v[0]+v[1]+v[2],b=v[3]+v[4]+v[5],c=v[6]+v[7]+v[8];
    bool x=(a==b&&b==c);
    a=v[0]+v[3]+v[6],b=v[1]+v[4]+v[7],c=v[2]+v[5]+v[8];
    bool y=(a==b&&b==c);
    return (x&&y);
}

class MNS {
public:
	int combos(vector <int> v) {
		sort(v.begin(),v.end());
        if(check(v))s.insert(v);
        while(next_permutation(v.begin(),v.end()))
            if(check(v))s.insert(v);
        return s.size();
	}
};

