#include "so_long.h"

int    ft_key_event(int keycode, t_data *data)
{
    mlx_clear_window(data->mlx, data->window);
    if (keycode == 2){//D
        data->position_x += 64;
        mlx_put_image_to_window(data->mlx, data->window, data->img[0],
                data->position_x, data->position_y);
    }
    else if (keycode == 0){//A
        data->position_x -= 64;
        mlx_put_image_to_window(data->mlx, data->window, data->img[0],
                data->128, data);
    }
	else if (keycode == 1){//S
		data->position_y += 64;
		mlx_put_image_to_window(data->mlx, data->window, data->img[0],
				data->position_x, data->position_y); 
	}
	else if (keycode == 13){//W
		data->position_y -= 64;
		mlx_put_image_to_window(data->mlx, data->window, data->img[0],
				data->position_x, data->position_y); 
	}
    return (0);
}