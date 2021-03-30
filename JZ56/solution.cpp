#include <iostream>
using namespace std;
#include <map>


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

/* 没有用到链表是排序的这一特点
//遍历两次 使用了一个额外的map
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        map<int, int> cnt;
        ListNode* p = pHead;
        while(p){
            if(cnt.find(p->val) != cnt.end()){
                cnt[p->val]++;
            }else{
                cnt[p->val] = 1;
            }
            p = p->next;
        }
        while(pHead && cnt[pHead->val] > 1){
            pHead = pHead->next;
        }
        p = pHead;
        while(p && p->next){
            if(cnt[p->next->val] > 1){
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        
        return pHead;
    }
}; 
*/

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        ListNode *newNode = new ListNode(0);
        newNode->next = pHead;
        ListNode* p = newNode;
        while(p && p->next){
            if(p->next->next && p->next->val == p->next->next->val){
                int tmp = p->next->val;
                while(p->next && p->next->val == tmp){
                    p->next = p->next->next;
                }
            }else{
                p = p->next;
            }
        }
        return newNode->next;
    }
};

/*
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        //样例中数值全为正，可以给tmp赋非正初值，而舍弃flag变量
        int tmp, flag = 0;

        //可以增加一个头结点以减少这部分代码
        // ListNode *newHead = new ListNode(0, pHead);
        while(pHead){
            if(pHead->next && pHead->val == pHead->next->val){
                tmp = pHead->val;
                flag = 1;
            }
            if(flag && pHead->val == tmp){
                pHead = pHead->next;
            }else{
                break;
            }
        }


        flag = 0;

        //p = newHead;
        ListNode* p = pHead;
        while(p && p->next){
            if(p->next->next && p->next->val == p->next->next->val){
                tmp = p->next->val;
                flag = 1;
            }
            if(flag && p->next->val == tmp){
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        return pHead;
    }
};
*/

int main()
{
    system("pause");
    return 0;
}