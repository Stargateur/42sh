/*
** my_aff_signal.c for my_aff_signal in /home/plasko_a/programation/epitech/PSU_2013_42sh
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May 25 12:26:26 2014 Antoine Plaskowski
** Last update Thu May 29 15:32:38 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<signal.h>
#include	"my_signal.h"
#include	"my_str.h"

static t_signal	tab_signal[] =
  {
    {SIGHUP, "Hangup detected on controlling terminal or \
death of controlling process\n"},
    {SIGINT, "Interrupt from keyboard\n"},
    {SIGQUIT, "Quit from keyboard\n"},
    {SIGILL, "Illegal Intruction\n"},
    {SIGABRT, "Abort signal from abort(3)\n"},
    {SIGFPE, "Floating point exception\n"},
    {SIGKILL, "Kill signal\n"},
    {SIGSEGV, "Invalid memory reference\n"},
    {SIGPIPE, "Broken pipe: write to pipe with no readers\n"},
    {SIGALRM, "Timer signal from alarm(2)\n"},
    {SIGTERM, "Termination signal\n"},
    {SIGUSR1, "User-defined signal 1\n"},
    {SIGUSR2, "User-defined signal 2\n"},
    {SIGCHLD, "Child stopped or terminated\n"},
    {SIGCONT, "Continue if stopped\n"},
    {SIGSTOP, "Stop process\n"},
    {SIGTSTP, "Stop typed at terminal\n"},
    {SIGTTIN, "Terminal input for background process\n"},
    {SIGTTOU, "Terminal output for background process\n"},
    {SIGBUS, "Bus error (bad memory access)\n"},
    {SIGPOLL, "Pollable event (Sys V). Synonym for SIGIO\n"},
    {SIGPROF, "Profiling timer expired\n"},
    {SIGSYS, "Bad argument to routine (SVr4)\n"},
    {SIGTRAP, "Trace/breakpoint trap\n"},
    {SIGURG, "Urgent condition on socket (4.2BSD)\n"},
    {SIGVTALRM, "Virtual alarm clock (4.2BSD)\n"},
    {SIGXCPU, "CPU time limit exceeded (4.2BSD)\n"},
    {SIGXFSZ, "File size limit exceeded (4.2BSD)\n"},
    {SIGIOT, "IOT trap. A synonym for SIGABRT\n"},
    {SIGSTKFLT, "Stack fault on coprocessor (unused)\n"},
    {SIGIO, "I/O now possible (4.2BSD)\n"},
    {SIGCLD, "A synonym for SIGCHLD\n"},
    {SIGPWR, "Power failure (System V)\n"},
    {SIGWINCH, "Window resize signal (4.3BSD, Sun)\n"},
    {SIGUNUSED, "Synonymous with SIGSYS\n"},
    {0, NULL}
  };

int		my_aff_signal(int signal)
{
  int		i;

  my_putnbr(signal, 2);
  my_putstr(" : ", 2);
  i = 0;
  while (tab_signal[i].signal != 0)
    {
      if (tab_signal[i].signal == signal)
	return (my_putstr(tab_signal[i].str, 2));
      i++;
    }
  return (my_putstr(" : Process terminal by this signal (unknow)\n", 2));
}
