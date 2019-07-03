string Solution::convert(string A, int B) 
{
    if(B==1)
        return A;
    vector<char> adj[B];
    int n=A.size();
    int cnt=0;
    bool turn=true;
    for(int i=0;i<n;i++)
    {
        adj[cnt].push_back(A[i]);
        if(turn)
        {
            cnt++;
            if(cnt==B)
                cnt-=2,turn=false;
        }
        else
        {
            cnt--;
            if(cnt<0)
                cnt+=2,turn=true;
        }
    }
    string s="";
    for(int i=0;i<B;i++)
    {
        for(auto el: adj[i])
            s+=el;
    }
    return s;
}
