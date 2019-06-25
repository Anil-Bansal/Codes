vector<int> Solution::maxLCS(string A) 
{
    string B=A;
    reverse(B.begin(),B.end());
    int n=A.size();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    int maxi=-1e9;
    int id=-1;
    for(int i=1;i<=n;i++)
    {
        int val=dp[i][n-i];
        if(val>maxi)
            maxi=val,id=i;
    }
    
    
    vector<int> v;
    v.push_back(id);
    v.push_back(maxi);
}
