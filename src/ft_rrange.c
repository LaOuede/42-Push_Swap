/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:56:50 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/25 14:54:53 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Subject :
  Write the following function:
    int     *ft_rrange(int start, int end);
  It must allocate (with malloc()) an array of integers, fill it with
  consecutive values that begin at end and end at start (Including start and
  end !), then return a pointer to the first value of the array.

Examples:
  - With (1, 3) you will return an array containing 3, 2 and 1
  - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
  - With (0, 0) you will return an array containing 0.
  - With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

#include <stdlib.h>

int	ft_abs_val(int nb)
{
	if (nb < 0)
		return (nb *= -1);
	return (nb);
}

int	*ft_rrange(int start, int end)
{
	int	len = ft_abs_val(end - start) + 1;
	int	*tab;

	tab = malloc(sizeof(tab) * (len));
	if (!tab)
		return (NULL);
	if (end >= 0)
	{
		while (len-- > 0)
		tab[len] = start++;
	}
	else
	{
		while (len-- >= 0)
		tab[len] = start--;
	}
	return (tab);
}

/*
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	int	*tab;
	int	start = 0;
	int	end = -3;
	int	i = 0;
	int	len = ft_abs_val(end - start) + 1;
	tab = ft_rrange(start, end);
	while (len-- > 0)
		printf("%d\n", tab[i++]);
	free(tab);
	return (0);
}
*/
