# 从上往下打印二叉树
## 题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。  
## 示例1
### 输入
> {5,4,#,3,#,2,#,1}
### 返回值
> [5,4,3,2,1]
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