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
    int findBottomLeftValue(TreeNode* root) {
        // Pre-order + height tracking
        stack<pair<TreeNode*,int>> stk; //node height
        stk.push({root,0});

        int sol=-1;
        int maxHeight=-1;

        while(!stk.empty()){
            auto [node,h]=stk.top(); stk.pop();
            if(h>maxHeight){
                sol=node->val;
                maxHeight=h;
            }
            if(node->right) stk.push({node->right,h+1});
            if(node->left) stk.push({node->left,h+1});
        }
        
        return sol;
    }
};