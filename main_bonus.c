/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:19:10 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/08 13:55:04 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
		
	srand(time(NULL));

	int		fd[3];
	char	*f1 = "files/mariah.txt";
	char	*f2 = "files/ascii_xmas_tree.txt";
	char	*f3 = "../get_next_line_bonus.c";
	fd[0] = open(f1, O_RDONLY);
	fd[1] = open(f2, O_RDONLY);
	fd[2] = open(f3, O_RDONLY);
	
	int		i[3] = {1, 1 ,1};
	
	printf("\n\t");
	printf("---------------------");
	printf("    --------------------------");
	printf("    -----------\n\t");
	printf("%s", "TESTING GET_NEXT_LINE");
	printf("    BUFFER_SIZE = %12d", BUFFER_SIZE);
	printf("    MULTIPLE_FD\n\t");
	printf("---------------------");
	printf("    --------------------------");
	printf("    -----------");
	printf("\n\n");

	char	*ptr;
	ptr = get_next_line(-8);
	printf("get_next_line invalid fd 1 |%s\n", ptr);
	free(ptr);
	ptr = get_next_line(4242);
	printf("get_next_line invalid fd 2 |%s\n", ptr);
	free(ptr);
	
	ptr = "A";
	int	random = 0;
	int	total = 0;

	while (total < atoi(av[1]))
	{
		random = rand() % 3;
		ptr = get_next_line(fd[random]);
		if (random == 0)
			printf("\e[0;32m");
		else if (random == 1)
			printf("\e[0;33m");
		else
			printf("\e[0;34m");
		if (ptr && i[random] != 0)
		{
			printf("get_next_line fd%d - %-7d|%s", random, i[random], ptr);
			i[random]++;
		}
		else if (!ptr && i[random] != 0)
		{
			i[random] = 0;
			printf("get_next_line fd%d - %-7d|%s\n", random, i[random], ptr);
		}
		free(ptr);
		total++;
		if (i[0] == 0 && i[1] == 0 && i[2] == 0)
			break;
	}
	//get_next_line(-1);
	printf("\e[0m");
	printf("\n----------------------\n");
}
