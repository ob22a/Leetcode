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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        deque<tuple<TreeNode*,int>> bfs;
        bfs.push_back({root,1});
        
        while(!bfs.empty()){
            auto [node, depth] = bfs.front();
            bfs.pop_front();

            if(node->left==nullptr && node->right==nullptr) return depth;
            if(node->left!=nullptr) bfs.push_back({node->left,depth+1});
            if(node->right!=nullptr) bfs.push_back({node->right,depth+1});
        }
        return -1;
    }
};