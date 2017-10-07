#include <bits/stdc++.h>
#define f first
#define s second
#define LL long long
#define ld long double
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
struct trie
{
	trie* child[128];
	bool leaf;
	trie()
	{
	    leaf=0;
	    for(int i=0;i<128;i++)
            child[i]=NULL;
	}
	void insert(string &s,int i)
	{
		if(i==s.size())return void(leaf=1);
        int cur=s[i];
        if(child[cur]==NULL)
            child[cur]=new trie();
        if(cur==92)leaf=1;
        child[cur]->insert(s,i+1);
	}
	void print(string sp,string s)
	{
        if(leaf)
            cout<<sp<<s<<'\n';
        if(child[92]!=NULL)
            child[92]->print(sp+' ',"");
        for(int i=0;i<128;i++)
            if(i!=92&&child[i]!=NULL)
                child[i]->print(sp,s+char(i));
	}

}t;
int n;
string s;
int main()
{
    IO;
    while(cin>>n)
    {
        t=trie();
        for(int i=0;i<n;i++)
        {
            cin>>s;
            t.insert(s,0);
        }
        t.print("","");
        cout<<'\n';
    }
}
