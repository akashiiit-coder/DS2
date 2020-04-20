/****************************************
 *This has been programmed by AKASH ANAND*
 ***********Roll no:11912051**************
 ******************IT*********************
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) a>b?a:b
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* root=NULL;
node* insert(node* t,int key)// this function inserts given key recursively
{
    if (!t)
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->data=key;
        temp->left=temp->right=NULL;
        return temp;
    }
    if (t->data>key)
    t->left=insert(t->left,key);
    if (t->data<key)
    t->right=insert(t->right,key);
    return t;
}
int u=1;
void create()// this function creates the binary search tree 
{
    printf ("To insert data press 1\n");
    int y;
    scanf("%d",&y);
    if (y==1)
    {
        root=insert(root,u++);
        create();
    }
}
int h_max=0;
int height(node* root)
{
    if (!root)
    return 0;
    int hl=height(root->left);
    int hr=height(root->right);
    h_max=max(hl,hr);
    return (1+h_max);
}
void unbalancing(node* root)// print unbalanced node data
{
    if (!root)return;
    int hl=height(root->left);
    int hr=height(root->right);
    if (hl-hr>=2)
    printf ("Unbalanced at %d \nLeft subtree is taller than right subtree by b.f.=%d\n",root->data,abs(hl-hr));
    if (hl-hr<=-2)
    printf ("Unbalanced at %d \nRight subtree is taller than left subtree by b.f.=%d\n",root->data,abs(hl-hr));
    unbalancing(root->left);
    unbalancing(root->right);
}
int main()
{
    create();
    unbalancing(root);
}