#include "main.h"

int main(void)
{
	char *s1 = "3843884348";
	char *s2 = "92";
	char *res = NULL;

	res = multiply(s1, s2);
	printf("the result of %s x %s is :\t%s\n", s1, s2, res);
	free(res);
	return (EXIT_SUCCESS);
}
