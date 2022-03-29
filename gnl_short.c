/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl_short.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 11:26:56 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/03/29 11:26:57 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*get_next_line_short(int fd)
{
	int		ret;
	int		i;
	char	c;
	char	*buf = malloc(100000);

	for(i = 0; (ret = read(fd, &c, 1) > 0); i++)
	{
		buf[i] = c;
		if (c == '\n')
			break;
	}
	if ((ret == -1) || (ret == 0) || (!buf[i - 1]))
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	buf[i + 1] = '\0';
	return (buf);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line_short(fd);
	printf("%s", line);
	line = get_next_line_short(fd);
	printf("%s", line);
	line = get_next_line_short(fd);
	printf("%s", line);
	line = get_next_line_short(fd);
	printf("%s", line);
}
