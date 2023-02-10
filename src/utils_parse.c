/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:40:40 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/10 16:18:05 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isnumber(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == 43 || argv[i] == 45) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]) == 1)
		i++;
	if (ft_isdigit(argv[i]) == 0 && argv[i] != '\0')
		return (F);
	return (T);
}
