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
    ListNode *detectCycle(ListNode *head) {

        ListNode* temp = head;
        unordered_map<ListNode*, int> mpp;
        int count = 0;

        while(temp != nullptr)
        {
            if(mpp.count(temp->next))
            {
                return temp->next;
            }
            mpp[temp] = count;
            count++;
            temp = temp->next;
        }

        return nullptr;


        
    }
};