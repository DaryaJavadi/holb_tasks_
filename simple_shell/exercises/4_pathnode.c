#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name);

typedef struct PathNode
{
    char *directory;
    struct PathNode *next;
} PathNode;

/**
 * create_node - Creates a new node for the linked list
 * @directory: The directory to be added to the node
 * Return: The created node
 */
PathNode *create_node(const char *directory)
{
    PathNode *new_node = malloc(sizeof(PathNode));
    if (new_node == NULL)
    {
        perror("malloc failed");
        return NULL;
    }
    new_node->directory = strdup(directory);
    new_node->next = NULL;
    return new_node;
}

/**
 * build_path_list - Builds the linked list of directories in PATH
 * Return: A pointer to the head of the linked list
 */
PathNode *build_path_list(void)
{
    char *path = _getenv("PATH");
    if (!path)
        return NULL;

    PathNode *head = NULL, *current = NULL;
    char *dir = strtok(path, ":");

    while (dir != NULL)
    {
        PathNode *new_node = create_node(dir);
        if (new_node == NULL)
            return NULL;

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            current->next = new_node;
        }
        current = new_node;
        dir = strtok(NULL, ":");
    }

    return head;
}

/**
 * print_path_list - Prints the linked list of directories in PATH in a single line
 * @head: The head of the linked list
 */
void print_path_list(PathNode *head)
{
    PathNode *current = head;
    while (current != NULL)
    {
        printf("%s", current->directory);
        if (current->next != NULL)
            printf(":");
        current = current->next;
    }
    printf("\n");
}

/**
 * free_path_list - Frees the memory allocated for the linked list
 * @head: The head of the linked list
 */
void free_path_list(PathNode *head)
{
    PathNode *current = head;
    while (current != NULL)
    {
        PathNode *temp = current;
        current = current->next;
        free(temp->directory);
        free(temp);
    }
}

/**
 * _getenv - Custom getenv function
 * @name: The environment variable name
 * Return: The value of the environment variable or NULL if not found
 */
char *_getenv(const char *name)
{
    for (int i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
            return environ[i] + strlen(name) + 1;
    }
    return NULL;
}

int main(void)
{
    PathNode *path_list = build_path_list();
    if (path_list != NULL)
    {
        print_path_list(path_list);
        free_path_list(path_list);
    }
    return 0;
}


