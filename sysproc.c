#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_queue(void)
{
    int pid, qnum;

    if(argint(0, &pid) < 0)
        return -1;
    if(argint(1, &qnum) < 0)
        return -1;

    if (qnum < 1 || qnum > 3)
        return -1;
    return queue(pid, qnum);
}

int
sys_setbjfp(void)
{
    int pid, cratio, aratio, pratio;

    if(argint(0, &pid) < 0)
        return -1;
    if(argint(1, &cratio) < 0)
        return -1;
    if(argint(2, &aratio) < 0)
        return -1;
    if(argint(3, &pratio) < 0)
        return -1;

    return setbjfp(pid, cratio, aratio, pratio);
}

int
sys_setbjfs(void)
{
    int cratio, aratio, pratio;

    if(argint(0, &cratio) < 0)
        return -1;
    if(argint(1, &aratio) < 0)
        return -1;
    if(argint(2, &pratio) < 0)
        return -1;

    return setbjfs(cratio, aratio, pratio);
}

void sys_printqinfo(void)
{
    printqinfo();
}

