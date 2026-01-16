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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // For each number we find NG number to left and right and store it
        int n=nums.size();
        vector<int> ngr(n,-1), ngl(n,-1);
        stack<int> stk;

        for(int i=n-1;i>=0;--i){
            while(!stk.empty() && nums[i]>nums[stk.top()]) stk.pop();
            if(!stk.empty()) ngr[i]=stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();
        for(int i=0;i<n;++i){
            while(!stk.empty() && nums[i]>nums[stk.top()]) stk.pop();
            if(!stk.empty()) ngl[i]=stk.top();
            stk.push(i);
        }

        vector<int> parent(n, -1);
        int root = -1;

        for (int i = 0; i < n; ++i) {
            if (ngl[i] == -1 && ngr[i] == -1) root = i;
            else if (ngl[i] == -1)  parent[i] = ngr[i];
            else if (ngr[i] == -1) parent[i] = ngl[i];
            else  parent[i] = (nums[ngl[i]] < nums[ngr[i]]) ? ngl[i] : ngr[i]; // if two larger ones exist the smaller one is its parent so the larger one would be grandparent
        }

        vector<TreeNode*> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = new TreeNode(nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) continue;
            if (i < parent[i]) nodes[parent[i]]->left = nodes[i];
            else  nodes[parent[i]]->right = nodes[i];
        }

        return nodes[root];
    }
};