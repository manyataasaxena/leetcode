class Solution {
    TreeNode* build(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode *slow = head, *fast = head, *prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);
        root->left = build(head);
        root->right = build(slow->next);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head);
    }
};