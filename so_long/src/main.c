/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:37:46 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/03 20:28:58 by yacis@stude      ###   ########.fr       */
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
	//free_all()
	exit(EXIT_FAILURE);
}

void	init_image(t_data *data)
{
	data->player_f = mlx_xpm_file_to_image(data->mlx, PL_FT, 
	&data->imgx, &data->imgy);
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
		init_image(data);
	}
	else
		ft_error("You just have to enter the map path!", data);
}
