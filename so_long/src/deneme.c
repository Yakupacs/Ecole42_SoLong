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
                data->position_x, data->position_y);
    }
	else if (keycode == 13){//W
		data->position_y += 64;
		mlx_put_image_to_window(data->mlx, data->window, data->img[0],
				data->position_x, data->position_y); 
	}
	else if (keycode == 1){//S
		data->position_y -= 64;
		mlx_put_image_to_window(data->mlx, data->window, data->img[0],
				data->position_x, data->position_y); 
	}
    return (0);
}

int    main(int ac, char **av)
{
	t_data    *data;
    data = calloc(sizeof(t_data), 1);
    data->img = (void **)malloc(sizeof(void *) * 1);
    data->mlx = mlx_init();
    data->player_f = mlx_xpm_file_to_image(data->mlx, PL_FT,
            &data->imgx, &data->imgy);
    data->window = mlx_new_window(data->mlx, 300, 300, "so_long");
    mlx_put_image_to_window(data->mlx, data->window, data->img[0],
                data->position_x, data->position_y);
    mlx_hook(data->window, 2, 1L << 0, key_event, data);  		//w a s d esc
	//mlx_hook(data->window, 17, 1L << 2, close_window, data);   //kapatma tuşu
	mlx_loop(data->mlx);
}
