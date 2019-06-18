int Solution::solve(const vector<int> &A) 
{   
    int n=A.size();
    if(n<=2)
        return n;
    int dp[n][n];
    memset(dp,-1,sizeof(dp));
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            dp[i][j]=2;
            int req=2*A[i]-A[j];
            if(m.count(req))
                dp[i][j]=max(dp[i][j],dp[m[req]][i]+1);
        }
        m[A[i]]=i;
    }
    
    int ans=-1e9;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans=max(ans,dp[i][j]);
            
    return ans;
}
