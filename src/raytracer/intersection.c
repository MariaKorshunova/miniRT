/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:22:39 by jmabel            #+#    #+#             */
/*   Updated: 2022/10/22 19:26:08 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*  ray.point[0] = global->scene->camera_point; Точка камеры (точка a)
    = координата луча на проецирумой плоскости
    Vector d = ray.point[0] -  ray.point[1] (вектор луча)
*/

float	check_intersection_plane(t_plane *plane, t_ray *ray, t_coord *d)
{
	float	t;
	float	dot_dn;
	t_coord	sub_ra;

	dot_dn = scalar_product_2_vectors(d, &(plane->orientation));
	if (dot_dn == 0)
		return (-1);
	vector_subtraction(&sub_ra, &(ray->point[0]), &(plane->point));
	t = scalar_product_2_vectors(&sub_ra, &(plane->orientation)) / dot_dn;
	if (t < 0)
		return (-1);
	return (t);
}

float	check_intersection_sphere(t_sphere *sphere, t_ray *ray, t_coord *d)
{
	float	points[2];
	t_coord	oc;

	vector_subtraction(&oc, &sphere->point, &(ray->point[0]));
	if (!solve_quadratic_equation(
			scalar_product_2_vectors(d, d),
			2 * scalar_product_2_vectors(d, &oc),
			scalar_product_2_vectors(&oc, &oc)
			- ((sphere->diameter / 2) * (sphere->diameter / 2)),
			points) || (points[0] < 0 && points[1] < 0))
		return (-1);
	if (points[0] < 0)
		points[0] = points[1];
	else if (points[1] < 0)
		points[1] = points[0];
	if (points[0] <= points[1] && points[0] > 0)
		return (points[0]);
	if (points[1] <= points[0] && points[1] > 0)
		return (points[1]);
	return (-1);
}

float	nearest_distance(float	*points)
{
	if (points[0] < 0 && points[1] < 0)
		return (-1);
	if (points[0] < 0)
		points[0] = points[1];
	else if (points[1] < 0)
		points[1] = points[0];
	if (points[0] <= points[1] && points[0] > 0)
		return (points[0]);
	if (points[1] <= points[0] && points[1] > 0)
		return (points[1]);
	return (-1);
}
