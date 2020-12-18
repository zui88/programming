#include <unistd.h> // fork(), ...
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {


//>>>>>>>>>>>> fork <<<<<<<<<<<<<
  pid_t pid = fork();
  if ((int) pid == -1){
    return -1;
  }
  else if (!pid){
    /* child */
    /* array of constant pointers of type char (non constant) */
    // gut, wenn mehrmals gebraucht
    char * const args[] = {"/home/zui/ShellScripts/daemon/hellod.a", (char*)NULL};
    int ret;
    ret = execv("./hellod.a", args);
    if (ret == -1) {
      exit(EXIT_FAILURE);
    }
  } else {
    /* father */
    int state;
    // auf kind warten
    wait(&state);
    exit (WIFEXITED(state));
  }


}
