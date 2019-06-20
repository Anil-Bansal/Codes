map<pair<int,int>,int> m;

int build(int start,int end)
{
    if(start>=end)
        return 1;
    
    if(m.count(make_pair(start,end)))
        return m[make_pair(start,end)];
    
    int ans=0;
    for(int i=start;i<=end;i++)
    {
        int tmp=build(start,i-1);
        tmp*=build(i+1,end);
        ans+=tmp;
    }
    return m[make_pair(start,end)]=ans;
}

int Solution::numTrees(int A) 
{
    m.clear();
    return build(1,A);
}
