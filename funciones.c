#include <stdio.h>
#include <stdarg.h>
#include <getopt.h>
#include <string.h>

struct _params {
	char file_in[100];
	int has_file_in;
	char file_out[100];
	int has_file_out;
	int flag_verbose;
};

void parse_params(struct _params *params, int argc, char *argv[])
{
    int option;
    params->flag_verbose = 0;
    params->has_file_in = 0;
    params->has_file_out = 0;
    while((option = getopt(argc, argv, "i:o:b")) != -1){
        switch(option) { 
            case 'i':
                strcpy(params->file_in, optarg);
                params->has_file_in = 1;
                break;
            case 'o':
                strcpy(params->file_out, optarg);
                params->has_file_out = 1;
                break;
            case 'b':
                params->flag_verbose = 1;
                break;
        }
    }
};

void dup_printf(int flag_verbose, FILE *f, char const *fmt, ...) { 
    va_list ap;
    if(flag_verbose){
        va_start(ap, fmt);
        vprintf(fmt, ap);
        va_end(ap);
    }
    va_start(ap, fmt);
    vfprintf(f, fmt, ap);
    va_end(ap);
};