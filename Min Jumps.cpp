vector<int> Solution::minJumps(vector<int> &A, int B) 
{
    int n=A.size();
    vector<int> dp(n,1e9);
    vector<int> path(n);
    if(A[0]==-1)
        return {};
    dp[0]=A[0];
    path[0]=-1;
    for(int i=1;i<n;i++)
    {
        if(A[i]==-1)
            continue;
        
        for(int j=max(0,i-B);j<=(i-1);j++)
        {
            int val=dp[j]+A[i];
            if(val<dp[i])
                dp[i]=val,path[i]=j;
        }
    }
    
    if(dp[n-1]==1e9)
        return {};
    
    int i=n-1;
    vector<int> v;
    while(i!=-1)
    {
        v.push_back(i+1);
        i=path[i];
    }
    reverse(v.begin(),v.end());
    return v;
}
