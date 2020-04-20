/****************************************
 *This has been programed by AKASH ANAND*
 ***********Roll no:11912051**************
 ******************IT*********************
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b
typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
}node;
node* root=NULL;
int key=1;
int r[2];
int h_max=0;
int height(node* root)// find the height of the tree
{
    if (!root)
    return 0;
    int hl=height(root->lchild);
    int hr=height(root->rchild);
    h_max=max(hl,hr);
    return (1+h_max);
}
node* t1=NULL,*t2=NULL;
node* unbalanced(node* root)// return unbalanced node's address else null
{
    if (!root) return NULL;
    int hl=height(root->lchild);
    int hr=height(root->rchild);
    if (hl-hr>=2)
    return root;
    if (hl-hr<=-2)
    return root;
    t1=unbalanced(root->lchild);
    t2=unbalanced(root->rchild);
    if (t1==NULL && t2==NULL)
    return NULL;
    else if (t1==NULL)
    return t2;
    else 
    return t1;
}
node* insert(node* t,int key)// inserts key inside the trey by recursion
{
    if (!t)
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->data=key;
        temp->lchild=temp->rchild=NULL;
        return temp;
    }
    if (t->data>key)
    t->lchild=insert(t->lchild,key);
    if (t->data<key)
    t->rchild=insert(t->rchild,key);
    return t;
}
//type of rotaion of the tree 
int rotation(int key)//assuming left = 1 right = 2
{
    node* temp=root;
    for (int i=0;i<2;i++)
    {
        if (temp->data<key)
        {
            temp=temp->rchild;
            r[i]=2;
            printf("R");
        }
        else
        {
            r[i]=1;
            printf ("L");
        }
    }
    printf ("\n");
    return 10*r[0]+r[1];
}
//this function actually performs the rotations
void balance(node* root,int rv)// i hve created this only for this case
{
    if (rv==22)//RR rotation
    {
        node* b=root->rchild;
        node* c=b->rchild;
        root->rchild=b->lchild;
        b->rchild=c;
        b->lchild=root;
    }
}
//this creates the A.V.L tree recursively 
void avl_create()
{
    if (key==7)
    return;
    root=insert(root,key);
    node* ub_n=unbalanced(root);
    if (ub_n!=NULL)
    balance(ub_n,rotation(key));
    key++;
    avl_create();
}
int main(void)
{
    avl_create();
}