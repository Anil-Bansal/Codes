bool visited[1005][1005];

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

bool inrange(int i,int j,int k,int r,int c)
{
    int tmpx=i+dx[k];
    int tmpy=j+dy[k];
    if(tmpx>=0 and tmpx<r and tmpy>=0 and tmpy<c)
        return 1;
    return 0;
}

void dfs(int i,int j,vector<string> &A,int r,int c)
{
    visited[i][j]=true;
    for(int k=0;k<4;k++)
    {
        if(inrange(i,j,k,r,c) and A[i+dx[k]][j+dy[k]]=='X' and !visited[i+dx[k]][j+dy[k]])
            dfs(i+dx[k],j+dy[k],A,r,c);
    }
}

int Solution::black(vector<string> &A) 
{
    memset(visited,false,sizeof(visited));
    int r=A.size();
    if(r==0)
        return 0;
    int c=A[0].size();
    int cnt=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(!visited[i][j] and A[i][j]=='X')
                dfs(i,j,A,r,c),cnt++;
        }
    }
    return cnt;
}
