#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  // Get PID of process
  int pid = getpid();

  // Get total number of getpid calls
  int getpid_count = getpidcount();

  // Print PID of process
  printf(1, "The PID of this process is %d\n", pid);

  // Print number of times getpid was called
  printf(1, "getpid was called %d times\n", getpid_count);
  exit();
}
