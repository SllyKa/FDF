/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:26:06 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 16:05:57 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_cont
{
	void	*mx_ptr;
	void	*wn_ptr;
}				t_cont;

t_cont			*init_tcont(void *a, void *b);

#endif