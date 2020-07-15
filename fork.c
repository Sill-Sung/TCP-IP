#include <stdio.h>
#include <unistd.h>

int gval = 10;
int main(int argc, char* argv[]){
        pid_t pid;

        int lval = 20;
        gval++, lval+=5;

        pid = fork();               // fail = -1, Parent = new PID, Child = 0

        if(pid == 0)                // Child Process
                gval+=2, lval+=2;
        else                        // Parent Process
                gval-=2, lval-=2;

        if(pid == 0)                // Child Process
                printf("Child Process : [%d, %d] \n", gval, lval);
        else                        // Parent Process
                printf("Parent Process : [%d, %d]\n", gval, lval);

        return 0;
}
