int Solution::cnttrue(string A) 
{
    vector<char> v1,v2;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]=='T' or A[i]=='F')
            v1.push_back(A[i]);
        else
            v2.push_back(A[i]);
    }
    
    n=v1.size();
    int t[n][n],f[n][n];
    for(int i=0;i<n;i++)
    {
        if(v1[i]=='T')
            t[i][i]=1,f[i][i]=0;
        else
            t[i][i]=0,f[i][i]=1;
    }
    
    for(int diff=1;diff<n;diff++)
    {
        for(int i=0,j=diff;j<n;i++,j++)
        {
            t[i][j]=f[i][j]=0;
            for(int gap=0;gap<diff;gap++)
            {
                int k=i+gap;
                int tik=t[i][k]+f[i][k];
                int tkj=t[k+1][j]+f[k+1][j];
                
                if (v2[k] == '&') 
                { 
                    t[i][j] += t[i][k]*t[k+1][j]; 
                    f[i][j] += (tik*tkj - t[i][k]*t[k+1][j]); 
                } 
                if (v2[k] == '|') 
                { 
                    f[i][j] += f[i][k]*f[k+1][j]; 
                    t[i][j] += (tik*tkj - f[i][k]*f[k+1][j]); 
                } 
                if (v2[k] == '^') 
                { 
                    t[i][j] += f[i][k]*t[k+1][j] + t[i][k]*f[k+1][j]; 
                    f[i][j] += t[i][k]*t[k+1][j] + f[i][k]*f[k+1][j]; 
                } 
                
            }
        }
    }
    return t[0][n-1];
}
