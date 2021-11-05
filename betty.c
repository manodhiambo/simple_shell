#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - get parent processing id
 * Return: always 0
 */
int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
		return (0);
}
