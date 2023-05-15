class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        int n = 0;
        ListNode* curr = head;
        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }

        if (k > n) return head;

        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        ListNode* second = head;
        for (int i = 1; i < n - k + 1; i++) {
            second = second->next;
        }

        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};