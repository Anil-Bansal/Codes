struct node
{
    int cnt[26];
    node *arr[26];
    node()
    {
        for(int i=0;i<26;i++)
            cnt[i]=0,arr[i]=NULL;
    }
};
 
void add(string &s,node *trie)
{
    for(int i=0;i<s.size();i++)
    {
        if(trie->arr[s[i]-'a']==NULL)
            trie->arr[s[i]-'a']=new node();
        
        (trie->cnt[s[i]-'a'])++;
        trie=trie->arr[s[i]-'a'];
    }
}
 
string findprefix(string &s,node *trie)
{
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        ans+=s[i];
        if(trie->cnt[s[i]-'a']==1)
            break;
        
        trie=trie->arr[s[i]-'a'];
    }
    return ans;
}
 
vector<string> Solution::prefix(vector<string> &A) 
{
    node *trie=new node();
    for(int i=0;i<A.size();i++)
        add(A[i],trie);
        
    vector<string> v;
    for(int i=0;i<A.size();i++)
    {
        string s=findprefix(A[i],trie);
        v.push_back(s);
    }
    return v;
}
