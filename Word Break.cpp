int Solution::wordBreak(string A, vector<string> &B) 
{
    map<string,bool> m;
    for(int i=0;i<B.size();i++)
        m[B[i]]=true;
    
    int n=A.size();
    bool dp[n+1];
    dp[n]=true;
    for(int i=n-1;i>=0;i--)
    {
        bool ans=false;
        string tmp="";
        for(int j=i;j<n;j++)
        {
            tmp+=A[j];
            if(m.count(tmp))
                ans=ans or dp[j+1];
            if(ans)
                break;
        }
        dp[i]=ans;
    }
    return dp[0];
}
