class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (true) {
            ListNode* kth = prev;

            // Find kth node
            for (int i = 0; i < k && kth; i++)
                kth = kth->next;

            if (!kth) break;

            ListNode* next = kth->next;

            // Reverse k nodes
            ListNode* cur = prev->next;
            ListNode* p = next;

            while (cur != next) {
                ListNode* temp = cur->next;
                cur->next = p;
                p = cur;
                cur = temp;
            }

            // Connect reversed group
            ListNode* temp = prev->next;
            prev->next = kth;
            prev = temp;
        }

        return dummy.next;
    }
};