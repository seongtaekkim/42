/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouswong <nouswong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 09:13:41 by seongtki          #+#    #+#             */
/*   Updated: 2023/01/03 14:02:14 by nouswong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_BONUS_H
# define SHELL_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <sys/stat.h>
# include "./libft/libft.h"

extern char	**g_envp;

# define EXITVALID 0
# define EXITGENERAL 1
# define EXITMISUSEBUILTIN 2
# define EXITCANNOTEXECUTE 126
# define EXITNOTFOUND 127
# define SIGNALOFFSET 128

typedef enum s_ast_type {
	AST_TOKEN			= -1,
	AST_PIPE			= 1,
	AST_QUOTE			= 3,
	AST_REDIRECT_IN		= 4,
	AST_REDIRECT_OUT	= 5,
	AST_HEREDOC			= 6,
	AST_APPEND			= 7,
	AST_CMDPATH			= 8,
	AST_ARGUMENT		= 9,
	AST_DATA			= 10,
	AST_AND				= 11,
	AST_OR				= 12,
	AST_PARENTHESES_O	= 13,
	AST_PARENTHESES_C	= 14
}	t_ast_type;

typedef enum s_bool
{
	false,
	true
}	t_bool;

typedef struct s_str
{
	char			c;
	struct s_str	*next;
}	t_str;

typedef struct s_token
{
	int				type;
	t_str			*t_str;
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	t_token	*token;
	int		quote;
	int		parentheses;
	int		type;
	int		syntex_error;
}	t_lexer;

typedef struct s_astree
{
	int				pid;
	int				type;
	int				before_meta;
	int				after_meta;
	int				parentheses;
	t_bool			is_builtin;
	t_bool			is_last;
	char			*data;
	struct s_astree	*left;
	struct s_astree	*right;
	struct s_astree	*subshell;
}	t_astree;

typedef struct s_redir
{
	int				type;
	char			*filename;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	int		seq;
	int		type;
	int		fd[2];
	t_bool	is_builtin;
	t_bool	is_parent;
	t_bool	is_filename;
	t_redir	*redirin;
	t_redir	*redirout;
	int		bak_stdout;
	int		bak_stdin;
	int		bak_stderr;
}	t_cmd;

// lexer
void		do_lexer(char *str, t_lexer *lexer, int *exit_code);
void		append_token_back(t_token **head, t_token *new);
t_token		*create_token(t_str *str);
void		append_str_back(t_str **head, t_str *new);
t_str		*create_str(char c);
void		lex_char(char **str, t_lexer **lexer, t_token **tail);
void		lex_quote(char **str, t_lexer **lexer, t_token **tail);
void		lex_space(char **str, t_lexer **lexer, t_token **tail);
void		lex_pipe_or(char **str, t_lexer **lexer, t_token **tail);
void		lex_in_here(char **str, t_lexer **lexer, t_token **tail);
void		lex_out_append(char **str, t_lexer **lexer, t_token **tail);
void		lex_and(char **str, t_lexer **lexer, t_token **tail);
void		lex_parentheses_open(char **str, t_lexer **lexer, t_token **tail);
void		lex_parentheses_close(char **str, t_lexer **lexer, t_token **tail);
int			get_lexical_type(char c);
void		lexer_valid(t_lexer *lexer);
char		*lex_asterisk(char *str);
char		*dir_to_string(char *wc);
t_bool		is_proper_file(char *wc, char *name);
char		*lex_heredoc(char *str, int *exit_code, t_lexer **lexer, int quote);
char		*create_filename(void);
void		child_heredoc(char *eof, char *filename);
int			waitpid_heredoc(int pid,
				int *exit_code, t_lexer **lexer, char *eof);
//astree
void		attach_node_ast(t_astree *root, t_astree *left, t_astree *right);
void		delete_node_ast(t_astree *ast);
void		set_type_ast(t_astree *ast, t_ast_type type);
void		set_data_ast(t_astree *ast, char *data);
char		*lex_env(char *str, int exit_code);
// paser
int			parse(t_lexer *lexer, t_astree **ast);
t_bool		term(t_token **cursor, int toketype, char **bufferptr);
t_astree	*job(t_token **cursor);
t_astree	*job1(t_token **cursor);
t_astree	*job2(t_token **cursor);
t_astree	*job3(t_token **cursor, int ast_type);
t_astree	*cmd(t_token **cursor);
t_astree	*single_cmd(t_token **cursor);
t_astree	*single_cmd1(t_token **cursor);
t_astree	*arg_list(t_token **cursor);
t_astree	*arg_list1(t_token **cursor);

// excute
void		execute(t_astree *ast, int *exit_code);
void		execute_job(t_astree *ast, t_cmd *cmd_line, int *exit_code);
char		**parse_envp(char *target);
int			exit_print(char *str, t_bool is_parent);
void		exit_not_found(char *str);
char		**make_cmd(t_astree *ast);
t_bool		is_exist_file(char *filename);
char		**parse_envp(char *target);
char		*valid_cmd(char *arg_cmd, char **path);
void		find_cmd(char ***cmd_list, t_cmd *cmd_line);
void		set_redirect(t_astree **ast, t_cmd **cmd);
int			open_infile(t_redir *redir, t_bool is_parent);
int			open_outfile(t_redir *redir, t_bool is_parent);
void		delete_tempfile(void);
void		do_waitpid(t_astree *ast, int *exit_code);
void		execute_waitpid_to_status(t_astree *ast, int *exit_status);
void		execute_waitpid(t_astree *ast, int *exit_code, t_cmd *cmd_line);
void		pipe_parent(t_cmd *cmd_line, t_astree *ast, int *local_fd);
void		pipe_child(t_cmd *cmd_line, t_astree *ast, int *local_fd);
void		execute_subshell(t_astree *ast, int *exit_code);
void		execute_pipe(t_astree *ast, t_cmd *cmd_line, int *exit_code);
void		execute_cmd(t_astree *ast, t_cmd *cmd_line, int *exit_code);
void		is_builtin_main(t_cmd *cmd_line, char *cmd);
int			execute_builtin_main_cmd_and_check(t_astree *ast,
				t_cmd *cmd_line, char **cmd, int *exit_code);
void		execute_builtin_sub_cmd(char **cmd, int *exit_code);
t_astree	*last_node(t_astree *node);
t_astree	*select_ast_or_right(t_astree *ast, t_astree *right);

// free
void		free_str(t_str *c);
void		free_token(t_token *token);
void		free2(char **str);
void		free_cmd(t_cmd *cmd);
void		free_redir(t_redir *redir);
int			file_free(char *filename);
//common
void		s_malloc(void **ptr, size_t size);
void		s_write(int fd, char *buf);
void		s_writeln(int fd, char *buf);
void		reverse_str(char *str);
void		handler(int sig);

// built_in
//ft_cd
int			no_operand(void);
void		ft_cd(char **path, int *exit_code);
void		ft_cd_exit(char **path, int *exit_code);
//ft_pwd
void		ft_pwd(char **cmd, int *exit_code);
void		ft_pwd_exit(char **cmd, int *exit_code);
//ft_echo
int			n_flag_check(char *flag_string);
void		ft_echo(char **string, int *exit_code);
void		ft_echo_exit(char **string, int *exit_code);
//ft_env
void		ft_env(char **argument, int *exit_code);
void		ft_env_exit(char **argument, int *exit_code);
//ft_exit
int			is_numeric(char **argument);
void		ft_exit(char **argument, int *exit_code);
void		ft_exit_exit(char **argument, int *exit_code);
//ft_export_util
int			ft_find_string(char *argument);
char		**copy_envp_export(char **argument, int add_size);
void		show_env_export(void);
int			check_argument(char **argument, int max_argument, int *flag);
int			check_argument_util(int index, char **argument, int target_index);
//ft_export
void		ft_export_exit(char **argument, int *exit_code);
void		ft_export(char **argument, int *exit_code);
void		ft_export_util(char ***argument, int *index, \
				int *skip, int **exit_code);
int			ft_find(char *argument, int c);
void		move_one(char ***argument, int temp);
//ft_unset
void		ft_unset_exit(char **argument, int *exit_code);
void		ft_unset(char **argument, int *exit_code);
// built_in_util
char		*get_envp(const char *path);
void		cd_err_print(int flag, char *path);
void		s_free(char *target);

#endif
