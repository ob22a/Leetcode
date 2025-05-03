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
    vector<int> inOrderTraversal(TreeNode* root){
        vector<int> sol;
        stack<TreeNode*> nodes;
        while(!nodes.empty() || root){
            while(root){
                nodes.push(root);
                root=root->left;
            }
            root=nodes.top();
            nodes.pop();
            sol.push_back(root->val);
            root=root->right;
        }
        return sol;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> sorted=inOrderTraversal(root);
        int i=0,j=sorted.size()-1;
        while(i<j){
            int sum=sorted[i]+sorted[j];
            if(sum==k) return true;
            else if(sum>k) --j;
            else ++i;
        }
        return false;
    }
};