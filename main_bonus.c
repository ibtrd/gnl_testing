/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:19:10 by ibertran          #+#    #+#             */
/*   Updated: 2023/12/20 23:22:37 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd[3];
	char	*f1 = "files/mariah.txt";
	char	*f2 = "files/ascii_xmas_tree";
	char	*f3 = "../get_next_line_bonus.h";
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

	char	*ptr = "A";

	int	random;
	int	total = 0;
	while (total < 150)
	{
		random = rand() % 3;
		ptr = get_next_line(fd[random]);
		if (random == 0)
			printf("\e[0;32m");
		else if (random == 1)
			printf("\e[0;33m");
		else
			printf("\e[0;34m");
		if (ptr)
			printf("get_next_line fd%d - %-7d|%s", random, i[random], ptr);
		else
			printf("get_next_line fd%d - %-7d|%s\n", random, i[random], ptr);
		free(ptr);
		i[random]++;
		total++;
	}
	//get_next_line(-1);
	printf("\e[0m");
	printf("\n----------------------\n");
}
