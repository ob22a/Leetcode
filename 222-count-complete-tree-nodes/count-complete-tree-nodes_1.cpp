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
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        vector<TreeNode*> stack={root};
        int count=0;
       
        while(!stack.empty()){
            TreeNode* last = stack.back();
            stack.pop_back();
            ++count;
            if(last->left) stack.push_back(last->left);
            if(last->right) stack.push_back(last->right);
        }
        return count;
    }
};
