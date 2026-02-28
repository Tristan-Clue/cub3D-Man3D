/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:53:22 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/02/28 20:07:39 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdint.h>
# include "cub3d.h"

typedef	struct render
{
	int			tx_height;
	int			tx_start;
	int			tx_end;
	double		wall_hit;
	int			tx_x;
	double		step;
	double		tx_pos;
	int			tx_y;
	t_direction	wall_face;
}			t_render;

typedef struct ray
{
	typedef enum e_wall
	{
		NS,
		EW,
	}	t_wall;
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

void	init_rays(t_player *player, t_ray *ray);
void	cast_rays(t_ray *ray, t_map *map);
void	get_height(t_ray *ray, t_render *render);
void	get_texture(t_player *player, t_ray *ray, t_render *render);
void	render_column(t_render *render, t_img *screen, t_map *map, int col);
void	render_background(t_img *screen, t_map *map);

#endif
