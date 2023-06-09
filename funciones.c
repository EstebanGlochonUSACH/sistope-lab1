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

int is_space(char c){
	return((c >= 0 && c <=32) || c == 127);
}

char *strtrim(char *s) {
	int start_index = 0;
	int end_index = strlen(s);
	char buffer[1000];
	// left trim
    while(is_space(s[start_index])) ++start_index;
	// right tirm
    while(is_space(s[end_index])) --end_index;
    s[end_index + 1] = '\0';

	// usar buffer para mover caracteres
	strcpy(buffer, &s[start_index]);
	strcpy(s, buffer);
    return s;
}