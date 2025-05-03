/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index)
{
    if(start > end)
    {
        return nullptr;
    }
    int rootval = preorder[index];
    // we start from the start index and go on until end, until we get the value of root at our ith index
    int i = start;
    for(; i<=end; i++)
    {
        if(inorder[i] == rootval)
        {
            break;
            // mil giy h hume humari i ki value
        }
    }
    index++;

    TreeNode* root = new TreeNode(rootval);

    root->left = solve(preorder,inorder,start, i-1,index);
    root->right = solve(preorder,inorder,i+1,end,index);

    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();
        int index = 0;
        return solve(preorder,inorder,0,n-1,index);
        
    }
};