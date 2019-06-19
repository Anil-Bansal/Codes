int Solution::calculateMinimumHP(vector<vector<int> > &A) 
{
    int r=A.size();
    int c=A[0].size();
    
    int dp[r][c];
    if(A[r-1][c-1]<0)
        dp[r-1][c-1]=abs(A[r-1][c-1])+1;
    else
        dp[r-1][c-1]=1;
    
    for(int i=c-2;i>=0;i--)
    {
        if(A[r-1][i]<0)
            dp[r-1][i]=abs(A[r-1][i])+dp[r-1][i+1];
        else
            dp[r-1][i]=max(1,dp[r-1][i+1]-A[r-1][i]);
    }
    
    for(int i=r-2;i>=0;i--)
    {
        if(A[i][c-1]<0)
            dp[i][c-1]=abs(A[i][c-1])+dp[i+1][c-1];
        else
            dp[i][c-1]=max(1,dp[i+1][c-1]-A[i][c-1]);
    }
    
    for(int i=r-2;i>=0;i--)
    {
        for(int j=c-2;j>=0;j--)
        {
            if(A[i][j]<0)
                dp[i][j]=abs(A[i][j])+min(dp[i+1][j],dp[i][j+1]);
            else
                dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-A[i][j]);
        }
    }
    return dp[0][0];
}
