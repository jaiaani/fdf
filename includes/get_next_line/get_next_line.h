/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:06:33 by jados-sa          #+#    #+#             */
/*   Updated: 2025/03/14 16:55:21 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 1024 
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "../libft/libft.h"

void	free_static_buffer(void);
char	*get_next_line(int fd);

#endif
