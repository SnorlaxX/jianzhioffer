# 二叉搜索树的第k个结点
## 题目描述
给定一棵二叉搜索树，请找出其中的第k小的TreeNode结点。
## 示例1
### 输入
> {5,3,7,2,4,6,8},3
### 返回值
> {4}
### 说明
> 按结点数值大小顺序第三小结点的值为4
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