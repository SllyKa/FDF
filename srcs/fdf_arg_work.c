/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_arg_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:37:13 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/12 05:56:23 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

static void		arg_usg(char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	ft_printf("usage: fdf file... [colors: RGB]\n");
}

static void		check_clrs(int argc, char **argv, int *color)
{
	int		er;
	int		num;
	int		num_cntr;
	int		i;

	er = 0;
	i = 2;
	num_cntr = 2;
	while(argc < 6 && i < argc)
	{
		num = ft_satoi(argv[i], &er);
		if ((er < 0) || (num > 255) || (num < 0))
		{
			arg_usg("fdf_color: bad color");
			exit (0);
		}
		i++;
		*color |= ((*color & 0) | num) << 8 * (num_cntr);
		num_cntr--;
	}
}

static void		arg_check(int argc, char **argv, int *color)
{
	int		fd;

	if (argc < 2 || argc > 5)
	{
		arg_usg("fdf: illegal number of arguments");
		exit (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror("fdf_file");
		arg_usg(NULL);
		exit (0);
	}
	if (argc > 2 && argc < 6)
	{
		check_clrs(argc, argv, color);
	}
	close(fd);
}

int				fdf_arg_process(int argc, char **argv, int *color)
{
	int		fd;
	
	arg_check(argc, argv, color);
	fd = open(argv[1], O_RDONLY);
	return (fd);
}