#include <stdio.h>
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len);
int	main(void)
{
	char	*str = "1337 Network";
	char	*res;

	// Test 1: normal substring
	res = ft_substr(str, 5, 7);
	printf("Test 1 -> '%s'\n", res);
	free(res);

	// Test 2: start = 0
	res = ft_substr(str, 0, 4);
	printf("Test 2 -> '%s'\n", res);
	free(res);

	// Test 3: len bigger than string length
	res = ft_substr(str, 5, 50);
	printf("Test 3 -> '%s'\n", res);
	free(res);

	// Test 4: start beyond string length
	res = ft_substr(str, 20, 5);
	printf("Test 4 -> '%s'\n", res);
	free(res);

	// Test 5: len = 0
	res = ft_substr(str, 3, 0);
	printf("Test 5 -> '%s'\n", res);
	free(res);

	return (0);
}
