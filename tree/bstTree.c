#include <stdio.h>
#include <stdlib.h>

#define True 1

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *getNode(int d)
{
    struct node *ptrnew = (struct node *)malloc(sizeof(struct node));
    if (ptrnew == NULL)
    {
        printf("Fatal Error: Memory allocation failed.");
        exit(0);
    }
    ptrnew->info = d;
    ptrnew->left = ptrnew->right = NULL;
    return ptrnew;
}

struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return getNode(data);
    }
    if (data < root->info)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->info)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct node *findMin(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->left == NULL)
    {
        return root;
    }
    return findMin(root->left);
}

struct node *removeNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->info)
    {
        root->left = removeNode(root->left, data);
    }
    else if (data > root->info)
    {
        root->right = removeNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            struct node *temp = findMin(root->right);
            root->info = temp->info;
            root->right = removeNode(root->right, temp->info);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

struct node *search(struct node *root, int data)
{
    if (root == NULL || root->info == data)
    {
        return root;
    }
    if (root->info < data)
    {
        return search(root->right, data);
    }
    return search(root->left, data);
}

int main()
{
    char ch;
    int data;
    while (True)
    {
        printf("Select your choice:\n");
        printf("1. Add\n2. Remove\n3. Inorder\n4. Preorder\n5. Postorder\n6. Search\n7. Exit\n");
        fflush(stdin);
        ch = getchar();
        switch (ch)
        {
        case '1':
            printf("Enter a number to be inserted: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            printf("Node inserted.\n");
            break;
        case '2':
            printf("Enter a number to be removed: ");
            scanf("%d", &data);
            root = removeNode(root, data);
            printf("Node removed.\n");
            break;
        case '3':
            printf("Tree in inorder:\n");
            inorder(root);
            printf("\n");
            break;
        case '4':
            printf("Tree in preorder:\n");
            preorder(root);
            printf("\n");
            break;
        case '5':
            printf("Tree in postorder:\n");
            postorder(root);
            printf("\n");
            break;
        case '6':
            printf("Enter a number to be searched: ");
            scanf("%d", &data);
            if (search(root, data) != NULL)
            {
                printf("%d exists in the tree.\n", data);
            }
            else
            {
                printf("%d does not exist in the tree.\n", data);
            }
            break;
        case '7':
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
