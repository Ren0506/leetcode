/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // 建立假頭節點
    struct ListNode* dummy =(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    // 用來建立答案
    struct ListNode* current = dummy;
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry != 0) {
        int x = 0;
        int y = 0;
        // 取 l1 的值
        if(l1 != NULL) {
            x = l1->val;
        }
        // 取 l2 的值
        if(l2 != NULL) {
            y = l2->val;
        }
        // 加法
        int sum = x + y + carry;
        // 更新進位
        carry = sum / 10;
        // 建立新節點
        struct ListNode* node =(struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        // 接到答案後面
        current->next = node;
        current = current->next;
        // 移動 l1
        if(l1 != NULL) {
            l1 = l1->next;
        }
        // 移動 l2
        if(l2 != NULL) {
            l2 = l2->next;
        }
    }
    return dummy->next;
}
