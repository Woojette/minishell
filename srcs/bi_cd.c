#include "minishell.h"

void ft_cd_home_sans_av(char **home, char ***env)
{
  int   j;
  char  *home;

  j = 0;
  home = "HOME=";
  while ((*env)[j] != NULL)
  {
    if (ft_strncmp((*env)[j], home, ft_strlen(home)) == 0)
      *home = ft_strdup((*env)[j] + ft_strlen(home));
    j++;
  }
}

int ft_cd(char *str, char ***env)
{
  char  *oldpwd;
  char  *pwd;
  char  *home;
  char  *path;

  if (str == NULL)
  {
    ft_cd_home_sans_av(&home, env);
    if (home == NULL)
    {
      printf("minishell: cd: HOME not set\n");
      return (-1);
    }
    path = home;
  }
  
}
