vector<string> Solution::wordBreak(string A, vector<string> &B) 
{
    map<string,bool> m;
    for(int i=0;i<B.size();i++)
        m[B[i]]=true;
        
    int n=A.size();
    vector<string> words[n+1];
    words[n].push_back("");
    for(int i=n-1;i>=0;i--)
    {
        string tmp="";
        for(int j=i;j<n;j++)
        {
            tmp+=A[j];
            if(m.count(tmp))
            {
                for(int k=0;k<words[j+1].size();k++)
                {
                    string s;
                    if(words[j+1][k]!="")
                        s=tmp+" "+words[j+1][k];
                    else
                        s=tmp;
                    words[i].push_back(s);
                }
            }
        }
    }
    return words[0];
}
