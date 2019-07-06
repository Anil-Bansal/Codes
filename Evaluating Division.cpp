class Solution {
public:
    map<string,int> m;
    vector<pair<int,double> > adj[27];
    bool visited[27];
    double ans=-1.0;
    
    void dfs(int id1,int id2,double val)
    {
        if(id1==id2)
        {
            ans=val;
            return;
        }
        
        visited[id1]=true;
        for(auto el: adj[id1])
        {
            if(visited[el.first])
                continue;
            
            dfs(el.first,id2,val*el.second);
        }
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        int n=values.size();
        int id=1;
        for(int i=0;i<n;i++)
        {
            string s1=equations[i][0];
            string s2=equations[i][1];
            int id1,id2;
            if(m.count(s1))
                id1=m[s1];
            else
                id1=id++,m[s1]=id-1;
            
            if(m.count(s2))
                id2=m[s2];
            else
                id2=id++,m[s2]=id-1;
            
            adj[id1].push_back({id2,values[i]});
            adj[id2].push_back({id1,1/values[i]});
        }
        
        vector<double> v;
        for(int i=0;i<queries.size();i++)
        {
            string s1=queries[i][0];
            string s2=queries[i][1];
            int id1=m[s1];
            int id2=m[s2];
            if(id1==0 or id2==0)
            {
                v.push_back(-1.0);
                continue;
            }
            memset(visited,false,sizeof(visited));
            dfs(id1,id2,1.0);
            v.push_back(ans);
        }
        return v;
    }
};
