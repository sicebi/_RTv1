/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 09:04:34 by antini            #+#    #+#             */
/*   Updated: 2018/09/28 09:04:36 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

u_int		ft_mult_color(u_int color, double perc)
{
	int		i;
	int		n_color[3];

	i = -1;
	while (++i < 3)
	{
		n_color[i] = (color >> ((2 - i) << 3)) & 0xFF;
		n_color[i] = n_color[i] * perc;
		n_color[i] = (n_color[i] > 0xFF ? 0xFF : n_color[i]);
		n_color[i] = (n_color[i] < 0 ? 0 : n_color[i]);
	}
	return ((n_color[0] << 16) + (n_color[1] << 8) + n_color[2]);
}

u_int		ft_add_2color(u_int color1, u_int color2)
{
	int		i;
	int		n_color1[3];
	int		n_color2[3];

	i = -1;
	while (++i < 3)
	{
		n_color1[i] = (color1 >> ((2 - i) << 3)) & 0xFF;
		n_color2[i] = (color2 >> ((2 - i) << 3)) & 0xFF;
		n_color1[i] = n_color1[i] + n_color2[i];
		n_color1[i] = (n_color1[i] > 0xFF ? 0xFF : n_color1[i]);
		n_color1[i] = (n_color1[i] < 0 ? 0 : n_color1[i]);
	}
	return ((n_color1[0] << 16) + (n_color1[1] << 8) + n_color1[2]);
}
