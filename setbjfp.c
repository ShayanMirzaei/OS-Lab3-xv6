#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int pid, cratio, aratio, pratio;
    if (argc < 4)
        printf(0, "usage: setbjfp <pid> <cycles_ratio> <arrival_ratio> <priority_ratio>\n");

    pid = atoi(argv[1]);
    cratio = atoi(argv[2]);
    aratio = atoi(argv[3]);
    pratio = atoi(argv[4]);

    setbjfp(pid, cratio, aratio, pratio);
    exit();
}