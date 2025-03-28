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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        /*
        post order traversal is left,right,node and since the node is processed at last it might lead to infinite loop if not properly handled 

        To avoid this problem this solution traverses in the opposite manner and uses 2 stacks(node,right,left). But the downside is it will be O(2n)
        */
        vector<int>sol;
        vector<TreeNode*>s1={root};
        vector<TreeNode*>s2;
        
        while(!s1.empty()){
            TreeNode* node=s1.back();
            s1.pop_back();
            s2.push_back(node);
            if(node->left) s1.push_back(node->left);
            if(node->right) s1.push_back(node->right);
        }
        
        while(!s2.empty()){
            sol.push_back(s2.back()->val);
            s2.pop_back();
        }
        
        return sol;
    }
};
