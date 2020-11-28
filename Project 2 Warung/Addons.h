#include <stdio.h>
#include <time.h>
void detectsystem()
{
    #ifdef _WIN32 
        printf("System: Windows\n"); 
         __APPLE__ 
        printf("System: Mac OS\n"); 
    #elif __linux__ 
        printf("System: Linux OS\n"); 
    #elif TARGET_OS_EMBEDDED 
        printf("System: iOS embedded OS\n"); 
    #elif TARGET_IPHONE_SIMULATOR 
        printf("System: iOS simulator OS\n"); 
    #elif TARGET_OS_IPHONE 
        printf("System: iPhone OS\n"); 
    #elif TARGET_OS_MAC 
        printf("System: MAC OS\n"); 
    #elif __unix__ 
        printf("System: unix OS\n"); 
    #elif _POSIX_VERSION 
        printf("System:  POSIX based OS\n"); 
    #elif __sun 
        printf("System: Solaris OS\n"); 
    #elif __hpux 
        printf("System: HP UX OS\n"); 
    #elif BSD 
        printf("System: Solaris OS\n"); 
    #elif __DragonFly__ 
        printf("System: DragonFly BSD OS\n"); 
    #elif __FreeBSD__ 
        printf("System: FreeBSD OS\n"); 
    #elif __NetBSD__ 
        printf("System: Net BSD OS\n"); 
    #elif __OpenBSD__ 
        printf("System: Open BSD OS\n");  
    #endif 
}
void detecttime()
{
    time_t t; 
    time(&t);
    printf("%s", ctime(&t));
}
void clear()
{
    for(int i = 0; i < 200; i++)
    {
        puts("");
    }
}
bool checknumber(char ch)
{
    if(ch >= 48 && ch <= 57)
    {
        return true;
    }
    return false;
}
int validatefood(char *str)
{
    struct Node* current = head;
    while (current != NULL) 
    { 
        if (strcmp(current->dishname, str) == 0)
        {
            return 1;
        } 
        current = current->next;
    } 
    return 0;
}
int validateqty(char *str)
{
    struct Node* current = head;
    int i = 1, temp;
    while (current != NULL) 
    { 
        if (strcmp(current->dishname, str) == 0)
        {
            temp = current->dishqty;
        } 
        current = current->next; 
    }
    return temp; 
}

