/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susong <susong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:04:10 by susong            #+#    #+#             */
/*   Updated: 2023/02/05 11:27:07 by susong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./mlx/mlx.h"
# include "./library/lib.h"
# include <math.h>
# include <fcntl.h>

# define MLX_WIDTH 1280
# define MLX_HEIGHT 720
# define MLX_ASPECT 1.777778
# define EPSILON 4.94065645841247E-324
# define MAX 1.7976931348623157E+308

typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;
typedef struct s_mlx	t_mlx;

struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_cam
{
	t_vec3	point;
	t_vec3	dir;
	double	fov;
}	t_cam;

typedef struct s_sphere
{
	t_vec3			center;
	double			radius;
	double			radius2;
	t_color3		color;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	t_vec3			point;
	t_vec3			dir;
	t_color3		color;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3				point;
	t_vec3				dir;
	double				diameter;
	double				height;
	t_vec3				color;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_light
{
	t_vec3		point;
	double		brightness;
	t_color3	light_color;
	double		amb_brightness;
	t_color3	amb_color;
}	t_light;

typedef struct s_objects
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
}	t_objects;

typedef struct s_viewport
{
	t_vec3	origin;
	double	width;
	double	height;
	double	focal_length;
	t_vec3	right;
	t_vec3	down;
}	t_viewport;

typedef struct s_scene
{
	t_cam		camera;
	t_objects	objects;
	t_light		lights;
	t_viewport	viewport;
}	t_scene;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direct;
	double	distance;
}	t_ray;

typedef struct s_hit
{
	double		distance;
	t_point3	hit_point;
	t_vec3		hit_normal;
	t_vec3		color;
}	t_hit;

typedef struct s_acl_check
{
	int	ambient;
	int	camera;
	int	light;
}	t_acl_check;
//parse.c
int			name_check(char *name);
t_scene		init_scene(char *filename);
//mlx_hook.c
int			key_hook(int keycode, t_mlx *vars);
int			end_hook(t_mlx *vars);
int			ft_exit(int code);
//calc.c
t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_point3	color3(double r, double g, double b);
void		vset(t_vec3 *vec, double x, double y, double z);
double		vlength2(t_vec3 vec);
double		vlength(t_vec3 vec);
t_vec3		vplus(t_vec3 vec, t_vec3 vec2);
t_vec3		vplus_(t_vec3 vec, double x, double y, double z);
t_vec3		vminus(t_vec3 vec, t_vec3 vec2);
t_vec3		vminus_(t_vec3 vec, double x, double y, double z);
t_vec3		vmult(t_vec3 vec, double t);
t_vec3		vmult_(t_vec3 vec, t_vec3 vec2);
double		vdot(t_vec3 vec, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec, t_vec3 vec2);
t_vec3		vunit(t_vec3 vec);
t_vec3		vmin(t_vec3 vec1, t_vec3 vec2);
//parsing
void		make_ambient(t_scene *out, char *line, t_acl_check *acl_check);
void		make_camera(t_scene *out, char *line, t_acl_check *acl_check);
void		make_light(t_scene *out, char *line, t_acl_check *acl_check);
void		make_plane(t_scene *out, char *line);
void		make_sphere(t_scene *out, char *line);
void		make_cylinder(t_scene *out, char *line);
void		valid_parse_data(char **point, int length);
void		check_value_range(t_scene out, t_acl_check *acl_check);
//ray
t_hit		init_hit(void);
t_ray		ray_init(t_scene scene, double x, double y);
t_color3	make_color(t_scene scene, t_ray ray);
int			check_all_sphere(t_scene scene, t_ray ray, t_hit *hit);
int			check_sphere(t_sphere *sphere, t_ray ray, t_hit *hit);
int			check_all_plane(t_scene scene, t_ray ray, t_hit *hit);
int			check_plane(t_plane *plane, t_ray ray, t_hit *hit);
int			check_cylinder_cap(t_cylinder *cylinder, \
t_ray ray, t_hit *hit, double height);
int			check_cylinder_side(t_cylinder *cylinder, t_ray ray,
				t_hit *hit, double distance);
int			check_all_cylinder(t_scene scene, t_ray ray, t_hit *hit);
int			check_cylinder(t_cylinder *cylinder, t_ray ray, t_hit *hit);
int			is_shadow(t_vec3 point, t_scene scene);
double		check_height(t_cylinder *cylinder, t_vec3 point);
t_vec3		cylinder_normal(t_cylinder *cylinder, t_vec3 point, double height);
//light
double		diffuse(t_scene scene, t_hit hit);
#endif
