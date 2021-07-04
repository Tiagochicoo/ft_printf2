/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type_and_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:28:39 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/04 18:46:43 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_type(t_arg *arg_struc)
{
	char	s;

	s = arg_struc->specifier;
	if (s == 'c')
		arg_struc->type = is_char;
	else if (s == 's')
		arg_struc->type = is_string;
	else if (s == 'p')
		arg_struc->type = is_unum;
	else if (s == 'd' || s == 'i')
		arg_struc->type = is_snum;
	else if (s == 'u')
		arg_struc->type = is_unum;
	else if (s == 'x' || s == 'X')
		arg_struc->type = is_snum;
	else if (s == '%')
		arg_struc->type = is_escape;
	else
		arg_struc->type = is_null;
}

void	set_unum(t_arg *arg_struct, va_list *args)
{
	size_t	unum;

	if (arg_struct->specifier == 'p')
		unum = va_arg(*args, size_t);
	arg_struct->data = &unum;
	set_base(arg_struct);
	arg_struct->str = ft_itoabase_umax(unum, arg_struct->base);
}

void	set_snum(t_arg *arg_struct, va_list *args)
{
	intmax_t	snum;
	char		*str;

	snum = va_arg(*args, int);
	arg_struct->data = &snum;
	set_is_negative(arg_struct, snum);
	if (snum < 0)
	{
		snum *= -1;
		str = ft_itoabase_umax(snum, arg_struct->base);
		arg_struct->str = str;
		arg_struct->is_negative = 0;
		free(str);
	}
	else
	{
		str = ft_itoabase_umax(snum, arg_struct->base);
		arg_struct->str = str;
	}
}

void	set_escape(t_arg *arg_struct, va_list *args)
{
	char	c;

	(void)args;
	c = arg_struct->specifier;
	arg_struct->data = &c;
	if (c)
		arg_struct->str = ft_chrtostr(c);
}

void	set_data(t_arg *arg_struct, va_list *args)
{
	void	(*set_datatype[8])(t_arg *, va_list *);

	set_datatype[is_char] = set_char;
	set_datatype[is_string] = set_string;
	set_datatype[is_unum] = set_unum;
	set_datatype[is_snum] = set_snum;
	set_datatype[is_escape] = set_escape;
	set_datatype[arg_struct->type](arg_struct, args);
}
