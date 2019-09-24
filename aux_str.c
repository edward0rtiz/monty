#include "monty.h"

/**
 * check_delim - checks if char is a delimitor
 * @str: type char 
 * @delim: type pointer array of delimitors
 * Return: 1 (success) 0 (failure)
 */

int check_delim(char str, char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (delim[i] == str)
			return (1);
		i++;
	}
	return (0);
}

/**
 * wstrlen - Calculates position of a word in a str
 * @str: type char str
 * description: function that returns a value position
 * return: wstrlen 0
 */
int wstrlen(char *str, char *delim)
{
	int wl = 0;
	int hold = 1;
	int i = 0;

	while (*(str + i))
	{
		if (check_delim(str[i], delim))
			hold = 1;
		else if (hold)
		{
			wl++;
		}
		if (wl > 0 && check_delim(str[i], delim))
			break;
		i++;
	}
	return (wl);
}

/**
 * wcounter - Counter of words in s str
 * @str: type char str
 * description: function that returns a value string
 * return: wcounter 0
 */
int wcounter(char *str, char *delim)
{
	int w = 0;
	int hold = 1;
	int i = 0;

	while (*(str + i))
	{
		if (check_delim(str[i], delim))
			hold = 1;
		else if (hold)
		{
			hold = 0;
			w++;
		}
		i++;
	}
	return (w);
}

char *wnext(char *str, char *delim)
{
	int hold = 0;
	int i = 0;

	while (*(str + i))
	{
		if (check_delim(str[i], delim))
			hold = 1;
		else if (hold)
			break;
		i++;
	}
	return (str + 1);
}


/**
 * **strtow - Function that splits a string into words.
 * @str: Type char str
 * description: function
 * Return: If str NULL or str = "" or function fails - NULL.
 */
char **strtow(char *str, char *delim)
{
	char **word = NULL;
	int wc;
	int wl;
	int i = 0;
	int j;

	if (str == NULL || !*str)
		return (NULL);
	wc = wcounter(str, delim);

	if (wc == 0)
		return (NULL);
	word = malloc((wc + 1) * sizeof(char *));
	if (word == NULL)
		return (NULL);
	while (i < wc)
	{
		wl = wstrlen(str, delim);
		if (check_delim(*str, delim))
		{
			str = wnext(str, delim);
		}
		word[i] = malloc((wl + 1) * sizeof(char));
		if (word[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(word[i]);
			}
			free(word);
			return (NULL);
		}
		j = 0;
		while (j < wl)
		{
			word[i][j] = *(str + j);
			j++;
		}
		word[i][j] = '\0';
		str = wnext(str, delim);
		i++;
	}
	word[i] = NULL;
	return (word);
}
