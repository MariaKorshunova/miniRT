/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoetess <bpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:38:00 by jmabel            #+#    #+#             */
/*   Updated: 2022/10/14 02:40:51 by bpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_roots(float roots[2], float root1, float root2)
{
	if (!roots)
		return ;
	roots[0] = root1;
	roots[1] = root2;
}

int	solve_quadratic_equation(float a, float b, float c, float roots[2])
{
	float	d_sqare;

	d_sqare = b * b - 4 * a * c;
	if (d_sqare < 0)
	{
		put_roots(roots, INFINITY, INFINITY);
		return (0);
	}
	if (d_sqare == 0)
	{
		put_roots(roots, (-b) / (2 * a), (-b) / (2 * a));
		if (roots)
			roots[1] = roots[0];
		return (1);
	}
	put_roots(roots, (-b - sqrt(d_sqare)) / (2 * a),
		(-b + sqrt(d_sqare)) / (2 * a));
	return (2);
}
