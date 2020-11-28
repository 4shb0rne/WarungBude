#include <stdio.h>
#include <string.h>
const int max = 26;
char HASHTABLES[26][255];

int hashFunction(char *str)
{
    return str[0]-'a';
}
void PrintHashTable()
{
    for(int i = 0; i < 26; i++)
    {
        printf("%d - > %s\n", i, HASHTABLES[i]);
    }
}
void insertHashTable(char *str)
{
    int index = hashFunction(str);
    if(HASHTABLES[index][0] != '\0') // sudah terisi
    {
        int curr = max-1;
        while(curr >= 0)
        {
            if(HASHTABLES[curr][0] != '\0')
            {
                break;
            }
            curr--;
        }
        if(curr < 0)
        {
            return;
        }
        strcpy(HASHTABLES[curr], str);
    } else
    {
        strcpy(HASHTABLES[hashFunction(str)], str);
    }
}
int main()
{
    /*
    int index = hashFunction((char*)"ynot");
    printf("%d\n", index);
    */
    insertHashTable((char*)"ashborne");
    insertHashTable((char*)"bshborne");
    PrintHashTable();
    return 0;
}