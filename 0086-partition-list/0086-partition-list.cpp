class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0), large(0);
        ListNode *s = &small, *l = &large;

        while (head) {
            if (head->val < x) {
                s->next = head;
                s = s->next;
            } else {
                l->next = head;
                l = l->next;
            }
            head = head->next;
        }

        l->next = nullptr;
        s->next = large.next;

        return small.next;
    }
};