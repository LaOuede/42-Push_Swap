/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:40:40 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/13 13:04:33 by gle-roux         ###   ########.fr       */
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
