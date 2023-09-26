/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:20:02 by gunjkim           #+#    #+#             */
/*   Updated: 2023/09/26 19:21:51 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*temp;
	unsigned char	c_tmp;

	index = 0;
	temp = (unsigned char *)b;
	c_tmp = (unsigned char)c;
	while (index < len)
	{
		temp[index] = c_tmp;
		index++;
	}
	return ((void *)temp);
}
