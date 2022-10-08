/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:56:13 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/08 16:41:08 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_make_map(t_data *data, char *map)
{
	int		fd;
	char	*buff;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("File don't found!", data);
	buff = get_next_line(fd);
	if (!buff)
		ft_error("File is empty!", data);
	while (buff)
	{
		data->map1 = ft_strjoin(data->map1, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	data->map2 = ft_split(data->map1, '\n');
	data->tmp_map2 = ft_split(data->map1, '\n');
}

void	ft_init_image(t_data *data)
{
	data->player_f = mlx_xpm_file_to_image(data->mlx, PL_FT,
			&data->imgx, &data->imgy);
	data->player_b = mlx_xpm_file_to_image(data->mlx, PL_BK,
			&data->imgx, &data->imgy);
	data->player_l = mlx_xpm_file_to_image(data->mlx, PL_LT,
			&data->imgx, &data->imgy);
	data->player_r = mlx_xpm_file_to_image(data->mlx, PL_RT,
			&data->imgx, &data->imgy);
	data->food = mlx_xpm_file_to_image(data->mlx, FOOD,
			&data->imgx, &data->imgy);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->imgx, &data->imgy);
	data->background = mlx_xpm_file_to_image(data->mlx, BACKG,
			&data->imgx, &data->imgy);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->imgx, &data->imgy);
	data->window = mlx_new_window(data->mlx, data->map_x * 64, \
		data->map_y * 64, "so_long");
	data->curr_pos = 'F';
	ft_put_image(data);
}

void	ft_put_image(t_data *data)
{
	int	x;
	int	y;

	ft_init_xy(&x, &y);
	while (y < data->map_y * 64)
	{
		if (data->map2[y / 64][x / 64] != '1'
			&& data->map2[y / 64][x / 64] != '0')
			mlx_put_image_to_window(data->mlx, data->window,
				data->background, x, y);
		if (data->map2[y / 64][x / 64] == '1')
			mlx_put_image_to_window(data->mlx, data->window, data->wall, x, y);
		else if (data->map2[y / 64][x / 64] == '0')
			mlx_put_image_to_window(data->mlx, data->window,
				data->background, x, y);
		else if (data->map2[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit, x, y);
		else if (data->map2[y / 64][x / 64] == 'C')
			mlx_put_image_to_window(data->mlx, data->window,
				data->food, x, y);
		else if (data->map2[y / 64][x / 64] == 'P')
			ft_put_image_player(data, x, y);
		ft_xy_operation(&x, &y, data);
	}
}

void	ft_put_image_player(t_data *data, int x, int y)
{
	if (data->curr_pos == 'F')
		mlx_put_image_to_window(data->mlx, data->window, data->player_f, x, y);
	else if (data->curr_pos == 'R')
		mlx_put_image_to_window(data->mlx, data->window, data->player_r, x, y);
	else if (data->curr_pos == 'L')
		mlx_put_image_to_window(data->mlx, data->window, data->player_l, x, y);
	else if (data->curr_pos == 'B')
		mlx_put_image_to_window(data->mlx, data->window, data->player_b, x, y);
}
