#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	// char	buffer[100000] = "Bonjour Adam je suis ton buffer d'aujourdhui";
	// ssize_t bytes_read;
	int		fd;
	char	*line;

	fd = open("multiple_nl.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	//buffer = "Bonjour Adam je suis ton buffer d'aujourdhui";
	// bytes_read = read(fd, buffer, 7000);
	// if (fd == -1)
	// 	return(1);
	// buffer[bytes_read] = '\0';
	printf("le fd est le numero: %d\n", fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return 0;
}
/*
int	ft_truc()
{
	if ((fd == -1) || (buffer == NULL) || (nbyte <= 0))
		return (0);

}
*/

