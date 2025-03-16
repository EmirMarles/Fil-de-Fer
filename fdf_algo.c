/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:02:33 by emarles           #+#    #+#             */
/*   Updated: 2025/03/02 15:20:26 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_prelimenary_calculations(t_window * main, grid *grid);

void ft_calculate_position(t_window *main, grid *grid) 
{
    float x;
    float y;
    float z;
    int i;
    int j;
    float angle;
    
    angle = M_PI / 6; // for projection 30degree angle
    i = 0;
    z = 1;

    ft_prelimenary_calculations(main, grid);

    // while (i < grid->length) 
    // {
    //     j = 0;
    //     while (j < grid->height)
    //     {
    //         x = main->dot[i][j].x;
    //         y = main->dot[i][j].y;
    //         // y = main->dot->y;
    //         main->dot[i][j].x = x * cos(angle) - y * cos(angle); // formula for calculating x position
    //         main->dot[i][j].y = x * sin(angle) + y * sin(angle) - z; // formula for calculating y position
    //         printf("the %ist x position is %f\n",i, main->dot[i][j].x);
    //         printf("the %ist y position is %f\n",i, main->dot[i][j].y);
    //         j++;
    //     }
    //     i++;
    // }
}

void ft_prelimenary_calculations(t_window * main, grid *grid) // prelimenary point in space relative to the amount of rows
{
    int grid_width;
    int grid_heigth;
    int rows;
    int columns;
    int i; // for y vertice
    int j; // for x vertice

    i = 1;
    rows = 9; // functions to determine the grid HEIGHT/WIDTH will go here
    columns = 11; 

    grid_width = (grid->height) * 50; 
    grid_heigth = (grid->length)  * 50; // 50 is a PRELIMENARY spacing size between the dots placed. shall be changed later on 

    printf("the height of the grid is %i\n", grid->height);
    printf("the width of the grid is %i\n", grid->length);
    while (i < grid->length + 1) // columns = lentgh
    {  
        j = 0;
        while (j < grid->height)
        {
            main->dot[i - 1][j].x = (((WIDTH - grid_width) / 2) + (i * 50)); // both x and y positions for a dot
            main->dot[i - 1][j].y = ((HEIGHT - grid_heigth) / 2) * i * 50;
            printf("the initial %i position of the x %f\n", i - 1, main->dot[i - 1][j].x);
            j++;
        }
        i++;
    }
}