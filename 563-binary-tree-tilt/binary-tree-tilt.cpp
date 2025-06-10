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
    int postOrder(TreeNode* root,int& sum){
        if(!root) return 0;

        int leftSum=postOrder(root->left,sum);
        int rightSum=postOrder(root->right,sum);
        sum+=abs(leftSum-rightSum);
        return leftSum+rightSum+root->val;
    }
    int findTilt(TreeNode* root) {
        int sum=0;
        postOrder(root,sum);
        return sum;
    }
};