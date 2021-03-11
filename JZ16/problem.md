# 合并两个排序的链表
## 题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
## 示例1
### 输入
> {1,3,5},{2,4,6}
### 返回值
> {1,2,3,4,5,6}
## 链表数据结构
```C++
  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };
```