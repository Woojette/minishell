#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
void	ft_echo(char *str, int option_n);
void	ft_env(char **env);
int		ft_export(char *str, char ***env);
int		ft_export_all(char **tab, char ***env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_unset(char *str, char ***env);
int		ft_unset_all(char **tab, char ***env);
int		ft_pwd(void);

#endif
