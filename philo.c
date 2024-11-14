/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:44:48 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/14 10:10:36 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!get_data_numbers(argc, argv, &data) || !init_simulation(&data))
		return (1);
	start_simulation(&data);
	clean_simulation(&data);
	return (0);
}
