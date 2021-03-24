#include <iostream>
using namespace std;
#include <cstring>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(root == NULL){
            return "#";
        }
        
        string tmp = to_string(root->val);
        tmp+="!";
        
        char* left = Serialize(root->left);
        char* right = Serialize(root->right);
        char* ret = new char[strlen(left) + strlen(right) + tmp.size()];
        
        strcpy(ret, tmp.c_str());
        strcat(ret, left);
        strcat(ret, right);
        
        return ret;
    }
    TreeNode* DeserializeHelp(char *&str) {
        if(*str == '#'){
            ++str;
            return NULL;
        }
        
        int val = 0;
        while(*str != '!'){
            val = val * 10 + (*str - '0');
            ++str;
        }
        ++str;
        
        TreeNode *root = new TreeNode(val);
        root->left = DeserializeHelp(str);
        root->right = DeserializeHelp(str);
        
        return root;
    }
    
    TreeNode* Deserialize(char *str) {
        return DeserializeHelp(str);
    }
};

int main()
{
    system("pause");
    return 0;
}