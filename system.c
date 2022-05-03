#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

#define LOCKFILE "lock"
#define STRFILE "str.txt"
int main(){
    char pans = '5'; // flag part

    int bufsize[7] = {25, 26, 27, 28, 29, 30, 40};
    // int bufsize[] = {40};
    int filelen = 1099;

    // read file
    int fd;
    int ret;

    int result = 0;
    int ans = 0;
    int times = sizeof(bufsize)/sizeof(int);
    int time = 7; // obfuscate
    char res[10] = "kalibotboy"; // flag part

    while(times--){
        result = 0;
        ans =0;
        
        fd = open(STRFILE, O_RDWR); // open file
        ret = flock(fd, LOCK_EX); // lock file
        
        int file_len = (int)lseek(fd,0,SEEK_END);//get file total size

        lseek(fd,0,SEEK_SET);
        char allfile[2000];
        read(fd,allfile,file_len);

        
        char stringA[100];
        char stringB[100];
        char another[2000];

        int len = bufsize[times];

        strncpy(stringA, allfile, len);
        strncpy(stringB, &allfile[len], len);
        strncpy(another, &allfile[len*2], file_len-(2*len));

        strcat(another, stringA);
        strcat(another, stringB);


        lseek(fd,0,SEEK_SET);
        write(fd,another,file_len);//file write
        flock(fd,LOCK_UN);
        close(fd);

        // printf("%s\n%s\n",stringA, stringB);

        char command[100] = "./lcsqs ";
        strcat(command, stringA);
        strcat(command, " ");
        strcat(command, stringB);
        result = system(command);
        result /= 256;
        fflush(stdout); 
        printf("%s\n%s\n",stringA, stringB);
        fflush(stdout); 

        scanf("%d",&ans);
        if(result != ans){ // answer fault
            if(time == 7){ // obfuscate
                int tome = time +9;
            }
            printf("you ");
            fflush(stdout); 
            printf("are ");
            fflush(stdout); 
            printf("wrong!\n");
            fflush(stdout); 
            exit(0);
        }
        else{
            res[times] = 'l';
            if(time == 7){ // obfuscate
                int tome = time +9;
            }
        }
    }
    char f3[6] = "9zzZi1";
    // print the flag

    printf("Bingo! Please write something you want to talk to organizer:");
    fflush(stdout); 
    char final[10000];
    scanf("%s",final);
    printf("Thanks!The flag is ");
    fflush(stdout); 
    printf("MACDX{hello_world_123654_fffffft}");
    fflush(stdout); 
    // if( 1 == 1){
    //     printf("%c",pans);
    // }
    // printf("%s",res);
    // printf("hiv");
    // printf("%s\n",f3);
    
    
    return 0;
}