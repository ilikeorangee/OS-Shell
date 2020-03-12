#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mem{
    char *var;
    char *value;
} *array;

struct mem* ptr;
int size = 1000;
int x = -1;

void initial()
{
    ptr = (struct mem*)malloc(size * sizeof(struct mem));
}

void shellFree()
{
    free(ptr);
}

int found(char *words[])
{
    for(int j=0;j<=x;j++)
    {
        if(strcmp((ptr[j]).var,words[1])==0)
            return j;
    }
    return -1;
}
int shellmemorySet(char *words[])
{
    char temp[100]="";
    int num = 0;
    for(int i=2;i<100;i++)
    {
        if (strcmp(words[i],"Empty")!=0)
        {
            num = num + 1;
            strcat(temp, words[i]);
            if (strcmp(words[i+1],"Empty")!=0)
            {
                strcat(temp, " ");
            }
            else
            {
                strcat(temp, "");
            }
        }
        else{ break;}
    }
    if(num == 0)
    {
        return 0;
    }
    else
    {
        int a = found(words);
        if(a != -1)
        {
            x=x+0;
            (ptr[a]).var = strdup(words[1]);
            (ptr[a]).value = strdup(temp);
//            printf("Value of variable '%s' updated\n", (ptr[a]).var);
        }
        else
        {
            x=x+1;
            (ptr[x]).var = strdup(words[1]);
            (ptr[x]).value = strdup(temp);
//            printf("Variable '%s' with value '%s' created and stored in memory\n", (ptr[x]).var, (ptr[x]).value);
        }
        return 0;
    }
}

int shellmemoryPrint(char *words[])
{
    int b = found(words);
    if(b != -1)
    {
        printf("%s\n", (ptr[b]).value);
    }
    else
    {
        printf("Variable does not exist\n");
    }
    return 0;
}
