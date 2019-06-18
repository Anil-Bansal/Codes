int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{
    int n=B.size();
    int dp[1005];
    dp[0]=0;
    for(int i=1;i<1005;i++)
    {
        dp[i]=1e9;
        for(int j=0;j<n;j++)
        {
            if(B[j]<=i)
                dp[i]=min(dp[i],dp[i-B[j]]+C[j]);
        }
    }
    
    
    int ans=0;
    int m=A.size();
    for(int i=0;i<m;i++)
        ans+=dp[A[i]];
    return ans;
    
}
