vector<int> Solution::solve(int A, vector<int> &B) 
{
    int mn = INT_MAX;
    int n = B.size();
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(B[i]<mn)
        {
            mn = B[i];
            pos = i;
        }
    }
    int maxkick = A/mn;
    
    vector<int> v;
    for(int i=0;i<maxkick;i++)
        v.push_back(pos);
        
    int rem = A-maxkick*mn;
    int i = 0;
    while(i<maxkick)
    {
        pos = v[i];
        int ind = -1;
        int j;
        for(j=0;j<n;j++)
        {
            if(rem-B[j]+B[pos] >= 0) 
            {
                ind = j;
                rem = rem-B[j]+B[pos];
                break;
            }
        }
        if(j == n)
            break;
        v[i] = j;
        i++;
    }
    return v;
}
