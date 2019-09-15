#include  <stdio.h>
#include <stdbool.h>


/* 
struct TreeNode* trimBST(struct TreeNode* root, int L, int R){
    if (root == NULL) return NULL;
    struct TreeNode *new_root = NULL;
    if (root->val >=L && root->val <=R) {
        new_root = root;
        new_root->left = trimBST(new_root->left, L,R);
        new_root->right = trimBST(new_root->right,L,R);
    } else if (root->val < L) {
        new_root = trimBST(root->right,L,R);
    } else if (root->val > R) {
        new_root = trimBST(root->left,L,R);
    }
    return new_root;
    
} */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

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

void preOrder (struct TreeNode *root) {
    if (root) {
        printf("%d ",root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder (struct TreeNode *root) {
    if (root) {
        inOrder(root->left);
        printf("%d ",root->val);
        inOrder(root->right);
    }
}

void PostOrder (struct TreeNode *root) {
    if (root) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ",root->val);
    }
}
/************************************************/
// leetcode 572 另一颗子树
bool isTrue(struct TreeNode* s, struct TreeNode* t) {
    if (s==NULL && t==NULL) return true;
    if (s==NULL || t==NULL) return false;
    if (s->val!=t->val) return false;
    
    return isTrue(s->left, t->left) && isTrue(s->right, t->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if (s == NULL) return isTrue(s,t);
    return isTrue(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
}
/*************************************************/

/********************/ //反转二叉树
struct TreeNode* invertTree(struct TreeNode* root){
    if(root==NULL) return NULL;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;  
    return root;

}
/**********leetcode 897. 递增顺序查找树***********/
void MidOrder(struct TreeNode* root, struct TreeNode **cur) {  // 此处二级指针是为了能够让cur有引用类型的效果
    if (root == NULL) return;
    MidOrder(root->left, cur);
    root->left = NULL;
    (*cur)->right = root;
    (*cur) = root;
    MidOrder(root->right, cur);
    return ;
}
struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode *head = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *cur = head;
    MidOrder(root, &cur);
    return head->right;

}
/*********************************************/

/**************判断平衡二叉树 *************leetcode 110 */

int height(struct TreeNode* root, int *flag) {
    if (root==NULL) return 0;
    int left = height(root->left, flag);
    int right = height(root->right, flag);
    if (abs(right - left) > 1) {
        *flag = 1;
    }
    return 1 + (left > right ? left:right); 
}

bool isBalanced(struct TreeNode* root){
    if (root==NULL) return true;
    int flag = 0;
    height(root, &flag);
    if (flag) return false;
    else
        return true;
}
/**************************************/

/* leetcode 993 二叉树的堂兄弟节点*/
bool search(struct TreeNode *root, struct TreeNode **parent, int x, int *dep) {
    if (root==NULL) return false;
    if (root->val == x) return true;
    (*dep)++;
    if(search(root->left, &root, x, dep) || search(root->right, &root, x, dep)) {
        (*parent) = root;
        return true;
    }
    (*dep)--;
    return false;
    
}

bool isCousins(struct TreeNode* root, int x, int y){
    int dep1 = 0;
    int dep2 = 0;
    struct TreeNode *pre1 = NULL;
    struct TreeNode *pre2 = NULL;
    search(root, &pre1, x, &dep1);
    search(root, &pre2, y, &dep2);
    return dep1==dep2 && pre1!=pre2;
    
}
/* */

struct TreeNode *CreateTree(int a[], int start, int len) {  // 根据数组建树
    if (start >= len) return NULL;
    if (a[start] < 0) return NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = a[start];
    root->left = CreateTree(a, 2*start+1, len);
    root->right = CreateTree(a, 2*start+2, len);
    return root;
}


int main() {
    // int preorder[5]= {3,9,20,15,7};
    // int inorder[5]= {9,3,15,20,7};
    // struct  TreeNode* root = buildTree(preorder, 5, inorder, 5); // 前序中序建树
    // struct TreeNode *head = increasingBST(root);
    int a[] = {1,2,3,-1,4};
    struct TreeNode *root = CreateTree(a, 0, 5);
    // inOrder(root);
    int x = 2;
    int y = 3;
    if(isCousins(root,x,y)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}



