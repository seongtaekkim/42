/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 08:58:45 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 13:58:25 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "shell_bonus.h"

char	**g_envp;

void	handler(int sig)
{
	(void) sig;
	s_write(STDOUT_FILENO, "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static char	**copy_envp(char **envp)
{
	const int	size = ft_strlen2((const char **)envp);
	int			i;
	char		**dest;

	i = 0;
	s_malloc((void **)&dest, sizeof(char *) * (size + 1));
	while (size > i)
	{
		*(dest + i) = ft_strdup(*(envp + i));
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}

static void	set_tc_attr(struct termios *term)
{
	tcgetattr(STDIN_FILENO, term);
	term->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, term);
}

void	do_process(t_lexer *lexer, t_astree **ast, int *exit_code)
{
	if (lexer->syntex_error == -2)
	{
		free_token(lexer->token);
		s_write(1, "\n");
	}
	else if (lexer->syntex_error == -1 || lexer->parentheses != 0)
	{
		free_token(lexer->token);
		s_write(1, "syntex error\n");
	}
	else
	{
		parse(lexer, ast);
		if (*ast)
			execute(*ast, exit_code);
		delete_node_ast(*ast);
		free_token(lexer->token);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	char			*str;
	t_lexer			lexer;
	t_astree		*astree;
	struct termios	term;
	int				exit_code;

	(void) argc;
	(void) argv;
	set_tc_attr(&term);
	signal(SIGQUIT, SIG_IGN);
	g_envp = copy_envp(envp);
	exit_code = 0;
	while (1)
	{
		delete_tempfile();
		signal(SIGINT, handler);
		str = readline("minishell$ ");
		add_history(str);
		if (!str)
			exit(0);
		do_lexer(str, &lexer, &exit_code);
		lexer_valid(&lexer);
		do_process(&lexer, &astree, &exit_code);
	}
	return (0);
}
