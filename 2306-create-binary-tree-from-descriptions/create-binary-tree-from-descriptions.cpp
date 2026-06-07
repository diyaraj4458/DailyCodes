class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> node;          // value -> TreeNode
        unordered_map<TreeNode*, TreeNode*> parent; // child node -> parent node

        TreeNode* cur = nullptr;

        for (auto &d : descriptions) {
            int p = d[0], c = d[1], isLeft = d[2];

            // Create parent node if it doesn't exist
            if (!node.count(p))
                node[p] = new TreeNode(p);

            // Create child node if it doesn't exist
            if (!node.count(c))
                node[c] = new TreeNode(c);

            // Connect parent with child
            if (isLeft)
                node[p]->left = node[c];
            else
                node[p]->right = node[c];

            // Store parent of current child
            parent[node[c]] = node[p];

            // Keep any node as a starting point
            cur = node[p];
        }

        // Move upwards until we reach a node with no parent
        while (parent.count(cur))
            cur = parent[cur];

        // Root node
        return cur;
    }
};
