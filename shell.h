#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM      0
#define CMD_OR        1
#define CMD_AND;      2
#define CMD_CHAIN     3

#define CONVERT_LOWERCASE
1
#define CONVERT_UNSUGNED
2
#define USE_GETLINE   0
#define USE_STRTOK   0
#define HIST_FILE
#define HIST_MAX
4096
extern char **environ;
/**
 * struct listr - singly linked list
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
 * struct passinfo - contains pseudo-arguments
 * @arg: string obtainedd from getline
 * @argv: generated from arg
 * @path:: a string path for corrent command
 * @argc: argument count
 * @line_count: error count
 * @err_num: error code for exit ()
 * @linecount_flag: if on count this line of input
 * @fname: filename
 * @env: linked list local copy
 * @environ:coy of environ from ll env
 * @history: history node
 * @alia: alias node
 * @status: return status
 * @cmd_buf: address  of pointer to cmd_buf
 * @readfd: fd from which to read line input
 * @histcount: history line number
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
	char *filename;
	list_t *env;
	list_t *history;
	list_t *alias;
	list_t **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFI_INIT \ {NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL ,NULL, \ 0, 0, 0}
/*
 * struct builtin - contains abuiltin string
 * @type: the builtin command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int hsh(info_t *, char **);
int (fnd_builtin(info_t *);
		void find_cmd(info_t *);
	
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);
int loopsh(char **);




void _eputs(char *);
int _eputchar(char *);
int _putfd(char n, int fd);
int _eputchar(char n);
void _eputs(char *str);
int _putsfd(char *s, int fd);
int _erratoi(char *s);
void print_err(info_t *info, char *str);
int print_d(int input, int fd);
char conv_no(long int num, int base, int flags);
void rem_comments(char *buf);
char *_strchr(char *str, char c);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int c);
int _setenv(info_t *info, char *var, char *value);
int _unsetenv(info_t *info, char *var);
char **get_environ(info_t *info);
ssize_t get_input(info_t *info);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
int rem_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int read_history(info_t *info);
char *get_history_file(info_t *info);
ssize_t list_len(const list_t *p);
char **list_to_strings(list_t *h);
size_t print_list(const list_t *head);
list_t *node_starts_with(list_t *node, char *prefix, char n);
ssize_t get_node_index(list_t *head, list_t *node);
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);
void *_realloc(void *p, unsigned int old_size, unsigned int new_size);
void ffree(char **pp);
char *_memset(char *s, char b, unsigned int n);
int hsh(info_t *info, char **av);
int find_builtin(info_t *info);
void find_cmd(info_t *info);
void fork_cmd(info_t *info);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _putchar(char c);
void _puts(char *str);
int is_chain(info_t *info, char *buf, size_t *p);
void check_chain(info_t *info, char *buf, size_t *p, size_ i, size_t len);
void *_realloc(void *p, unsigned int old_size, unsigned int new_size);
int interactive(info_t *);
int is_delim(char c, char *del);
int _isalpha(int h);
int _atoi(char *s);
void print_err(info_t *info, char *str);
int print_d(int input, int fd);
int _myexit(info_t *);
int _myhistory (info_t *);
int _mycd(info_t *);
int _myalias(info_t *);
int _myhelp(info_t *);
int _getline(info_t *, char **, size_t *);
int unset_alias(info_t *info, chr *str);
#endif;
