/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psatoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:49:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/13 15:12:10 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_psatoi_top(char *str, int *sign, long int *res)
{
	*sign = 1;
	*res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
			*str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

int			ft_psatoi(char *str, int *er_cod, char **lstpntr)
{
	long int	res;
	int			sign;

	str = ft_psatoi_top(str, &sign, &res);
	if (*str < '0' || *str > '9')
	{
		*er_cod = -3;
		*lstpntr = str;
		return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + ((*str++) - 48);
		if ((res * sign < -2147483648) || (res * sign > 2147483647))
			*er_cod = -1;
	}
	if (*str != '\0' && (*str < '0' || *str > '9'))
	{
		*er_cod = -2;
		*lstpntr = str;
	}
	return (res * sign);
}
