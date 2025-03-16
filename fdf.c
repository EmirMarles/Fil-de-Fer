/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:51 by emarles           #+#    #+#             */
/*   Updated: 2025/03/02 16:10:38 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int    ft_display(char *file);
static int file_reading(char * file, grid *grid);
static void  dot_pointers(t_window *main, grid *grid);

int main(int argc, char*argv[])
{
    if (argc < 2)
    {
        printf("Not enough arguments\n");
        return (0);
    }
    ft_display(argv[1]);
    return (0);
}

static int file_reading(char *file, grid* grid)
{
    int fd;
    char *string;
    
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (1);
    string = get_next_line(fd);
    grid->length = grid_lentgh(string);
    grid->height = grid_height(fd);
    printf("the lentgth of the grid is %i\n", grid->length);
    printf("the height of the grid is %i\n", grid->height);
    free(string);
    close (fd);
    return (0);
}

static int    ft_display(char *file)
{
    t_window  main; // everything should be saved here for manipulating the data
    grid    grid; // grid data
    int i;
    int j;

    i = 0;
    file_reading(file, &grid); // grid height/width
            // here function to malloc memory for array of dots is needed    
    main.mlx_connection = mlx_init();
    if (main.mlx_connection == NULL)
        return(1);
    main.mlx_win = mlx_new_window(main.mlx_connection, WIDTH, HEIGHT, "Fil De Fer");
    if (NULL == main.mlx_win)
    {
        mlx_destroy_display(main.mlx_connection);
        free(main.mlx_connection);
        return (1);
    }
            // painting the screen
    main.img.img_ptr = mlx_new_image(main.mlx_connection, WIDTH, HEIGHT); //creating an image
    main.img.img_pixels_ptr = mlx_get_data_addr(main.img.img_ptr, &main.img.bits_per_pixel, &main.img.line_len, &main.img.endian); //memory info about the image

    // dot_pointers(&main, &grid);
    ft_render(&main, &grid);
    mlx_key_hook(main.mlx_win, fdf_keyhook, &main);
    mlx_mouse_hook(main.mlx_win, fdf_mouse, &main);
    mlx_loop(main.mlx_connection);
    return (0);
}

//separate function for creation of dot pointers
static void  dot_pointers(t_window *main, grid *grid)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < grid->length) // creating info for each DOT in an array of arrays.
    {
        j = 0;
        while (j < grid->height)
        {
            main->dot[i][j].img_ptr = mlx_new_image(main->mlx_connection, 1, 1);
            main->dot[i][j].img_pixels_ptr = mlx_get_data_addr(main->dot[i][j].img_ptr, &main->dot[i][j].bits_per_pixel, &main->dot[i][j].line_len, &main->dot[i][j].endian);
            j++; 
        }
        i++;
    }
}