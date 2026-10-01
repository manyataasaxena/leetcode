class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                cur->next = a;
                a = a->next;
            } else {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }

        cur->next = a ? a : b;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int interval = 1;

        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += interval * 2)
                lists[i] = merge(lists[i], lists[i + interval]);

            interval *= 2;
        }

        return lists[0];
    }
};