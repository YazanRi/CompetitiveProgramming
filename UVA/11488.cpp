#include <bits/stdc++.h>
#define f first
#define s second
#define LL long long
#define ld long double
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int mx;
struct trie
{
	trie* child[2];
	int cnt;
	trie()
	{
	    cnt=0;
		child[0]=child[1]=NULL;
	}
	void insert(string &s,int i)
	{
		cnt++;
		if(i==s.size())return;
        int cur=s[i]-'0';
        if(child[cur]==NULL)
            child[cur]=new trie();
        child[cur]->insert(s,i+1);
	}
	void getmax(int i)
	{
        mx=max(mx,cnt*i);
        for(int j=0;j<2;j++)
            if(child[j]!=NULL)
                child[j]->getmax(i+1);
	}

}t;
int n;
string s;
int main()
{
    IO;
    int tc; cin>>tc;
    while(tc--)
    {
        t=trie();
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            t.insert(s,0);
        }
        mx=0;
        t.getmax(0);
        cout<<mx<<'\n';
    }
}
