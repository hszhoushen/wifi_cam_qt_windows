#ifndef LOG
#define LOG

#define ErrorHandling(message)   {fputs(message, stderr);    \
                        fputc('\n', stderr);}

#endif // LOG

