/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdidier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 10:02:35 by rdidier           #+#    #+#             */
/*   Updated: 2016/02/03 16:13:31 by rdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file_de_fer.h"

static t_pix		*point_to_pix(double **matrix, t_3Dpoint *point, int d)
{
	t_pix		*pix;

	matrix_on_point(point, matrix);
	print_point(point);
	pix = new_pix(d * point->x / point->z, d * point->y / point->z, point->z);
	return (pix);
}

static int			*pre_map(int ***readed, t_map **map)
{
	int		i;
	int		j;
	int		*ret;

	ret = (int*)malloc(sizeof(int) * 2);
	ret[1] = 0;
	i = -1;
	while (readed[++i])
		;
	(*map)->map = (t_pix***)malloc(sizeof(t_pix**) * i);
	(*map)->map[i] = NULL;
	ret[0] = i / 2;
	i = -1;
	while (readed[++i])
	{
		j = -1;
		while (readed[i][++j])
			ret[1]++;
		(*map)->map[i] = (t_pix**)malloc(sizeof(t_pix*) * j);
		(*map)->map[i][j] = NULL;
	}
	ft_putnbr(j);
	ret[1] = ret[1] / j;
	return (ret);
}

static double		**give_final_matrix(t_cam *cam)
{
	double			**final;
	double			**projection_m;

	projection_m = give_null_matrix(4);
	final = add_matrix(mult_matrix(give_rotation_matrix_z(cam->theta),
				give_rotation_matrix_x(cam->phi), 4),
			give_translation_matrix(cam->carth),4);
	print_matrix(4, final);
	

	return (final);
}

t_map				*new_map(int ***readed, t_cam *cam)
{
	int			i;
	int			j;
	int			*mid;
	t_map		*map;
	t_3Dpoint		*point;
	double		**final_matrix;

	final_matrix = give_final_matrix(cam);
	cam++;
	map = (t_map*)malloc(sizeof(t_map));
	mid = pre_map(readed, &map);
	i = -1;
	while (readed[++i])
	{
		j = -1;
		while (readed[i][++j])
		{
			point = new_3Dpoint((i - mid[0]) * PAS, (j - mid[1]) * PAS, *readed[i][j] * PAS);
			print_point(point);
			map->map[i][j] = point_to_pix(final_matrix, point, cam->far - cam->r);
		}
	}
	return (map);
}
