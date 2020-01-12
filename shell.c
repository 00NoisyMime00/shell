#include<stdio.h>
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/wait.h>
#include<sys/types.h>
#include <string.h>



int main(){
    pid_t cpid;

    

    char status[] = "running";
    char s[100];
    int historyCount = 0;
    char history[100][100];

    while(strcmp(status, "running") == 0){
        printf("\033[0;32m");
        printf("shell@");
        printf("\033[0;34m");
        printf("%s", getcwd(s, 100));
        printf("\033[0m");
        printf("$ ");
        char str[80];
        char base[] = "/bin/";
        char flags[][50]={"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
        int countOfQuotes = 0;
        
        gets(str);
        // for history
        if(strcmp(str, "") != 0 && str[0] != ' '){
            for(int i = 0; i < strlen(str); i++){
                history[historyCount][i] = str[i];
            }
            historyCount++;
        }

        // for separating into flags
        int j, cnt;
        j = 0; cnt = 0;
        for(int i = 0; i <= strlen(str); i++){
            if((str[i] == ' ' || str[i] == '\0') && countOfQuotes % 2 == 0){
                if(strcmp(flags[cnt], "") != 0){
                    flags[cnt][j] = '\0';
                    cnt++;
                }
                j = 0;
                
            }
            else{
                if(str[i] == '"'){
                    countOfQuotes ++;
                }
                else{
                    flags[cnt][j] = str[i];
                    j++;
                }
            }
        }
        
        char temp[100];
        int index = 0;

        
        if(strcmp(flags[0], "exit") == 0){
            return 0;
        }
        else if(strcmp(flags[0], "cd") == 0){
            if(strcmp(flags[1], "") == 0){
                chdir("/home/");
            }
            else{
                chdir(flags[1]);
            }
        }
        else if(strcmp(flags[0], "echo") == 0){
            for(int i = 1; i < sizeof(flags)/sizeof(flags[i]); i++){
                if(strcmp(flags[i], "") != 0 && strcmp(flags[i], "-n") != 0){
                    printf("%s ", flags[i]);
                }
            }
            if(strcmp(flags[1], "-n") != 0){
                printf("\n");
            }
        }
        else if(strcmp(flags[0], "pwd") == 0){
            printf("%s\n", getcwd(s, 100));
        }
        else if(strcmp(flags[0], "history") == 0){
            for(int i = 0; i < historyCount; i++){
                printf("%s\n", history[i]);
            }
        }

        else if(strcmp(flags[0], "") != 0){
            if(strcmp(flags[0], "ll") == 0){
                flags[0][0] = 'l';
                flags[0][1] = 's';
                flags[1][0] = '-';
                flags[1][1] = 'l';
            }

            if(fork() == 0){
                strcat(base, flags[0]);
                
                char *args[28];
                args[0] = base;
                
                int count = 1;
                for(int i = 1; i < 28; i++){
                    
                    if(strcmp(flags[i],"") != 0){
                        args[count] = flags[i];
                        count++;
                    }
                }
                args[count] = NULL;
                
                execv(args[0], args);
            }
            else{
                cpid = wait(NULL);
            } 
        }
       
    }
    return 0;
}