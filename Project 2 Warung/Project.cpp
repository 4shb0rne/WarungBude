#include <stdio.h>
#include "Linked-list.h"
#include "Addons.h"
#include "hashtable.h"
void add_dish();
void remove_dish();
void add_customer();
void search_customer();
void customer_list();
void order();
void payment();
int main()
{
    int menu;
    do
    {
        detectsystem();
        detecttime();
        printf("1. Add Dish\n");
        printf("2. Remove Dish\n");
        printf("3. Add Customer\n");
        printf("4. Search Customer\n");
        printf("5. View Warteg\n");
        printf("6. Order\n");
        printf("7. Payment\n");
        printf("8. Exit Warteg\n");
        printf(">>  ");
        scanf("%d", &menu);
        if(menu == 1)
        {
            add_dish();
        } else if(menu == 2)
        {
            remove_dish();
        } else if(menu == 3)
        {
            add_customer();
        } else if(menu == 4)
        {
            search_customer();
        } else if(menu == 5)
        {
            customer_list();    
        } else if(menu ==  6)
        {
            order();
        } else if(menu == 7)
        {
            payment();
        } else if(menu == 8)
        {
            
            clear();
            char c;
            FILE *fptr = fopen("splash-screen.txt", "r");
            while((c=fgetc(fptr))!=EOF)
            {
                printf("%c",c);
            }
            fclose(fptr);
            getchar();getchar();
            break;

        }
    } while (1);
    
    return 0;
}

void add_dish()
{
    clear();
    char dishname[101];
    int dishprice;
    int dishqty;
    int flag = 0;
    do
    {
        printf("Insert the name of the dish [Lowercase letters]: ");
        scanf("%s", dishname);
        flag = 0;
        for(int i = 0; dishname[i] != '\0'; i++)
        {
            if(dishname[i] >= 65 && dishname[i] <= 90)
            {
                flag = 1;
            }
        }
    } while (flag == 1);
    do
    {
        printf("Insert the price of the dish [1000..50000]: ");
        scanf("%d", &dishprice);
    } while (dishprice < 1000 || dishprice > 50000);
    do
    {
        printf("Insert the quantity of the dish [1..999]: ");
        scanf("%d", &dishqty);
    } while (dishqty < 1 || dishqty > 999);
    pushTail(dishname, dishprice, dishqty);
    printf("The dish has been added!\n");
    printf("Press enter to continue...");
    getchar();getchar();
    clear();
}
void remove_dish()
{
    if(!head)
    {
        clear();
        printf("There is nothing to delete\n");
        printf("Press enter to continue...");
        getchar();getchar();
        clear();
    } else
    {
        clear();
        char name[101];
        int flag = 0;
        printlinkedlist();
        do
        {
            flag = 0;
            printf("Insert dish's name to be deleted : ");
            scanf(" %[^\n]", name);
            for(int i = 0; name[i] != '\0'; i++)
            {
                if(name[i] >= 65 && name[i] <= 90)
                {
                    flag = 1;
                }
            }
        } while (flag == 1);
        
        int search_result = search(name);
        if(search_result == 0)
        {
            printf("Cannot find the dish\n");
            printf("Press enter to continue...");
            getchar();getchar();
            clear();
        } else
        {
            deleteNodeAtGivenPos(&head, search_result);
            printf("The dish has been removed!\n");
            printf("Press enter to continue...");
            getchar();getchar();
            clear();
        }
    }
}

void add_customer()
{
    clear();
    char cust_name[101];
    int flag = 0;
    do
    {
        flag = 0;   
        printf("Insert the customer's name [Without space]: ");
        scanf(" %[^\n]", cust_name);
        for(int i = 0; cust_name[i] != '\0'; i++)
        {
            if(cust_name[i] == ' ')
            {
                flag = 1;
            }
        }
    } while (flag == 1);
    insert((char*)cust_name);
    printf("Customer has been added\n");
    printf("Press enter to continue...");
    getchar();getchar();
    clear();
}
void search_customer()
{
    clear();
    int flag = 0;
    char cust_name[101];
    do
    {
        flag = 0;
        printf("Insert the customer’s name to be searched: ");
        scanf(" %[^\n]", cust_name);
        for(int i = 0; cust_name[i] != '\0'; i++)
        {
            if(cust_name[i] == ' ' || cust_name[i] < 65 && cust_name[i] > 90 || cust_name[i] < 97 && cust_name[i] > 122)
            {
                flag = 1;
            }
        }
    } while (flag == 1);
    int result = searchcust(cust_name);
    if(result == 1)
    {
        printf("%s is present.\n", cust_name);
        printf("Press enter to continue...");
        getchar();getchar();
    } else
    {
        printf("%s is not present.\n", cust_name);
        printf("Press enter to continue...");
        getchar();getchar();
    }
    clear();
}
void customer_list()
{
    clear();
    printf("Customer List\n");
    view();
    printf("Press enter to continue...");
    getchar();getchar();
    clear();
}
void order()
{
    clear();
    char name[101], nameqty[110], dishname[101], qty[10];
    int flag = 0, result = 0, quantity, index = 0;
    do
    {
        flag = 0;
        printf("Insert the customer's name: ");
        scanf(" %[^\n]", name);
        result = searchcust(name);
        for(int i = 0; name[i] != '\0'; i++)
        {
            if(name[i] == ' ')
            {
                flag = 1;
            }
        }
    } while (flag == 1 && result != 1);
    printf("Insert the amount of dish: ");
    scanf("%d", &quantity);
    int foodquantity[quantity];
    for(int i = 0; i < quantity; i++)
    {
        flag = 1;
        do
        {
            int x = 0, k = 0;
            index = 0;
            printf("[%d] Insert the dish’s name and quantity: ", i+1);
            scanf(" %[^\n]", nameqty);
            for(int j = 0; nameqty[j] != '\0'; j++)
            {
                if(nameqty[j] == 'x' && checknumber(nameqty[j+1]) == true)
                {
                    x = 1;
                    index = j+1;
                    flag = 0;
                }
            }
            if(x >= 1)
            {
                for(int j = index; nameqty[j] != '\0'; j++)
                {
                    if(checknumber(nameqty[j]) == true)
                    {
                        qty[k] = nameqty[j];
                        k++;
                        flag = 0;
                    }
                }
            } else
            {
                flag = 1;
            }
            if(k == 0)
            {
                flag = 1;
            }
            for(int j = 0; j < index-2; j++)
            {
                if(dishname[j] == ' ')
                {
                    continue;
                }
                dishname[j] = nameqty[j];
            }
            foodquantity[i] = atoi(qty);
            int countqty = Countqty(dishname);
            if(foodquantity[i] > countqty)
            {
                flag = 1;
            }
        } while (flag == 1);
        
        int res = searchstr(name); //index hashtable
        int res1 = search1(dishname);
        int res2 = search2(dishname);
        Dish *temp = createDish(dishname, res1, res2);
        addNewOrder(name, res, temp , foodquantity[i]);
    }
    printf("Order Success!\n");
    printf("Press enter to continue...");
    getchar();getchar();
    clear();
}
void payment()
{
    int index;
    printf("Insert the customer's index : ");
    scanf("%d", &index);
    table *currCust = Head[index-1];
    while (currCust && !currCust->order) 
    {
        currCust = currCust->next;
    }
    printf("%s\n", currCust->name);
    long long int total_price = 0;	    
    CustomerOrder *	custOrder = currCust->order;
    int ctrOrder = 0;
    while (custOrder) 
    {
        printf("[%d] %s x%d\n", ctrOrder + 1, custOrder->name, custOrder->quantity);
        total_price += (custOrder->price_per_quantity * custOrder->quantity);
        ctrOrder++;
        custOrder = custOrder->next;
    }
    printf("Total: Rp%lld\n", total_price);
    printf("Press enter to continue...");
    removeUser(index-1, currCust->name);
    getchar();getchar();
    clear();
}