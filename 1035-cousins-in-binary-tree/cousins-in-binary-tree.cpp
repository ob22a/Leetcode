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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<vector<pair<int,TreeNode*>>> bfs; // node parent
        stack<tuple<TreeNode*,TreeNode*,int>> stk; //node parent level
        int solIdx=-1;
        stk.push({root,nullptr,0});
        while(!stk.empty()){
            auto [node,parent,level]=stk.top();
            stk.pop();

            if(bfs.size()<=level) bfs.push_back({});
            bfs[level].push_back({node->val,parent});

            if(node->val==x || node->val==y) solIdx=level;
            if(node->left) stk.push({node->left,node,level+1});
            if(node->right) stk.push({node->right,node,level+1});
        }
        if(solIdx==-1) return false;
        int count=0;
        TreeNode* xParent=nullptr,*yParent=nullptr;
        for(const auto& [num,parent]:bfs[solIdx]){
            if(num==x){
                count++;
                xParent=parent;
            }
            else if(num==y){
                count++;
                yParent=parent;
            }
        }
        return (count==2 && xParent!=yParent);
    }
};