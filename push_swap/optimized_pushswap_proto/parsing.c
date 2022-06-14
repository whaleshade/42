/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:00:17 by jibang            #+#    #+#             */
/*   Updated: 2022/06/13 19:51:42 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_include_non_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '+' || s[i] == '-')
		{
			i++;
			continue ;
		}
		else if (ft_isdigit(s[i]))
		{
			i++;
			continue ;
		}
		else
			return (1);
		i++;
	}
	return (0);
}

int	ft_syntax_error(int ac, char **av)
{
	int	i;
	int	err_check;

	i = 1;
	err_check = 0;
	while (i < ac)
	{
		if (ft_include_non_num(av[i]))
			err_check++;
		i++;
	}
	if (err_check != 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int ft_overflow_check(const char *str)
{
    long long	i;
    long long	sign;
    long long	n;

    i = 0;
    sign = 1;
    n = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i])
        n = n * 10 + (str[i++] - '0');
	if ( sign * n > 2147483647 || sign * n < -2147483648)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int	ft_check_duplicates(int *parsed, int k)
{
	int		i;

	i = 0;
	while (i < k)
	{
		if (parsed[i] == parsed[k])
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_is_white_space(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' \
			|| str[i] == '\b' || str[i] == '\v' \
			|| str[i] == '\n' || str[i] == '\r' \
			|| str[i] == '\f' || str[i] == '\a')
		{
			j++;
			if (j == (int)ft_strlen(str))
			{
				ft_printf("Error\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_is_nul(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
