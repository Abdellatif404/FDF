/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bouz <ael-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:05:51 by ael-bouz          #+#    #+#             */
/*   Updated: 2024/04/19 20:25:04 by ael-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

# define SUCCESS 0
# define FAILURE -1
# define WIN_HEIGHT 1250
# define WIN_WIDTH 2200
# define OFFSET 50

typedef struct s_pixel_info
{
	int		r;
	int		g;
	int		b;
	float	r_steps;
	float	g_steps;
	float	b_steps;
	float	r_remainder;
	float	g_remainder;
	float	b_remainder;
}			t_pixel_info;

typedef struct s_line_params
{
	t_pixel_info	*pixel;
	int				dx;
	int				dy;
	int				decision;
	int				slope;
	int				scale;
}					t_line_params;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_matrix
{
	int				x_idx;
	int				y_idx;
	int				x;
	int				y;
	int				z;
	int				red;
	int				green;
	int				blue;
	struct s_matrix	*right;
	struct s_matrix	*down;
}					t_matrix;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_matrix	**head;
	t_img		img;
	int			shape_height;
	int			shape_width;
	int			steps;
}				t_mlx;

int	max(int n1, int n2);
int	free_if_and_close(char *line, char *buff, int fd);
int	free_line(char *line);
char	**free_array(char **ptr);
void	*free_matrix(t_matrix **head);

int			ft_htoi(char *s);
int			ft_atoi(char *s);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		**ft_split(char *s, char c);

int			free_line(char *line);
char		**free_array(char **ptr);
void		verify_filename(int ac, char **av);
void		get_file_dimensions(char *filename, t_mlx *data);
t_matrix	**create_matrix(t_mlx *data);
int			parse_map(char *filename, t_matrix **head);
int			draw_map(t_mlx *mlx, t_matrix **head);
void	img_pixel_put(t_img *img, int x, int y, int color);
void		bresenham(t_img *img, t_matrix *point1, t_matrix *point2, t_line_params *params);

// void	connect_points(t_mlx mlx, int x1, int y1, int x2, int y2);

#endif
