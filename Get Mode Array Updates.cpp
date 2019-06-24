vector<int> Solution::getMode(vector<int> &A, vector<vector<int> > &B) 
{
    map<int,int> m;
    map<int,set<int> > freq;
    int n=A.size();
    for(int i=0;i<n;i++)
        m[A[i]]++;
    
    for(auto el: m)
    {
        int cnt=el.second;
        int val=el.first;
        freq[el.second].insert(val);
    }
    
    vector<int> v;
    int q=B.size();
    for(int i=0;i<q;i++)
    {
        int id=B[i][0];
        int val=B[i][1];
        
        id--;
        
        int ini_num=A[id];
        int ini_freq=m[ini_num];
        freq[ini_freq].erase(ini_num);
        if(freq[ini_freq].size()==0)
            freq.erase(ini_freq);
            
        m[ini_num]--;
        if(m[ini_num]!=0)
            freq[m[ini_num]].insert(ini_num);
        
        int doosre_freq=m[val];
        freq[doosre_freq].erase(val);
        if(freq[doosre_freq].size()==0)
            freq.erase(doosre_freq);
            
        m[val]++;
        freq[m[val]].insert(val);
        A[id]=val;
        
        auto it=freq.rbegin();
        v.push_back(*((it->second).begin()));
    }
    return v;
}
