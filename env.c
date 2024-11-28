#include <stdio.h>

void ft_exec_env(char **env) {
    if (!env || !*env) {
        ft_putstr_fd("env: no environment variables found\n", 2);
        return;
    }
    while (*env) {
       ft_putstr_fd(*env, 1);
       ft_putstr_fd("\n", 1);
        env++;
    }
}
