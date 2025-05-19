#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
    char c;
    int i;
} Message;

Message g_msg;

void	bit_handler_0(int signum)
{
	if (signum == SIGUSR1)
	{
		g_msg.c += (0 << g_msg.i);
		g_msg.i++;
	}
	if (g_msg.i == 8)
	{
		printf("%c", g_msg.c);
		if (!g_msg.c)
			printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

void	bit_handler_1(int signum)
{
	if (signum == SIGUSR2)
	{
		g_msg.c += (1 << g_msg.i);
		g_msg.i++;
	}
	if (g_msg.i == 8)
	{
		printf("%c", g_msg.c);
		if (!g_msg.c)
			printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int	main(void)
{
	printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, bit_handler_0);
		signal(SIGUSR2, bit_handler_1);
		pause();
	}
	return (0);
}
