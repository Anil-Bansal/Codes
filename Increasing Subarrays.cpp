#define mod 1000000007


int Solution::cntInc(vector<int> &A) 
{
    int n=A.size();
    int i=0;
    long long ans=0;
    while(i<n)
    {
        int cnt=1;
        i++;
        while(i<n and A[i]>A[i-1])
            cnt++,i++;
        
        long long tmp=(cnt*(cnt+1))/2;
        tmp%=mod;
        ans=ans+tmp,ans%=mod;
    }
    return ans;
}
