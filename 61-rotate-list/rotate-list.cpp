class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Calculate the length
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        k = k % length;
        if (k == 0) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 2: Move fast pointer k steps ahead
        while (k--) {
            fast = fast->next;
        }

        // Step 3: Move both pointers until fast reaches the last node
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Step 4: Rearrange pointers
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return newHead;
    }
};
