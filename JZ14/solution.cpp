#include <iostream>
using namespace std;
#include <stack>
#include <vector>


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(nullptr) {
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // 栈
        // stack<ListNode *> s;
        // ListNode *pTmp = pHead;
        // while(pTmp){
        //     s.push(pTmp);
        //     pTmp = pTmp->next;
        //     cout << 1 << endl;
        // }
        // if (k > s.size()){ //这题突然多了异常情况
        //     return nullptr;
        // }
        // while(k-1){
        //     s.pop();
        //     k--;
        // }
        // return s.top();

        //数组
        // vector<ListNode *> s;
        // ListNode *pTmp = pHead;
        // while(pTmp){
        //     s.push_back(pTmp);
        //     pTmp = pTmp->next;
        // }
        // if(k>s.size())
        //     return nullptr;
        // return s[s.size()-k];

        ListNode *pa, *pb;
        pa = pHead;
        pb = pHead;
        while(k){
            if(pa==nullptr){
                return nullptr;
            }
            pa = pa->next;
            k--;
        }
        while(pa){
            pa = pa->next;
            pb = pb->next;
        }
        return pb;
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
    int res = s.FindKthToTail(l1, 1)->val;
    cout << res << endl;
    system("pause");
    return 0;
}