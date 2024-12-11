#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define STR_SIZE 10000
#define arrsize 10000

typedef struct llnode* LLNODE;

struct llnode
{
    int ele;
    LLNODE next;
};

typedef struct linked_list* LIST;

struct linked_list
{
    int count;
    LLNODE head;
};

LIST createNewList()
{
    LIST myList;
    myList = (LIST) malloc(sizeof(struct linked_list));
    myList->count=0;
    myList->head=NULL;
    return myList;
}

LLNODE NewLLNode(int value)
{
    LLNODE myNode;
    myNode = (LLNODE) malloc(sizeof(struct llnode));
    myNode->ele=value;
    myNode->next=NULL;
    return myNode;
}

void InsertAfter(int searchEle, LLNODE n1, LIST l1)
{
    if(l1->head==NULL)
    {
    l1->head = n1;
    n1->next = NULL;
    l1->count++;
    }
    else
    {
        LLNODE temp = l1->head;
        LLNODE prev = temp;
        while(temp!=NULL)
        {
            if (temp->ele == searchEle)
            {
            break;
            }
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL)
        {
            printf("Element not found\n");
            return;
        }
        else
        {
            if(temp->next == NULL)
            {
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            }
            else
            {
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
        return;
        }
    }
    return;
}

void InsertFirst(LIST l, LLNODE n)
{
    if (l->head == NULL)
    {
        InsertAfter(0, n, l);
    }
    else
    {
        int ele1 = l->head->ele;
        InsertAfter(ele1, n, l);
    }
}

typedef struct bstnode
{
    LLNODE value;
    struct bstnode *left;
    struct bstnode *right;
} BSTNODE;

typedef struct bst
{
    BSTNODE *node;
} BST;

BST *NewBST()
{
    BST *bst = (BST *)malloc(sizeof(BST));
    bst->node = NULL;
    return bst;
}

BSTNODE *NewBSTNode(LIST l)
{
    BSTNODE *node = (BSTNODE *)malloc(sizeof(BSTNODE));
    node->value = l->head;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void creation(FILE *fptr){
    for (int i = 0; i < arrsize; i++)
    {   
        int temp;
        LIST l1 = createNewList();
        int a = ftell(fptr);
        fscanf(fptr, "%d", &temp);
        int b = ftell(fptr);
        LLNODE n = NewLLNode(temp);
        InsertFirst(l1, temp);
        int a = ftell(fptr);
        fscanf(fptr, "%d", &temp);
        int b = ftell(fptr);

        if ((b - a) > 3)
        {
            BSTNODE *node = NewBSTNode(l1);
            free(l1);
            creation(fptr);
        } 
        LLNODE n = NewLLNode(temp);
        InsertAfter(1, n, l1);
    }
}


BST readData(char* filename)
{
    int size;
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Error opening file");
        return;
    }
    BST *Tree = NewBST();
    fscanf(fptr, "%d", &size);
    creation(fptr);

    return *Tree;
}

void inORder(BSTNODE *root, FILE* fptr)
{
    int num;
    if (root == NULL)
    {
        return;
    }
    inORder(root->left, fptr);
    LLNODE *current = root;
    while(current != NULL)
    {
        fprintf(fptr, "%d", root->value);
        current = root->next;
    }
    inORder(root->right, fptr);
    
}

void traverse(BST *Tree, BSTNODE *root)
{
    int num;
    FILE* fptr;
    fptr = fopen("file2.txt", "w+");
    inORder(*root, *fptr);
}
