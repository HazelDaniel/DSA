#include "main.h"

unsigned int _strlen(char *c);
int is_digit(char c);
char to_digit(char c);

char *multiply(char *num1, char *num2)
{
	char *res_tmp = NULL, *str1 = NULL, *str2 = NULL;
	int *res_int_tmp = NULL;
	unsigned int i, j, k, len1, len2, res_len;
	// unsigned int prod;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	res_len = len1 + len2;
	/*checking for zeros*/
	if (len1 == 0 && *num1 == '0')
		return ("0");
	if (len2 == 0 && *num2 == '0')
		return ("0");
	str1 = (char *)malloc(len1 * sizeof(char));
	str2 = (char *)malloc(len2 * sizeof(char));
	res_tmp = (char *)malloc((len1 + len2) * sizeof(char));
	res_int_tmp = (int *)malloc((len1 + len2) * sizeof(int));/*sentinel values, not garbage*/
	if (str1 == NULL || str2 == NULL || res_tmp == NULL || res_int_tmp == NULL)
		return (NULL);
	
	/*reverse the strings for multiplication*/
	for (i = 0; i < len1; i++)
		*(str1 + i) = *(num1 + (len1 - 1 - i));
	for (j = 0; j < len2; j++)
		*(str2 + j) = *(num2 + (len2 - 1 - j));
	
	
	for (i = 0; i < len1; i++)
	{
		if (!(is_digit(*(str1 + i))))
		{
			puts("Error!");
			exit(98);
		}
		for (j = 0; j < len2; j++)
		{
			if (!(is_digit(*(str2 + j))))
			{
				puts("Error!");
				exit(98);
			}
			*(res_int_tmp + (i + j)) += ((to_digit(*(str1 + i)) * to_digit(*(str2 + j))));
			*(res_int_tmp + (i + j + 1)) += (*(res_int_tmp + (i + j)) / 10);
			*(res_int_tmp + (i + j)) %= 10;
		}
	}

	for (k = res_len - 1; *(res_int_tmp + k) == 0;)
		k --;
	
	res_len = k + 1;
	res_tmp = (char *)realloc(res_tmp, res_len + 1);

	for (j = 0; j < res_len; j++)
		*(res_tmp + j) = *(res_int_tmp + (res_len - 1 - j)) + '0';
	*(res_tmp + res_len) = '\0';
	
	free(str1);
	free(str2);
	free(res_int_tmp);

	return (res_tmp);
}

unsigned int _strlen(char *c)
{
	unsigned int count = 0;
	while (*(c + count) != '\0')
		count++;
	return (count);
}

int is_digit(char c)
{
	if (c <= '9' && c >= 0)
		return (1);
	return (0);
}

char to_digit(char c)
{
	return (c - '0');
}
