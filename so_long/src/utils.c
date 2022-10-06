/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:39:58 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/06 20:37:03 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_xy(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

void	ft_xy_operation(int *x, int *y, t_data *data)
{
	if (*x == data->map_x * 64)
	{
		*x = -64;
		*y += 64;
	}
	*x += 64;
}

void	ft_render_after_move(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	ft_put_image(data);
}

int	ft_check_movement(t_data *data, int x, int y)
{
	if (data->map2[y][x] != '1')
	{
		if (data->map2[y][x] == 'C')
			data->food_count--;
		else if (!data->food_count && data->map2[y][x] == 'E')
		{
			ft_printf("Move: %d\nCongratulations!",++(data->move_count));
			ft_free_all(data);
			exit(EXIT_SUCCESS);
		}
		if (data->map2[y][x] == 'E')
			return (0);
		ft_printf("Move: %d\n",++(data->move_count));
		return (1);
	}
	return (0);
}