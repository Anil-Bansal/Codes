int Solution::maxProfit(const vector<int> &A) 
{
    int n=A.size();
    int front[n+1],back[n+1];
    if(n==0)
        return 0;
    front[0]=0;
    int mini=A[0];
    for(int i=1;i<n;i++)
    {
        front[i]=max(front[i-1],A[i]-mini);
        mini=min(mini,A[i]);
    }
    
    back[n-1]=0;
    int maxi=A[n-1];
    for(int i=n-2;i>=0;i--)
    {
        back[i]=max(back[i+1],maxi-A[i]);
        maxi=max(maxi,A[i]);
    }
    
    int ans=0;
    for(int i=0;i<(n-1);i++)
        ans=max(ans,front[i]+back[i+1]);
    
    ans=max(ans,back[0]);
    return ans;
}
