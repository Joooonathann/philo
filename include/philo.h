/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:44:59 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/19 14:17:06 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PH_MAX 410

typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;

typedef struct s_data
{
	long				ph_total;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				meals_total;
	long				started_time;
	int					is_end;
	int					is_ready;
	pthread_mutex_t		mtx_set;
	pthread_mutex_t		mtx_get;
	pthread_mutex_t		mtx_write;
	t_fork				*forks;
	t_philo				*philos;
	pthread_t			monitor;
}						t_data;

typedef struct s_fork
{
	int					id;
	pthread_mutex_t		fork;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				last_meal;
	long				meals_total;
	int					is_dead;
	pthread_t			philo;
	t_fork				*left_fork;
	t_fork				*right_fork;
	t_data				*data;
}						t_philo;

int						get_data_numbers(int argc, char **argv, t_data *data);
bool					whitespace(char c);
bool					is_digit(char c);
long					ft_atol(const char *s);
long					get_time(void);
int						init_simulation(t_data *data);
void					*process_philo(void *arg);
int						start_simulation(t_data *data);
void					*process_philo(void *arg);
void					*is_end(void *arg);
void					write_status(t_philo *philo, char *status);
void					clean_simulation(t_data *data);
void					free_simulation(t_data *data);
int						get_value(int *value, t_data *data);
void					set_value(int *value, int new, t_data *data);
void					set_time(long *value, long new, t_data *data);

#endif