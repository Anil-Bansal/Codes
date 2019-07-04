double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        
        if(n==0 or m==0)
        {
            vector<int> v;
            if(n)
                v=nums1;
            else
                v=nums2;
            
            if(v.size()&1)
                return v[(v.size()-1)/2];
            return (v[v.size()/2]+v[v.size()/2-1])/2.0;
        }
        
        
        double ans;
        int start=0,end=n;
        while(start<=end)
        {
            int mid=(start+end)/2;
            int smid=(n+m+1)/2-mid;
            if(smid<0)
            {
                end=mid-1;
                continue;
            }
            if(smid>m)
            {
                start=mid+1;
                continue;
            }
            
            int maxleft_pehle=(mid==0)?INT_MIN:nums1[mid-1];
            int minright_pehle=(mid==n)?INT_MAX:nums1[mid];
            int maxleft_doosra=(smid==0)?INT_MIN:nums2[smid-1];
            int minright_doosra=(smid==m)?INT_MAX:nums2[smid];
            
            if(maxleft_pehle<=minright_doosra and maxleft_doosra<=minright_pehle)
            {
                if((n+m)&1)
                    ans= max(maxleft_pehle,maxleft_doosra);
                else
                    ans= (max(maxleft_pehle,maxleft_doosra)+min(minright_pehle,minright_doosra))/2.0;
                break;
            }
            if(maxleft_pehle>minright_doosra)
                end=mid-1;
            else
                start=mid+1;
        }
        return ans;
    }
