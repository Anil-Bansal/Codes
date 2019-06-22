struct Item
{
    int a,b,mov;  
};

int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={-1,-2,-2,-1,1,2,2,1};

bool inrange(int x,int y,int n,int m)
{
    if(x>=1 and x<=n and y>=1 and y<=m)
        return true;
    return false;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) 
{
    map<pair<int,int>,bool> m;
    Item obj;
    obj.a=C;
    obj.b=D;
    obj.mov=0;
    queue<Item> q;
    q.push(obj);
    m[make_pair(C,D)]=true;
    while(!q.empty())
    {
        Item obj=q.front();
        q.pop();
        if(obj.a==E and obj.b==F)
            return obj.mov;
            
        for(int i=0;i<8;i++)
        {
            int tmpx=obj.a+dx[i];
            int tmpy=obj.b+dy[i];
            if(inrange(tmpx,tmpy,A,B) and !m.count(make_pair(tmpx,tmpy)))
            {
                Item tmp;
                tmp.a=tmpx;
                tmp.b=tmpy;
                tmp.mov=obj.mov+1;
                q.push(tmp);
                m[make_pair(tmpx,tmpy)]=true;
            }
        }
    }
    return -1;
}
