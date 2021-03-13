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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        //也可暴力存储所有结点地址，循环到重复值时即可


        ListNode *pSlow = pHead;    //每次移动一格
        ListNode *pFast = pHead;    //每次移动两格
        while(pFast && pFast->next){
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            if(pFast == pSlow){     //相遇代表有环
                break;
            }
        }
        if(pFast == NULL || pFast->next == NULL){
            return NULL;
        }

        /*如果pSlow走了L步，则pFast走了2L步
        **假设pSlow在环内走了m步，链表起点到环的入口有s步，环内剩余n步
        **则 L = s + m；2L = s + m + p(m + n), p为pFast走过的完整圈数
        **联立可得 s = (p - 1)m + n
        **即两点分别从起点和此前的相遇点出发，将在环的入口点相遇
        */
        pFast = pHead;
        while(pFast != pSlow){
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pFast;
    }
};

int main()
{
    system("pause");
    return 0;
}