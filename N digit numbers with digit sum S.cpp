#define mod 1000000007
int dp[1005][1005];

int build(int dig,int A,int B,int sum)
{
    if(dig==A)
    {
        if(sum==B)
            return 1;
        return 0;
    }
    if(sum>B)
        return 0;
    
    if(dp[dig][sum]!=-1)
        return dp[dig][sum];
    int start=1;
    if(dig)
        start=0;
    int ans=0;
    for(;start<=9;start++)
        ans+=build(dig+1,A,B,sum+start),ans%=mod;
    return dp[dig][sum]=ans;
}

int Solution::solve(int A, int B) 
{
    memset(dp,-1,sizeof(dp));
    return build(0,A,B,0);
}
