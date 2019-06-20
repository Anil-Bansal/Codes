#define mod 1000000007

int Solution::solve(int A) 
{
    if(A==0)
        return 0;
    
    long long dp[A+1],dp1[A+1];
    dp[1]=24;
    dp1[1]=12;
    
    for(int i=2;i<=A;i++)
    {
        dp[i]=dp[i-1]*11+dp1[i-1]*10,dp[i]%=mod;
        dp1[i]=dp[i-1]*5+dp1[i-1]*7,dp1[i]%=mod;
    }
    return (dp[A]+dp1[A])%mod;
}
