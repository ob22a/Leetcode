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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<tuple<TreeNode*,bool>> nodeStack;
        int leftSum=0;
        nodeStack.push({root,false});

        while(!nodeStack.empty()){
            auto [node,isLeft] = nodeStack.top();
            nodeStack.pop();

            if(node->left) nodeStack.push({node->left,true});
            if(node->right) nodeStack.push({node->right,false});

            if(isLeft && !node->left && !node->right) leftSum+=node->val;
        }
        
        return leftSum;
    }
};