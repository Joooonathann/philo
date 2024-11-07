/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:41:35 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/07 02:58:29 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_total)
	{
		if (pthread_create(&data->philos[i].philo, NULL, process_philo,
				(void *)&data->philos[i]))
			exit (0);
		i++;
	}
	return (1);
}