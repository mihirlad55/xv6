#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int getpid_count = getpidcount();
  int pid = getpid();
  printf(1, "The PID of this process is %d\n", pid);
  printf(1, "getpid was called %d times\n", getpid_count);
  exit();
}
