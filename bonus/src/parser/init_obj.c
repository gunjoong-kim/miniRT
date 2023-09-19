#include "parser.h"
#include "bvh.h"

int	init_sphere(t_hittable *new_object, char **data)
{
	t_point3	center;
	double		radius;
	int			atod_errno;

	atod_errno = 0;
	if (count_element_2pt_arr(data) != 3)
		return (-1);
	if (data_to_point(data[1], &center) == -1)
		return (-1);
	radius = ft_atod(data[2], &atod_errno);
	if (atod_errno == ATOD_FORMAT_ERR)
		return (-1);
	new_object->object = (t_sphere *)xmalloc(sizeof(t_sphere));
	new_object->type = sphere;
	((t_sphere *)(new_object->object))->center = center;
	((t_sphere *)(new_object->object))->radius = radius;
	return (1);
}

int	init_plane(t_hittable *new_object, char **data)
{
	t_point3	p;
	t_vec3		normal;

	if (count_element_2pt_arr(data) != 3)
		return (-1);
	if (data_to_point(data[1], &p) == -1)
		return (-1);
	if (data_to_point(data[2], &normal) == -1)
		return (-1);
	if (check_nan_in_vec3(normal))
		return (-1);
	new_object->object = (t_plane *)xmalloc(sizeof(t_plane));
	new_object->type = plane;
	((t_plane *)(new_object->object))->p = p;
	((t_plane *)(new_object->object))->n = vec3_unit(normal);
	return (1);
}

int	init_cylinder(t_hittable *new_object, char **data)
{
	t_point3	center;
	t_vec3		axis;
	double		diameter;
	double		height;
	int			atod_errno;

	atod_errno = 0;
	if (count_element_2pt_arr(data) != 5)
		return (-1);
	if (data_to_point(data[1], &center) == -1)
		return (-1);
	if (data_to_point(data[2], &axis) == -1)
		return (-1);
	diameter = ft_atod(data[3], &atod_errno);
	height = ft_atod(data[4], &atod_errno);
	if (atod_errno == ATOD_FORMAT_ERR || check_nan_in_vec3(axis))
		return (-1);
	new_object->object = (t_cylinder *)xmalloc(sizeof(t_cylinder));
	new_object->type = cylinder;
	((t_cylinder *)(new_object->object))->center = center;
	((t_cylinder *)(new_object->object))->axis = vec3_unit(axis);
	((t_cylinder *)(new_object->object))->diameter = diameter;
	((t_cylinder *)(new_object->object))->height = height;
	return (1);
}

int	init_cone(t_hittable *new_object, char **data)
{
	t_point3	center;
	t_point3	top;
	double		radius;
	int			atod_errno;
	int			is_inf;

	atod_errno = 0;
	if (count_element_2pt_arr(data) != 5)
		return (-1);
	if (data_to_point(data[1], &center) == -1)
		return (-1);
	if (data_to_point(data[2], &top) == -1)
		return (-1);
	if (check_nan_in_vec3(vec3_unit(vec3_sub(center, top))))
		return (-1);
	radius = ft_atod(data[3], &atod_errno);
	if (atod_errno == ATOD_FORMAT_ERR)
		return (-1);
	if (ft_strequal(data[4], INF) == 1)
		is_inf = 1;
	else if (ft_strequal(data[4], NOT_INF) == 1)
		is_inf = 0;
	else
		return (-1);
	new_object->object = (t_cone *)xmalloc(sizeof(t_cone));
	new_object->type = cone;
	((t_cone *)(new_object->object))->center = center;
	((t_cone *)(new_object->object))->top = top;
	((t_cone *)(new_object->object))->radius = radius;
	((t_cone *)(new_object->object))->axis = vec3_unit(vec3_sub(center, top));
	((t_cone *)(new_object->object))->is_inf = is_inf;
	return (1);
}

int	init_object(t_hittable *hittable, char *obj_line)
{
	int		ret;
	char	**data;

	data = ft_split_white(obj_line);
	if (data == NULL || data[0] == NULL)
		minirt_str_error_exit(ERR_MAP);
	if (ft_strequal(SPHERE, data[0]))
		ret = init_sphere(hittable, data);
	else if (ft_strequal(PLANE, data[0]))
		ret = init_plane(hittable, data);
	else if (ft_strequal(CYLINDER, data[0]))
		ret = init_cylinder(hittable, data);
	else if (ft_strequal(CONE, data[0]))
		ret = init_cone(hittable, data);
	else
		ret = -1;
	ft_double_free(data);
	return (ret);
}
