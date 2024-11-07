/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:57:19 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/07 04:15:36 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_simulation(t_philo *philo)
{
	if (philo->id == (philo->data->ph_total - 1))
		philo->data->is_ready = 1;
	while (!philo->data->is_ready)
		;
}

void	is_end(t_philo *philo)
{
	if ((get_time() - philo->last_meal) > philo->data->time_to_die)
	{
		printf("[PHILO][%ld][%d] is dead\n", get_time(), philo->id);
		philo->data->is_end = 1;
	}
	if (philo->data->meals_total != -1
		&& philo->data->meals_total > philo->meals_total)
		philo->data->is_end = 1;
}
