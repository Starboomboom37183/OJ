#树的操作

根据一棵树的前序遍历与中序遍历构造二叉树,你可以假设树中没有重复的元素。

例如，给出
```
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
```
返回如下的二叉树：
```
      3
     / \
    9  20
        /  \
       15   7
```

```
struct TreeNode *createTree(int start, int* preorder, int preorderSize, int* inorder, int midStart, int midEnd) {
    if (start >= preorderSize || midStart > midEnd) return NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[start];
    root->right = root->left = NULL;
    int i;
    for (i =midStart;i <= midEnd;++i) {
        if (inorder[i]==preorder[start]) break;
    }
    if (i-1 >= midStart) {
        root->left = createTree(start+1,preorder, preorderSize, inorder, midStart, i-1);
    }
    if (i+1 <= midEnd) {
        int len = i - midStart;
        root->right = createTree(start + len + 1, preorder, preorderSize, inorder, i+1, midEnd);
    }
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode *root = NULL;
    root = createTree(0, preorder, preorderSize, inorder, 0, inorderSize-1);
    return root;
}
```
#堆

#堆排序

#单调栈

#并查集

#后缀数组

#图
##最小生成树

##二部图

##最大团

##欧拉图


## 回溯法/dfs搜索法
框架
```
int search(int t)
{
    if(满足输出条件)
    {
        输出解;
    }
    else
    {
        for(int i=1;i<=尝试方法数;i++)
            if(满足进一步搜索条件)
            {
                为进一步搜索所需要的状态打上标记;
                search(t+1);
                恢复到打标记前的状态;//也就是说的{回溯一步}
            }
    }
}

```
