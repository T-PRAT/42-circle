/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:48:38 by tprat             #+#    #+#             */
/*   Updated: 2021/08/26 16:54:46 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

typedef struct s_ms
{
	char			**env;
	char			**path;
	struct s_tok	*tok;
}				t_ms;

typedef struct s_tok
{
	char			*cont;
	struct s_tok	*prev;
	struct s_tok	*next;
}				t_tok;

t_tok	*parse_line(char *line);
void	ft_echo(char *str, char opt);
void	ft_cd(char *path);
void	ft_pwd(char **env);
t_tok	*create_lst(char *cont);

#endif
