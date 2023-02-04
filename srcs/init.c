#include "../includes/cub3d.h"

void	init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Addams_cube");
	data->texture[NORTH].img = ft_calloc(1, sizeof(t_img));
	data->texture[SOUTH].img = ft_calloc(1, sizeof(t_img));
	data->texture[EAST].img = ft_calloc(1, sizeof(t_img));
	data->texture[WEST].img = ft_calloc(1, sizeof(t_img));
}

void	init_image(t_data *data, t_img *img)
{
	img->ptr = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->data = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->size_l, &img->endian);
}

void	init_texture(t_data *data, t_texture *texture, char *path)
{
	// printf("wot\n");
	texture->img->ptr = mlx_xpm_file_to_image(data->mlx, path, \
						&texture->width, &texture->height);
	texture->img->data = mlx_get_data_addr(texture->img->ptr, \
		&texture->img->bpp, &texture->img->size_l, &texture->img->endian);
	if (!texture->img->ptr)
		errno(TEXTURE, path, data);
}
