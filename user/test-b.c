#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  // Get number of times a system call was invoked
  int syscall_count = syscallcount();

  // Print number of syscalls invoked
  printf(1, "%d syscalls were called\n", syscall_count);

  exit();
}
