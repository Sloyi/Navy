/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** printf but mine
*/

#include <stdarg.h>
#include "myprint.h"
#include <unistd.h>
#include <stdio.h>

void arg_print2(const char *s, va_list ap, int *i, struct precision prec)
{
    if (s[*i] == 'p') {
        my_printf("0x");
        my_put_hex(va_arg(ap, unsigned int), 'x');
    }
    if (s[*i] == 'l')
        lflag(s, ap, i, prec);
    if (s[*i] == 'h')
        hflag(s, ap, i, prec);
    if (s[*i] == 'q')
        llflag(s, ap, i, prec);
    missflag(s, ap, i, prec);
}

void arg_print(const char *s, va_list ap, int *i, struct precision prec)
{
    if (s[*i] == '%')
        my_putchar('%');
    if (s[*i] == 'i' || s[*i] == 'd')
        do_prec_int(prec, va_arg(ap, int));
    if (s[*i] == 's')
        do_prec_chare(prec, va_arg(ap, char*));
    if (s[*i] == 'c')
        do_prec_char(prec, va_arg(ap, int));
    if (s[*i] == 'u')
        do_prec_uint(prec, va_arg(ap, unsigned int));
    if (s[*i] == 'o')
        do_precision_base(prec, va_arg(ap, unsigned int), 8);
    if (s[*i] == 'b')
        do_precision_base(prec, va_arg(ap, unsigned int), 2);
    if (s[*i] == 'X' || s[*i] == 'x')
        do_prec_hexa(prec, va_arg(ap, unsigned int), s[*i]);
    arg_print2(s, ap, i, prec);
}

void get_precision(struct precision *prec, const char *s, int *i)
{
    while (s[*i] == ' ')
        *i += 1;
    prec->before = my_getnbrprec(s, i);
    if (s[*i] == '.')
        *i += 1;
    prec->after = my_getnbrprec(s, i);
}

void put_plus(const char *s, int *i)
{
    if (s[*i] == '+') {
        my_putchar('+');
        *i += 1;
    }
}

int my_printf(const char *s, ...)
{
    va_list ap;
    struct precision prec = {0, 0};
    int i = 0;

    va_start(ap, s);
    for (; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            i++;
            put_plus(s, &i);
            get_precision(&prec, s, &i);
            arg_print(s, ap, &i, prec);
        } else
            my_putchar(s[i]);
    }
    va_end(ap);
    return 0;
}