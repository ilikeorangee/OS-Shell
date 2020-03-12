#include <stdio.h>
#include <string.h>

int check = 0;

int help(char *words[])
{
    printf("\n");
    printf("COMMAND\t\t\t\t\tDESCRIPTION\n\n");
    printf("help\t\t\t\t\tDisplays all the commands\n");
    printf("quit\t\t\t\t\tExits / terminates the shell with “Bye!”\n");
    printf("set VAR STRING\t\t\t\tAssigns a value to shell memory\n");
    printf("print VAR\t\t\t\tDisplays the STRING assigned to VAR\n");
    printf("run SCRIPT.TXT\t\t\t\tExecutes the file SCRIPT.TXT\n");
    printf("\n");
    return 0;
}

int quit(char *words[])
{
    if(check == 0)
    {
        printf("Bye!\n");
        shellFree();
        return -1;
    }
    else
    {
        printf("Bye!\n");
    }
}

int set(char *words[])
{
    return shellmemorySet(words);
}

int print(char *words[])
{
    return shellmemoryPrint(words);
}

int run(char *words[])
{
    int errCode = 0;
    char line[1000];
    FILE* p = fopen(words[1], "rt");
    if (! p ) // equivalent to saying if ( p == NULL )
    {
        printf("Script not found\n");
        return 0;
    }
    fgets(line,999,p);
    while(!feof(p)) {
        check = 1;
        errCode=parse(line);
        if (errCode != 0)
        {
            fclose(p);
            check = 0;
            return errCode;
        }
        fgets(line,999,p);
    }
    fclose(p);
    check = 0;
    return errCode;
}

int interpreter(char *words[])
{
    int errorCode = 0;
    if(strcmp(words[0],"help")==0)
    {
        errorCode = help(words);
    }
    else if (strcmp(words[0],"quit")==0)
    {
        errorCode = quit(words);
    }
    else if (strcmp(words[0],"set")==0)
    {
        errorCode = set(words);
    }
    else if (strcmp(words[0],"print")==0)
    {
        errorCode = print(words);
    }
    else if (strcmp(words[0],"run")==0)
    {
        errorCode = run(words);
    }
    else
    {
        printf("Unknown command\n");
    }

    return errorCode;
}