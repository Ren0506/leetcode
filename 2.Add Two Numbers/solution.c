/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));//宣告一個假的head
    dummy->next = NULL;
    struct ListNode*current = dummy;//宣告現在位置
    int carry = 0;
    int sum = 0;
    while(l1 != NULL || l2 != NULL || carry != 0){
        int x = 0;
        int y = 0;
        if(l1 != NULL){
            x = l1->val;
        }
        if(l2 != NULL){
            y = l2->val;
        }
        sum = x + y + carry;
        carry = sum / 10;
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));//每跑一個while要建一個node，所以此行要放在while裡
        current->next = node;
        current = current->next;
        node->val = sum % 10;
        node->next = NULL;
        if(l1 != NULL){
            l1 = l1->next;
        }
        if(l2 != NULL){
            l2 = l2->next;
        }
    }
    return dummy->next;
}
