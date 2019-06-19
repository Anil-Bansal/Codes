int Solution::maximalRectangle(vector<vector<int> > &A) 
{
    int r=A.size();
    int c=A[0].size();
    
    int left[r+1][c+1];
    int down[r+1][c+1];
    
    for(int i=0;i<r;i++)
    {
        for(int j=c-1;j>=0;j--)
        {
            if(j==c-1)
            {
                if(A[i][j])
                    left[i][j]=1;
                else
                    left[i][j]=0;
            }
            else
            {
                if(A[i][j])
                    left[i][j]=1+left[i][j+1];
                else
                    left[i][j]=0;
            }
        }
    }
    for(int i=0;i<c;i++)
    {
        for(int j=r-1;j>=0;j--)
        {
            if(j==r-1)
            {
                if(A[j][i])
                    down[j][i]=1;
                else
                    down[j][i]=0;
            }
            else
            {
                if(A[j][i])
                    down[j][i]=1+down[j+1][i];
                else
                    down[j][i]=0;
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(A[i][j]==0)
                continue;
            int neeche=down[i][j];
            int right_kitne=left[i][j];
            for(int k=i;k<i+neeche;k++)
            {
                right_kitne=min(right_kitne,left[k][j]);
                ans=max(ans,(k-i+1)*right_kitne);
            }
        }
    }
    return ans;
}
