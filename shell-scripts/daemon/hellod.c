#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (){
  //>>>>>>>>>>>>> setsid <<<<<<<<<<<<<<
  /* deamon things to do */
  /* creat a new session and process group */
  if (setsid () == -1){
    perror("setsid call");
    exit(2);
  }


  //>>>>>>>>>>>>> chngen dier <<<<<<<<<<<<<<
  /* set the working directory */
  if(chdir (".") == -1){
    perror("chdir call");
    exit(3);
  }


  /* close all open files--NR_OPEN is overkill, but works */
  /* int i; */
  /* for (i = 0; i < NR_OPEN; i++) */
  /*   close (i); */


  //>>>>>>>>>>> set umask <<<<<<<<<<<<
  umask(0);


  //>>>>>>>>>>> close stdio /stderr <<<<<<<<<<<<<<
  close(0); close(1); close(2);


  //>>>>>>>>>>> open file <<<<<<<<<<<<<<<<<
  /* create file (override, if exists one) an write */
  int fd = creat ("hello.txt", 0644);
  if (fd == -1) exit (-1);
  char const * const buf = "hello from daemon\n";


  //>>>>>>>>>>>>> write file <<<<<<<<<<<<<<
  while(1){
    ssize_t wd = write (fd, buf, strlen (buf));
    if (wd == -1) exit (-1);
  }
  return 0;
}
