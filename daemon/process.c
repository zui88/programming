#include <unistd.h> // fork
#include <stdlib.h>

int main (int args, const char **argv) {
  pid_t pid = fork();
  if ((int) pid == -1)
    return -1;
  else if (!pid){
    /* child */
    /* array of constant pointers of type char (non constant) */
    char * const argse[] = {"hellod.a", NULL};
    int ret;
    ret = execv("/home/zui88/daemon/hellod.a", argse);
    if (ret == -1) {
      exit(EXIT_FAILURE);
    }
  } else {
    /* father */
    exit (EXIT_SUCCESS);
  }
}
