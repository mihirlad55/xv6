#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int syscall_count = syscallcount();
  printf(1, "%d syscalls were called\n", syscall_count);
  exit();
}
