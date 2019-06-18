#define mod 1000000007
const int N=2005;
long long dp[N][N];

int build(int start,int end)
{
    if(start==end)
        return 0;
    if(start>end)
        return 1;
    
    if(dp[start][end]!=-1)
        return dp[start][end];
        
    long long ans=0;
    for(int i=start+1;i<=end;i++)
    {
        long long tmp=build(start+1,i-1);
        tmp%=mod;
        tmp*=build(i+1,end),tmp%=mod;
        //cout<<"tmp: "<<tmp<<" start: "<<start<<" end: "<<end<<endl;
        ans+=tmp,ans%=mod;
    }
    return dp[start][end]=ans;
}

int Solution::chordCnt(int A) 
{
    for(int i=0;i<=2*A;i++)
        for(int j=0;j<=2*A;j++)
            dp[i][j]=-1;
            
    
    return build(1,2*A);
}

//This is a O(n^3) solution. This will give a partial score. Check on gfg for O(n^2) approach.
