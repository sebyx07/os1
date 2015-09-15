#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()

{
char *buf;
rl_bind_key('\t',rl_abort);//disable auto-complete
while((buf = readline("$: "))!=NULL)

{

if (strcmp(buf,"exit")==0 || strcmp(buf, "Exit")==0)
	break;
	printf(" %s \n", buf);

if (buf[0]!=0)

add_history(buf);
}

free(buf);
return 0;

}
