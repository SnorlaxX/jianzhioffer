#include <iostream>
using namespace std;
#include <stack>
#include <vector>


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};

class Solution {
public:
    //或用数组储存结点，倒序遍历数组连接
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pa, *pb, *pTmp;
        if(pHead == NULL)
            return NULL;
        pa = pHead;
        pb = pHead->next;
        pa->next = NULL;
        while(pb){
            pTmp = pb->next;
            pb->next = pa;
            pa = pb;
            pb = pTmp;
        }
        return pa;
    }
};

int main()
{
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode *p = s.ReverseList(l1);
    while(p){
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
    system("pause");
    return 0;
}