#include  <stdio.h>


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
int main() {
    int preorder[5]= {3,9,20,15,7};
    int inorder[5]= {9,3,15,20,7};
    struct  TreeNode* root = buildTree(preorder, 5, inorder, 5);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    PostOrder(root);
    return 0;
}