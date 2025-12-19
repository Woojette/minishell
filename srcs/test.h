#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct minis
{
	char	**res;
	char	*line;
	char	**env;
	int		exit_status;
}	t_minis;

// fonctions
size_t		ft_strlen(const char *str);
char		*ft_strdup(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int		 	ft_toupper(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_bzero(void *s, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_isdigit(int c);

// builtin
void		ft_echo_all(char **tab);  ////// 
int	  		ft_echo_option_n(char *str);

void		ft_env(char **env); /////

int			ft_export_all(char **tab, char ***env); /////
int			ft_check_env_egal(char *str);
int			ft_check_env_double(char *str, char **env);
int			ft_export_sans_double(char *str, char ***env);
int			ft_export_double(char *str, char ***env);
int			ft_export(char *str, char ***env);

int			ft_unset_all(char **tab, char ***env); ////
int			ft_unset(char *str, char ***env);
void		ft_unset_init_int_zero(int *j, int *supprime, int *taille);

int			ft_pwd(void); ////

int			ft_cd_all(char **tab, char ***env); ////
char		 *ft_cd_val_env(char *str, char ***env);
int			ft_cd_sans_av(char **val, char **path, char *str, char ***env);
int			ft_cd_tiret(char **oldpwd, char **path, char ***env);
int			ft_cd_env_update(char **oldpwd, char **pwd, char ***env);

int			ft_exit(char **tab, t_minis **mini);
int			ft_exit_check_not_int(char *str);
long long	ft_exit_atoi_long(const char *str, int *error);
void		ft_exit_sans_arg(int *exit_temp, t_minis *mini);
void		ft_exit_normal_arg(char *str, t_minis **mini);
void		ft_exit_pl_arg(int *exit_temp, t_minis **mini);
void	ft_exit_wrong_arg(int *exit_temp, char *str, t_minis **mini);

#endif

// power leveling
// echo "-n" "hola" | cd .. | cat -e



// echo
// "hola"
// |
// cd
// ..
// |
// cat
// -e


// **tab = "echo" "hola"
// tab[0] = "echo"
// tab[1] = "hola"
// "cd" ".."
