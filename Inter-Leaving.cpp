int Solution::isInterleave(string A, string B, string C) 
{
    int n=A.size();
    int m=B.size();
    bool dp[n+1][m+1];
    int k=C.size();
    if((n+m)!=k)
        return 0;
    
    int id1=0,id2=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=false;   
            if(i==0 and j==0)
                dp[i][j]=true;
            else if(i==0 and B[j-1]==C[j-1])
                dp[i][j]=dp[i][j-1];
            else if(j==0 and A[i-1]==C[i-1])
                dp[i][j]=dp[i-1][j];
            else if(A[i-1]==C[i+j-1] and B[j-1]!=C[i+j-1])
                dp[i][j]=dp[i-1][j];
            else if(B[j-1]==C[i+j-1] and A[i-1]!=C[i+j-1])
                dp[i][j]=dp[i][j-1];
            else if(B[j-1]==C[i+j-1] and (A[i-1]==C[i+j-1]))
                dp[i][j]=dp[i-1][j] or dp[i][j-1];
        }
    }
    if(dp[n][m])
        return 1;
    return 0;
}
