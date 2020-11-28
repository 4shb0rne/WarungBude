#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char dishname[101];
    int dishprice;
    int dishqty;
    Node *next, *prev; 
} *head, *tail, *curr;

Node *createNode(char *dishname, int dishprice, int dishqty)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->dishname, dishname);
    temp->dishprice = dishprice;
    temp->dishqty = dishqty;
    temp->next = temp->prev = NULL;
    return temp;
}
int CountPrice(char *name)
{
    struct Node* current = head;
    while (current != NULL) 
    { 
        if (strcmp(current->dishname, name) == 0)
        {
            return current->dishprice;
        } 
        current = current->next;
    }
    return 0; 
}
int Countqty(char *name)
{
    struct Node* current = head;
    while (current != NULL) 
    { 
        if (strcmp(current->dishname, name) == 0)
        {
            return current->dishqty;
        } 
        current = current->next;
    }
    return 0;
}
void pushTail(char *dishname, int dishprice, int dishqty)
{
    Node *temp = createNode(dishname, dishprice, dishqty);
    if(!head){
        head = tail = temp;
    } else if(head == tail)
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void printlinkedlist()
{
    if(!head)
    {
        return;
    } else
    {
        int i = 1;
        curr = head;
        printf("=============================================\n");
        printf("No  |   Name        |   Qty   |     Price   |\n");
        while(curr)
        {
            printf("%-3d | %-13s | %-7d | %-11d |\n", i, curr->dishname, curr->dishqty, curr->dishprice);
            curr = curr->next;
            i++;
        }
        printf("=============================================\n");
    }
}
int search(char *name) 
{ 
    curr = head;
    int i = 1;
    while (curr != NULL) 
    { 
        if (strcmp(curr->dishname, name) == 0)
        {
            return i;
        } 
        curr = curr->next;
        i++; 
    } 
    return 0;
}
int search1(char *name) 
{ 
    curr = head;
    int i = 1;
    while (curr != NULL) 
    { 
        if (strcmp(curr->dishname, name) == 0)
        {
            return curr->dishprice;
        } 
        curr = curr->next;
        i++; 
    } 
    return 0;
}
int search2(char *name) 
{ 
    curr = head;
    int i = 1;
    while (curr != NULL) 
    { 
        if (strcmp(curr->dishname, name) == 0)
        {
            return curr->dishqty;
        } 
        curr = curr->next;
        i++; 
    } 
    return 0;
}
void deleteNode(struct Node** head_ref, struct Node* del)
{
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}
void deleteNodeAtGivenPos(struct Node** head_ref, int n)
{
    if (*head_ref == NULL || n <= 0)
        return;
        
    struct Node* current = *head_ref;
    int i;
 
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;
 
    if (current == NULL)
        return;
 
    deleteNode(head_ref, current);
}
/*
void pushTail(int value)
{
    Node *temp = createNode(value);
    if(!head){
        head = tail = temp;
    } else if(head == tail)
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;

    }
}


void pushMid(int value)
{
    Node *temp = createNode(value);
    if(!head){
        head = tail = temp;
    } else if(value < head->value)
    {
        pushHead(value);
    } else if(value > tail->value)
    {
        pushTail(value);
    } else
    {
        curr = head;
        while(curr->value < value)
        {
            curr = curr->next;
        }
        temp->prev = curr->prev;
        temp->next = curr;

        curr->prev->next = temp;
        curr->prev = temp;
    }
}
void popHead()
{
    if(head && head == tail)
    {
        head = tail = NULL;
        free(head);
    } else
    {
        Node *newHead = head->next;
        head->next = newHead->prev = NULL;
        free(head);
        head = newHead;
    }
}
void popTail()
{
    if(head && head == tail)
    {
        head = tail = NULL;
        free(head);
    } else
    {
        Node *newTail = tail->prev;
        tail->prev = newTail->next = NULL;
        free(tail);
        tail = newTail;
    }
}
void popMid(int value)
{
    if(!head)
    {
        return;
    } else if(head->value == value)
    {
        popHead();
    } else if(tail->value == value)
    {
        popTail();
    } else
    {
        curr = head;
        while(curr && curr->value != value)
        {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->prev = curr->next = NULL;
        free(curr);
    }  
}
*/