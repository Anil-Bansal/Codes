int Solution::solve(vector<vector<int> > &A) 
{
    int rows = (int)A.size()+1;
    int cols = (int)A[0].size()+1;
    int max = -1e9;
    vector<vector<int> > matrix(rows);
    for(int i = 0; i < rows; i++)
        matrix[i].resize(cols);

    for(int i=rows-2 ; i >= 0 ; i--)
    {
        for(int j=cols-2 ; j >= 0 ; j--)
        {
            matrix[i][j] = A[i][j];
            matrix[i][j] += matrix[i+1][j] + matrix[i][j+1] - matrix[i+1][j+1];
            max = matrix[i][j]>max ? matrix[i][j] : max;
        }
    }
    return max;
}
