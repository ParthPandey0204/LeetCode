
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*temp = head;
        int n =0;
        while(temp){
           n++;
           temp = temp->next;
        }
        int res = (n/2)+1;
        temp = head;
        while(temp){
            res--;
            if(res==0) break;
            temp = temp->next;
        }
        return temp;
    }
};