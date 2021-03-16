/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:36:02 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/16 17:43:11 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	struct_init(void)
{
	g_p.res_w = 0;
	g_p.res_h = 0;
	g_p.n_wall[0] = 0;
	g_p.n_wall[1] = 0;
	g_p.n_wall[2] = 0;
	g_p.s_wall[0] = 0;
	g_p.s_wall[1] = 0;
	g_p.s_wall[2] = 0;
	g_p.w_wall[0] = 0;
	g_p.w_wall[1] = 0;
	g_p.w_wall[2] = 0;
	g_p.e_wall[0] = 0;
	g_p.e_wall[1] = 0;
	g_p.e_wall[2] = 0;
	g_p.sky[0] = 0;
	g_p.sky[1] = 0;
	g_p.sky[2] = 0;
	g_p.floor[0] = 0;
	g_p.floor[1] = 0;
	g_p.floor[2] = 0;
	g_p.ceiling[0] = 0;
	g_p.ceiling[1] = 0;
	g_p.ceiling[2] = 0;
}

int	main()
{
	char	**line;
	int		fd_map;
	int		i;
	int		rd;

	fd_map = open("map.cub", O_RDONLY);
	i = 1;
	struct_init();
	while (i)
	{
		i = get_next_line(fd_map, line);
		if(i == 1)
    	    i = parsing(line);
		else
			write(1, "Error!\n", 7);
	}
	printf("\n|heigth: %d|\n", g_p.res_h);
	printf("\n|width: %d|\n", g_p.res_w);
	printf("\n|NO: %d, %d, %d|\n", g_p.n_wall[0], g_p.n_wall[1], g_p.n_wall[2]);
	return (0);
}