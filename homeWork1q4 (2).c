#include <stdio.h>
#include <sys/resource.h>

int main() {
  struct rlimit r1, r2, r3;

  getrlimit(RLIMIT_CPU, &r1);
  getrlimit(RLIMIT_STACK, &r2);
  getrlimit(RLIMIT_NOFILE, &r3);

  printf("Maximum Stack Size: %ld\n", r2.rlim_max);
  printf("Maximum Number of File Descriptors: %ld\n", r3.rlim_max);

  // Check if the resource is defined
  if (getrlimit(RLIMIT_AS, &r1) == 0) {
    printf("Maximum Address Space: %ld\n", r1.rlim_max);
  }

  if (getrlimit(RLIMIT_NPROC, &r2) == 0) {
    printf("Maximum Number of Processes: %ld\n", r2.rlim_max);
  }

  if (getrlimit(RLIMIT_MEMLOCK, &r3) == 0) {
    printf("Maximum Memory Lock: %ld\n", r3.rlim_max);
  }

  return 0;
}