#include <bits/stdc++.h>
#define LL long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
LL sum;
struct trie
{
    trie* child[26];
    bool leaf;
    trie()
    {
        leaf=0;
        for(int i=0; i<26; i++)
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
    void calc(int key)
    {
        if(leaf)sum+=key;
        int cnt=0,to;
        for(int i=0; i<26; i++)
            if(child[i]!=NULL)cnt++,to=i;
        if(!cnt)
            return;
        if(cnt==1)
            child[to]->calc(key+leaf);
        else
            for(int i=0; i<26; i++)
                if(child[i]!=NULL)
                    child[i]->calc(key+1);
    }
} t;
int n;
string s;
set<char>st;
int main()
{
    IO;
    while(cin>>n&&n)
    {
        sum=0;
        t=trie();
        st.clear();
        for(int i=0; i<n; i++)
        {
            cin>>s;
            t.insert(s);
            st.insert(s[0]);
        }
        t.calc((st.size()==1));
        cout<<fixed<<setprecision(2)<<(1.0*sum/n+1e-8)<<'\n';
    }
}
