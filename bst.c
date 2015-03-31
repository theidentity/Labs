#include<stdio.h>
#include<stdlib.h>

typedef struct BTreeNode BTNode;
struct BTreeNode
{
int value;
struct BTreeNode *left_child,*right_child;
};

BTNode* insert(int input_value, BTNode **head_node)
{
    BTNode *temp,*head;
    temp = (BTNode*)malloc(sizeof(BTNode));
    temp->value = input_value;
    temp->left_child = NULL;
    temp->right_child = NULL;
    head = *head_node;
    while(1)
    {
        if(head == NULL)
        {
            *head_node = temp;
            printf("Inserted successfully\n");
//          break;
            return *head_node;
        }
        if(temp->value > head->value)
        {
            if(head->right_child==NULL)     //<- in case the right child is null    
            {
                head->right_child=temp;
                break;
            }
            else
                head = head->right_child;
        }
        else if(temp->value < head->value)
        {
            if(head->left_child==NULL)     //<- in case the left child is null
            {
                head->left_child=temp;
                break;
            }
            else
             head = head->left_child;
        }
        else
        {
            break;
        }
    }
    return *head_node;                  //<- returb always the Tree root!
}

void printtree(BTNode **head_node)
{
    BTNode *head;
    head = *head_node;
    if(head == NULL)
    {
        //printf("Print exit\n");
        return;
    }
    else
    {
        printf("%d\n",head->value);
        printtree(&(head->left_child));
        printtree(&(head->right_child));
    }
}

int main()
{
    BTNode *root=NULL;
    root=insert(23,&root);
    root=insert(32,&root);
    root=insert(230,&root);
    root=insert(3,&root);
    root=insert(2,&root);
    root=insert(50,&root);
    printtree(&root);
}