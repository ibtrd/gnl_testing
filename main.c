/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:19:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/02/09 17:35:06 by ibertran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	(void)ac;
	
	char	*ptr;
	int		fd = open(av[1], O_RDONLY);
	
	printf("\n\t");
	printf("---------------------");
	printf("    --------------------------");
	printf("    ------------------------------------\n\t");
	printf("%s", "TESTING GET_NEXT_LINE");
	printf("    BUFFER_SIZE = %12d", BUFFER_SIZE);
	printf("    FILE = %29s\n\t", av[1]);
	printf("---------------------");
	printf("    --------------------------");
	printf("    ------------------------------------");
	printf("\n\n");
	
	int	i = 1;
	ptr = "A";
	while (ptr)
	{
		ptr = get_next_line(fd);
		if (ptr)
			printf("get_next_line %-7d|%s", i, ptr);
		free(ptr);
		i++;
	}
	printf("\n----------------------\n");
}
