int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    int n=A.size();
    int ans=0;
    int inix=A[0];
    int iniy=B[0];
    for(int i=1;i<n;i++)
    {
        int diffx=abs(A[i]-inix);
        int diffy=abs(B[i]-iniy);
        ans+=min(diffx,diffy);
        ans+=(diffx-min(diffx,diffy));
        ans+=(diffy-min(diffx,diffy));
        inix=A[i];
        iniy=B[i];
    }
    return ans;
}