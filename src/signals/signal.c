#include "minishell.h"

volatile sig_atomic_t	g_signal_status = 0;


void	disable_echoctl(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL; // turn off echoing of ctrl c 
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void handle_sigint_prompt(int signum)
{
    (void)signum;
    g_signal_status = 1;
    write(STDOUT_FILENO, "\n", 1);
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
}

void setup_signals_prompt(void)
{
    struct sigaction sa_int;
    struct sigaction sa_quit;

    disable_echoctl();  

    sa_int.sa_handler = handle_sigint_prompt;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = SA_RESTART;

    sa_quit.sa_handler = SIG_IGN;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = SA_RESTART;

    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGQUIT, &sa_quit, NULL);
}

void	setup_signals_child(void)
{
	struct sigaction sa;
	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void setup_signals_parent(void)
{
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
