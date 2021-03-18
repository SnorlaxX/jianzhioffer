# 二叉树的深度
## 题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
## 示例1
### 输入
> {1,2,3,4,5,#,6,#,#,7}
### 返回值
> 4
## 二叉树数据结构
```C++
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : 
		val(x), left(NULL), right(NULL){
    } 
};
```