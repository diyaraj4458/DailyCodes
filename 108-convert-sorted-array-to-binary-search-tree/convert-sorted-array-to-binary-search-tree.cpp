class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& a) {
        function<TreeNode*(int, int)> b = [&](int l, int r) -> TreeNode* {
            if (l > r) return NULL;
            int m = l + (r - l) / 2;
            TreeNode* n = new TreeNode(a[m]);
            n->left = b(l, m - 1);
            n->right = b(m + 1, r);
            return n;
        };
        return b(0, a.size() - 1);
    }
};