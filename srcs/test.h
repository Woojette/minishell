#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// fonctions
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int	  ft_toupper(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// built-in
void	ft_echo_all(char **tab);
int	  ft_echo_option_n(char *str);
// void	ft_echo(char *str);
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
