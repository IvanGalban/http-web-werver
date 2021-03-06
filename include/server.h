
#define MINPORT 0
#define MAXPORT 65535
#define	MAXLINE	 8192  /* max text line length */
#define DOWNLOAD_BUFFER 8192
#define append(t) (t)+(strlen(t)) 

typedef struct {

    int maxfd;
    int nready;
    int maxi;
    int clientfd[FD_SETSIZE];
    int open_writer_fds[FD_SETSIZE];

    fd_set read_set;
    fd_set read_ready_set;
   
   	ull ssize[FD_SETSIZE];
    off_t off_set[FD_SETSIZE];

} pool;


typedef struct{

	char *name;
	char *type;
	char *lst_mdf;

	int size_byte;
	int end;
	int dir;

	time_t date;

}cfile;

typedef struct{

    char text[100];
    
}string;

enum {NAME, SIZE, TYPE, DATE};

int main(int, char **);
void init_pool(int listenfd, pool *p);
void add_client(int, pool *);
void check_clients(pool *);
void download(pool *, int);
void error_msg(const char *, int);
void response(char [], int, pool *, int);
void translate(char []);
int cmp_type (string, string);
int cmp_name (string, string);
int cmp_date (string, string);
int cmp_size (string, string);
int check_back(string, string);
int get_extension(string, char *);
void build1(string, struct stat *);
void build2(string, string, struct stat *, struct stat *);
void add_download(int, pool *, char *, long long, int);
void server_error(int, char *, char *, char *, char *);
void html_content(char [], int, int, int);
void mergesort(string [], int, int, int (*)(string, string));
void merging(string [] ,int, int, int, int (*)(string, string));