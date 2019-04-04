/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnurkass <mnurkass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 07:25:24 by mnurkass          #+#    #+#             */
/*   Updated: 2019/04/04 11:42:55 by mnurkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_symbol(char *str,int i)
{
	char bef;
	char c;
	c = str[i];
		bef = str[i - 1];
		if ((c == '\t' || c == ' ' || c == '\n')
		 && (bef != '\t' && bef != ' ' && bef != '\n')) 
		 	return 1;
			 else
			 {
				 return NULL;
			 }
			 
}

int get_count_word(char *str)
{
	int i;
	int count;
	char bef;
	char c;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		bef = str[i - 1];
		if ((c == '\t' || c == ' ' || c == '\n')
		 && (bef != '\t' && bef != ' ' && bef != '\n')) 
			count++;
		i++;
	}
	if(str[i] == '\0')
		count++;
	return count;
}

int get_count_l(char *str,int nb_word)
{
	int i;
	int count;
	int count_l;
	char bef;
	char c;

	i = 0;
	count = 0;
	count_l = 0;
	if(nb_word == 0)
		count_l++;
	while (str[i] != '\0')
	{
		c = str[i];
		bef = str[i - 1];
		if ((c == '\t' || c == ' ' || c == '\n')
		 && (bef != '\t' && bef != ' ' && bef != '\n')) 
			count++;
		if(nb_word == count && ((bef != '\t' || bef != ' ' || bef != '\n')))	
			count_l++;	
			
		i++;
	}
	// if(str[i] == '\0')
	// 	count++;
	return count_l;
}

char **get_memory(char **array_result,char *str, int count_word)
{
	int i;

	i = 0;
	while(i < count_word){
		array_result[i] = (char*)malloc(sizeof(char) * get_count_l(str, i));
		i++;
	}
	return (array_result);
}

char **ft_split_whitespaces(char *str)
{
	int count_word;
	char **array_result;
	int i;
	int l;
	int w;

	i = 0;
	l = 0;
	w = 0;

	count_word = get_count_word(str);

	array_result = (char**)malloc(sizeof(char *) * (count_word + 1));

	array_result = get_memory(array_result, str, count_word);

	while(str[i] != '\0')
	{
			if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
			{	
				array_result[w][l] = '\0';
				l = 0;	
				w++;	 			
			}
			else
			{
				array_result[w][l] = str[i];				
				l++;		
			}
			i++;
	} 
	array_result[w][l] = '\0';
	array_result[++w] = '\0';
	return (array_result);

}

int main()
{
	char **res;
	for (res = ft_split_whitespaces("s1   s2 \t\n\t\ns3"); *res != 0; res++)
	printf("'%s',", *res);
	printf("\n");
}
