/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
stack<TreeNode *> s;

BSTIterator::BSTIterator(TreeNode *root) 
{
    while(!s.empty())
        s.pop();
    
    TreeNode *tmp=root;
    while(tmp)
        s.push(tmp),tmp=tmp->left;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() 
{
    return !s.empty();
}

/** @return the next smallest number */
int BSTIterator::next() 
{
    int ans=s.top()->val;
    TreeNode *tmp=s.top();
    s.pop();
    tmp=tmp->right;
    while(tmp)
        s.push(tmp),tmp=tmp->left;
    
    return ans;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
