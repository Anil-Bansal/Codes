int Solution::solve(vector<vector<int> > &A) 
{
    int r=A.size();
    int c=A[0].size();
    vector<vector<int> > v(r,vector<int>(c,0));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0)
                v[i][j]=A[i][j];
            else
            {
                if(A[i][j])
                    v[i][j]=A[i][j]+v[i-1][j];
            }
        }
    }
    
    for(int i=0;i<r;i++)
    {
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
    }
    
    int ans=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            ans=max(ans,(j+1)*v[i][j]);
    }
    return ans;
}
