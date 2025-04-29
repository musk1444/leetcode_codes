/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        // we have gotten the count of total nodes
        int mid = count/2 + 1;
        temp = head; // re inititalising the temp to the head
        while(temp != nullptr)
        {
            mid = mid-1;
            if(mid == 0)
            {
                break;
            }
            temp = temp->next;
        }

        return temp;
        
    }
};