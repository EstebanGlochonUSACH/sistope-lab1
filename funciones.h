#ifndef _H_FUNCIONES
#define _H_FUNCIONES

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

struct _params {
	char file_in[100];
	int has_file_in;
	char file_out[100];
	int has_file_out;
	int flag_verbose;
};
typedef struct _params params_t;

void parse_params(params_t *params, int argc, char *argv[]);

void dup_printf(int flag_verbose, FILE *f, char const *fmt, ...);

#endif