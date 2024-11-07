/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:34 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/07 03:18:11 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think_process(t_philo *philo)
{
	printf("[PHILO][%ld][%d] is thinking\n", get_time(), philo->id);
	usleep(philo->data->time_to_sleep * 1000);
}

static void	eat_process(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	printf("[PHILO][%ld][%d] has taken a fork\n", get_time(), philo->id);
	printf("[PHILO][%ld][%d] has taken a fork\n", get_time(), philo->id);
	philo->last_meal = get_time();
	philo->last_meal++;
	printf("[PHILO][%ld][%d] is eating\n", get_time(), philo->id);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
}

static void	sleep_process(t_philo *philo)
{
	if (is_end(philo))
		return ;
	printf("[PHILO][%ld][%d] is eating\n", get_time(), philo->id);
	usleep(philo->data->time_to_sleep * 1000);
}

void	*process_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		wait_simulation(philo);
		if (is_end(philo))
			break ;
		think_process(philo);
		eat_process(philo);
		sleep_process(philo);
	}
	return (NULL);
}
