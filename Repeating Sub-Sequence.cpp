int Solution::anytwo(string A) 
{
    map<char,vector<int> > m;
    string s;
    for(int i=0;i<A.length();i++)
    {
        m[A[i]].push_back(i);
        if(m[A[i]].size()>=3)
            return 1;
    }
    for(int i=0;i<A.length();i++)
    {
        if(m[A[i]].size()==2)
            s=s+A[i];
    }
    int i=0,j=s.length()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
            return 1;
        i++;
        j--;
    }
    return 0;   
}
