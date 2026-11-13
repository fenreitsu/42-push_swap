/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfavela- <rfavela-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:55:41 by rfavela-          #+#    #+#             */
/*   Updated: 2026/11/13 22:38:35 by rfavela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match_flag(char *flag)
{
	int	flag_len;

	flag_len = ft_strlen(flag);
	if ((flag_len == 8) && (ft_strncmp(flag, "--simple", flag_len)) == 0)
		return (1);
	if ((flag_len == 8) && (ft_strncmp(flag, "--medium", flag_len)) == 0)
		return (2);
	if ((flag_len == 9) && (ft_strncmp(flag, "--complex", flag_len)) == 0)
		return (3);
	if ((flag_len == 10) && (ft_strncmp(flag, "--adaptive", flag_len)) == 0)
		return (4);
	if ((flag_len == 7) && (ft_strncmp(flag, "--bench", flag_len)) == 0)
		return (5);
	return (0);
}

char	parse_args(int argc, char** argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		argv[i]
		i++;
	}
}