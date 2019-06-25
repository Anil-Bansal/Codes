#define mod 1000000007

int check(string &s1,string &s2)
{
    int cnt=0;
    int i=0,j=0;
    while(i<s1.size() and j<s2.size() and s1[i]==s2[j])
        i++,j++,cnt++;
        
    return cnt;
}


int Solution::LCPrefix(vector<string> &A, int B) 
{
    int n=A.size();
    if(n==1)
        return 1;
    vector<long long> v(n,0);
    
    for(int i=1;i<n;i++)
    {
        string s1=A[i];
        string s2=A[i-1];
        v[i]=check(s1,s2);
    }
    
    long long ans=0;
    long long cnt;
    int i=0;
    while(i<n)
    {
        long long mini=1e18;
        cnt=1;
        i++;
        while(i<n and min(mini,v[i])>=B)
            cnt++,i++;
        
        long long tmp=cnt*(cnt+1)/2;
        tmp%=mod;
        ans+=tmp,ans%=mod;
    }
    return ans;
}
