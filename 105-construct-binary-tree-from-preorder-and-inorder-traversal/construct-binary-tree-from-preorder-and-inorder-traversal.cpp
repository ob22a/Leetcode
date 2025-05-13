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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* head=new TreeNode(preorder[0]);
        stack<TreeNode*>s;
        s.push(head);

        int inIdx=0;

        for(int preIdx=1;preIdx<preorder.size();++preIdx){
            TreeNode* node=s.top();
            
            if(node->val!=inorder[inIdx]){
                node->left = new TreeNode(preorder[preIdx]);
                s.push(node->left);
            }
            else{
                while(!s.empty() && s.top()->val==inorder[inIdx]){
                    node=s.top();
                    s.pop();
                    ++inIdx;
                }
                node->right=new TreeNode(preorder[preIdx]);
                s.push(node->right);
            }
        }
        return head;
    }
};