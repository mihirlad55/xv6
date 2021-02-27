#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"
#include "pstat.h"

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
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
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
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/**
 * Set the calling process's number of tickets
 *
 * @return 0 on success, -1 otherwise
 */
int sys_settickets(void)
{
  int num;

  // Get number of tickets argument
  if (argint(0, &num) < 0)
    return -1;

  // Assign tickets
  return assigntickets(num);
}

/**
 * Get process info for all processes.
 *
 * @return 0 on success, -1 otherwise
 */
int sys_getpinfo(void)
{
  // Array of pstat
  struct pstat *pstats;

  // Get pointer to array of pstat structs
  argptr(0, (char**)&pstats, NPROC * sizeof(struct pstat));

  // Make sure it is not a null pointer
  if (pstats == NULL)
    return -1;

  // Populate pstats
  getpinfo(pstats);

  return 0;
}
