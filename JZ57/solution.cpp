#include <iostream>
using namespace std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode == NULL){
            return NULL;
        }
        /*如果存在右子树，就一直找到该右子树的最左边就是下一个结点
        **如果存在父结点，一直找到他是父结点的左子树，这个父结点就是下一个结点
        */
        if(pNode->right){
            TreeLinkNode *tmp = pNode->right;
            while(tmp->left){
                tmp = tmp->left;
            }
            return tmp;
        }else{
            TreeLinkNode *tmp = pNode;
            while(tmp->next){   
                if(tmp->next->left == tmp){
                    return tmp->next;
                }             
                tmp = tmp->next;
            }
            return NULL;
        }
    }
};

int main()
{
    system("pause");
    return 0;
}