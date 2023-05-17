#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 500
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node *head=NULL;
struct node** createQueue(int*, int*);
void enQueue(struct node**, int*, struct node*);
struct node* deQueue(struct node**, int*);
void printLevelOrder(struct node* root)
{
    int rear, front;
    struct node** queue = createQueue(&front, &rear);
    struct node* temp_node = root;
 
    while (temp_node){
        printf("%d ", temp_node->data);
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);
        temp_node = deQueue(queue, &front);
    }
}
struct node** createQueue(int* front, int* rear)
{
    struct node** queue = (struct node**)malloc(sizeof(struct node*) * MAX_Q_SIZE);
    *front = *rear = 0;
    return queue;
}
 
void enQueue(struct node** queue, int* rear, struct node* new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}
 
struct node* deQueue(struct node** queue, int* front)
{
    (*front)++;
    return queue[*front - 1];
}
struct  node *create(){
	int x;
	struct node *nn;
	nn=(struct node *)malloc(sizeof(struct node));
	printf("enter data -1 to exit\n");
	scanf("%d",&x);
	if(x==-1){
		return 0;
	}
	nn->data=x;
	printf("enter left child o %d",x);
	nn->left=create();
	printf("enter right child of %d",x);
	nn->right=create();
	return nn; 
}
int main()
{
   head=create();
 
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(head);
 
    return 0;
}
