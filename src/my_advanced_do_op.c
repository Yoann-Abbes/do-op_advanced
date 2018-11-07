/*
** EPITECH PROJECT, 2018
** doop advanced Yoann ABBES
** File description:
** doop advanced Yoann ABBES
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "advanced_do_op.h"
#include "my_opp.h"

void my_usage(void)
{
    char *sop = NULL;
    int i = 0;
    int size = 0;

    for (; OPERATORS_FUNCS[i].av[0] != '\0'; i++)
	size += my_strlen(OPERATORS_FUNCS[i].av);
    sop = malloc(sizeof(char) * (size * 2));
    sop[0] = '\0';
    for (i = 0; OPERATORS_FUNCS[i].av[0] != '\0'; i++) {
	sop = my_strcat(sop, OPERATORS_FUNCS[i].av);
	sop = my_strcat(sop, " ");
    }
    write(2, "error: only [ ", 14);
    write(2, sop, my_strlen(sop));
    write(2, "] are supported\n", 16);
    free(sop);
}

char advanced_do_op(int nb1, char* op, int nb2)
{
    int (*ptr)(int, int) = NULL;
    void (*err)(void) = &my_usage;
    int i = 0;
    int found = 0;
    
    for (i = 0; OPERATORS_FUNCS[i].av[0] != '\0'; i++) {
	if (my_strcmp(op, OPERATORS_FUNCS[i].av) == 0) {
	    ptr = OPERATORS_FUNCS[i].addr;
	    found = 1;
	}
    }
    if (found == 1) {
	my_put_nbr(ptr(nb1, nb2));
	return ('t');
    }
    err();
    return ('f');
   
}

int main(int ac, char *av[])
{
    if (ac < 4)
	return (84);
    if (my_strlen(av[1]) <= 0 || my_strlen(av[2]) <= 0
	|| my_strlen(av[3]) <= 0)
	return (84);
    if (my_getnbr(av[3]) == 0) {
	if (av[2][0] == '/') {
	    write(2, "Stop: division by zero\n", 23);
	    return (84);
	}
	if (av[2][0] == '%') {
	    write(2, "Stop: modulo by zero\n", 22);
	    return (84);
	}
    }
    if (advanced_do_op(my_getnbr(av[1]), av[2], my_getnbr(av[3])) == 't')
	return (0);
    else
	return (84);
    return (0);
}
