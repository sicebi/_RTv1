/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 09:06:39 by antini            #+#    #+#             */
/*   Updated: 2018/09/28 09:06:40 by antini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIN_X		1000
# define WIN_Y		700
# define R			100

# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef unsigned int	u_int;
typedef struct			s_xyz
{
	double				x;
	double				y;
	double				z;
}						t_xyz;
typedef enum			e_type
{
	SPHERE,
	CYLINDER,
	CONE,
	PLAN
}						t_type;
typedef struct			s_obj
{
	t_type				type;
	t_xyz				pos;
	t_xyz				rot;
	u_int				color;
	struct s_obj		*next;
}						t_obj;
typedef struct			s_img
{
	void				*ptr;
	char				*data;
	int					x;
	int					y;
	int					bpp;
	int					sline;
	int					endian;
}						t_img;
typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	t_img				screen;
	t_obj				*objs;
	t_xyz				eye;
	t_xyz				eyerot;
	t_xyz				plan;
	t_xyz				vector;
	t_xyz				spot;
	t_xyz				spot2;
	double				focale;
	double				k;
	t_obj				*cur_obj;
}						t_mlx;

void				ft_calc_rtv1(t_mlx *mlx);
void				all_rot(t_xyz *xyz, t_xyz *rot, int invert);
void				ft_pxl_puting(t_mlx *mlx, int x, int y, u_int color);
void				ft_putstr(const char *str);
int					ft_puterror(char *str);
int					ft_keypress(int keycode, t_mlx *mlx);
int					get_expose(t_mlx *mlx);
t_obj				*obj_new(t_type type, t_xyz pos,
							t_xyz rot, u_int color);
void				obj_pushback(t_obj **list, t_obj *new);
void				calc_sphere(t_xyz *eye, t_xyz *vector, double *k);
void				calc_cylinder(t_xyz *eye, t_xyz *vector, double *k);
void				calc_cone(t_xyz *eye, t_xyz *vector, double *k);
void				calc_plan(t_xyz *eye, t_xyz *vector, double *k);
void				calc_curobj(t_xyz *eye, t_xyz *vector,
								t_obj *obj, double *k);
u_int				calc_light(t_mlx *mlx, t_xyz *spot);
u_int				shadow_cast(t_mlx *mlx, t_xyz *spot, u_int cur_color);
u_int				ft_mult_color(u_int color, double perc);
u_int				ft_add_2color(u_int color1, u_int color2);
void				move_eye(t_xyz *eye, t_xyz *vector,
							t_obj *tmp, int invert);
#endif
