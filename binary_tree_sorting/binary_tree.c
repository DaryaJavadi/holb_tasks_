#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct TreeNode* insertNode(struct TreeNode *root, int value) {
    if (root == NULL) {
        root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->value = value;
        root->left = root->right = NULL;
    } else if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}


int calculateHeight(struct TreeNode *root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


void inOrderTraversal(struct TreeNode *root, int *arr, int *index) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left, arr, index);
    arr[*index] = root->value;
    (*index)++;
    inOrderTraversal(root->right, arr, index);
}

void freeTree(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void sortArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp
		}
		}
	}
}
