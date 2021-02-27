#include "user.h"

int main() {
  struct pstat pstats[NPROC];

  getpinfo(pstats);

  printf(1, "PID\tTickets\tTicks\tStride\tPass\n");
  for (struct pstat *p = pstats; p < &pstats[NPROC]; p++) {
    if (p->inuse)
      printf(1, "%d\t%d\t%d\t%d\t%d\n", p->pid, p->tickets, p->ticks, p->stride, p->pass);
  }

  exit();
}
