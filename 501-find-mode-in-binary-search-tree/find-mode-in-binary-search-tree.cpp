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
    int maxCount=0;
    int curCount=0;
    TreeNode* prev=nullptr;
    vector<int>modes;
    
    void inOrder(TreeNode* root){
        if(!root) return ;
        inOrder(root->left);
        if(prev && root->val==prev->val) ++curCount;
        else curCount=1;

        if(curCount>maxCount){
            modes.clear();
            maxCount=curCount;
            modes.push_back(root->val);
        }
        else if(curCount==maxCount) modes.push_back(root->val);

        prev=root;
        inOrder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return modes;
    }
};