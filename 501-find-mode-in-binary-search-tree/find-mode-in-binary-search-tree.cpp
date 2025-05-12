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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> freq;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();

            freq[node->val]++;
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }

        int maxCount=0;
        vector<int> sol;
        for(const auto& [num,count]:freq){
            if(count>maxCount){
                sol.clear();
                maxCount=count;
                sol.push_back(num);
            }
            else if(count==maxCount){
                sol.push_back(num);
            }
        }
        return sol;
    }
};