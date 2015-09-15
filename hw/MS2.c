#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


void  parse(char *line, char **argv){


     while (*line != '\0') {
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0'; 
          *argv++ = line;
          while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n') 
               line++;
     }
     *argv = '\0';  

}
int main()
{

char *buf;
rl_bind_key('\t',rl_abort);//disable auto-complete
while((buf = readline("$ "))!=NULL)

{

if (strcmp(buf,"exit")==0 || strcmp(buf, "Exit")==0)
	break;
	//printf(" %s \n", buf);


char *argv[100];



parse(buf, argv);


pid_t pid,a;
int s;
pid=fork();

if(pid > 0) { //parrent
	a = wait(&s);
	}
else { //child
	execvp(*argv, argv);
	printf("Error");
	break;
	}



if (buf[0]!=0)

add_history(buf);
}

free(buf);
return 0;

}


