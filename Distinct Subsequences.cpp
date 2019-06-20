
const int N=1005;
int dp[N][N];

int build(string &A,string &B,int id1,int id2)
{
    if(id1==A.size())
    {
        if(id2==B.size())
            return 1;
        return 0;
    }
    if(dp[id1][id2]!=-1)
        return dp[id1][id2];
    
    int ans=0;
    if(id2<B.size())
    {
        if(A[id1]==B[id2])
            ans+=build(A,B,id1+1,id2+1);
    }
    ans+=build(A,B,id1+1,id2);
    return dp[id1][id2]=ans;
}

int Solution::numDistinct(string A, string B) 
{
    memset(dp,-1,sizeof(dp));
    return build(A,B,0,0);
}

