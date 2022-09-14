/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhenriqu <hhenriqu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:05:56 by hhenriqu          #+#    #+#             */
/*   Updated: 2022/07/11 16:50:31 by hhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H
#define OPEN_MAX 1024
#include	<unistd.h> 
#include	<stdlib.h>


char	*get_next_line(int fd);
char	*ft_read(int fd, char *str, char *aux, char *buf);
char	*ft_getrest(char *str);
char	*ft_getline(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_newline(char *str);
size_t	ft_strlen(const char *s);
char	*ft_calloc(int size);

#endif