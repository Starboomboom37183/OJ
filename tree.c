#include  <stdio.h>

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
    
}
int main() {
    return 0;
}