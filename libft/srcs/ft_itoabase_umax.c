/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_umax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:01:46 by tpereira          #+#    #+#             */
/*   Updated: 2021/04/22 22:40:11 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  get_unumlen(size_t num, int base)
{
    int i;

    i = 1;
    while (num /= base)
        i++;
    return (i);
}

/*
** The ft_itoabase_umax() function takes an unsigned size_t number and
** converts it into a string, printed in the specified base
*/

char    *ft_itoabase_umax(size_t num, int base)
{
    char    *str;
    int     len;
    char    *basestr;

    basestr = ft_strdup("0123456789abcdef");
    len = get_unumlen(num, base);
    if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
        return NULL;
    str[len] = '\0';
    str[--len] = basestr[num % base];
    while (num /= base)
        str[--len] = basestr[num % base];
    free(basestr);
    return (str);
}