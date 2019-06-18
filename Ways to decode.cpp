
const int N=1e5+5;
int dp[N];

int build(int id,int n,string &A)
{
    if(id==n)
        return 1;
    if(dp[id]!=-1)
        return dp[id];
    
    int ans=0;    
    int curdig=A[id]-'0';
    if(curdig==0)
        return dp[id]=0;
    int nextdigit=-1;
    if((id+1)<n)
        nextdigit=A[id+1]-'0';
    
    if(nextdigit==0)
    {
        if(curdig<=2)
            ans=build(id+2,n,A);
    }
    else
    {
        ans=build(id+1,n,A);
        if(curdig==1 and nextdigit!=-1)
            ans+=build(id+2,n,A);
        else if(curdig==2 and nextdigit!=-1 and nextdigit<=6)
            ans+=build(id+2,n,A);
    }
    return dp[id]=ans;
}


int Solution::numDecodings(string A) 
{
    if(A[0]=='0')
        return 0;
    int n=A.size();
    memset(dp,-1,sizeof(dp));
    return build(0,n,A);
}
