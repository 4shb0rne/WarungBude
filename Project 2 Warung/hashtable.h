#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX_ELEMENT = 26;

struct CustomerOrder {
    char *name;
    int quantity;
    int price_per_quantity;
    CustomerOrder *next;
};
struct Dish{
    char dishname[101];
    int dishprice;
    int dishqty;
    Dish *next, *prev; 
};
Dish *createDish(char *dishname, int dishprice, int dishqty)
{
    Dish *temp = (Dish*)malloc(sizeof(Dish));
    strcpy(temp->dishname, dishname);
    temp->dishprice = dishprice;
    temp->dishqty = dishqty;
    temp->next = temp->prev = NULL;
    return temp;
}

struct table {
    char name[255];
    CustomerOrder *order;
    table *next;
}*Head[MAX_ELEMENT], *Tail[MAX_ELEMENT];

void removeUser(int index, char *user_name) 
{
  int total_user = 0;
    if (Head[index]) 
    {
        table *curr = Head[index];
        table *prev = curr;
        while (curr && strcmp(curr->name, user_name) != 0) 
        {
            total_user++;
            prev = curr;
            curr = curr->next;
        }
        if (!curr) 
        {
            return;
        }
        if (total_user < 1) 
        {
            Head[index] = Tail[index] = NULL;
        } else 
        {
            prev->next = curr->next; 
            free(curr->order);
            free(curr);
        }
    }
}
void AddOrder(CustomerOrder *mainHead, CustomerOrder *temp_node) {
    CustomerOrder *curr = mainHead;
    CustomerOrder *lastKnown = NULL;
    while (curr) {
        lastKnown = curr;
        curr = curr->next;
    }
    lastKnown->next = temp_node;
}
void addNewOrder(char *user_name, int user_id, Dish *dish_data, int order_amount) {
    table *curr = Head[user_id];
    while (curr) {
        if (strcmp(user_name, curr->name) == 0) {
            CustomerOrder *temp_node = (CustomerOrder*)malloc(sizeof(CustomerOrder));
            temp_node->name = dish_data->dishname;
            temp_node->price_per_quantity = dish_data->dishprice;
            temp_node->quantity = order_amount;
            temp_node->next = NULL;
            if (!curr->order) {
                curr->order = temp_node;
            } else {
                CustomerOrder *mainHead = curr->order;
                AddOrder(curr->order, temp_node);
            }
            return;
        }
        curr = curr->next;
    }
}

table *createNode(char *name) {
  table *temp = (table*)malloc(sizeof(table));
  strcpy(temp->name, name);
  temp->next = NULL;
  return temp;
}

unsigned long djb2(char *str, int range) 
{
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % range;
}
void insert(char *str) {
  int index = djb2(str, MAX_ELEMENT);

  if(Head[index]) { 
    table *temp = createNode(str);
    Tail[index]->next = temp;
    Tail[index] = temp;
  } else { 
    Head[index] = Tail[index] = createNode(str);
  }
}
int searchcust(char *str) {
  for(int i = 0; i < MAX_ELEMENT; i++) {
    if(Head[i]) 
    {
      table *curr = Head[i];
      while(curr) 
      {
        if(strcmp(curr->name, str) == 0)
        {
            return 1;
        }
        curr = curr->next;
      }
    }
  }
  return 0;
}
void view() {
  for(int i = 0; i < MAX_ELEMENT; i++) {
    int flag = 0;
    if(Head[i]) {
      table *curr = Head[i];
      while(curr) {
        if(curr != NULL)
        {
          if(flag == 0)
          {
            printf("%-3d. ", i+1);
            flag = 1;
          }
          printf("%s ",curr->name);
        }
        curr = curr->next;
      }
      puts("");
    }
  }
}

int searchstr(char *str) {
  for(int i = 0; i < MAX_ELEMENT; i++) {
    if(Head[i]) 
    {
      table *curr = Head[i];
      while(curr) 
      {
        if(strcmp(curr->name, str) == 0)
        {
            return i;
        }
        curr = curr->next;
      }
    }
  }
  return 0;
}



