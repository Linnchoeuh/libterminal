/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@csr-pi03.ecole-89.com>
** Ecole 89 - 14/02/2022 10:00:00
**
** - term_strcmp.c -
**
** *****************************************************************************
*/

int	term_strcmp(const char *str1,
				const char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0')
		i++;
	return (str2[i] - str1[i]);
}

