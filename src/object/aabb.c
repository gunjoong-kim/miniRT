#include "object.h"

t_aabb		aabb_b_box(void *object)
{
	t_aabb	*ret;

	ret = (t_aabb *)object;
	return (*ret);
}

double	find_inverse(t_vec3 dir, int i)
{
	if (i == 0)
		return (1.0f / dir.x);
	else if (i == 1)
		return (1.0f / dir.y);
	return (1.0f / dir.z);
}

double	sub_p_orig(t_vec3 p, t_vec3 orig, int i)
{
	if (i == 0)
		return (p.x - orig.x);
	else if (i == 1)
		return (p.y - orig.y);
	return (p.z - orig.z);
}

bool		aabb_hit(t_ray *r, double min_t, double max_t,
			t_hit_rec *rec, void *object)
{
	int		i;
	double	invD;
	double	t0;
	double	t1;
	t_aabb	*aabb;

	aabb = (t_aabb *)object;
	i = 0;
	while (i < 3)
	{
        invD = find_dimention(r->dir, i);
		t0 =  sub_p_orig(aabb->p_min, r->orig, i) * invD;
		t1 = sub_p_orig(aabb->p_max, r->orig, i) * invD;
		if (invD < 0.0f)
			swap_d(&t0, &t1);
		if (t0 > min_t)
			min_t = t0;
		if (t1 < max_t)
			max_t = t1;
		if (max_t <= min_t)
			return (false);
		i++;
	}
    return (true);
}
