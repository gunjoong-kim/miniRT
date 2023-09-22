#include "minirt.h"
#include "bvh.h"
#include "object.h"

int	sphere_data(char **data, t_list **list)
{
	t_hittable	*new_object;
	t_point3	center;
	double		radius;
	t_color		rgb;
	int			atod_errno;

	atod_errno = 0;
	if (count_element_2pt_arr(data) != 4)
		return (-1);
	if (data_to_point(data[1], &center) == -1)
		return (-1);
	radius = ft_atod(data[2], &atod_errno);
	if (atod_errno == ATOD_FORMAT_ERR)
		return (-1);
	if (data_to_rgb(data[3], &rgb) == -1)
		return (-1);
	new_object = (t_hittable *)xmalloc(sizeof(t_hittable));
	new_object->object = sphere_constructor(center, radius, rgb);
	new_object->center = ((t_sphere *)new_object->object)->center;
	new_object->hit = sphere_hit;
	new_object->b_box = sphere_b_box;
	ft_lstadd_back(list, ft_lstnew(new_object));
	return (1);
}

int	plane_data(char **data, t_list **list)
{
	t_hittable	*new_object;
	t_point3	p;
	t_point3	normal;
	t_color		rgb;
	int			atod_errno;

	atod_errno = 0;
	if (count_element_2pt_arr(data) != 4)
		return (-1);
	if (data_to_point(data[1], &p) == -1)
		return (-1);
	if (data_to_point(data[2], &normal) == -1)
		return (-1);
	if (data_to_rgb(data[3], &rgb) == -1)
		return (-1);
	new_object = (t_hittable *)xmalloc(sizeof(t_hittable));
	new_object->object = plane_constructor(p, normal, rgb);
	new_object->center = ((t_plane *)new_object->object)->p;
	new_object->hit = plane_hit;
	new_object->b_box = plane_b_box;
	ft_lstadd_back(list, ft_lstnew(new_object));
	return (1);
}

int	cylinder_data(char **data, t_list **list)
{
	t_hittable	*new_object;
	int			atod_errno;
	t_cy_vars	cy_vars;

	atod_errno = 0;
	if (count_element_2pt_arr(data) != 6)
		return (-1);
	if (data_to_point(data[1], &cy_vars.center) == -1)
		return (-1);
	if (data_to_point(data[2], &cy_vars.axis) == -1)
		return (-1);
	cy_vars.diameter = ft_atod(data[3], &atod_errno);
	cy_vars.height = ft_atod(data[4], &atod_errno);
	if (atod_errno == ATOD_FORMAT_ERR)
		return (-1);
	if (data_to_rgb(data[5], &cy_vars.rgb) == -1)
		return (-1);
	new_object = (t_hittable *)xmalloc(sizeof(t_hittable));
	new_object->object = cylinder_constructor(cy_vars);
	new_object->center = ((t_cylinder *)new_object->object)->center;
	new_object->hit = cylinder_hit;
	new_object->b_box = cylinder_b_box;
	ft_lstadd_back(list, ft_lstnew(new_object));
	return (1);
}
