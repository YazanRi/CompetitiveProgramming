#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n,m,apos,ccw,t,k;
int main()
{
    IO;
    cin>>n>>m;
    while(m--)
    {
        cin>>t>>k;
        if(t==1)apos=(apos+k)%n;
        else ccw=!ccw,apos=(n+k-apos)%n;
    }
    if(!ccw)cout<<"1 "<<n-apos;
    else cout<<"2 "<<apos;
}
