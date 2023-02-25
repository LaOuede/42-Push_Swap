/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:56:50 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/02/25 14:48:56 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Subject :
	Write the following function:
		int     *ft_range(int start, int end);
	It must allocate (with malloc()) an array of integers, fill it with
	consecutive values that begin at start and end at end (Including start and
	end !), then return a pointer to the first value of the array.

Examples:
	- With (1, 3) you will return an array containing 1, 2 and 3.
	- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
	- With (0, 0) you will return an array containing 0.
	- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdio.h>

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
		tab[len] = end--;
	}
	else
	{
		while (len-- >= 0)
		tab[len] = end++;
	}
	return (tab);
}

/*
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	int	*tab;
	int	start = -1;
	int	end = 2;
	int	i = 0;
	int	len = ft_abs_val(end - start) + 1;
	tab = ft_rrange(start, end);
	while (len-- > 0)
		printf("%d\n", tab[i++]);
	free(tab);
	return (0);
}
*/
