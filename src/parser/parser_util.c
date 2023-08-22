#include "minirt.h"

int	count_element_2pt_arr(char **data)
{
	int	count;

	count = 0;
	while (*data)
	{
		count++;
		data++;
	}
	return (count);
}

int	is_value_btw_255(int value, int *rgb_errno)
{
	if (value < 0 || value > 255)
		*rgb_errno = 1;
	return (value);
}

// ft_atoi로 넘길 str 검사를 해봐야함
int	data_to_rgb(char *str, t_color *rgb)
{
	char	**rgb_data;
	int		value;
	int		rgb_errno;

	rgb_errno = 0;
	rgb_data = ft_split(str, ',');
	if (count_element_2pt_arr(rgb_data) != 3)
	{
		ft_double_free(rgb_data);
		return (-1);
	}
	rgb->x = is_value_btw_255(ft_atoi(rgb_data[0]), &rgb_errno);
	rgb->y = is_value_btw_255(ft_atoi(rgb_data[1]), &rgb_errno);
	rgb->z = is_value_btw_255(ft_atoi(rgb_data[2]), &rgb_errno);
	value = ft_atoi(rgb_data[1]);
	ft_double_free(rgb_data);
	if (rgb_errno == 1)
		return (-1);
	return (1);
}

int	data_to_point(char *str, t_point3 *point)
{
	char	**point_data;
	int		atod_errno;

	atod_errno = 0;
	point_data = ft_split(str, ',');
	if (count_element_2pt_arr(point_data) != 3)
	{
		ft_double_free(point_data);
		return (-1);
	}
	point->x = ft_atod(point_data[0], &atod_errno);
	point->y = ft_atod(point_data[1], &atod_errno);
	point->z = ft_atod(point_data[2], &atod_errno);
	ft_double_free(point_data);
	if (atod_errno == ATOD_FORMAT_ERR)
		return (-1);
	return (1);
}
