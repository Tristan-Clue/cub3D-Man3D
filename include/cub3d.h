/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:51:26 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/21 14:30:28 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>

# define TITLE			"MAN3D"
# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720
# define RESO_WIDTH		640
# define RESO_HEIGHT	360
# define TEXTURE_SIZE	64

# define SUCCESS		0
# define FAILURE		1

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

typedef struct vec
{
	double	x;
	double	y;
}			t_vec

typedef	struct tx
{
	// NOTE: Struct containing texture image and requisites
}			t_tx;

typedef	struct render
{
	int		tx_height;
	int		tx_start;
	int		tx_end;
	int		wall_hit;
	int		tx_x;
	double	step;
	double	tx_pos;
	int		tx_y;
}			t_render;

typedef struct ray
{
	enum	e_wall
	{
		NS,
		EW,
	}		t_wall;
	int		map_x;
	int		map_y;
	double	camera_x;
	t_vec	dir;
	t_vec	delta_dist;
	t_vec	side_dist;
	t_vec	step;
	double	ray_dist;
	double	perp_dist;
	int		wall;
	int		hit;
}			t_ray;

typedef	struct player
{
	t_vec	pos;		// Player pos in world map
	t_vec	plane;		// Vector of the camera plane, perpendicular to
	t_vec	dir;		// The vector of player facing direction
}			t_player;

typedef struct s_map
{
	char	**layout;
	int		width;
	int		depth;
	int		height;
	int		floor_color;
	int		ceiling_color;
	t_tx	textures[4];
}			t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*px;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	t_map	map;
	t_img	img;
	void	*mlx;
	void	*window;
}			t_data;

void	error_exit(char *str);
void	perror_exit(char *str);

int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
uint8_t	get_red(int rgb);
uint8_t	get_green(int rgb);
uint8_t	get_blue(int rgb);

#endif
