#include "user.h"

int main() {
  for (int i = 1; i < 5; i++) {
    int rc = fork();
    if (rc == 0) {
      settickets(i * 10);
      for (;;)
        ;
    }
  }

  exit();
}
