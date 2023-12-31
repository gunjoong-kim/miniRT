/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:30:53 by gunjkim           #+#    #+#             */
/*   Updated: 2023/09/27 12:31:00 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*xmalloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
	{
		perror("Error\nxmalloc");
		exit(1);
	}
	return (p);
}

void	minirt_error_exit(void)
{
	perror("Error\nminiRT");
	exit(1);
}

void	minirt_str_error_exit(char *str)
{
	errno = 0;
	perror(str);
	exit(1);
}

t_color	black_color(void)
{
	t_color	black;

	black.x = 0;
	black.y = 0;
	black.z = 0;
	return (black);
}
