int Solution::fibsum(int A) 
{
    int fib1=1;
    int fib2=1;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    while(fib2<=A)
    {
        int tmp=fib2;
        fib2+=fib1;
        fib1=tmp;
        v.push_back(fib2);
    }
    
    int cnt=0;
    while(A)
    {
        int id=lower_bound(v.begin(),v.end(),A)-v.begin();
        if(v[id]>A)
            id--;
        cnt++;
        A-=v[id];
    }
    return cnt;
}
