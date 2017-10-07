#include <bits/stdc++.h>
#define f first
#define s second
#define LL long long
#define ld long double
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string prfx;
bool f,ff;
struct trie
{
	trie* child[26];
	bool isleaf;
	trie()
	{
	    isleaf=0;
		for(int i=0;i<26;i++)
            child[i]=NULL;
	}
	void insert(string &s,int i)
	{
		if(i==s.size())
        {
            isleaf=1;
            return;
        }
        int cur=s[i]-'a';
        if(child[cur]==NULL)
            child[cur]=new trie();
        child[cur]->insert(s,i+1);
	}
	void find(string &s,int i)
	{
	    if(i==s.size())
        {
            ff=0;
            travel("");
            return;
        }
	    int cur=s[i]-'a';
	    if(child[cur]==NULL)return;
	    child[cur]->find(s,i+1);
	}
	void travel(string s)
	{
	    if(isleaf&&ff)
            cout<<prfx<<s<<'\n',f=1;
        ff=1;
        for(int i=0;i<26;i++)
            if(child[i]!=NULL)
                child[i]->travel(s+char(i+'a'));
	}

}t;
int n,k;
string s;
int main()
{
    IO;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        t.insert(s,0);
    }
    cin>>k;
    for(int tc=1;tc<=k;tc++)
    {
        cin>>prfx;
        f=0;
        cout<<"Case #"<<tc<<":\n";
        t.find(prfx,0);
        if(!f)cout<<"No match.\n";
    }
}
