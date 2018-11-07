/*
** EPITECH PROJECT, 2018
** advanced do_op h
** File description:
** 
*/

#ifndef ADV_DO_OP
#define ADV_DO_OP

struct operator {
    char* av;
    int (*addr)(int, int);
};

int my_add(int, int);
int my_sub(int, int);
int my_div(int, int);
int my_mul(int, int);
int my_mod(int, int);
void my_usage(void);

#endif /* ADV_DO_OP */
