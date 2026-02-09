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
    vector<int> sortedNodes;

    void inorderTraversal (TreeNode* root) {
        if (!root) return;
        inorderTraversal (root->left);
        sortedNodes.push_back(root->val);
        inorderTraversal (root->right);
    }

    TreeNode* createBalancedBST(int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end-start) / 2;
        TreeNode* node = new TreeNode (sortedNodes[mid]);
        node->left = createBalancedBST(start, mid - 1);
        node->right = createBalancedBST(mid + 1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal (root);
        return createBalancedBST(0, sortedNodes.size()-1);
    }
};