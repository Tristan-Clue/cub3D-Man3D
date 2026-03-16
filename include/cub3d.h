/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:51:26 by kchiang           #+#    #+#             */
/*   Updated: 2026/03/16 14:05:52 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include <sys/time.h>

# define TITLE			"MAN3D"
# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720
# define RESO_WIDTH		640
# define RESO_HEIGHT	360

# define MAX_MAP_SIZE	100

# define SUCCESS		0
# define FAILURE		1
# define CEILING		0
# define FLOOR			1

# define PIXEL_WHITE	0xFFFFFF
# define PIXEL_GREY		0x555555
# define PIXEL_LTGREY	0xA0A0A0
# define PIXEL_BLACK	0x0
# define PIXEL_RED		0xFF0000
# define PIXEL_GREEN	0xFF00
# define PIXEL_BLUE		0xFF

# define BASE16_LOWER	"0123456789abcdef"

# define KEY_UP			0b1
# define KEY_DOWN		0b10
# define KEY_LEFT		0b100
# define KEY_RIGHT		0b1000
# define KEY_W			0b10000
# define KEY_A			0b100000
# define KEY_S			0b1000000
# define KEY_D			0b10000000

# define PAN_ANGLE		2
# define MOUSE_SENSE	10
# define MOVE_SPEED		0.1

# define LANTURN_PATH	"textures/lantern.xpm"

typedef struct timeval	t_tv;
typedef struct timezone	t_tz;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	UNINITIALIZED,
}	t_direction;

typedef struct s_vec
{
	double	x;
	double	y;
}			t_vec;

typedef struct s_img
{
	void	*img_ptr;
	char	*px;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_tx
{
	t_img	img;
	int		width;
	int		height;
}			t_tx;

typedef struct s_input
{
	int	movement;
	int	rotation;
	int	mouse_x;
	int	mouse_y;
	int	rot_angle;
}			t_input;

typedef struct s_player
{
	t_vec	pos;		// Player pos in world map
	t_vec	plane;		// Vector of the camera plane, perpendicular to
	t_vec	dir;		// The vector of player facing direction
}			t_player;

typedef struct s_map
{
	char		layout[MAX_MAP_SIZE][MAX_MAP_SIZE];
	char		*tx_path[4];
	t_tx		tx[4];
	int			floor_color;
	int			ceiling_color;
	char		bgcolor_set[2];
	int			row_number;
	int			col_number;
	t_vec		starting_pos;
	t_direction	starting_dir;
}				t_map;

typedef struct s_flag
{
	int		render;
	int		focus;
}			t_flag;

typedef struct s_framerate
{
	int		frames;
	long	sec;
}			t_framerate;

typedef struct s_anim
{
	t_img		img;
	int			frames;
	int			width;
	int			height;
	int			sprite_width;
	int			sprite_height;
	int			col;
	int			fps;
	t_framerate	curr;
	int			scale;
	int			tex_x;
	int			tex_y;
	t_vec		pos;
	double		step;
}			t_anim;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	t_input		input;
	t_img		img;
	t_flag		flag;
	t_tv		tv;
	t_tz		tz;
	t_framerate	frames;
	t_anim		anim;
	void		*mlx;
	void		*window;
}			t_data;

void	error_exit(char *str);
void	perror_exit(char *str);
void	destroy_map(t_map *map);
void	destroy_array(char **arr);

int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
uint8_t	get_red(int rgb);
uint8_t	get_green(int rgb);
uint8_t	get_blue(int rgb);

/*			init			*/
void	parse_map(t_map *map, const char *s);
int		init_mlx(t_data *data);
void	init_player_dir(t_player *player, t_map *map);
int		assign_tx_path(void *mlx, t_map *map);
int		init_lanturn(void *mlx, t_anim *obj);

/*			render			*/
void	render_pov(t_img *screen, t_player *player, t_map *map);

/*			destroy			*/
void	delete_mlx(t_data *data);
int		destroy(t_data *data);

/*			events			*/
void	event_loop(t_data *data);
void	detect_input(t_data *data);
void	update_data(t_data *data);
void	rotate_camera(t_input *input, t_player *player);
void	handle_movement(t_input *input, t_player *player, t_map *map);

/*			DEBUG			*/
void	print_map_info(t_map *map);
void	print_tex_info(t_map *map);
void	print_player_info(t_player *player);
void	print_lanturn_info(t_anim *obj);

/*			animation		*/
void	render_anim(t_anim *obj, t_img *screen, int start_x, int start_y);

#endif
