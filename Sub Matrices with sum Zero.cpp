int Solution::solve(vector<vector<int> > &A) 
{
    int r=A.size();
    if(r==0)
        return 0;
    int c=A[0].size();
    if(c==0)
        return 0;
    
    int dp[r][c];
    dp[r-1][c-1]=A[r-1][c-1];
    for(int i=r-2;i>=0;i--)
        dp[i][c-1]=A[i][c-1]+dp[i+1][c-1];
        
    for(int i=c-2;i>=0;i--)
        dp[r-1][i]=A[r-1][i]+dp[r-1][i+1];
        
    for(int i=r-2;i>=0;i--)
    {
        for(int j=c-2;j>=0;j--)
            dp[i][j]=A[i][j]+dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1];
    }
    
    int ans=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            for(int k=i;k<r;k++)
            {
                for(int l=j;l<c;l++)
                {
                    int val=dp[i][j];
                    if(k+1<r)
                        val-=dp[k+1][j];
                    if(l+1<c)
                        val-=dp[i][l+1];
                    
                    if((k+1)<r and (l+1)<c)
                        val+=dp[k+1][l+1];
                        
                    if(val==0)
                        ans++;
                }
            }
        }
    }
    return ans;
    
}
