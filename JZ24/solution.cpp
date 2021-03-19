#include <iostream>
using namespace std;
#include <vector>
#include <queue>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){
    } 
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ret;
        if(root == NULL){
            return ret;
        }

        vector<int> tmp;
        tmp.push_back(root->val);
        queue<vector<int>> path;                            //保存每个结点的路径
        path.push(tmp); 

        queue<TreeNode *> tNodeTmp;
        tNodeTmp.push(root);

        //广度优先搜索
        while(!tNodeTmp.empty()){
            TreeNode *ptmp = tNodeTmp.front();
            vector<int> pathTmp = path.front();
            int sum = 0;

            if(ptmp->left == NULL && ptmp->right == NULL){  //对叶结点计算路径值
                for(auto i : pathTmp){
                    sum += i;
                }
                if(sum == expectNumber){                    //插入到前面
                    ret.insert(ret.begin(), pathTmp);
                }
            }
            
            if(ptmp->left){
                tNodeTmp.push(ptmp->left);
                vector<int> newPathtmp(pathTmp);
                newPathtmp.push_back(ptmp->left->val);
                path.push(newPathtmp);
            }
            if(ptmp->right){
                tNodeTmp.push(ptmp->right);
                vector<int> newPathtmp(pathTmp);
                newPathtmp.push_back(ptmp->right->val);
                path.push(newPathtmp);
            }

            tNodeTmp.pop();
            path.pop();
        }

        return ret;
    }
};

int main()
{
    Solution s;
    TreeNode *t1 = new TreeNode(10);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(12);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(7);

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;

    vector<vector<int> > ret = s.FindPath(t1, 22);
    for(auto path : ret){
        for(auto i : path){
            cout << i << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}