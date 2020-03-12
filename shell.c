#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exit(int status);

int parse(char ui[])
{
    int a,b;
    int w=0; // wordsIdx
    char tmp[200];
    char *words[100];
    for(a=0; ui[a]==' ' && a<1000; a++); // skip white spaces
    while(ui[a] != '\0' && a<1000) {
    for(b=0; ui[a]!='\0' && ui[a]!=' ' && ui[a]!='\n' && ui[a]!='\r' && a<1000; a++, b++)
        tmp[b] = ui[a]; // extract a word
    tmp[b] = '\0';
    words[w] = strdup(tmp);
    a++;
    w++;
   }
   if(w<99)
   {
    for(int j=w;j<100;j++)
    {
        words[w] = strdup("Empty");
    }
   }
   return interpreter(words); // assumes: cmd switches args
}

int main()
{
    printf("Welcome to the Srijak shell!\n");
    printf("Version 1.0 Created January 2020\n");
    char prompt[100] = {'$','\0'}; // prompts can be modified
    char userInput[1000];
    int errorCode = 0;
    initial();

    while(1) {
        printf("%s ",prompt);
        fgets(userInput, 1000, stdin);
        errorCode = parse(userInput);
        if (errorCode == -1)
            exit(-1);
    }
    return 0;
}
