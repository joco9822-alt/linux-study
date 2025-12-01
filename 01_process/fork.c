#include <stdio.h>      
#include <unistd.h>     // Linux System Call: fork(), getpid(), getppid() 
#include <sys/types.h>  // Type: pid_t 

int main() {
    printf("1. [부모] 자식을 낳기 전입니다.\n");

    pid_t pid = fork(); // 분기점

    if (pid == 0) {
        // 자식 프로세스
        printf("2. [자식] 응애! 내 PID: %d, 부모 PID: %d\n", getpid(), getppid());
    } else {
        // 부모 프로세스
        printf("3. [부모] 자식(PID: %d)을 낳았습니다.\n", pid);
    }
    return 0;
}
