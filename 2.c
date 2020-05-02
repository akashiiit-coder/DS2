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
int h_max=0;
int height(node* root)// find the height of the tree  ......checked OK!
{
    if (!root)
    return 0;
    int hl=height(root->lchild);
    int hr=height(root->rchild);
    h_max=max(hl,hr);
    return (1+h_max);
}
node* ub_n=NULL,*ub_n_p=NULL;
void unbalanced(node* root)//if node is unbalanced unbalanced_node will get its value
// not returning the nearest unbalanced node instead returning the first unbanced node
{
    if (!root) return ;
    unbalanced(root->lchild);
    unbalanced(root->rchild);
    int hl=height(root->lchild);
    int hr=height(root->rchild);
    if ( !ub_n && (hl-hr>=2 || hl-hr<=-2) )
    ub_n=root;
    if (!ub_n_p && ((root->rchild && root->rchild==ub_n) || (root->lchild && root->lchild==ub_n) ))
    ub_n_p=root;

}
node* insert(node* t,int key)// inserts key inside the tree by recursion
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
//type of rotaion of the tree checks from unbalanced node to newly inserteed node
int rotation(node* temp,int key)//assuming left = 1 right = 2
{
    int r[2];
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
void balance(node* ubn,node* ubn_parent,int rv)// i hve created this only for this case
{
    if (rv==22)//RR rotation
    {
        node* b=ubn->rchild;
        node* c=b->rchild;
        ubn->rchild=b->lchild;
        b->lchild=ubn;
        if (!ubn_parent)//root is unbalanced
        root=b;
        else
        {
            if (ubn_parent->data>b->data)// if unbalanced node is left child of it's parent
            ubn_parent->lchild=b;
            else 
            ubn_parent->rchild=b;
        }
    }
}
//this creates the A.V.L tree recursively 
void avl_create()
{
    if (key==7)
    return;
    root=insert(root,key);
    ub_n=NULL;
    ub_n_p=NULL;
    unbalanced(root);
    if (ub_n!=NULL)
    {
        if (ub_n_p!=NULL)
        printf ("Parent of ubn is %d",ub_n_p->data);
        printf("data of unb node= %d, when element inserted = %d\n",ub_n->data, key);
        balance(ub_n,ub_n_p,rotation(ub_n,key));
    }
    key++;
    avl_create();
}
void display(node* root, int level)
{
    if (!root)return;
    display(root->rchild,level+1);
    for (int i=0;i<level;i++)
    printf ("   ");
    printf ("%d\n",root->data);
    display(root->lchild,level+1);
}
int main(void)
{
    avl_create();
    display(root,0);
}
