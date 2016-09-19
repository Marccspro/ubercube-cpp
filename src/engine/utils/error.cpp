#include "error.h"

int error(const char *error)
{
	write(1, "ERROR:", 6);
	while (*(error++))
		write(1, error - 1, 1);
	write(1, "\n", 1);
}

int sever(const char *error)
{
	write(1, "SEVER:", 6);
	while (*(error++))
		write(1, error - 1, 1);
	write(1, "\n", 1);
	exit(1);
}
