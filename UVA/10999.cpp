#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
vector<vector<int> >val;
struct trie
{
	trie* child[26];
	bool leaf;
	trie()
	{
	    leaf=0;
	    for(int i=0;i<26;i++)
            child[i]=NULL;
	}
	void insert(string &s,int i=0)
	{
		if(i==s.size())
        {
            leaf=1;
            return;
        }
        int cur=s[i]-'a';
        if(child[cur]==NULL)
            child[cur]=new trie();
        child[cur]->insert(s,i+1);
	}
	bool find(string &s,int i=0)
	{
	    if(i==s.size())return leaf;
        int cur=s[i]-'a';
        if(child[cur]==NULL)return 0;
        return child[cur]->find(s,i+1);
	}
}t;
int n,m,p;
char x[11];
int v[11];
int getmax(string s="",int val=0,int i=0)
{
    if(i==p)
    {
        sort(s.begin(),s.end());
        return (t.find(s)?val:-2e9);
    }
    return max(getmax(s+x[i],val+v[i],i+1),getmax(s,val,i+1));
}
string s;
int main()
{
    IO;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        sort(s.begin(),s.end());
        t.insert(s);
    }
    cin>>m;
    while(m--)
    {
        cin>>p;
        for(int i=0;i<p;i++)
            cin>>x[i]>>v[i];
        cout<<getmax()<<'\n';
    }
}
