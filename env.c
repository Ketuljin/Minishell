#include <stdio.h>
//Voire pour créer une structure quie stockera toutes les informations de env (en utilisant le meme procédé que pour l'afficher)
void ft_env(char **envp) {
    if (!envp || !*envp) {
        fprintf(stderr, "env: no environment variables found\n");
        return;
    }
    while (*envp) {
        printf("%s\n", *envp);
        envp++;
    }
}
