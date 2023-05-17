#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
void printCurrentLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
struct node *head=NULL;
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
/*struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}*/
 
/* Driver program to test above functions*/
int main()
{
  	head=create();
 	int h;
	h=height(head);
	printf("height of the tree=%d\n",h);
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(head);
 
    return 0;
}
