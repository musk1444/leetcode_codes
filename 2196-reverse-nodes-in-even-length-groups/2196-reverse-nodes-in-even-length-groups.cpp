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

int revlist(ListNode* last ,ListNode* headnode, int n)
{
    ListNode* prev = nullptr;
    ListNode* curr = headnode;
    ListNode* front = curr->next;

    int count = 0;
    // we need to keep track of the elements on our group

    while(curr != nullptr && n>0)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
        n--;
        count++;

    }
    // 1 2 3 4 5 6
    // 1 3 2 null 4 5 6 
    // lekin hume 2 ka next 4 ko krna h

    headnode->next = front;

    // 2->4 hogya ab 1->3 krna h to
    last->next = prev;

    return count;
}
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        int gn = 0;

        int eleminprevgroup = 0;

        ListNode* curr = head;
        ListNode* lastofpreviousgroup = nullptr;
        ListNode* lastofevengroup = nullptr;

        

        while(curr != nullptr)
        {
            gn++;
            if(gn%2 == 0)
            {
                // even length h groupnumber
                eleminprevgroup = revlist(lastofpreviousgroup,curr,gn);
                lastofevengroup = curr;
                curr = curr->next; 
            }
            else
            {
                int k = gn;
                eleminprevgroup = 0;

                while(curr != nullptr && k>0)
                {
                    eleminprevgroup++;
                    lastofpreviousgroup = curr;
                    // matlb ya to list khatam ya to usme groupsize se zyada elements h
                    curr = curr->next;
                    k--;
                }
            }
        }

        if(gn % 2 == 1 && eleminprevgroup % 2 == 0)
        {
            // agar group number odd h but elements jo present h usme vo even h
            revlist(lastofevengroup, lastofevengroup->next,eleminprevgroup);
        }
        else if(gn % 2 == 0 && eleminprevgroup%2 == 1)
        {
            revlist(lastofpreviousgroup, lastofpreviousgroup->next, eleminprevgroup);
        }

        return head;

        
    }
};