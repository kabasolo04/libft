/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:29:48 by kabasolo          #+#    #+#             */
/*   Updated: 2024/01/30 12:25:03 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}

	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);

	ft_putchar_fd(nb % 10 + '0', fd);
}