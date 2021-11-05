**Simple_shell**

This a UNIX shell coded from scratch with both interactive mode that allows a user to enter content after (cisfun>> ).

This shell does not allow user login or recognize the computer name once installed since its not intended for commercial use.


**Synopsis**

This repository holds all the code needed to run the shell and also the executable files found in /bin/ls.

**File description**

Shell.c ---------- Contains the main function and other function declarations.

builtin.c --------- Contains all the builtin functions ie: exit, cd.

handler.c ---------- Contains the processes and execution of the programs.

man_3_shell ------- Custom man page.

**Environment**

Language: C
OS: Ubuntu 14.04 LTS
Compiler: gcc 4.8.4
Style guidelines: Betty style

**How to Install, compile and Use**

Install and compile

	(your_terminal)$ git clone git@github.com:Qimae/simple_shell.git
	(your_terminal)$ cd simple_shell
	(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o shell

Non_interactive mode

	echo "ls -l" | ./shell

Interactive Mode

	(your_terminal)$ ./shell
	cisfun>> 

**Usage**

        ********** Welcome to Our New custom C-Shell **********

                ********** Made for ALX Kenya **********

	cisfun>> ls -l

	total 36

	-rw-r--r-- 1 qimae qimae  1825 Nov  5 12:01 builtin.c

	-rw-r--r-- 1 qimae qimae  1807 Nov  5 11:48 handler.c

	-rwxr-xr-x 1 qimae qimae 17920 Nov  5 12:01 shell

	-rw-r--r-- 1 qimae qimae   401 Nov  2 12:59 shell.c

	-rw-r--r-- 1 qimae qimae   471 Nov  2 17:25 shell.h

	cisfun>> echo c programming is cool

	c programming is cool

	cisfun>> 


**Authors**

Kimae Ngowa.

Kevin Odhiambo.
