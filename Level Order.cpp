/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) 
{
    vector<vector<int> > ans;
    queue<pair<TreeNode *,int> > q;
    if(A==NULL)
        return ans;
    
    q.push(make_pair(A,0));
    int last=0;
    vector<int> v;
    while(!q.empty())
    {
        pair<TreeNode *,int> p=q.front();
        q.pop();
        if(p.second==last)
            v.push_back((p.first)->val);
        else
        {
            ans.push_back(v);
            v.clear();
            last=p.second;
            v.push_back((p.first)->val);
        }
        
        if((p.first)->left)
            q.push(make_pair((p.first)->left,p.second+1));
        if((p.first)->right)
            q.push(make_pair((p.first)->right,p.second+1));
    }
    ans.push_back(v);
    return ans;
}
