#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
//be carefull its quite hard make sure u go slow and 
// keep  a  notecopy to make sure u are doing it right


    #include "tree.h"



int main()
{

  Node *root = NULL;
  

    for(int i =0 ; i <200;i++)
    {
    root =  insert_t(root,i);
    }

    int found = search(root,19);
    root =delete_tn(root,15);
    root =delete_tn(root,16);
    root =delete_tn(root,17);

    printf(" if find print 19 %d \n",found);
    
    inorder(root);


    return 0;
}



*/
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node * create_t(int data)
{
    Node *n  = malloc(sizeof(Node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}

Node *insert_t(Node * root , int data)
{
    if(root==NULL) return create_t(data);

    if(data < root->data) 
    {
        root->left = insert_t(root->left,data);
    }
    else if (data > root->data)
    {
        root ->right = insert_t(root->right,data);
    }

    return root;
}

int search(Node * root, int target)
{
    if(root==NULL)return 0;
    if(root->data == target) return 1;

    if(root->data > target) 
    { 
       return search(root->left,target);
    }
    else if(root->data < target)
    {
        return search(root->right,target);
    }
}
Node *find_min(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node * delete_tn(Node *root,int target)
{
    if(root==NULL){return NULL;}
    if(root->data > target)
    {
        root->left = delete_tn(root->left,target);
    }
    else if(root->data < target)
    {
        root->right = delete_tn(root->right,target);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *successor = find_min(root->right);
        root->data      = successor->data;
        root->right     = delete_tn(root->right, successor->data);        
    }
    
    return root;
}

void inorder(Node * root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("[%d]->",root->data);
    inorder(root->right);

}

#endif
