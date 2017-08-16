#include <bits/stdc++.h>
#define NN if(x.n!=y.n)return x.n<y.n
#define AA if(x.a!=y.a)return x.a<y.a
#define WW if(x.w!=y.w)return x.w>y.w
#define all(v) v.begin(),v.end()
using namespace std;
struct p
{
    string n;
    int a,w;

};
bool naw(p x, p y){NN;AA;WW;}
bool nwa(p x, p y){NN;WW;AA;}
bool awn(p x, p y){AA;WW;NN;}
bool anw(p x, p y){AA;NN;WW;}
bool wna(p x, p y){WW;NN;AA;}
bool wan(p x, p y){WW;AA;NN;}
bool check(vector<p>&V, vector <string> &N, vector <int> &A, vector <int> &W)
{
    for(int i=0;i<N.size();i++)
        if(V[i].n!=N[i]||V[i].a!=A[i]||V[i].w!=W[i])return 0;
    return 1;
}
class WhatSort {
public:
	string sortType(vector <string> N, vector <int> A, vector <int> W) {
	    string ans="NOT";
        vector<p>v(N.size());
        for(int i=0;i<N.size();i++)
        {
            v[i].n=N[i];
            v[i].a=A[i];
            v[i].w=W[i];
        }
        sort(all(v),naw);
        if(check(v,N,A,W))
        {
            if(ans!="NOT")return "IND";
            ans="NAW";
        }

        sort(all(v),nwa);
        if(check(v,N,A,W))
        {
            if(ans!="NOT")return "IND";
            ans="NWA";
        }

        sort(all(v),awn);
        if(check(v,N,A,W))
        {
            if(ans!="NOT")return "IND";
            ans="AWN";
        }

        sort(all(v),anw);
        if(check(v,N,A,W))
        {
            if(ans!="NOT")return "IND";
            ans="ANW";
        }

        sort(all(v),wna);
        if(check(v,N,A,W))
        {
            if(ans!="NOT")return "IND";
            ans="WNA";
        }

        sort(all(v),wan);
        if(check(v,N,A,W))
        {
            if(ans!="NOT")return "IND";
            ans="WAN";
        }
        return ans;
	}
};
