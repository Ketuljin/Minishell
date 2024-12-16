/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerthe <jkerthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:04:13 by jkerthe           #+#    #+#             */
/*   Updated: 2024/12/16 18:36:47 by jkerthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    **ft_check(t_command *command, char **env)
{
    if (!is_pipe(command))
    {
        if (check_builtin(command->first->content))
            env = exec_builtin(command, env);
        else
            ft_execve(command, env);
    }
    else
    {
        
    }
}