/*
** EPITECH PROJECT, 2021
** flag.c
** File description:
** flag function
*/

#include <stdarg.h>
#include "myprint.h"
#include <unistd.h>
#include <stdio.h>

void llflag(const char *s, va_list ap, int *i, struct precision prec)
{
    *i += 1;
    if (s[*i] == 'i' || s[*i] == 'd')
        do_prec_int(prec, va_arg(ap, long long int));
    if (s[*i] == 'u')
        do_prec_uint(prec, va_arg(ap, long long unsigned int));
    if (s[*i] == 'o')
        do_precision_base(prec, va_arg(ap, long long unsigned int), 8);
    if (s[*i] == 'b')
        do_precision_base(prec, va_arg(ap, long long unsigned int), 2);
    if (s[*i] == 'X' || s[*i] == 'x')
        do_prec_hexa(prec, va_arg(ap, long long unsigned int), s[*i]);
}

void lflag(const char *s, va_list ap, int *i, struct precision prec)
{
    *i += 1;
    if (s[*i] == 'i' || s[*i] == 'd')
        do_prec_int(prec, va_arg(ap, long int));
    if (s[*i] == 'u')
        do_prec_uint(prec, va_arg(ap, long unsigned int));
    if (s[*i] == 'o')
        do_precision_base(prec, va_arg(ap, long unsigned int), 8);
    if (s[*i] == 'b')
        do_precision_base(prec, va_arg(ap, long unsigned int), 2);
    if (s[*i] == 'X' || s[*i] == 'x')
        do_prec_hexa(prec, va_arg(ap, long unsigned int), s[*i]);
    if (s[*i] == 'l')
        llflag(s, ap, i, prec);
}

void hflag(const char *s, va_list ap, int *i, struct precision prec)
{
    *i += 1;
    if (s[*i] == 'i' || s[*i] == 'd')
        do_prec_int(prec, convert_int_hint(va_arg(ap, int)));
    if (s[*i] == 'u')
        do_prec_uint(prec, convert_int_hint(va_arg(ap, int)));
    if (s[*i] == 'o')
        do_precision_base(prec, convert_int_hint(va_arg(ap, int)), 8);
    if (s[*i] == 'b')
        do_precision_base(prec, convert_int_hint(va_arg(ap, int)), 2);
    if (s[*i] == 'X' || s[*i] == 'x')
        do_prec_hexa(prec, convert_int_hint(va_arg(ap, int)), s[*i]);
    if (s[*i] == 'h')
        hhflag(s, ap, i, prec);
}

void hhflag(const char *s, va_list ap, int *i, struct precision prec)
{
    *i += 1;
    if (s[*i] == 'i' || s[*i] == 'd')
        do_prec_int(prec, convert_int_char(va_arg(ap, int)));
    if (s[*i] == 'u')
        do_prec_uint(prec, convert_int_char(va_arg(ap, int)));
    if (s[*i] == 'o')
        do_precision_base(prec, convert_int_char(va_arg(ap, int)), 8);
    if (s[*i] == 'b')
        do_precision_base(prec, convert_int_char(va_arg(ap, int)), 2);
    if (s[*i] == 'X' || s[*i] == 'x')
        do_prec_hexa(prec, convert_int_char(va_arg(ap, int)), s[*i]);
}

void missflag(const char *s, va_list ap, int *i, struct precision prec)
{
    if (s[*i] != '%' && s[*i] != 'i' && s[*i] != 'd' && s[*i] != 's' &&
    s[*i] != 'c' && s[*i] != 'u' && s[*i] != 'o' && s[*i] != 'b' &&
    s[*i] != 'X' && s[*i] != 'x' && s[*i] != 'p' && s[*i] != 'l' &&
    s[*i] != 'h')
        my_printf("%%%c", s[*i]);
}