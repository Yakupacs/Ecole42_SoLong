/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:39:37 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/02 21:18:13 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ber_check(char *map_name, t_data *data){
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'r' && map_name[len - 2] != 'e' &&
			map_name[len - 3] != 'b' && map_name[len - 4] != '.' &&
				len <= 9)
					ft_error("Must be '.ber' extension!", data);
}

void	ft_check_map(t_data *data){
	int i;
	int j;

	i = 0;
	while (data->map2[i]){
		j = 0;
		while (data->map2[i][j]){
			if (data->map2[i][j] == 'C')
				data->food += 1;
			else if (data->map2[i][j] == 'E')
				data->exit += 1;
			else if (data->map2[i][j] == 'P')
				data->player += 1;
			j++;
		}
		i++;
	}
	if (data->food < 1 || data->exit != 1 ||
			data->player != 1)
			ft_error("This map is not available.", data);
}