#ifndef _DBG_H
#define _DBG_H

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
// does nothing if NDEBUG is set
#define debug(M, ...)
#else
// prints a debug message along with filename and lineno to stderr
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

// returns a clean errno, i.e. return None when errno=0
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

// logs an error message to stderr along with filename and lineno
#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// logs a warning  message to stderr along with filename and lineno
#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

// logs an info message to stderr along with filename and lineno
#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

// prints a message if a condition is invalid, sets errno=0 and goto error block
// expects an error block to be declared
#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// always prints an error message, sets errno=0 and goto error block
// can be used to handle unexpected or unwanted code paths
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

// shortcut that checks a pointer, use immediately after allocating memory
#define check_mem(A) check((A), "Out of memory.")

// shortcut that checks a pointer after allocating memory
// uses debug instead of log_err, to use in non-critical cases
#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif
