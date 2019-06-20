int Solution::longestValidParentheses(string A) 
{
    stack<int> s;
    s.push(-1);
    int ans=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]=='(')
            s.push(i);
        else
        {
            s.pop();
            if(!s.empty())
                ans=max(ans,i-s.top());
            else
                s.push(i);
        }
    }
    return ans;
}
