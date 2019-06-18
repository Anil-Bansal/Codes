//Precomputation of pallindromic substring will give O(n^2) solution this is O(n^3)

bool check_pallindrome(int start,int end,string &A)
{
    while(start<end)
    {
        if(A[start]!=A[end])
            return false;
        start++,end--;
    }
    return true;
}

int Solution::minCut(string A) 
{
    int n=A.size();
    if(n==1)
        return 0;
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        dp[i]=1e9;
        for(int j=0;j<=i;j++)
        {
            if(check_pallindrome(j,i,A))
            {
                if(j==0)
                    dp[i]=0;
                else
                    dp[i]=min(dp[i],1+dp[j-1]);
            }
        }
    }
    return dp[n-1];
}
