int Solution::minimumTotal(vector<vector<int> > &A) 
{
    int n=A.size();
    int dp[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=1e9;
            
    dp[0][0]=A[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<A[i].size();j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>0)
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            dp[i][j]+=A[i][j];
        }
    }
    int ans=1e9;
    for(int i=0;i<A[n-1].size();i++)
        ans=min(ans,dp[n-1][i]);
    return ans;
}
