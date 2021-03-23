# 按之字形打印二叉树
## 题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
## 示例1
### 输入
> {8,6,10,5,7,9,11}
### 返回值
> [[8],[10,6],[5,7,9,11]]
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