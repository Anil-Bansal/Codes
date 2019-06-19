int Solution::solve(const vector<int> &A) 
{
    int n=A.size();
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=A[i];
        
    int weightreq=sum/2;
    map<int,pair<int,int> > m;
    //First for cuts
    //Second for Sum
    m[0]=make_pair(0,0);
    for(int j=0;j<n;j++)
    {
        for(int i=weightreq;i>=1;i--)
        {
            if(A[j]<=i)
            {
                if(m.count(i))
                {
                    int created=m[i].second;
                    int now=A[j]+m[i-A[j]].second;
                    int cuts_before=m[i].first;
                    int cuts_now=1+m[i-A[j]].first;
                    if(now>created)
                        m[i].second=now,m[i].first=cuts_now;
                    else if(now==created)
                        m[i].first=min(cuts_now,cuts_before);
                }
                else
                    m[i]=make_pair(1+m[i-A[j]].first,A[j]+m[i-A[j]].second);
                
                //cout<<i<<" "<<m[i].first<<" "<<m[i].second<<endl;        
            }
        }
        //cout<<i<<" "<<m[i].first<<" "<<m[i].second<<endl;
    }
    return m[weightreq].first;
}
