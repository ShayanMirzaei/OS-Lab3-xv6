#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    long q = 0;
    setbjfs(10, 5, 20);
    int pid1 = fork();
    if (pid1 == 0) {
        queue(getpid(), 3);
        for (long i = 0; i < 5000000000; i++) {
            q += i;
            q -= i;
        }
    }
    else {
        int pid2 = fork();
        if (pid2 == 0) {
            queue(getpid(), 3);
            for (long i = 0; i < 5000000000; i++) {
                q += i;
                q -= i;
            }
        }
        else {
            queue(getpid(), 3);
            for (long i = 0; i < 5000000000; i++) {
                q += i;
                q -= i;
            }
        }
    }

    exit();
}