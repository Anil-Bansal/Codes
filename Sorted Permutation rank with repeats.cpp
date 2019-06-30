#define mod 1000003
 
 
long long powermod(long long n,long long p)
{
    if(p==0)
        return 1;
    long long tmp=powermod(n,p/2);
    if(p&1)
        return (tmp*(tmp*n)%mod)%mod;
    return (tmp*tmp)%mod;
}
 
void precompute(long long fact[],int n)
{
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=mod;
}
 
long long modinv(long long x)
{
    return powermod(x,mod-2);
}
 
int index(char ch)
{
    if(ch>='A' and ch<='Z')
        return ch-'A';
    
    return ch-'a'+26;
}
 
int Solution::findRank(string A) 
{
    int n=A.size();
    long long fact[n+1];
    precompute(fact,n);
    int freq[55]={};
    for(int i=0;i<n;i++)
        freq[index(A[i])]++;
        
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        int id=index(A[i]);
        for(int j=0;j<id;j++)
        {
            if(!freq[j])
                continue;
            
            freq[j]--;
            long long tmp=fact[n-i-1];
            for(int k=0;k<55;k++)
                tmp*=modinv(fact[freq[k]]),tmp%=mod;
            //cout<<tmp<<" "<<i<<endl;
            freq[j]++;
            ans+=tmp,ans%=mod;
        }
        freq[id]--;
    }
    return (ans+1)%mod;
}
