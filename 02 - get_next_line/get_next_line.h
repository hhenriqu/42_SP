/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:56 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/09/12 16:38:48 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include	<unistd.h> 
#include	<stdlib.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *str, char *aux, char *buf);
char	*ft_getrest(char *str);
char	*ft_getline(char *str);
int		ft_newline(char *str);
size_t	ft_strlen(const char *s);
char	*ft_calloc(int size);

#endif