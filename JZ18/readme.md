# 二叉树的镜像
## 题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。  
比如：源二叉树 
>            8
>           /  \
>          6   10
>         / \  / \
>         5  7 9 11
镜像二叉树
>            8
>           /  \
>          10   6
>         / \  / \
>        11 9 7  5
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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){
    } 
};
```