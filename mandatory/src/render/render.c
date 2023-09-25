#include "minirt.h"
#include "bvh.h"
#include "object.h"
#include "vec3.h"
#include "ray.h"

void	write_color(t_color color, t_data *image, int i, int j)
{
	double	scale;
	int		pixel;

	scale = 1.0 / (SAMPLE_PER_PIXEL);
	color.x = clamp(sqrt(scale * color.x), 0.0, 0.999);
	color.y = clamp(sqrt(scale * color.y), 0.0, 0.999);
	color.z = clamp(sqrt(scale * color.z), 0.0, 0.999);
	pixel = ((int)(255.999 * color.x) << 16) + ((int)(255.999 * color.y) << 8)
		+ ((int)(255.999 * color.z));
	my_mlx_pixel_put(image, i, DEFAULT_IMAGE_HGT - j - 1, pixel);
}

t_color	aa_phong(int i, int j, t_world *world, t_sphere *l)
{
	t_ray	r;
	t_color	color;
	int		s;

	s = 0;
	vec3_init(&color, 0, 0, 0);
	while (s++ < SAMPLE_PER_PIXEL)
	{
		r = get_ray(&world->cam,
				(i + random_double()) / (DEFAULT_IMAGE_WID - 1),
				(j + random_double()) / (DEFAULT_IMAGE_HGT - 1));
		color = vec3_add(color, phong_color(r, world, l));
	}
	return (color);
}

void	multi_light(t_data *image, t_world *world, int i, int j)
{
	t_color	color;
	int		s;

	s = 0;
	vec3_init(&color, 0, 0, 0);
	if (world->light_lst[0] == NULL)
		color = aa_phong(i, j, world, NULL);
	else
	{
		while (world->light_lst[s] != NULL)
			color = vec3_add(color, aa_phong(i, j, world,
						world->light_lst[s++]));
		color = vec3_mul_scalar(color, 1 / (double)s);
	}
	write_color(color, image, i, j);
}

void	phong_trace(t_data *image, t_world *world)
{
	t_color	color;
	int		i;
	int		j;
	int		s;

	j = DEFAULT_IMAGE_HGT - 1;
	while (j >= 0)
	{
		printf("\rScanlines remaining : %d\n", j);
		i = 0;
		while (i < DEFAULT_IMAGE_WID)
		{
			multi_light(image, world, i, j);
			i++;
		}
		j--;
	}
}
