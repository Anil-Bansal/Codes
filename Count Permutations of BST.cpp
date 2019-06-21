#define lli long long int
#define mod 1000000007
lli comb[105][105];
lli dp[55][55];

lli build(int n,int B)
{
    if(n<=1)
        return (B==0);
    if(B<0) 
        return 0;
        
    if(dp[n][B]!=-1)
        return dp[n][B];
     
    lli ans=0;  
    for(int i=1;i<=n;i++)
    {
        lli x=i-1;
        lli y=n-i;
        
        lli tmp1=0;
        for(int j=0;j<=(B-2);j++)
        {
            lli z=build(x,j);
            lli k=build(y,B-1);
            //cout<<"n "<<n<<" i "<<i<<" j "<<j<<" k "<<k<<" z "<<z<<endl;
            tmp1+=(z*k),tmp1%=mod;
        }
        
        for(int j=0;j<=(B-2);j++)
            tmp1+=(build(y,j)*build(x,B-1)),tmp1%=mod;
        
        tmp1+=build(x,B-1)*build(y,B-1),tmp1%=mod;
        ans +=tmp1*comb[x+y][y],ans%=mod;
    }
    return dp[n][B]=ans;
}


int Solution::cntPermBST(int A, int B) 
{
    if(B>(A-1))
        return 0;
    for(int i=0;i<=2*A;i++)
        comb[i][0]=1,comb[i][i]=1;
        
    for(int i=1;i<=A;i++)
    {
        for(int j=1;j<i;j++)
            comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
    }
    
    memset(dp,-1,sizeof(dp));
    return build(A,B);
    
}
