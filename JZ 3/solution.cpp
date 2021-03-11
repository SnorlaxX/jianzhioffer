#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        // reverse
        // vector<int> res;
        // while (head) {
        //     res.push_back(head->val);
        //     head = head->next;
        // }
        // reverse(res.begin(), res.end());
        // return res;
        vector<int> res;
        stack<int> trans;
        ListNode *pTmp = head;
        while(pTmp){
            trans.push(pTmp->val);
            pTmp = pTmp->next;
        }
        while(!trans.empty()){
            res.push_back(trans.top());
            trans.pop();
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}