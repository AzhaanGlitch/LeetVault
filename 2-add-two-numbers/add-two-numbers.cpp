class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultHead = nullptr; 
        ListNode* resultTail = nullptr;

        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry > 0){
            int value1 = 0;
            int value2 = 0;

            if(l1 != nullptr){
                value1 = l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                value2 = l2->val;
                l2 = l2->next;
            }

            int sum = value1 + value2 + carry;

            int digit = sum % 10;
            carry = sum / 10; 

            ListNode* newNode = new ListNode(digit);
            
            if(resultHead == nullptr){ 
                resultHead = newNode;
                resultTail = newNode;
            } else {
                resultTail->next = newNode;
                resultTail = newNode;
            } 
        } 
        return resultHead;
    }
};