/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 18:54:07 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/03 19:50:10 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_make_map(t_data *data){
// 	data->img = (void **)malloc(sizeof(void *) * 1);
// 	data->mlx = mlx_init();
// 	data->img[0] = mlx_xpm_file_to_image(data->mlx, PL_FT, &data->imgx,
// 			&data->imgy);
// 	data->window = mlx_new_window(data->mlx, 600, 600, "so_long");
// 	mlx_put_image_to_window(data->mlx, data->window, data->img[0],
// 			data->position_x, data->position_y);
// 	mlx_hook(data->window, 2, 1L << 0, ft_key_event, data);
// 	mlx_loop(data->mlx);	
// }

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
