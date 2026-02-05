/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:51:26 by kchiang           #+#    #+#             */
/*   Updated: 2026/02/05 16:09:46 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>

# define TITLE			"MAN3D"
# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080
# define TEXX_WIDTH		640
# define TEXX_HEIGHT	480

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

typedef struct map
{
	double	x;
	double	y;
	int		x_step;
	int		y_step;
}			t_map;

typedef struct ray
{
	double	dir_x;
	double	dir_y;
	double	sidedist_x;
	double	sidedist_y;
}			t_ray;

typedef	struct player
{
	double	x;
	double	y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	t_ray	ray;
	t_map	map;
}			t_player;

typedef struct s_map
{
	char	**layout;
	int		width;
	int		depth;
	int		height;
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
