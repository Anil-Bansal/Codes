int Solution::maxProfit(const vector<int> &A) 
{
    int n=A.size();
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        long long diff=(long long)(A[i]-A[i-1]);
        if(diff>0)
            ans+=(long long)diff;
    }
    return ans;
}
