#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for num_conv() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USEline_cd 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int hsh(info_t *, char **);
int get_in(info_t *);
void get_command(info_t *);
void remove_command(info_t *);

/* toem_parser.c */
int on_command(info_t *, char *);
char *dcopy_chars(char *, int, int);
char *get_dir(info_t *, char *, char *);

/* rpt_shell.c */
int rpt_shell(char **);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int char_putsfd(char *str, int fd);

/* toem_string.c */
int char_point(char *);
int cmp_string(char *, char *);
char *initi_str(const char *, const char *);
char *show_str(char *, char *);

/* toem_string1.c */
char *t_stry(char *, char *);
char *str_up(const char *);
void char_puts(char *);
int _putchar(char);

/* toem_exits.c */
char *char_puts(char *, char *, int);
char *string_show(char *, char *, int);
char *characetr_str(char *, char);

/* toem_tokenizer.c */
char **token_stro(char *, char *);
char **token_stro2(char *, char);

/* toemall_loc.c */
char *lloc_set(char *, char, unsigned int);
void total_free(char **);
void *all_loc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int free_void(void **);

/* toemto_to.c */
int int_shell(info_t *);
int int_she_del(char, char *);
int alpha_isa(int);
int to_to(char *);

/* toem_errors1.c */
int err_tot(char *);
void err_print(info_t *, char *);
int d_prt(int, int);
char *num_conv(long int, int, int);
void com_rmv(char *);

/* toem_builtin.c */
int ext_built(info_t *);
int ent_cdd(info_t *);
int srch_hlp(info_t *);

/* toem_builtin1.c */
int hist_cd(info_t *);
int al_my(info_t *);

/*toemline_cd.c */
ssize_t int_inpt(info_t *);
int line_cd(info_t *, char **, size_t *);
void int_sgnht(int);

/* toem_getinfo.c */
void delete_dat(info_t *);
void puts_data(info_t *, char **);
void free_info(info_t *, int);

/* toem_environ.c */
char *info_env(info_t *, const char *);
int my_info_en(info_t *);
int set_my_info(info_t *);
int myunset_my_info(info_t *);
int tot_list(info_t *);

/* toeminfo_env.c */
char **get_environ(info_t *);
int eenv_set(info_t *, char *);
int eenv_set_env(info_t *, char *, char *);

/* toem_history.c */
char *gt_file_hist(info_t *info);
int wrt_only(info_t *info);
int rt_hist_only(info_t *info);
int bld_hist(info_t *info, char *buf, int linecount);
int new_hist_num(info_t *info);

/* toem_lists.c */
list_t *plus_node(list_t **, const char *, int);
list_t *plus_node_end(list_t **, const char *, int);
size_t prt_new_list(const list_t *);
int rm_index_node(list_t **, unsigned int);
void release_list(list_t **);

/* toem_lists1.c */
size_t list_lv(const list_t *);
char **str_liist(list_t *);
size_t print_list(const list_t *);
list_t *node_initi_str(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int present_chain(info_t *, char *, size_t *);
void str_sim(info_t *, char *, size_t *, size_t, size_t);
int sim_asl(info_t *);
int sim_asl_list(info_t *);
int str_sub(char **, char *);

#endif
