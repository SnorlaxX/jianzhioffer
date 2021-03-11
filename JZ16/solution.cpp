#include <iostream>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // 递归
        // if(pHead1 == NULL){
        //     return pHead2;
        // }else if(pHead2 == NULL){
        //     return pHead1;
        // }
        // if(pHead1->val < pHead2->val){
        //     pHead1->next = Merge(pHead1->next, pHead2);
        //     return pHead1;
        // }else{
        //     pHead2->next = Merge(pHead2->next, pHead1);
        //     return pHead2;
        // }
        ListNode *ret;
        ListNode *pTmp = new ListNode(0);
        ret = pTmp;
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                pTmp->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                pTmp->next = pHead2;
                pHead2 = pHead2->next;
            }
            pTmp = pTmp->next;
        }
        if(pHead1 == NULL){
            pTmp->next = pHead2;
        }else if(pHead2 == NULL){
            pTmp->next = pHead1;
        }
        return ret->next;
    }
};

int main()
{
    system("pause");
    return 0;
}