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
    int height(TreeNode* root){
        if(!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0;
        int maxHeight=height(root);
        stack<tuple<TreeNode*,int>> s;
        s.push({root,1});

        while(!s.empty()){
            auto [node,height]=s.top();
            s.pop();
            if(height==maxHeight) sum+=node->val;
            if(node->left) s.push({node->left,height+1});
            if(node->right) s.push({node->right,height+1});
        }
        return sum;
    }
};