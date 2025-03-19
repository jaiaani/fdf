#include "libft/libft.h"
#include <stdio.h>

int	strhex_to_number(const char *hex_str)
{
	int	color;

	if (!hex_str || *hex_str != '0' || *(hex_str + 1) != 'x')
		return (0);
	color = 0;
	hex_str += 2;
	while (*hex_str)
	{
		color *= 16;
		if (*hex_str >= '0' && *hex_str <= '9')
			color += *hex_str - '0';
		else if (*hex_str >= 'a' && *hex_str <= 'f')
			color += *hex_str - 'a' + 10;
		else if (*hex_str >= 'A' && *hex_str <= 'F')
			color += *hex_str - 'A' + 10;
		else
			return (0);
		hex_str++;
	}
	return (color);
}

int	count_elements(char *z_info[])
{
	int 	i;

	i = 0;
	while (z_info[i])
	{
		printf("%s\n", z_info[i]);
		i++;
	}
	return (i);
}

int	main(void)
{
	printf("----\n");
	char	*a[] = {"hello", "me", '\0'};

	char **b;

	b = ft_split("helloworld", ',');
	printf("%d\n", count_elements(b));
	printf("%s\n", b[0]);
	

	return (0);	
}
