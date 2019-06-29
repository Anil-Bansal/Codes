class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        int freq[26]={};
        for(int i=0;i<tasks.size();i++)
            freq[tasks[i]-'A']++;
        
        int cnt=0;
        priority_queue<int> pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i])
                pq.push(freq[i]);
        }
        
        int time=0;
        while(!pq.empty())
        {
            vector<int> v;
            int i=0;
            while(i<=n)
            {
                if(!pq.empty())
                {
                    int val=pq.top();
                    pq.pop();
                    if(val>1)
                        v.push_back(val-1);
                }
                time++;
                if(pq.empty() and v.size()==0)
                    break;
                i++;
            }
            for(auto el: v)
                pq.push(el);
        }
        return time;
    }
};
