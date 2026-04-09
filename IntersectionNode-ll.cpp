/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int lengtha(ListNode *headA){
        int l1=0;
        while(headA != NULL){
            headA=headA->next;
            l1++;
        }
        return l1;
    }
    int lengthb(ListNode *headB){
        int l2=0;
        while(headB != NULL){
            headB=headB->next;
            l2++;
        }
        return l2;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena=lengtha(headA);
        int lenb=lengthb(headB);
        //length func use karo aur nikalo
        while(lena>lenb){
            lena--;
            headA=headA->next;
        }
        while(lena<lenb){
            lenb--;
            headB=headB->next;
        }
        //now ab hum interssection aa gye h
        while(headA != headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;//headB bhi return krwa sakte kyunki iss point pr dono ki value same ho chuki hai
    }
};
//main functt
