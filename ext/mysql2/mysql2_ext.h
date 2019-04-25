#ifndef MYSQL2_EXT
#define MYSQL2_EXT

void Init_mysql2(void);

/* tell rbx not to use it's caching compat layer
   by doing this we're making a promise to RBX that
   we'll never modify the pointers we get back from RSTRING_PTR */
#define RSTRING_NOT_MODIFIED
#include <ruby.h>

#ifdef HAVE_MYSQL_H
#include <mysql.h>
#include <mysql_version.h>
#include <errmsg.h>
#else
#include <mysql/mysql.h>
#include <mysql/mysql_version.h>
#include <mysql/errmsg.h>
#endif

#include <ruby/encoding.h>
#include <ruby/thread.h>

#if (LIBMYSQL_VERSION_ID >= 50700) && (LIBMYSQL_VERSION_ID < 50800)
#define HAVE_MYSQL_CLIENT_20
#endif

#if defined(__GNUC__) && (__GNUC__ >= 3)
#define RB_MYSQL_NORETURN __attribute__ ((noreturn))
#define RB_MYSQL_UNUSED __attribute__ ((unused))
#else
#define RB_MYSQL_NORETURN
#define RB_MYSQL_UNUSED
#endif

/* MySQL 8.0 replaces my_bool with C99 bool. Earlier versions of MySQL had
 * a typedef to char. Gem users reported failures on big endian systems when
 * using C99 bool types with older MySQLs due to mismatched behavior. */
#ifndef HAVE_TYPE_MY_BOOL
#include <stdbool.h>
typedef bool my_bool;
#endif

#include <client.h>
#include <statement.h>
#include <result.h>
#include <infile.h>

#endif
