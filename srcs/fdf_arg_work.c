/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_arg_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:37:13 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/10 19:51:30 by gbrandon         ###   ########.fr       */
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
		printf("%s\n", msg);
	ft_printf("usage: fdf [file ...]\n");
}

static void		arg_check(int argc, char **argv)
{
	int		fd;

	if (argc < 2 || argc > 2)
	{
		arg_usg("fdf: illegal numbers of arguments");
		exit (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror("fdf_file");
		arg_usg(NULL);
		exit (0);
	}
	close(fd);
}

int				fdf_arg_process(int argc, char **argv)
{
	int		fd;
	
	arg_check(argc, argv);
	fd = open(argv[1], O_RDONLY);
	return (fd);
}