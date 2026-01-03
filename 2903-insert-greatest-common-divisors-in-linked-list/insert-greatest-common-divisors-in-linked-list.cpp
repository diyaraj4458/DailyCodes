class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            int g = gcd(curr->val, curr->next->val);
            ListNode* node = new ListNode(g, curr->next);
            curr->next = node;
            curr = node->next;
        }
        return head;
    }
};