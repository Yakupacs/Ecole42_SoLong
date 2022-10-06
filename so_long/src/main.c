/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:37:46 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/06 20:30:18 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
2 arg olmalı+
.ber checki yapmalısın+
void make_map() --> tmp = get_next_line(fd), ft_strjoin(map1, tmp);+
map2 = ft_split(map1, '\n')  //map2 cift pointer+
rectangular, wall'larla kaplı mı, (1p, 1e, >1 c)+
valid_map checki yapıcaksın. recursive yapıcaksın.
resimleri init et
ilk renderı yap, valid bir hareket yaparsa ona göre render yap
free'leri düzgün yap
game_end fonksiyonun olsun tek çıkışlı.
*/

void	ft_error(char *msg, t_data *data)
{
	ft_printf(msg);
	ft_free_all(data);
	exit(EXIT_FAILURE);
}

int	ft_close_window(t_data *data)
{
	ft_free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->map1)
		free(data->map1);
	if (data->map2)
	{
		while(data->map2[i])
		{
			free(data->map2[i]);
			i++;
		}
		free(data->map2);
	}
	if (data->mlx)
		ft_free_mlx(data);
}

void	ft_free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->background);
	mlx_destroy_image(data->mlx, data->food);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player_l);
	mlx_destroy_image(data->mlx, data->player_r);
	mlx_destroy_image(data->mlx, data->player_b);
	mlx_destroy_image(data->mlx, data->player_f);
	mlx_destroy_window(data->mlx, data->window);
	free(data->mlx);
}

int	main(int ac, char **av)
{
	t_data    *data;

	if (ac == 2){
		data = ft_calloc(sizeof(t_data), 1);
		ft_ber_check(av[1], data);
		ft_make_map(data, av[1]);
		ft_map_check(data);
		ft_rectangular_check(data);
		ft_wall_check(data);
		ft_validmap_check(data, data->ply_x, data->ply_y);
		ft_path_check(data);
		data->mlx = mlx_init();
		ft_init_image(data);
		mlx_hook(data->window, 2, 1L << 0, ft_key_event, data);
		mlx_hook(data->window, 17, 1L << 2, ft_close_window, data);
		mlx_loop(data->mlx);
	}
	else
		ft_error("You just have to enter the map path!", data);
}
