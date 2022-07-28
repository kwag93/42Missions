#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct s_zone
{
	int width;
	int height;
	char background;
}t_zone;

typedef struct s_shape
{
	char type;
	float x;
	float y;
	float radius;
	char color;
}t_shape;

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

int ft_error(char *str)
{
	if(str)
		write(1, str, ft_strlen(str));
	return 1;
}

int clear(FILE *file, char *drawing, char *str)
{
	if (file)
		fclose(file);
	if (drawing)
		free(drawing);
	if (str)
		ft_error(str);
	return 1;
}

char	*get_zone(FILE *file, t_zone *zone)
{
	char *tmp;
	int i;

	if (fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background) != 3)
		return NULL;
	if (zone->width <= 0 || zone->width > 300 || zone->height <= 0 || zone->height > 300)
		return NULL;
	if(!(tmp = (char*)malloc(sizeof(char) * (zone->height * zone->width))))
		return NULL;
	i = 0;
	while(i < zone->width * zone->height)
		tmp[i++] = zone->background;
	return tmp;
}
int		in_circle(float x, float y, t_shape *shape)
{
	float dist;

	dist = sqrtf(powf(x - shape->x, 2.f) + powf(y - shape->y, 2.f));
	if (dist <= shape->radius)
	{
		if(shape->radius - dist < 1.f)
			return 2;
		return 1;
	}
	return 0;
}

void	draw_shape(char *drawing, t_zone *zone, t_shape *shape)
{
	int y;
	int x;
	int is_it;

	y = 0;
	while(y < zone->height)
	{
		x = 0;
		while(x < zone->width)
		{
			is_it = in_circle((float)x, (float)y, shape);
			if((shape->type == 'c' && is_it == 2)
			|| (shape->type == 'C' && is_it))
				drawing[(y * zone->width) + x] = shape->color;
			x++;
		}
		y++;
	}
}

int		draw_shapes(FILE *file, char *drawing, t_zone *zone)
{
	int ret;
	t_shape shape;

	while((ret = fscanf(file, "%c %f %f %f %c\n", &shape.type, &shape.x, &shape.y, &shape.radius, &shape.color)) == 5)
	{
		if ((shape.type != 'c' && shape.type != 'C') || shape.radius <= 0.f)
			return 0;
		draw_shape(drawing, zone, &shape);
	}
	if(ret != -1)
		return 0;
	return 1;
}

void write_s(char *drawing, t_zone *zone)
{
	int i;

	i = 0;
	while(i < zone->height)
	{
		write(1, drawing + (i * zone->width), zone->width);
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	FILE *file;
	char *drawing;
	t_zone zone;

	zone.width = 0;
	zone.height = 0;
	zone.background = 0;
	if (argc != 2)
		return ft_error("Error: argument\n");
	else
	{
		if(!(file = fopen(argv[1], "r")))
			return ft_error("Error: Operation file corrupted\n");
		if(!(drawing = get_zone(file, &zone)))
			return clear(file, NULL, "Error: Operation file corrupted\n");
		if(!(draw_shapes(file, drawing, &zone)))
			return clear(file, drawing , "Error: Operation file corrupted\n");
		write_s(drawing, &zone);
		clear(file, drawing, NULL);
	}
	return 0;
}
