#include <bits/stdc++.h>
#define f first
#define s second
#define LL long long
#define ld long double
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
struct trie
{
	trie* child[10];
	bool isleaf;
	trie()
	{
	    isleaf=0;
		for(int i=0;i<10;i++)
            child[i]=NULL;
	}
	void insert(string &s,int i)
	{
		if(i==s.size())
        {
            isleaf=1;
            return;
        }
        int cur=s[i]-'0';
        if(child[cur]==NULL)
            child[cur]=new trie();
        child[cur]->insert(s,i+1);
	}
	bool find(string &s,int i)
	{
	    if(i==s.size())return 1;
	    if(isleaf)return 0;
	    int cur=s[i]-'0';
	    return child[cur]->find(s,i+1);
	}

}t;
int n;
string a[10050];
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
            cin>>a[i];
            t.insert(a[i],0);
        }
        bool ok=1;
        for(int i=0;ok&&i<n;i++)
            ok&=t.find(a[i],0);
        cout<<(ok?"YES\n":"NO\n");
    }
}
