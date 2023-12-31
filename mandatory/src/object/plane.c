/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:29:57 by gunjkim           #+#    #+#             */
/*   Updated: 2023/09/27 12:29:58 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_aabb	plane_b_box(void *object)
{
	t_aabb	pl_box;

	(void)object;
	pl_box.p_min.x = -INFINITY;
	pl_box.p_min.y = -INFINITY;
	pl_box.p_min.z = -INFINITY;
	pl_box.p_max.x = INFINITY;
	pl_box.p_max.y = INFINITY;
	pl_box.p_max.z = INFINITY;
	return (pl_box);
}

bool	plane_hit(t_ray *r, t_hit_rec *rec, void *object)
{
	t_plane	*pl;
	double	numer;
	double	denomi;
	double	root;

	pl = (t_plane *)object;
	numer = vec3_dot(pl->n, vec3_sub(pl->p, r->orig));
	denomi = vec3_dot(pl->n, r->dir);
	if (denomi == 0)
		return (false);
	root = numer / denomi;
	if (root < rec->min_t || rec->max_t < root)
		return (false);
	rec->center = pl->p;
	rec->t = root;
	rec->max_t = rec->t;
	rec->p = ray_at(*r, rec->t);
	set_face_normal(r, pl->n, rec);
	rec->mat = &pl->mat;
	return (true);
}
