/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sglass <sglass@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:46:54 by sglass            #+#    #+#             */
/*   Updated: 2021/01/25 13:10:23 by sglass           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx_opengl_20191021 2/mlx.h"
# define BUFFER_SIZE 1

typedef struct		s_data
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	void			*w_img;
	void			*so_img;
	void			*n_img;
	void			*e_img;
	void			*sp_img;
	char			*addr;
	char			*w_ad;
	char			*so_ad;
	char			*n_ad;
	char			*e_ad;
	char			*sp_ad;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				x;
	int				y;
	double			perpwalldist;
	double			planex;
	double			planey;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			deltadistx;
	double			deltadisty;
	double			olddirx;
	double			oldplanex;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
	int				wasd[6];
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			weight;
	double			currentfloorx;
	double			currentfloory;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				stripe;
	int				d;
	int				texww;
	int				texhw;
	int				texwe;
	int				texhe;
	int				texws;
	int				texhs;
	int				texwn;
	int				texhn;
	int				texwsp;
	int				texhsp;
	int				i;
	unsigned int	color;
	int				r;
	int				g;
	int				b;
	int				filesize;
	int				fd;
	char			*dst;
	unsigned char	*img2;
	int				flag;
}					t_data;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_squire
{
	int		haserr;
	int		countparametres;
	int		xrender;
	int		yrender;
	int		floorr;
	int		floorg;
	int		floorb;
	int		ceillingr;
	int		ceillingg;
	int		ceillingb;
	int		countplayer;
	char	*ntxt;
	char	*stxt;
	char	*wtxt;
	char	*etxt;
	char	*sptxt;
	char	player;
	int		xplayer;
	int		yplayer;
	int		flagrender;
	int		flagfloor;
	int		flagceilling;
	int		flagnorthtexture;
	int		flagsouthtexture;
	int		flagwesttexture;
	int		flageasttexture;
	int		flagspritetexture;
	char	**tmap;
	int		**sprites;
	int		numsprites;
}					t_squire;

typedef struct		s_errors
{
	int rendererr;
	int northtextureerr;
	int southtextureerr;
	int westtextureerr;
	int easttextureerr;
	int spritetextureerr;
	int floorerr;
	int ceillingerr;
	int mapsymbolerr;
	int firstlineerr;
	int lastlineerr;
	int surrounderr;
	int haserr;
}					t_errors;

typedef struct		s_collect
{
	t_data		img;
	t_squire	squire;
}					t_collect;

void				exit2(void);
void				scr1(t_collect *collect);
void				scr2(t_collect *collect);
void				scr3(t_collect *collect, int i, int j);
void				scr4(t_collect *collect);
void				screen(t_collect *collect);
int					checkargs(int argc, char **argv);
void				*ft_memset(void *b, int c, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
void				inittextures(t_collect *collect);
void				errorexit(t_collect *collect);
int					redexit(t_collect *collect);
void				countsprites(char **map, t_collect
	*collect, t_errors *errors);
void				mallocsprites(char **map, t_collect *collect,
	t_errors *err, int count);
void				takepossprites(char **map, t_collect *collect);
void				wkey(t_collect *collect);
void				akey(t_collect *collect);
void				skey(t_collect *collect);
void				dkey(t_collect *collect);
void				lkey(t_collect *collect);
void				rkey(t_collect *collect);
int					render_next_frame(t_collect *collect);
int					nopush(int keycode, t_collect *collect);
int					push(int keycode, t_collect *collect);
void				my_mlx_pixel_put(t_collect *collect, int x, int y,
	int color);
void				wtext2(t_collect *collect);
void				etext2(t_collect *collect);
void				ntext2(t_collect *collect);
void				stext2(t_collect *collect);
void				sprites(t_collect *collect, double *zbuffer);
void				sprites2(t_collect *col, int i);
void				sprites3(t_collect *col, double *zbuffer);
void				sorter(t_collect *collect);
void				sorter2(t_collect *collect, int x, int y, int i);
void				ntext(t_collect *collect);
void				etext(t_collect *collect);
void				stext(t_collect *collect);
void				wtext(t_collect *collect);
void				floors(t_collect *collect);
void				floors2(t_collect *collect);
void				calclineheight(t_collect *collect);
void				game_engine(t_collect *collect);
void				camdist(t_collect *collect);
void				checkhit(t_collect *collect);
void				calcstep(t_collect *collect);
void				movement(t_collect *collect);
void				eastplayer(t_collect *collect);
void				southplayer(t_collect *collect);
void				northplayer(t_collect *collect);
void				westplayer(t_collect *collect);
void				init_player(t_collect *collect);
void				initkeys(t_collect *col);
void				initimgs(t_collect *col);
void				takepossprites(char **map, t_collect *collect);
void				mallocsprites(char **map, t_collect *col,
	t_errors *errors, int count);
void				countsprites(char **map, t_collect *collect,
	t_errors *errors);
void				getfloors3(char *map, t_collect *collect);
int					getfloors2(char *map);
void				getfloors1(char *map, t_collect *collect, t_errors *errors);
int					scipspaces(char *map);
void				getceill3(char *map, t_collect *collect);
int					getceill2(char *map);
void				getceill1(char *map, t_collect *collect, t_errors *errors);
void				getreso2(char *map, t_collect *collect);
void				getreso1(char *map, t_collect *collect, t_errors *errors);
void				getnorth(char *map, t_collect *collect, t_errors *errors);
void				getsouth(char *map, t_collect *collect, t_errors *errors);
void				getwest(char *map, t_collect *collect, t_errors *errors);
void				geteast(char *map, t_collect *collect, t_errors *errors);
void				getsprite(char *map, t_collect *collect, t_errors *errors);
int					checkemptylines(char **map, t_errors *errors);
void				checksymbols(char **m, t_collect *collect,
	t_errors *errors);
void				checksurround(char **map, int countlines, t_errors *errors);
int					countparameters(t_collect *collect);
void				validmap(char **map, t_collect *collect, t_errors *errors);
void				initializationsquire(t_collect *collect);
void				mlxwindow(t_collect *collect);
void				checkerrors1(t_errors *errors, t_collect *collect);
void				checkerrors2(t_errors *errors, t_collect *collect);
void				finalinputvalidation(t_errors *errors);
void				parseinputparameters(char **map, t_collect *collect,
	t_errors *errors);
void				parseinputparameters2(char *map, t_collect *collect,
	t_errors *errors);
void				initializationerrors(t_errors *errors);
char				**make_map(t_list **head, int size, int flag);
int					main(int argc, char **argv);
void				processinginputparameters(char **map, int flag);
char				*ft_strjoin(char const *s1, char const *s2);
int					try1(int fd, char **line, char *buf);
void				try2(char **line, char *buf);
int					gnl(char *buf, int fd, char **line);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strchr(const char *s, int c);
int					get_next_line(int fd, char **line);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_calloc(size_t count, size_t size);
void				ft_putendl_fd(char *s);
t_list				*ft_lstlast(t_list *lst);
size_t				ft_strlen(const char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_putnbr_fd(int n);
#endif
