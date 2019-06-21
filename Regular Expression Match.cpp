int Solution::isMatch(const string A, const string B) 
{
    int n=A.size();
    int m=B.size();
    bool dp[n+1][m+1];
    memset(dp,false,sizeof(dp));

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 and j==0)
                dp[i][j]=true;
            else if(i==0)
            {
                if(B[j-1]=='*')
                    dp[i][j]=dp[i][j-1];
                else
                    dp[i][j]=false;
            }
            else if(j==0)
                dp[i][j]=false;
            else if(B[j-1]=='*')
                dp[i][j]=dp[i][j-1] or dp[i-1][j];
            else if(A[i-1]==B[j-1] or B[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=false;
        }
    }
    return dp[n][m];
}
