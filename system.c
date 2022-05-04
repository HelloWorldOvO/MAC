#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <time.h>

#define LOCKFILE "lock"
#define STRFILE "str.txt"
int main(){

    // int bufsize[7] = {40, 26, 27, 28, 29, 30, 40};
    // int bufsize[] = {40};
    int filelen = 1099;

    // read file
    int fd;
    int ret;

    int result = 0;
    int ans = 0;
    // int times = sizeof(bufsize)/sizeof(int);
    int times = 7;
    int seed = times; // random seed

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
        
        srand(seed);
        seed = rand();
        seed %= 23;
        seed += 27;

        // printf("seed=%d\n",seed);
        // fflush(stdout); 
        // bufsize[times] = seed;

        // int len = bufsize[times];
        int len = seed;
        // printf("len=%d\n",len);
        // fflush(stdout); 


        strncpy(stringA, allfile, len);
        strncpy(stringB, &allfile[len], len);
        strncpy(another, &allfile[len*2], file_len-(2*len));

        strcat(another, stringA);
        strcat(another, stringB);

        int i;
        for(i=strlen(stringA);i>=len;i--){
            stringA[i] = '\0';
        }
        for(i=strlen(stringB);i>=len;i--){
            stringB[i] = '\0';
        }


        lseek(fd,0,SEEK_SET);
        write(fd,another,file_len);//file write
        flock(fd,LOCK_UN);
        close(fd);

        // printf("%s\n%s\n",stringA, stringB);

        char command[100] = "./lcsqs ";
        strcat(command, stringA);
        strcat(command, " ");
        strcat(command, stringB);

        // printf("command=%s\n", command);
        // fflush(stdout); 

        result = system(command);
        result /= 256;
        printf("%s\n%s\n",stringA, stringB);
        fflush(stdout); 
        printf("input lcsqs:");
        fflush(stdout); 

        scanf("%d",&ans);
        seed = ans;
        
        if(result != ans){ // answer fault
            printf("you ");
            fflush(stdout); 
            printf("are ");
            fflush(stdout); 
            printf("wrong!\n");
            fflush(stdout); 
            exit(0);
        }
    }
    // print the flag

    printf("Bingo! Please write something you want to talk to organizer:");
    fflush(stdout); 
    char final[10000];
    scanf("%s",final);
    printf("Thanks!The flag is ");
    fflush(stdout); 
    printf("MACDX{Algorithm_Lcsqs_game_30}");
    fflush(stdout); 
    
    
    return 0;
}