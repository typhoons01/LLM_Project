#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT_LEN 50

//structure to store the node of the linked list of integers
typedef struct LLNode{
	int ele;
	struct LLNode* next;
}LLNode;


//structure to store the header of the linked list of integers
typedef struct LLHeader{
	LLNode* node;
}LLHeader;

//structure to store the tail of the linked list of integers
typedef struct LLTail{
	LLNode* node;
}LLTail;


//structure to store the linked list of integers
typedef struct record{
	LLHeader header;
	LLTail tail;
	int length;
}record;

//function to create a new record(basically a linked list)
record* createNewRecord(){
	record* newRecord;
	newRecord = (record*)malloc(sizeof(record));
	newRecord->length = 0;
	newRecord->header.node = NULL;
	newRecord->tail.node = NULL;
	return newRecord;
}

//function to create a new node with a given integer
LLNode* createNewNode(int value){
	LLNode* newNode = (LLNode*)malloc(sizeof(LLNode));
	newNode->ele = value;
	newNode->next = NULL;
	return newNode;
}

//function to add a node to a record with a given integer
void addNodeToRecord(record* r, int value){
	LLNode* newNode = createNewNode(value);
	if(r->length == 0){
		r->header.node = newNode;
		r->tail.node = newNode;
	} else{
		r->tail.node->next = newNode;
		r->tail.node = newNode; 
	}
	r->length++;
}

//node of BST where each node contains a record as its attribute
typedef struct node
{
	record record;
	struct node* left;
	struct node* right;
}Node;

//structure of a BST where each node is a record
typedef struct bst{
	Node* root;
	int size;
}BST;

//function to create a BST
BST* new_bst()
{
	BST* bst = (BST*)malloc(sizeof(BST));
	bst->root = NULL;
	bst->size = 0;
	return bst;

}

//function to create a new node of the BST
Node* new_node(record* record)
{
	Node* node = malloc(sizeof(Node));
	node->record = *record;
	node->left = NULL;
	node->right = NULL;
}

//function to insert a record into the BST taking the first node of the record as the key
void insert(BST* bst, record* record)
{
	Node* node = new_node(record);
	if(bst->root == NULL)
	{
		bst->root = node;
		bst->size++;
		return;
	}

	Node* current = bst->root;
	while(current!= NULL)
	{
		if(record->header.node->ele < current->record.header.node->ele)
		{
			if(current->left == NULL)
			{
				current->left = node;
				bst->size++;
				return;
			}
			current= current->left;
		}

		else
		{
			if(current->right == NULL)
			{
				current->right = node;
				bst->size++;
				return;
			}
			current = current->right;
		}
	}
}
//function takes the name of the file as an input parameter, creates a BST, reads the integers from the input file line by line and inserts them into their records in the BST and returns the BST
BST* readData(char* fileName){
	FILE* fp = fopen(fileName, "r");
	//creates a BST with elements of type record
	BST* bst = new_bst();
	//allocating memory for a character array to read the first line of the file which contains the total number of lines.
	char* num_line = malloc(10);
	fgets(num_line, 8, fp);
	int num = (int) *num_line - 48;
	//assuming each line in the file contains no more than 50 integers
	int max_int[MAX_INT_LEN];
	while(fgets(max_int, MAX_INT_LEN, fp)){
		for(int i = 0; i<50; i++){
			record* r = createNewRecord();
			addNodeToRecord(r, max_int[i]);
			insert(bst, r);
		}
	}
	return bst;
	fclose(fp);
}

//normal traversal function of BST to help sortLists (iterative merge sort) function
void traverse_in_order(Node* node){
	if(node == NULL)
		return;
	traverse_in_order(node->left);
	traverse_in_order(node->right);
}


//helper function for sortLists (iterative merge sort) function
LLNode* mergeIn(LLNode* head, int st1, int st2, int en2){
	LLNode* head1 = head, *head2, *newListHead=NULL, *newListTail = NULL;
	LLNode* insertStart = head, *insertEnd= NULL;
	for(int i = 0; i<st1; i++){
		head1 = head1->next;
		if(i!=st1-1) insertStart = insertStart->next;
	}
	head2 = head1;
	for(int i = 0; i<st2 - st1; i++)
		head2= head2->next;
	int len1 = st2-st1, len2 = en2-st2+1;
	int coveredLen1 = 0, coveredLen2 = 0;

	for(int i = 0; i<len1+len2; i++){
		if(coveredLen1==len1){
			if(newListHead==NULL){
				newListHead = head2;
				newListTail = head2;
			} else{
				newListTail->next = head2;
				newListTail = head2;
			}
			head2 = head2->next;
			coveredLen2++;

			} else if(coveredLen2==len2){
				if(newListHead == NULL){
					newListHead = head1;
					newListTail = head1;
				} else{
					newListTail->next = head1;
					newListTail = head1;
				}
				head1 = head1->next;
				coveredLen1++;
			} else{
				if(newListHead == NULL){
					newListHead = head2;
					newListTail = head2;
				} else{
					newListTail->next = head2;
					newListTail = head2;
				}
				head2 = head2->next;
				coveredLen2++;
			}

		}
		if(len2==0)
			newListTail->next = head1;
		else newListTail->next = head2;
		if(st1==0) return newListHead;
		else{
			insertStart->next = newListHead;
			return head;
		}
		return head;
	}



//function that sorts every single linked list node in the BST, an iterative merge sort has been used
void sortLists(BST* bst){
	while(bst->root!= NULL)
		traverse_in_order(bst->root);
	if(bst->root->record.length<=1){
		int maxSlSz, slSz, st1, last = bst->root->record.length -1;
		for(maxSlSz=1; bst->root->record.length>maxSlSz; maxSlSz * 2);
			for(slSz=1; slSz<=maxSlSz; slSz*=2){
				for(st1 = 0; st1<=last; st1=st1+2*slSz){
					int st2 = st1+slSz;
					int en2 = st2+slSz-1;
					if(st2>last) continue;
					if(en2>last){
						en2 = last;
					}
					bst->root->record.header.node = mergeIn(bst->root->record.header.node, st1, st2, en2);
				}
	}
}
}




//a function that performs in-order traversal
void traverse(Node* node){
	if(node == NULL)
		return;
	traverse(node->left);
	LLNode* traversal_node = node->record.header.node;
	for(int i = 0; i<=node->record.length; i++){
		FILE* fpt = fopen("file2.txt", "w");
		fprintf(fpt, "%d", traversal_node->ele);
		traversal_node = traversal_node->next;
		fclose(fpt);

	}
	traverse(node->right);
	
} 


//main driver function that drives the above program
int main(){
	BST* bst = readData("file1.txt");
	sortLists(bst);
	traverse(bst->root);
	return 0;
}