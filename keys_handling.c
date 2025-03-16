/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:37 by emarles           #+#    #+#             */
/*   Updated: 2025/02/16 17:18:10 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int close_win(int keycode, t_window *main)
{
    printf("key '%i' has been pressed\n", keycode);
    if (keycode == XK_Escape)
    {
        printf("The exit\n");
        mlx_destroy_window(main->mlx_connection, main->mlx_connection);
        mlx_destroy_display(main->mlx_connection);
        free(main->mlx_connection);
        exit(1);
    }
    return (0);
}

int mouse_function(int button, int x, int y, void *param)
{
    printf("mouse %i key has been pressed\n", button);
    return (0);
}
