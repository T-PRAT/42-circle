/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:44:55 by tprat             #+#    #+#             */
/*   Updated: 2021/06/22 16:14:17 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

typedef struct s_philo
{
	int				num;
	pthread_t		ptid;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	struct s_params	*params;
}				t_philo;

typedef struct s_params
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	char			*fork;
	t_philo			*philo;
	pthread_mutex_t	mutex;
}			t_params;

void	ft_putstr_fd(char *s, int fd);
void	ft_error(char *str, t_params *params);
int		ft_atoi(const char *str);
int		is_num(char *str);
void	start_philos(t_params *params);
#endif
