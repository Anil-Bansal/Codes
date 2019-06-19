vector<int> Solution::solve(int A, int B, int C, int D) 
{
    vector<int> v;
    set<int> s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    while(v.size()!=D)
    {
        v.push_back(*s.begin());
        int val=*s.begin();
        s.insert(val*A);
        s.insert(val*B);
        s.insert(val*C);
        s.erase(s.begin());
    }
    return v;
}
