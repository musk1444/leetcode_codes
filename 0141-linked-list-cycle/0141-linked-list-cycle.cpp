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
    bool hasCycle(ListNode *head) {

        unordered_set<ListNode*> vis;
        if(head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode* temp = head;
        while(temp != nullptr)
        {
            if(vis.count(temp))
            {
                return true;
            }
            vis.insert(temp);
            temp = temp->next;
        }

        return false;
        
    }
};