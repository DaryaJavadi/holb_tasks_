#ifndef BINARY_TREE_H
#define BINARY_TREE_H
struct TreeNode {
     int value;
     struct TreeNode *left;
     struct TreeNode *right;
};
struct TreeNode* insertNode(struct TreeNode *root, int value);
int calculateHeight(struct TreeNode *root);
void inOrderTraversal(struct TreeNode *root, int *arr, int *index);
void freeTree(struct TreeNode *root);
void sortArray(int *arr, int size);
#endif
