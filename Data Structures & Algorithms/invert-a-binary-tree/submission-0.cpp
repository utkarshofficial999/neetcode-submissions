class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        // Base case
        if (root == nullptr) {
            return nullptr;
        }

        // Swap left and right
        swap(root->left, root->right);

        // Invert left subtree
        invertTree(root->left);

        // Invert right subtree
        invertTree(root->right);

        return root;
    }
};