#ifndef MINISHELL_H
# define MINISHELL_H

# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_mini
{
	char			*cmd;
	char			*redir;
	char			*arg;
	int				arg_index;
	int				exit_status;
	t_parse			parse;
	struct s_mini	*next;
}	t_mini;

typedef enum s_state
{
	DQUOTES,
	SQUOTES,
	GENERAL,
}	t_state;

typedef struct s_parse
{
	char			*val;
	t_state			state;
	struct s_parse	*next;
}	t_parse;

// typedef struct minis
// {
// 	char	**res;
// 	char	*line;
// 	char	**env;
// 	int		exit_status;
// }	t_minis;

void	ft_echo(char *str, int option_n);
void	ft_env(char **env);
int		ft_export_all(char **tab, char ***env);
int		ft_check_env_egal(char *str);
int		ft_check_env_double(char *str, char **env);
int		ft_export_sans_double(char *str, char ***env);
int		ft_export_double(char *str, char ***env);
int		ft_export(char *str, char ***env);
int		ft_unset_all(char **tab, char ***env);
int		ft_unset(char *str, char ***env);
void	ft_unset_init_int_zero(int *j, int *supprime, int *taille);
int		ft_pwd(void);

#endif