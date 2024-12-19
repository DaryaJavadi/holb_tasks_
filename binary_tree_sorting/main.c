#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
int main() {
        struct TreeNode *root = NULL;
        int value;
        int height;
        int *arr = NULL ;
        int index = 0;
        int arr_size = 0;
        printf("Write the value for Tree (Write -1 to stop): \n");
        while(1){
                printf("Write the number: ");
                scanf("%d" , &value);
                if (value == -1) break;
                root = insertNode(root, value);
        }
                height = calculateHeight(root);
                printf("Height of the tree: %d\n", height);
        inOrderTraversal(root, NULL, &arr_size);
        arr = (int*)malloc(arr_size * sizeof(int));
        index = 0;
        inOrderTraversal(root, arr, &index);
        sortArray(arr, arr_size);
        printf("Sorted values from in-order traversal:\n");
        for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
        freeTree(root);
        return 0;
}
