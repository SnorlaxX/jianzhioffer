# 树的子结构
## 题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
## 示例1
### 输入
> {8,8,#,9,#,2,#,5},{8,9,#,2}
### 返回值
> {1,2,3,4,5,6}
## 二叉树数据结构
```C++
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {     
    }
};
```