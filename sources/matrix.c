/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 12:27:04 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/02 15:28:45 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

double			**give_null_matrix(int size)
{
	double				**ret;
	int					i;
	int					j;

	ret = (double**)malloc(sizeof(double*) * size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		ret[i] = (double*)malloc(sizeof(double) * size);
		while (++j < size)
			ret[i][j] = 0;
	}
	return (ret);
}

double			**give_translation_matrix(t_3Dpoint *vector)
{
	double	**ret;

	ret = give_null_matrix(4);
	ret[0][0] = 1;
	ret[1][1] = 1;
	ret[2][2] = 1;
	ret[3][3] = 1;
	ret[3][0] = vector->x;
	ret[3][1] = vector->y;
	ret[3][2] = vector->z;
	return (ret);
}
	
double			**give_homothety_matrix(int factor)
{
	double	**ret;

	ret = give_null_matrix(4);
	ret[0][0] = factor;
	ret[1][1] = factor;
	ret[2][2] = factor;
	ret[3][3] = 1;
	return (ret);
}

double			**mult_matrix(int **m, int **n, int size)
{
	double				**ret;
	int					i;
	int					j;

	ret = give_null_matrix(size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while(++j < size)
			ret[i][j] = m[i][j] * n[i][j];
	}
	return (ret);
}

double			**add_matrix(int **m, int **n, int size)
{
	double				**ret;
	int					i;
	int					j;

	ret = give_null_matrix(size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while(++j < size)
			ret[i][j] = m[i][j] + n[i][j];
	}
	return (ret);
}
