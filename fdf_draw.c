/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:18:26 by emarles           #+#    #+#             */
/*   Updated: 2025/03/02 16:15:45 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_render(t_window *main, grid *grid)
{
	int	i;
	int	j;

	i = 0;
	ft_calculate_position(main, grid);
    // // ft_draw_dots(main, grid);
    // while (i < grid->length)
    // {
	// 	j = 0;
	// 	while (j < grid->height)
	// 	{
    //     	mlx_put_image_to_window(main->mlx_connection, main->mlx_win, main->dot[i][j].img_ptr, main->dot[i][j].x, main->dot[i][j].y);
	// 		j++;
	// 	}
	// 	i++;
    // }
}
void	draw_instructions(t_window * main) 
{
	mlx_string_put(main->mlx_connection, main->mlx_win, 15, WIDTH - 1200, 0x003366FF, "The first line"); 
    mlx_string_put(main->mlx_connection, main->mlx_win, 15, WIDTH - 1180, 0x003366FF, "The second line");
    mlx_string_put(main->mlx_connection, main->mlx_win, 15, WIDTH - 1160, 0x003366FF, "The third line");
}

void	my_pixel_put(t_img  *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	color_screen(t_window *data, int color) // fills in the image for it then to be pushed.
{
	for (int y = 0; y < HEIGHT; ++y)	
	{
		for (int x = 0; x < WIDTH; ++x) //fills in each individual pixel with my_pixel_put
		{
			my_pixel_put(&data->img,
						x, 
						y, 
						color);
		}
	}
}

void ft_draw_dots(t_window *data, grid *grid)
{
	int		color;
	int	i;
	int	j;
	color =	0x00CCFFFF;

	// while loop for puting the pixels on the image
	i = 0;
	while (i < grid->length) // size of the basictest length.
	{
		j = 0;
		while (j < grid->height)
		{
			my_pixel_put(&data->dot[i][j], data->dot[i][j].x, data->dot[i][j].y, color);
			j++;
		}
		i++;	
	}
}
