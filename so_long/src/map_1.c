/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:54:07 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/06 20:16:21 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_map(t_data *data,char *map)
{
	int fd;
	char *buff;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("File don't found!", data);
	buff = get_next_line(fd);
	while (buff){
		data->map1 = ft_strjoin(data->map1, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	data->map2 = ft_split(data->map1, '\n');
	data->tmp_map2 = ft_split(data->map1, '\n');
}
