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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL){
            return NULL;
        }
        /* 暴力 O(n^2)
        ListNode *p1 = pHead1;
        ListNode *p2;
        while(p1){
            p2 = pHead2;
            while(p2){
                if(p2 == p1){
                    return p1;
                }
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        return NULL; 
        */
        //O(n)
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        int len1 = 0;
        int len2 = 0;
        int lenabs;
        while(p1){
            p1 = p1->next;
            len1++;
        }
        while(p2){
            p2 = p2->next;
            len2++;
        }
        lenabs = abs(len1 - len2); //获取两链表长度差
        p1 = pHead1;
        p2 = pHead2;
        if(len1>len2){              //从两链表剩余长度相等的地方开始比较
            while(lenabs){
                p1 = p1->next;
                lenabs--;
            }
        }else{
            while(lenabs){
                p2 = p2->next;
                lenabs--;
            }
        }
        while(p1){
            if(p1 == p2){
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};

int main()
{
    system("pause");
    return 0;
}