/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:44:34 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/14 12:40:16 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think_process(t_philo *philo)
{
	write_status(philo, "is thinking");
}

static void	eat_process(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	write_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->right_fork->fork);
	write_status(philo, "has taken a fork");
	philo->last_meal = get_time();
	philo->meals_total++;
	write_status(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
}

static void	sleep_process(t_philo *philo)
{
	write_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

static int	first_turn(t_data *data)
{
	static int	nbr_p = 0;

	if (nbr_p == data->ph_total)
		return (1);
	else
		nbr_p++;
	return (0);
}

void	*process_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!get_value(&philo->data->is_end, philo->data))
	{
		if (philo->data->ph_total == 1)
		{
			write_status(philo, "has taken a fork");
			usleep(philo->data->time_to_die * 1000);
			write_status(philo, "died");
			set_value(&philo->data->is_end, 1, philo->data);
			return (NULL);
		}
		if (first_turn(philo->data) == 0)
		{
			if (philo->id % 2 == 0)
				eat_process(philo);
		}
		else
			eat_process(philo);
		sleep_process(philo);
		think_process(philo);
	}
	return (NULL);
}
