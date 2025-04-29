class Solution {
public:
    bool isvalid(TreeNode* head, TreeNode*& prev) {
        if (head == nullptr) return true;

        if (!isvalid(head->left, prev)) return false;

        if (prev != nullptr && prev->val >= head->val) return false;

        prev = head;

        return isvalid(head->right, prev);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isvalid(root, prev);
    }
};
