//#include "structure_minishell.h"


/*
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
*/
/*int main(int argc, char *argv[], char *envp[])
{
	char **test;
	int index = 0;
	while (envp[index])
		index++;
	test= malloc (sizeof(char *) * index);
	index = 0;
	while (envp[index])
	{
		test[index] = malloc(sizeof(char) * strlen(envp[index]));
		strcpy(test[index], envp[index]);
		index++;
	}
	test[index] = envp[index];
	index = 0;
	while(test[index])
	{
		//printf("%s\n", test[index]);
		free(test[index]);
		//test[index] = NULL;
		index++;
	}
	free(test);
}
*/


//MODIFIER LES VARIABLES SI ELLES EXISTENT DEJA TODO SUR EXPORT



