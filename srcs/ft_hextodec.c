/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:51:45 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/13 15:11:36 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	chk_base(char c, int *base, int *dec)
{
	if (c >= '0' && c <= '9')
	{
		*dec += (c - 48) * *base;
		*base = *base * 16;
	}
	else if (c >= 'A' && c <= 'F')
	{
		*dec += (c - 55) * *base;
		*base = *base * 16;
	}
	else if (c >= 'a' && c <= 'f')
	{
		*dec += (c - 87) * *base;
		*base = *base * 16;
	}
	else
		return (-1);
	return (0);
}

int			ft_hextodec(char *hex, int *dec)
{
	int		hlen;
	int		base;

	base = 1;
	*dec = 0;
	hlen = ft_strlen(hex);
	hlen--;
	while (hlen >= 0)
	{
		if (chk_base(hex[hlen], &base, dec) < 0)
			return (-1);
		hlen--;
	}
	return (0);
}
