int n,m;

void floodfill(int r,int c,vector<vector<char> >&v)
{
    if(r<0 or r>=n or c<0 or c>=m)
        return;
    if(v[r][c]!='-')
        return;
    
    v[r][c]='O';
    floodfill(r+1,c,v);
    floodfill(r-1,c,v);
    floodfill(r,c+1,v);
    floodfill(r,c-1,v);
}

void Solution::solve(vector<vector<char> > &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    n=A.size();
    if(n==0)
        return;
    m=A[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='O')
                A[i][j]='-';
        }
    }
    for(int i=0;i<n;i++)
        floodfill(i,0,A);
    for(int i=0;i<m;i++)
        floodfill(0,i,A);
    for(int i=0;i<n;i++)
        floodfill(i,m-1,A);
    for(int i=0;i<m;i++)
        floodfill(n-1,i,A);
        
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(A[i][j]=='-')
                A[i][j]='X';
                
    return;
}
