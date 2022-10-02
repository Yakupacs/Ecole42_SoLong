/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:37:46 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/02 21:08:45 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
2 arg olmalı
.ber checki yapmalısın
void make_map() --> tmp = get_next_line(fd), ft_strjoin(map1, tmp);
map2 = ft_split(map1, '\n')  //map2 cift pointer
rectangular, wall'larla kaplı mı, (1p, 1e, >1 c)
valid_map checki yapıcaksın. recursive yapıcaksın.
resimleri init et
ilk renderı yap, valid bir hareket yaparsa ona göre render yap
free'leri düzgün yap
game_end fonksiyonun olsun tek çıkışlı.
*/

void	ft_error(char *msg, t_data *data){
	ft_printf(msg);
	//free_all()
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_data    *data;

	if (ac == 2){
		data = ft_calloc(sizeof(t_data), 1);
		ft_ber_check(av[1], data);
		ft_line_map(data, av[1]);
		ft_check_map(data);
		
		ft_make_map(data);
	}
	else
	{
		ft_error("You just have to enter the map path!", data);
	}
}