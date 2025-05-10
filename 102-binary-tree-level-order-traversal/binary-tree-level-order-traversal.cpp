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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> result;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        while(!q.empty()){
            auto [node,level]=q.front();
            q.pop();
            
            if(result.size()>=level){
                result[level-1].push_back(node->val);
            }
            else result.push_back({node->val});

            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }
        return result;
    }
};