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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int>mp;
        while(headA!=nullptr || headB!=nullptr){
            if(headA!=nullptr){
                if(mp.find(headA)!=mp.end()){
                    return headA;
                }
                mp[headA]++;
                headA = headA->next;
                
            }
            if(headB!=nullptr){
                if(mp.find(headB)!=nullptr){
                    return  headB;
                }
                mp[headB]++;
                headB = headB->next;
            }
        }
        return nullptr;
    }
};