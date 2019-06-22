string Solution::multiple(int A) 
{
    if(A==0)
        return "0";
    int parent[A+1];
    queue<int> q;
    bool visited[A+1];
    int val[A+1];
    memset(visited,false,sizeof(visited));
    memset(val,-1,sizeof(val));
    memset(parent,-1,sizeof(parent));
    visited[1%A]=1;
    parent[1%A]=-1;
    val[1%A]=1;
    q.push(1%A);
    while(!q.empty())
    {
        int num=q.front();
        q.pop();
        if(num==0)
        {
            string s="";
            while(num!=-1)
            {
                s+=val[num]+'0';
                num=parent[num];
            }
            reverse(s.begin(),s.end());
            return s;
        }
        
        int num1=(num*10+0)%A;
        int num2=(num*10+1)%A;
        
        if(!visited[num1])
        {
            val[num1]=0;
            visited[num1]=true;
            parent[num1]=num;
            q.push(num1);
        }
        
        if(!visited[num2])
        {
            val[num2]=1;
            visited[num2]=true;
            parent[num2]=num;
            q.push(num2);
        }
        
    }
}
