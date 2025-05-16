/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode* curr = node;
        ListNode* temp = node->next;

        while(temp)
        {
            curr->val = temp->val;
            if(temp->next == NULL)
            {
                curr->next = nullptr;
                delete temp;
                break;
                
            }
            else
            {
                temp = temp->next;
                curr = curr->next;
            }
        }




        // ListNode* temp = node;
        // temp->val = temp->next->val;
        // node->next = temp->next->next;      
    }
};