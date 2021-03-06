/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 14:41:08 by rdidier           #+#    #+#             */
/*   Updated: 2016/03/15 18:22:42 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fil_de_fer.h"
#include "../includes/fil_de_fer.h"

t_3dpoint		*new_3dpoint(double x, double y, double z)
{
	t_3dpoint		*ret;

	ret = (t_3dpoint*)malloc(sizeof(t_3dpoint));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

double			**give_rotation_matrix_x(double a)
{
	double			**ret;
	double			c;
	double			s;

	c = cos(a);
	s = sin(a);
	ret = give_null_matrix(4);
	ret[3][3] = 1;
	ret[0][0] = 1;
	ret[1][1] = c;
	ret[1][2] = -s;
	ret[2][1] = s;
	ret[2][2] = c;
	return (ret);
}

double			**give_rotation_matrix_y(double a)
{
	double			**ret;
	double			c;
	double			s;

	c = cos(a);
	s = sin(a);
	ret = give_null_matrix(4);
	ret[3][3] = 1;
	ret[0][0] = c;
	ret[0][2] = s;
	ret[1][1] = 1;
	ret[2][0] = -s;
	ret[2][2] = c;
	return (ret);
}

double			**give_rotation_matrix_z(double a)
{
	double			**ret;
	double			c;
	double			s;

	c = cos(a);
	s = sin(a);
	ret = give_null_matrix(4);
	ret[3][3] = 1;
	ret[2][2] = 1;
	ret[0][0] = c;
	ret[0][1] = -s;
	ret[1][0] = s;
	ret[1][1] = c;
	return (ret);
}

void			matrix_on_point(t_3dpoint *point, double **m)
{
	point->x = m[0][0] * point->x
		+ m[0][1] * point->y
		+ m[0][2] * point->z + m[0][3];
	point->y = m[1][0] * point->x
		+ m[1][1] * point->y
		+ m[1][2] * point->z + m[1][3];
	point->z = m[2][0] * point->x
		+ m[2][1] * point->y
		+ m[1][2] * point->z + m[2][3];
}
