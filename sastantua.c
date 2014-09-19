/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssegal <ssegal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/01 14:19:25 by ssegal            #+#    #+#             */
/*   Updated: 2014/09/01 18:12:03 by adethieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int             ft_putchar(char c);

int             ft_get_first_line_blanks(int size)
{
	int height;
	int i;
	int last_line_width;
	int blanks;

	height = 0;
	i = 0;
	while (i < size)
	{
		height = i + 3;
		++i;
	}
	last_line_width = height * (size * 2) + 1;
	blanks = last_line_width / 2;
	return (blanks);
}

char    ft_get_door_chars(int handle_x, int handle_y,
		int cpt_stars, int cpt_height)
{
	if (handle_x != 0 && handle_y != 0
			&& cpt_stars == handle_x && cpt_height == handle_y)
	{
		return ('$');
	}
	else
	{
		return ('|');
	}
}

void    ft_print_inside_char(int door_data[], int cpt_height,
		int cpt_stars, int nb_char_line)
{
	int start_char;
	int end_char;
	int handle_x;
	int handle_y;

	handle_x = 0;
	handle_y = 0;
	start_char = (nb_char_line - door_data[0]) / 2;
	end_char = nb_char_line - start_char;
	if (door_data[0] >= 5)
	{
		handle_x = end_char - 2;
		handle_y = (door_data[0] / 2) + door_data[1];
	}
	if (door_data[1] != 0 && door_data[1] <= cpt_height
			&& cpt_stars >= start_char && cpt_stars < end_char)
	{
		ft_putchar(ft_get_door_chars(handle_x, handle_y,
					cpt_stars, cpt_height));
	}
	else
	{
		ft_putchar('*');
	}
}

void    ft_print_section(int *stars, int *blanks, int section_height,
		int door_data[])
{
	int cpt_blanks;
	int cpt_stars;
	int cpt_height;

	cpt_height = 1;
	while (cpt_height <= section_height)
	{
		cpt_blanks = 1;
		cpt_stars = 1;
		while (cpt_blanks <= *blanks)
		{
			ft_putchar(' ');
			++cpt_blanks;
		}
		ft_putchar('/');
		while (cpt_stars <= *stars)
		{
			ft_print_inside_char(door_data, cpt_height, cpt_stars, *stars + 2);
			++cpt_stars;
		}
		ft_putchar('\\');
		ft_putchar('\n');
		*blanks = *blanks - 1;
		*stars = *stars + 2;
		++cpt_height;
	}
}

void    sastantua(int size)
{
	int i;
	int blanks;
	int section_height;
	int stars;
	int door_data[2];

	section_height = 3;
	i = 1;
	stars = 1;
	blanks = ft_get_first_line_blanks(size);
	while (i <= size && size > 0)
	{
		if (i == size)
		{
			door_data[0] = size - 1;
			if (size % 2 != 0)
				door_data[0] = size;
			door_data[1] = section_height - (door_data[0] - 1);
		}
		ft_print_section(&stars, &blanks, section_height, door_data);
		blanks = blanks - 2;
		stars = stars + 4;
		++section_height;
		++i;
	}
}
