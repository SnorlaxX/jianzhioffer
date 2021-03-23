# 对称的二叉树
## 题目描述
请实现一个函数，用来判断一棵二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
## 示例1
### 输入
> {8,6,6,5,7,7,5}
### 返回值
> true
## 示例1
### 输入
> {8,6,9,5,7,7,5}
### 返回值
> false
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