/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacis@student.42istanbul.com.tr <yacis>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:39:37 by yacis@stude       #+#    #+#             */
/*   Updated: 2022/10/03 20:20:20 by yacis@stude      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ber_check(char *map_name, t_data *data)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'r' && map_name[len - 2] != 'e' &&
			map_name[len - 3] != 'b' && map_name[len - 4] != '.' &&
				len <= 9)
					ft_error("Must be '.ber' extension!", data);
}

void	ft_map_check(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map2[i]){
		j = 0;
		while (data->map2[i][j]){
			if (data->map2[i][j] == 'C')
				data->food_count++;
			else if (data->map2[i][j] == 'E')
				data->exit_count++;
			else if (data->map2[i][j] == 'P')
			{
				data->player_count++;
				data->ply_x = j;
				data->ply_y = i;
			}
			j++;
		}
		i++;
	}
	if (data->food_count < 1 || data->exit_count != 1 ||
			data->player_count != 1)
			ft_error("Error! Map must include only 1 player, only 1 exit \
and at least 1 collectibles.", data);
}

void	ft_rectangular_check(t_data *data)
{
	int line_len1;
	int line_len2;
	int	i;

	i = 0;
	line_len1 = ft_strlen(data->map2[0]);
	while (data->map2[i]){
		line_len2 = ft_strlen(data->map2[i]);
		if (line_len2 != line_len1)
			ft_error("Error! The map is not rectangular.",data);
		i++;
	}
}

void	ft_wall_check(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data->map2[i]){
		len++;
		i++;
	}
	i = 0;
	while (data->map2[0][i] && data->map2[len - 1][i]){
		if (data->map2[0][i] != '1' || data->map2[len - 1][i] != '1')
			ft_error("Error! The walls are not closed.", data);
		i++;
	}
	ft_wall_leftright_check(data, len);
}

void	ft_wall_leftright_check(t_data *data, int row_len)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(data->map2[0]);
	while (i < row_len)
	{
		if (data->map2[i][0] != '1' || data->map2[i][len - 1] != '1')
			ft_error("Error! The walls are not closed.", data);
		i++;
	}
	data->tmp_food_count = data->food_count;
}