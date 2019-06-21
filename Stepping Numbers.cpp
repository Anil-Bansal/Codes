
vector<int> v;

void solve(int num,int A,int B)
{
    if(num>B)
        return;
    
    if(num>=A)
        v.push_back(num);
    int dig=num%10;
    if(dig==0)
        solve(num*10+1,A,B);
    else if(dig==9)
        solve(num*10+8,A,B);
    else
    {
        solve(num*10+dig+1,A,B);
        solve(num*10+dig-1,A,B);
    }
}

vector<int> Solution::stepnum(int A, int B) 
{
    v.clear();
    if(A>B)
        return v;
    
    if(A==0)
        v.push_back(0);
    for(int i=1;i<=9;i++)
        solve(i,A,B);
    sort(v.begin(),v.end());
    return v;
}
