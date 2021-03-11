#include <iostream>
using namespace std;
#include <vector>


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        RandomListNode *p = pHead;
        RandomListNode *ret = new RandomListNode(0);
        RandomListNode *retTmp = ret;
        vector<RandomListNode *> randomIndex;
        int index = 0;
        while(p){   //储存所有random指针的值
            randomIndex.push_back(p->random);
            p = p->next;
        }
        p = pHead;
        while(p){
            RandomListNode *tmp = new RandomListNode(p->label); //为每个结点创建新的空间
            for (auto &index : randomIndex){    //将random指针的值替换为新生成的结点地址
                if(index == p){
                    index = tmp;
                    break;
                }
            }
            retTmp->next = tmp;
            retTmp = retTmp->next;
            p = p->next;
        }
        retTmp = ret->next;
        while(retTmp){
            retTmp->random = randomIndex[index];
            index++;
            retTmp = retTmp->next;
        }
        return ret->next;
    }
};

int main()
{
    RandomListNode *r1 = new RandomListNode(5);
    RandomListNode *r2 = new RandomListNode(4);
    RandomListNode *r3 = new RandomListNode(3);
    r1->next = r2;
    r2->next = r3;
    r1->random = r3;
    r2->random = r1;
    r3->random = r2;
    Solution s;
    RandomListNode *r4 = s.Clone(r1);
    delete r1;
    delete r2;
    delete r3;
    while(r4){
        cout << r4->random->label << " ";
        r4 = r4->next;
    }
    cout << endl;
    system("pause");
    return 0;
}