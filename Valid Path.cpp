bool check(int x,int y,int r,int c,int n,int radius,vector<int> &E,vector<int> &F)
{
    if(x<0 or x>r or y<0 or y>c)
        return false;
    
    for(int i=0;i<n;i++)
    {
        int dis=abs(E[i]-x)*abs(E[i]-x)+abs(F[i]-y)*abs(F[i]-y);
        if(dis<=radius)
            return false;
    }
    return true;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) 
{
    int dx[]={-1,-1,-1,1,1,1,0,0};
    int dy[]={-1,0,1,0,1,-1,1,-1};
    queue<pair<int,int> > q;
    int r=D*D;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        if(p.first==A and p.second==B)
            return "YES";
        
        q.pop();
        for(int i=0;i<8;i++)
        {
            int x=p.first+dx[i];
            int y=p.second+dy[i];
            if(check(x,y,A,B,C,r,E,F))
                q.push(make_pair(x,y));
        }
    }
    return "NO";
}
