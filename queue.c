#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid, qnum;
    if (argc <2)
        printf(0, "usage: queue <pid> <queue_number>");
    pid = atoi(argv[1]);
    qnum = atoi(argv[2]);
    if ((queue(pid, qnum)) == 0)
        printf(0, "pid %d moved to queue %d\n", pid, qnum);
    else
        printf(0, "failed\n");
    exit();
}