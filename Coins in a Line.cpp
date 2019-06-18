
int dp[1005][1005][2];

int build(int start,int end,vector<int> &A,int turn)
{
    if(start>end)
        return 0;
    if(dp[start][end][turn]!=-1)
        return dp[start][end][turn];
    
        
    int ans=0;
    if(turn)
        ans=max(A[start]+build(start+1,end,A,0),A[end]+build(start,end-1,A,0));
    else
        ans=min(build(start+1,end,A,1),build(start,end-1,A,1));
        
    return dp[start][end][turn]=ans;
}

int Solution::maxcoin(vector<int> &A) 
{
    memset(dp,-1,sizeof(dp));
    int n=A.size();
    return build(0,n-1,A,1);
}
