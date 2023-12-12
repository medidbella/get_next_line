#include "get_next_line.h"

int main()
{
	int fd = open("to_read_write.txt", O_RDONLY);
	char *res = scaner(fd, NULL);
	printf("after scaner function =>|%s|\n", res);
	res = get_the_line(res);
	printf("after get_the_line function =>|%s|\n", res);
	free(res);
	close(fd);
}