struct node
{
    bool isend;
    node *arr[26];
    node()
    {
        isend=false;
        for(int i=0;i<26;i++)
            arr[i]=NULL;
    }
};

void add(string s,node *trie)
{
    for(int i=0;i<s.size();i++)
    {
        if(trie->arr[s[i]-'a']==NULL)
            trie->arr[s[i]-'a']=new node();
        
        trie=trie->arr[s[i]-'a'];
    }
    trie->isend=true;
}

bool search(string s,node *trie)
{
    for(int i=0;i<s.size();i++)
    {
        if(trie->arr[s[i]-'a']==NULL)
            return false;
        
        trie=trie->arr[s[i]-'a'];
    }
    return trie->isend;
}

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first==p2.first)
        return p1.second<p2.second;
    return p1.first>p2.first;
}

vector<int> Solution::solve(string A, vector<string> &B) 
{
    node *trie=new node();
    string tmp="";
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!='_')
            tmp+=A[i];
        else
            add(tmp,trie),tmp="";
    }
    //cout<<tmp<<endl;
    add(tmp,trie);
    vector<pair<int,int> > v;
    for(int i=0;i<B.size();i++)
    {
        int cnt=0;
        string s=B[i];
        string tmp="";
        //cout<<s<<endl;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]!='_')
                tmp+=s[j];
            else
            {
                //cout<<tmp<<endl;
                if(search(tmp,trie))
                    cnt++;
                tmp="";
            }
        }
        if(search(tmp,trie))
            cnt++;
        v.push_back({cnt,i});
    }
    sort(v.begin(),v.end(),compare);
    vector<int> ans;
    for(int i=0;i<v.size();i++)
        ans.push_back(v[i].second);
    return ans;
}
