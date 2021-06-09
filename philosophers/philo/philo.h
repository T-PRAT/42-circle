/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:44:55 by tprat             #+#    #+#             */
/*   Updated: 2021/06/09 17:22:04 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_thread_info
{
	pthread_t	thread_id;
	int			thread_num;
	char		*argv_string;
}				t_thread_info;

typedef struct s_params
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_eat;
}				t_params;

void	ft_putstr_fd(char *s, int fd);
void	ft_error(char *str);
int		ft_atoi(const char *str);
int		is_num(char *str);
void	start_philos(t_params *params);
#endif
