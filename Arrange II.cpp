const int N=1e3+5;
int dp[N][N];

int build(int id,int n,int stables,string &A)
{
    if(id==n and stables==0)
        return 0;
    if(id==n or stables=0)
        return 1e18;
        
    if(dp[id][stables]!=-1)
        return dp[id][stables];
        
    int ans=1e18;
    int cntw=0,cntb=0;
    for(int i=id;i<n;i++)
    {
        if(A[i]=='W')
            cntw++;
        else
            cntb++;
        
        ans=min(ans,cntw*cntb+build(i+1,n,))
    }
}

int Solution::arrange(string A, int B) 
{
    int n=A.size();
    if(n==0)
        return 0;
    if(B==0)
        return -1;
    memset(dp,-1,sizeof(dp));
    int val=build(0,n,B,A);
    if(val==1e18)
        return -1;
    return val;
}
