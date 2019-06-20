vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<vector<int> >v;
    int n=B.size();
    if(n==0)
        return v;
    int m=B[0].size();
    int dp[2][n][m];
    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(i==0)
                    dp[i][j][k]=B[j][k];
                else
                {
                    int cur=-1e9;
                    if(j>0)
                        cur=max(cur,dp[(i-1)%2][j-1][k]);
                    if(j<(n-1))
                        cur=max(cur,dp[(i-1)%2][j+1][k]);
                    if(k>0)
                        cur=max(cur,dp[(i-1)%2][j][k-1]);
                    if(k<(m-1))
                        cur=max(cur,dp[(i-1)%2][j][k+1]);
                        
                    dp[i%2][j][k]=max(dp[(i-1)%2][j][k],cur);
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        vector<int> tmp;
        for(int j=0;j<m;j++)
            tmp.push_back(dp[A%2][i][j]);
        v.push_back(tmp);
    }
    return v;
}
