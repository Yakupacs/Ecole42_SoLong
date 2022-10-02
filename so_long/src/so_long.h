#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# define PL_FT "./images/player_front.xpm"

typedef struct s_data
{
    void    *mlx;
    void    *window;
    void    **img;
    int     imgx;
    int     imgy;
    int        position_x;
    int        position_y;
	int		p_x;
	int		p_y;
	int		map_x;
	int		map_y;
	char	*map1;
	char	**map2;
	int		food;
	int		exit;
	int		player;
}    t_data;

void	ft_ber_check(char *map_name, t_data *data);
void	ft_error(char *msg, t_data *data);
int		ft_key_event(int keycode, t_data *data);
void	ft_make_map(t_data *data);
void	ft_line_map(t_data *data,char *map);
void	ft_check_map(t_data *data);

#endif
