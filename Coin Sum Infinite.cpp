#define mod 1000007


int Solution::coinchange2(vector<int> &A, int B) 
{
    int dp[B+1];
    for(int i=0;i<=B;i++)
        dp[i]=0;
    dp[0]=1;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        for(int j=A[i];j<=B;j++)
        {
            dp[j]+=dp[j-A[i]];
            dp[j]%=mod;
        }
    }
    return dp[B];
}
