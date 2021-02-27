#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

struct pstat {
  int inuse;    // 1 if this slot of the process is in use, 0 otherwise
  int tickets;  // Number of tickets this process has
  int pid;      // PID of the process
  int ticks;    // Number of tickets the process has accumulated
  int stride;   // Stride value of process
  int pass;     // Number of strides the process has accumulated
};

#endif // _PSTAT_H_
