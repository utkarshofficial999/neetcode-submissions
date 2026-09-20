class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base case
        if (root == nullptr) {
            return 0;
        }

        // Find depth of left and right
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};