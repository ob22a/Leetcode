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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        vector<vector<TreeNode*>> stack={{root->left,root->right}};
        
        while(!stack.empty()){
            vector<TreeNode*> mirror=stack.back();
            stack.pop_back();
            
            if(mirror[0]==nullptr && mirror[1]==nullptr) continue;
            if(mirror[0]==nullptr || mirror[1]==nullptr) return false;
            if(mirror[0]->val!=mirror[1]->val) return false;
            
            stack.push_back({mirror[0]->left,mirror[1]->right});
            stack.push_back({mirror[0]->right,mirror[1]->left});
        }
        return true;
    }
};
