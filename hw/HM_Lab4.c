#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int Divisor(int n)
{	int i;
  	int us=0;
		for(i=1;i<=n;i++)
			{if(n%i==0)
		 	us++;}
	return us;
}

int main(int argc,char **argv)
{
int i,n,nb=0;
n=atoi(argv[1]);
	for(i=0;i<=n;i++)
		if(fork()==0)
		{ nb=Divisor(i*10);
		  printf("for %d i found %d\n",i,nb);
		break;
		}

for(i=0;i<=n;i++)
	wait(&nb);
return 0;
}