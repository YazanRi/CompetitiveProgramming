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

int main()
{
    IO;
    int tc; cin>>tc;
    while(tc--)
    {
        t=trie();
    }
}
