/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:57:40 by otiniako          #+#    #+#             */
/*   Updated: 2018/02/28 18:49:37 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		check(int len, char *base)
{
	int i;
	int j;

	i = 0;
	while (base[len] != '\0')
		len++;
	if (len > 1)
		while (++i < len && i != -1)
		{
			j = i;
			while (++j < len && i != -1)
				if (base[i] == base[j] || base[i] == '-' || base[i] == '+')
					return (0);
		}
	return (len);
}

static int		ft_strcmp1(char s1, char *s2)
{
	if (s1 && *s2 && s1 != *s2)
		return (ft_strcmp1(s1, s2 + 1));
	else
		return (s1 - *s2);
}

static int		count(int i, char s1, char *s2)
{
	while (s1 && *s2 && s1 != s2[i])
		i++;
	return (i);
}

int				ft_atoi_base(char *str, char *base)
{
	int nb[4];

	nb[0] = 0;
	nb[1] = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	nb[3] = check(0, base);
	if (*str != '-' && *str != '+' && ft_strcmp1(*str, base) && !nb[3])
		return (0);
	if (*str == '-')
	{
		nb[1] = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (!ft_strcmp1(*str, base))
	{
		nb[0] *= nb[3];
		nb[2] = count(0, *str, base);
		nb[0] += nb[2];
		str++;
	}
	return (nb[1] == 1 ? -nb[0] : nb[0]);
}
