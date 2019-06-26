vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int id=abs(nums[i])-1;
            if(nums[id]>0)
                nums[id]*=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                v.push_back(i+1);
        }
        return v;
    }
