pair<int,int> check(int val,vector<vector<int> >&v)
{
    int n=v.size();
    int m=v[0].size();
    int chhote=0;
    int barabar=0;
    for(int i=0;i<n;i++)
    {
        int id1=lower_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
        int id2=upper_bound(v[i].begin(),v[i].end(),val)-v[i].begin();
        chhote+=id1;
        barabar+=(id2-id1);
    }
    return make_pair(chhote,barabar);
}
 
 
int Solution::findMedian(vector<vector<int> > &A) 
{
    int mini=1e9,maxi=-1e9;
    int n=A.size();
    int m=A[0].size();
    for(int i=0;i<n;i++)
        mini=min(mini,A[i][0]),maxi=max(maxi,A[i][m-1]);
        
    int req=n*m/2;
    while(mini<=maxi)
    {
        int mid=(mini+maxi)/2;
        pair<int,int> val=check(mid,A);
        int chhote=val.first;
        int barabar=val.second;
        
        if(chhote<=req and (chhote+barabar)>req)
            return mid;
        
        if(chhote>req)
            maxi=mid-1;
        else
            mini=mid+1;
    }
}
