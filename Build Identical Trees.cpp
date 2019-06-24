/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int solve(TreeNode *A,TreeNode *B,int mini,int maxi)
{
    if(B==NULL and A!=NULL)
        return -1;
    if(A==NULL and B==NULL)
        return 0;
    
    int mid;
    if(A==NULL and B!=NULL)
    {
        int mid=(mini+maxi)/2;
        int left=solve(NULL,B->left,mini,mid);
        int right=solve(NULL,B->right,mid,maxi);
        if(left==-1 or right==-1)
            return -1;
        return (1+left+right);
    }
    
    int left=solve(A->left,B->left,mini,mid);
    int right=solve(A->right,B->right,mid,maxi);
    return (left+right);
}
 
int Solution::cntMatrix(TreeNode* A, TreeNode* B) 
{
    return solve(A,B,-1e9,1e9);   
}
