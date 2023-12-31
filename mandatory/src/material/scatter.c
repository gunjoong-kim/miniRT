/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:29:46 by gunjkim           #+#    #+#             */
/*   Updated: 2023/09/27 12:29:46 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

bool	scatter_diffuse(t_ray *r, t_hit_rec *rec, t_color *att, t_ray *scat)
{
	t_vec3	scatter_direction;

	(void)r;
	scatter_direction = vec3_add(rec->normal, vec3_random_unit());
	if (vec3_near_zero(scatter_direction))
		scatter_direction = rec->normal;
	scat->orig = rec->p;
	scat->dir = scatter_direction;
	*att = rec->mat->t.value(rec, rec->mat->t.rgb);
	return (true);
}

bool	scatter_light(t_ray *r, t_hit_rec *rec, t_color *att, t_ray *scat)
{
	(void)r;
	(void)rec;
	(void)att;
	(void)scat;
	return (false);
}
