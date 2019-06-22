//BFS will give MLE try DFS


struct Item
{
    int x,y,idx;  
};
 
bool isvalid(int tmpx,int tmpy,int r,int c)
{
    if(tmpx<0 or tmpx>=r or tmpy<0 or tmpy>=c)
        return false;
    return true;
}
 
bool check(int i,int j,int id,vector<string> &A,string &B)
{
    int r=A.size();
    int c=A[0].size();
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    int n=B.size();
    queue<Item> q;
    Item tmp;
    tmp.x=i;
    tmp.y=j;
    tmp.idx=id;
    q.push(tmp);
    while(!q.empty())
    {
        Item obj=q.front();
        q.pop();
        if(obj.idx==(n-1))
            return 1;
            
        for(int k=0;k<4;k++)
        {
            int tmpx=obj.x+dx[k];
            int tmpy=obj.y+dy[k];
            if(isvalid(tmpx,tmpy,r,c) and A[tmpx][tmpy]==B[obj.idx+1])
            {
                //cout<<tmpx<<" "<<tmpy<<endl;
                Item It;
                It.x=tmpx;
                It.y=tmpy;
                It.idx=obj.idx+1;
                q.push(It);
            }
        }
    }
    return 0;
}
 
 
int Solution::exist(vector<string> &A, string B) 
{
    if(B=="")
        return 0;
    int n=A.size();
    if(n==0)
        return 0;
    for(int i=0;i<n;i++)
    {
        int sz=A[i].size();
        for(int j=0;j<sz;j++)
        {
            if(B[0]==A[i][j])
            {
                if(check(i,j,0,A,B))
                    return 1;
            }
        }
    }
    return 0;
}
