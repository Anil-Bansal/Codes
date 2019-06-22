/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

vector<int> v; 

TreeNode *solve(int start,int end)
{
    if(start>end)
        return NULL;
    
    int mid=(start+end)/2;
    TreeNode *root=new TreeNode(v[mid]);
    root->left=solve(start,mid-1);
    root->right=solve(mid+1,end);
    return root;
}

TreeNode* Solution::sortedListToBST(ListNode* A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    v.clear();
    while(A)
    {
        v.push_back(A->val);
        A=A->next;
    }
    
    return solve(0,v.size()-1);
    
}
