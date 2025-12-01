#include <stdio.h>      
#include <stdlib.h>     // sleep() 
#include <unistd.h>     // Linux System Call: fork(), getpid(), getppid() 
#include <sys/types.h>  // Type: pid_t 

int main() {
    printf("1. [부모] 자식을 낳기 전입니다. (10초 대기)\n");

    for(int i = 0; i < 10; i++) {
        printf("%d초\n", i);
	sleep(1);
    } 
    
    pid_t pid = fork(); 
 
    if (pid == 0) {
        // 자식 프로세스
        printf("2. [자식] 응애! 내 PID: %d, 부모 PID: %d\n", getpid(), getppid());
    } else {
        // 부모 프로세스
        printf("3. [부모] 자식(PID: %d)을 낳았습니다.\n", pid);
    }

    sleep(30); 

    return 0;
}

