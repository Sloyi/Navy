/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** prototype of all function
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>

typedef struct precision {
    int before;
    int after;
}   precision_t;

short int convert_int_hint(int nb);
char convert_int_char(int nb);
void missflag(const char *s, va_list ap, int *i, struct precision prec);
void hhflag(const char *s, va_list ap, int *i, struct precision prec);
void hflag(const char *s, va_list ap, int *i, struct precision prec);
void llflag(const char *s, va_list ap, int *i, struct precision prec);
void lflag(const char *s, va_list ap, int *i, struct precision prec);
void do_prec_int(struct precision prec, long long int stck);
void do_prec_uint(struct precision prec, long long unsigned int stck);
void do_prec_char(struct precision prec, int stck);
void do_prec_chare(struct precision prec, char *stck);
int check_len(long long unsigned int nb, int base);
int my_printf(const char *s, ...);
void my_put_base(long long unsigned int nb, int base);
void do_precision_base(struct precision prec, long long
unsigned int stck, int base);
void do_prec_hexa(struct precision prec, long long unsigned int stck, char x);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_intlen(int res);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_getnbrprec(char const *str, int *i);
int my_put_nbr(long long int nb);
int my_put_nbr_unsigned(long long unsigned int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
void my_put_hex(long long unsigned int nb, char x);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *my_getnbr_str(char *str, int *gap);

#endif
