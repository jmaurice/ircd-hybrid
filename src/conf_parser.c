/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 25 "conf_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "conf_class.h"
#include "event.h"
#include "log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "irc_string.h"
#include "memory.h"
#include "modules.h"
#include "s_serv.h"
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "s_user.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/dh.h>
#endif

#include "rsa.h"

int yylex(void);

static struct
{
  struct {
    dlink_list list;
  } mask,
    leaf,
    hub;

  struct {
    char buf[IRCD_BUFSIZE];
  } name,
    user,
    host,
    addr,
    bind,
    file,
    ciph,
    rpass,
    spass,
    class;

  struct {
    unsigned int value;
  } flags,
    modes,
    size,
    type,
    port,
    aftype,
    ping_freq,
    max_perip,
    con_freq,
    min_idle,
    max_idle,
    max_total,
    max_global,
    max_local,
    max_ident,
    max_sendq,
    max_recvq,
    cidr_bitlen_ipv4,
    cidr_bitlen_ipv6,
    number_per_cidr;
} block_state;

static void
reset_block_state(void)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.mask.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.mask.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.leaf.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.leaf.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.hub.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.hub.list);
    free_dlink_node(ptr);
  }

  memset(&block_state, 0, sizeof(block_state));
}


/* Line 371 of yacc.c  */
#line 181 "conf_parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_CONF_PARSER_H_INCLUDED
# define YY_YY_CONF_PARSER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ACCEPT_PASSWORD = 258,
     ADMIN = 259,
     AFTYPE = 260,
     ANTI_NICK_FLOOD = 261,
     ANTI_SPAM_EXIT_MESSAGE_TIME = 262,
     AUTOCONN = 263,
     BYTES = 264,
     KBYTES = 265,
     MBYTES = 266,
     CALLER_ID_WAIT = 267,
     CAN_FLOOD = 268,
     CHANNEL = 269,
     CIDR_BITLEN_IPV4 = 270,
     CIDR_BITLEN_IPV6 = 271,
     CLASS = 272,
     CONNECT = 273,
     CONNECTFREQ = 274,
     DEFAULT_FLOODCOUNT = 275,
     DEFAULT_SPLIT_SERVER_COUNT = 276,
     DEFAULT_SPLIT_USER_COUNT = 277,
     DENY = 278,
     DESCRIPTION = 279,
     DIE = 280,
     DISABLE_AUTH = 281,
     DISABLE_FAKE_CHANNELS = 282,
     DISABLE_REMOTE_COMMANDS = 283,
     DOTS_IN_IDENT = 284,
     EGDPOOL_PATH = 285,
     EMAIL = 286,
     ENCRYPTED = 287,
     EXCEED_LIMIT = 288,
     EXEMPT = 289,
     FAILED_OPER_NOTICE = 290,
     IRCD_FLAGS = 291,
     FLATTEN_LINKS = 292,
     GECOS = 293,
     GENERAL = 294,
     GLINE = 295,
     GLINE_DURATION = 296,
     GLINE_ENABLE = 297,
     GLINE_EXEMPT = 298,
     GLINE_REQUEST_DURATION = 299,
     GLINE_MIN_CIDR = 300,
     GLINE_MIN_CIDR6 = 301,
     GLOBAL_KILL = 302,
     IRCD_AUTH = 303,
     NEED_IDENT = 304,
     HAVENT_READ_CONF = 305,
     HIDDEN = 306,
     HIDDEN_NAME = 307,
     HIDE_SERVER_IPS = 308,
     HIDE_SERVERS = 309,
     HIDE_SERVICES = 310,
     HIDE_SPOOF_IPS = 311,
     HOST = 312,
     HUB = 313,
     HUB_MASK = 314,
     IGNORE_BOGUS_TS = 315,
     INVISIBLE_ON_CONNECT = 316,
     IP = 317,
     KILL = 318,
     KILL_CHASE_TIME_LIMIT = 319,
     KLINE = 320,
     KLINE_EXEMPT = 321,
     KNOCK_DELAY = 322,
     KNOCK_DELAY_CHANNEL = 323,
     LEAF_MASK = 324,
     LINKS_DELAY = 325,
     LISTEN = 326,
     T_LOG = 327,
     MAX_ACCEPT = 328,
     MAX_BANS = 329,
     MAX_CHANS_PER_OPER = 330,
     MAX_CHANS_PER_USER = 331,
     MAX_GLOBAL = 332,
     MAX_IDENT = 333,
     MAX_LOCAL = 334,
     MAX_NICK_CHANGES = 335,
     MAX_NICK_LENGTH = 336,
     MAX_NICK_TIME = 337,
     MAX_NUMBER = 338,
     MAX_TARGETS = 339,
     MAX_TOPIC_LENGTH = 340,
     MAX_WATCH = 341,
     MIN_NONWILDCARD = 342,
     MIN_NONWILDCARD_SIMPLE = 343,
     MIN_IDLE = 344,
     MAX_IDLE = 345,
     RANDOM_IDLE = 346,
     HIDE_IDLE_FROM_OPERS = 347,
     MODULE = 348,
     MODULES = 349,
     NAME = 350,
     NEED_PASSWORD = 351,
     NETWORK_DESC = 352,
     NETWORK_NAME = 353,
     NICK = 354,
     NICK_CHANGES = 355,
     NO_CREATE_ON_SPLIT = 356,
     NO_JOIN_ON_SPLIT = 357,
     NO_OPER_FLOOD = 358,
     NO_TILDE = 359,
     NUMBER = 360,
     NUMBER_PER_CIDR = 361,
     NUMBER_PER_IP = 362,
     OPERATOR = 363,
     OPERS_BYPASS_CALLERID = 364,
     OPER_ONLY_UMODES = 365,
     OPER_PASS_RESV = 366,
     OPER_SPY_T = 367,
     OPER_UMODES = 368,
     JOIN_FLOOD_COUNT = 369,
     JOIN_FLOOD_TIME = 370,
     PACE_WAIT = 371,
     PACE_WAIT_SIMPLE = 372,
     PASSWORD = 373,
     PATH = 374,
     PING_COOKIE = 375,
     PING_TIME = 376,
     PORT = 377,
     QSTRING = 378,
     QUIET_ON_BAN = 379,
     REASON = 380,
     REDIRPORT = 381,
     REDIRSERV = 382,
     REGEX_T = 383,
     REHASH = 384,
     REMOTE = 385,
     REMOTEBAN = 386,
     RESTRICT_CHANNELS = 387,
     RSA_PRIVATE_KEY_FILE = 388,
     RSA_PUBLIC_KEY_FILE = 389,
     SSL_CERTIFICATE_FILE = 390,
     SSL_DH_PARAM_FILE = 391,
     T_SSL_CLIENT_METHOD = 392,
     T_SSL_SERVER_METHOD = 393,
     T_SSLV3 = 394,
     T_TLSV1 = 395,
     RESV = 396,
     RESV_EXEMPT = 397,
     SECONDS = 398,
     MINUTES = 399,
     HOURS = 400,
     DAYS = 401,
     WEEKS = 402,
     MONTHS = 403,
     YEARS = 404,
     SENDQ = 405,
     SEND_PASSWORD = 406,
     SERVERHIDE = 407,
     SERVERINFO = 408,
     IRCD_SID = 409,
     TKLINE_EXPIRE_NOTICES = 410,
     T_SHARED = 411,
     T_CLUSTER = 412,
     TYPE = 413,
     SHORT_MOTD = 414,
     SPOOF = 415,
     SPOOF_NOTICE = 416,
     STATS_E_DISABLED = 417,
     STATS_I_OPER_ONLY = 418,
     STATS_K_OPER_ONLY = 419,
     STATS_O_OPER_ONLY = 420,
     STATS_P_OPER_ONLY = 421,
     TBOOL = 422,
     TMASKED = 423,
     TS_MAX_DELTA = 424,
     TS_WARN_DELTA = 425,
     TWODOTS = 426,
     T_ALL = 427,
     T_BOTS = 428,
     T_SOFTCALLERID = 429,
     T_CALLERID = 430,
     T_CCONN = 431,
     T_CCONN_FULL = 432,
     T_SSL_CIPHER_LIST = 433,
     T_DEAF = 434,
     T_DEBUG = 435,
     T_DLINE = 436,
     T_EXTERNAL = 437,
     T_FULL = 438,
     T_INVISIBLE = 439,
     T_IPV4 = 440,
     T_IPV6 = 441,
     T_LOCOPS = 442,
     T_MAX_CLIENTS = 443,
     T_NCHANGE = 444,
     T_OPERWALL = 445,
     T_RECVQ = 446,
     T_REJ = 447,
     T_SERVER = 448,
     T_SERVNOTICE = 449,
     T_SET = 450,
     T_SKILL = 451,
     T_SPY = 452,
     T_SSL = 453,
     T_UMODES = 454,
     T_UNAUTH = 455,
     T_UNDLINE = 456,
     T_UNLIMITED = 457,
     T_UNRESV = 458,
     T_UNXLINE = 459,
     T_GLOBOPS = 460,
     T_WALLOP = 461,
     T_WEBIRC = 462,
     T_RESTART = 463,
     T_SERVICE = 464,
     T_SERVICES_NAME = 465,
     THROTTLE_TIME = 466,
     TRUE_NO_OPER_FLOOD = 467,
     UNKLINE = 468,
     USER = 469,
     USE_EGD = 470,
     USE_LOGGING = 471,
     VHOST = 472,
     VHOST6 = 473,
     XLINE = 474,
     WARN_NO_NLINE = 475,
     T_SIZE = 476,
     T_FILE = 477
   };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ADMIN 259
#define AFTYPE 260
#define ANTI_NICK_FLOOD 261
#define ANTI_SPAM_EXIT_MESSAGE_TIME 262
#define AUTOCONN 263
#define BYTES 264
#define KBYTES 265
#define MBYTES 266
#define CALLER_ID_WAIT 267
#define CAN_FLOOD 268
#define CHANNEL 269
#define CIDR_BITLEN_IPV4 270
#define CIDR_BITLEN_IPV6 271
#define CLASS 272
#define CONNECT 273
#define CONNECTFREQ 274
#define DEFAULT_FLOODCOUNT 275
#define DEFAULT_SPLIT_SERVER_COUNT 276
#define DEFAULT_SPLIT_USER_COUNT 277
#define DENY 278
#define DESCRIPTION 279
#define DIE 280
#define DISABLE_AUTH 281
#define DISABLE_FAKE_CHANNELS 282
#define DISABLE_REMOTE_COMMANDS 283
#define DOTS_IN_IDENT 284
#define EGDPOOL_PATH 285
#define EMAIL 286
#define ENCRYPTED 287
#define EXCEED_LIMIT 288
#define EXEMPT 289
#define FAILED_OPER_NOTICE 290
#define IRCD_FLAGS 291
#define FLATTEN_LINKS 292
#define GECOS 293
#define GENERAL 294
#define GLINE 295
#define GLINE_DURATION 296
#define GLINE_ENABLE 297
#define GLINE_EXEMPT 298
#define GLINE_REQUEST_DURATION 299
#define GLINE_MIN_CIDR 300
#define GLINE_MIN_CIDR6 301
#define GLOBAL_KILL 302
#define IRCD_AUTH 303
#define NEED_IDENT 304
#define HAVENT_READ_CONF 305
#define HIDDEN 306
#define HIDDEN_NAME 307
#define HIDE_SERVER_IPS 308
#define HIDE_SERVERS 309
#define HIDE_SERVICES 310
#define HIDE_SPOOF_IPS 311
#define HOST 312
#define HUB 313
#define HUB_MASK 314
#define IGNORE_BOGUS_TS 315
#define INVISIBLE_ON_CONNECT 316
#define IP 317
#define KILL 318
#define KILL_CHASE_TIME_LIMIT 319
#define KLINE 320
#define KLINE_EXEMPT 321
#define KNOCK_DELAY 322
#define KNOCK_DELAY_CHANNEL 323
#define LEAF_MASK 324
#define LINKS_DELAY 325
#define LISTEN 326
#define T_LOG 327
#define MAX_ACCEPT 328
#define MAX_BANS 329
#define MAX_CHANS_PER_OPER 330
#define MAX_CHANS_PER_USER 331
#define MAX_GLOBAL 332
#define MAX_IDENT 333
#define MAX_LOCAL 334
#define MAX_NICK_CHANGES 335
#define MAX_NICK_LENGTH 336
#define MAX_NICK_TIME 337
#define MAX_NUMBER 338
#define MAX_TARGETS 339
#define MAX_TOPIC_LENGTH 340
#define MAX_WATCH 341
#define MIN_NONWILDCARD 342
#define MIN_NONWILDCARD_SIMPLE 343
#define MIN_IDLE 344
#define MAX_IDLE 345
#define RANDOM_IDLE 346
#define HIDE_IDLE_FROM_OPERS 347
#define MODULE 348
#define MODULES 349
#define NAME 350
#define NEED_PASSWORD 351
#define NETWORK_DESC 352
#define NETWORK_NAME 353
#define NICK 354
#define NICK_CHANGES 355
#define NO_CREATE_ON_SPLIT 356
#define NO_JOIN_ON_SPLIT 357
#define NO_OPER_FLOOD 358
#define NO_TILDE 359
#define NUMBER 360
#define NUMBER_PER_CIDR 361
#define NUMBER_PER_IP 362
#define OPERATOR 363
#define OPERS_BYPASS_CALLERID 364
#define OPER_ONLY_UMODES 365
#define OPER_PASS_RESV 366
#define OPER_SPY_T 367
#define OPER_UMODES 368
#define JOIN_FLOOD_COUNT 369
#define JOIN_FLOOD_TIME 370
#define PACE_WAIT 371
#define PACE_WAIT_SIMPLE 372
#define PASSWORD 373
#define PATH 374
#define PING_COOKIE 375
#define PING_TIME 376
#define PORT 377
#define QSTRING 378
#define QUIET_ON_BAN 379
#define REASON 380
#define REDIRPORT 381
#define REDIRSERV 382
#define REGEX_T 383
#define REHASH 384
#define REMOTE 385
#define REMOTEBAN 386
#define RESTRICT_CHANNELS 387
#define RSA_PRIVATE_KEY_FILE 388
#define RSA_PUBLIC_KEY_FILE 389
#define SSL_CERTIFICATE_FILE 390
#define SSL_DH_PARAM_FILE 391
#define T_SSL_CLIENT_METHOD 392
#define T_SSL_SERVER_METHOD 393
#define T_SSLV3 394
#define T_TLSV1 395
#define RESV 396
#define RESV_EXEMPT 397
#define SECONDS 398
#define MINUTES 399
#define HOURS 400
#define DAYS 401
#define WEEKS 402
#define MONTHS 403
#define YEARS 404
#define SENDQ 405
#define SEND_PASSWORD 406
#define SERVERHIDE 407
#define SERVERINFO 408
#define IRCD_SID 409
#define TKLINE_EXPIRE_NOTICES 410
#define T_SHARED 411
#define T_CLUSTER 412
#define TYPE 413
#define SHORT_MOTD 414
#define SPOOF 415
#define SPOOF_NOTICE 416
#define STATS_E_DISABLED 417
#define STATS_I_OPER_ONLY 418
#define STATS_K_OPER_ONLY 419
#define STATS_O_OPER_ONLY 420
#define STATS_P_OPER_ONLY 421
#define TBOOL 422
#define TMASKED 423
#define TS_MAX_DELTA 424
#define TS_WARN_DELTA 425
#define TWODOTS 426
#define T_ALL 427
#define T_BOTS 428
#define T_SOFTCALLERID 429
#define T_CALLERID 430
#define T_CCONN 431
#define T_CCONN_FULL 432
#define T_SSL_CIPHER_LIST 433
#define T_DEAF 434
#define T_DEBUG 435
#define T_DLINE 436
#define T_EXTERNAL 437
#define T_FULL 438
#define T_INVISIBLE 439
#define T_IPV4 440
#define T_IPV6 441
#define T_LOCOPS 442
#define T_MAX_CLIENTS 443
#define T_NCHANGE 444
#define T_OPERWALL 445
#define T_RECVQ 446
#define T_REJ 447
#define T_SERVER 448
#define T_SERVNOTICE 449
#define T_SET 450
#define T_SKILL 451
#define T_SPY 452
#define T_SSL 453
#define T_UMODES 454
#define T_UNAUTH 455
#define T_UNDLINE 456
#define T_UNLIMITED 457
#define T_UNRESV 458
#define T_UNXLINE 459
#define T_GLOBOPS 460
#define T_WALLOP 461
#define T_WEBIRC 462
#define T_RESTART 463
#define T_SERVICE 464
#define T_SERVICES_NAME 465
#define THROTTLE_TIME 466
#define TRUE_NO_OPER_FLOOD 467
#define UNKLINE 468
#define USER 469
#define USE_EGD 470
#define USE_LOGGING 471
#define VHOST 472
#define VHOST6 473
#define XLINE 474
#define WARN_NO_NLINE 475
#define T_SIZE 476
#define T_FILE 477



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 138 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 674 "conf_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 702 "conf_parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  228
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  290
/* YYNRULES -- Number of rules.  */
#define YYNRULES  643
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1259

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   477

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   227,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   223,
       2,   226,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   225,     2,   224,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    50,    53,    54,    56,    59,
      63,    67,    71,    75,    79,    83,    87,    88,    90,    93,
      97,   101,   105,   111,   114,   116,   118,   120,   123,   128,
     133,   139,   142,   144,   146,   148,   150,   152,   154,   156,
     158,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   181,   186,   191,   195,   197,   199,   201,   205,   207,
     209,   211,   216,   221,   226,   231,   236,   241,   246,   251,
     256,   261,   266,   271,   276,   281,   286,   292,   295,   297,
     299,   301,   303,   306,   311,   316,   321,   327,   330,   332,
     334,   336,   339,   344,   345,   352,   355,   357,   359,   361,
     363,   366,   371,   376,   381,   382,   388,   392,   394,   396,
     398,   400,   402,   404,   406,   408,   409,   416,   419,   421,
     423,   425,   427,   429,   431,   433,   435,   437,   440,   445,
     450,   455,   460,   465,   470,   471,   477,   481,   483,   485,
     487,   489,   491,   493,   495,   497,   499,   501,   503,   505,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   524,
     530,   534,   536,   538,   540,   542,   544,   546,   548,   550,
     552,   554,   556,   558,   560,   562,   564,   566,   568,   570,
     572,   574,   575,   582,   585,   587,   589,   591,   593,   595,
     597,   599,   601,   603,   605,   607,   609,   611,   613,   615,
     617,   619,   622,   627,   632,   637,   642,   647,   652,   657,
     662,   667,   672,   677,   682,   687,   692,   697,   698,   704,
     708,   710,   712,   714,   715,   722,   723,   729,   733,   735,
     737,   739,   741,   744,   746,   748,   750,   752,   754,   757,
     758,   764,   768,   770,   772,   776,   781,   786,   787,   794,
     797,   799,   801,   803,   805,   807,   809,   811,   813,   815,
     818,   823,   828,   833,   838,   839,   845,   849,   851,   853,
     855,   857,   859,   861,   863,   865,   867,   869,   871,   876,
     881,   886,   887,   894,   897,   899,   901,   903,   905,   908,
     913,   918,   923,   929,   932,   934,   936,   938,   943,   944,
     951,   954,   956,   958,   960,   962,   965,   970,   975,   976,
     982,   986,   988,   990,   992,   994,   996,   998,  1000,  1002,
    1004,  1006,  1008,  1009,  1016,  1019,  1021,  1023,  1025,  1028,
    1033,  1034,  1040,  1044,  1046,  1048,  1050,  1052,  1054,  1056,
    1058,  1060,  1062,  1064,  1066,  1067,  1074,  1077,  1079,  1081,
    1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,
    1103,  1105,  1108,  1113,  1118,  1123,  1128,  1133,  1138,  1143,
    1148,  1149,  1155,  1159,  1161,  1163,  1165,  1170,  1175,  1180,
    1185,  1190,  1191,  1198,  1199,  1205,  1209,  1211,  1213,  1216,
    1218,  1220,  1222,  1224,  1226,  1231,  1236,  1237,  1244,  1247,
    1249,  1251,  1253,  1255,  1260,  1265,  1271,  1274,  1276,  1278,
    1280,  1285,  1286,  1293,  1294,  1300,  1304,  1306,  1308,  1311,
    1313,  1315,  1317,  1319,  1321,  1326,  1331,  1337,  1340,  1342,
    1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362,
    1364,  1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,
    1384,  1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1402,
    1404,  1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,
    1424,  1426,  1428,  1430,  1432,  1434,  1436,  1438,  1440,  1445,
    1450,  1455,  1460,  1465,  1470,  1475,  1480,  1485,  1490,  1495,
    1500,  1505,  1510,  1515,  1520,  1525,  1530,  1535,  1540,  1545,
    1550,  1555,  1560,  1565,  1570,  1575,  1580,  1585,  1590,  1595,
    1600,  1605,  1610,  1615,  1620,  1625,  1630,  1635,  1640,  1645,
    1650,  1655,  1660,  1665,  1666,  1672,  1676,  1678,  1680,  1682,
    1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,  1700,  1702,
    1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1719,  1725,
    1729,  1731,  1733,  1735,  1737,  1739,  1741,  1743,  1745,  1747,
    1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,  1765,  1767,
    1769,  1771,  1776,  1781,  1786,  1792,  1795,  1797,  1799,  1801,
    1803,  1805,  1807,  1809,  1811,  1813,  1815,  1817,  1819,  1821,
    1823,  1825,  1827,  1832,  1837,  1842,  1847,  1852,  1857,  1862,
    1867,  1872,  1877,  1882,  1887,  1892,  1897,  1903,  1906,  1908,
    1910,  1912,  1914,  1916,  1918,  1920,  1922,  1924,  1929,  1934,
    1939,  1944,  1949,  1954
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     229,     0,    -1,    -1,   229,   230,    -1,   264,    -1,   270,
      -1,   284,    -1,   491,    -1,   302,    -1,   325,    -1,   339,
      -1,   240,    -1,   508,    -1,   354,    -1,   361,    -1,   365,
      -1,   375,    -1,   384,    -1,   404,    -1,   414,    -1,   420,
      -1,   434,    -1,   424,    -1,   235,    -1,     1,   223,    -1,
       1,   224,    -1,    -1,   232,    -1,   105,   231,    -1,   105,
     143,   231,    -1,   105,   144,   231,    -1,   105,   145,   231,
      -1,   105,   146,   231,    -1,   105,   147,   231,    -1,   105,
     148,   231,    -1,   105,   149,   231,    -1,    -1,   234,    -1,
     105,   233,    -1,   105,     9,   233,    -1,   105,    10,   233,
      -1,   105,    11,   233,    -1,    94,   225,   236,   224,   223,
      -1,   236,   237,    -1,   237,    -1,   238,    -1,   239,    -1,
       1,   223,    -1,    93,   226,   123,   223,    -1,   119,   226,
     123,   223,    -1,   153,   225,   241,   224,   223,    -1,   241,
     242,    -1,   242,    -1,   253,    -1,   258,    -1,   263,    -1,
     255,    -1,   256,    -1,   257,    -1,   260,    -1,   261,    -1,
     262,    -1,   251,    -1,   250,    -1,   259,    -1,   254,    -1,
     249,    -1,   243,    -1,   244,    -1,   252,    -1,     1,   223,
      -1,   137,   226,   245,   223,    -1,   138,   226,   247,   223,
      -1,   245,   227,   246,    -1,   246,    -1,   139,    -1,   140,
      -1,   247,   227,   248,    -1,   248,    -1,   139,    -1,   140,
      -1,   135,   226,   123,   223,    -1,   133,   226,   123,   223,
      -1,   136,   226,   123,   223,    -1,   178,   226,   123,   223,
      -1,    95,   226,   123,   223,    -1,   154,   226,   123,   223,
      -1,    24,   226,   123,   223,    -1,    98,   226,   123,   223,
      -1,    97,   226,   123,   223,    -1,   217,   226,   123,   223,
      -1,   218,   226,   123,   223,    -1,   188,   226,   105,   223,
      -1,    81,   226,   105,   223,    -1,    85,   226,   105,   223,
      -1,    58,   226,   167,   223,    -1,     4,   225,   265,   224,
     223,    -1,   265,   266,    -1,   266,    -1,   267,    -1,   269,
      -1,   268,    -1,     1,   223,    -1,    95,   226,   123,   223,
      -1,    31,   226,   123,   223,    -1,    24,   226,   123,   223,
      -1,    72,   225,   271,   224,   223,    -1,   271,   272,    -1,
     272,    -1,   273,    -1,   274,    -1,     1,   223,    -1,   216,
     226,   167,   223,    -1,    -1,   275,   222,   225,   276,   224,
     223,    -1,   276,   277,    -1,   277,    -1,   278,    -1,   280,
      -1,   279,    -1,     1,   223,    -1,    95,   226,   123,   223,
      -1,   221,   226,   234,   223,    -1,   221,   226,   202,   223,
      -1,    -1,   158,   281,   226,   282,   223,    -1,   282,   227,
     283,    -1,   283,    -1,   214,    -1,   108,    -1,    40,    -1,
     181,    -1,    65,    -1,    63,    -1,   180,    -1,    -1,   108,
     285,   225,   286,   224,   223,    -1,   286,   287,    -1,   287,
      -1,   288,    -1,   289,    -1,   290,    -1,   294,    -1,   293,
      -1,   291,    -1,   292,    -1,   298,    -1,     1,   223,    -1,
      95,   226,   123,   223,    -1,   214,   226,   123,   223,    -1,
     118,   226,   123,   223,    -1,    32,   226,   167,   223,    -1,
     134,   226,   123,   223,    -1,    17,   226,   123,   223,    -1,
      -1,   199,   295,   226,   296,   223,    -1,   296,   227,   297,
      -1,   297,    -1,   173,    -1,   176,    -1,   177,    -1,   179,
      -1,   180,    -1,   183,    -1,    51,    -1,   196,    -1,   189,
      -1,   192,    -1,   200,    -1,   197,    -1,   182,    -1,   190,
      -1,   194,    -1,   184,    -1,   206,    -1,   174,    -1,   175,
      -1,   187,    -1,    -1,    36,   299,   226,   300,   223,    -1,
     300,   227,   301,    -1,   301,    -1,    47,    -1,   130,    -1,
      65,    -1,   213,    -1,   181,    -1,   201,    -1,   219,    -1,
      40,    -1,    25,    -1,   208,    -1,   129,    -1,     4,    -1,
     100,    -1,   190,    -1,   205,    -1,   112,    -1,   131,    -1,
     195,    -1,    93,    -1,    -1,    17,   303,   225,   304,   224,
     223,    -1,   304,   305,    -1,   305,    -1,   306,    -1,   316,
      -1,   317,    -1,   307,    -1,   318,    -1,   308,    -1,   309,
      -1,   310,    -1,   311,    -1,   312,    -1,   313,    -1,   314,
      -1,   315,    -1,   319,    -1,   320,    -1,   321,    -1,     1,
     223,    -1,    95,   226,   123,   223,    -1,   121,   226,   232,
     223,    -1,   107,   226,   105,   223,    -1,    19,   226,   232,
     223,    -1,    83,   226,   105,   223,    -1,    77,   226,   105,
     223,    -1,    79,   226,   105,   223,    -1,    78,   226,   105,
     223,    -1,   150,   226,   234,   223,    -1,   191,   226,   234,
     223,    -1,    15,   226,   105,   223,    -1,    16,   226,   105,
     223,    -1,   106,   226,   105,   223,    -1,    89,   226,   232,
     223,    -1,    90,   226,   232,   223,    -1,    -1,    36,   322,
     226,   323,   223,    -1,   323,   227,   324,    -1,   324,    -1,
      91,    -1,    92,    -1,    -1,    71,   326,   225,   331,   224,
     223,    -1,    -1,    36,   328,   226,   329,   223,    -1,   329,
     227,   330,    -1,   330,    -1,   198,    -1,    51,    -1,   193,
      -1,   331,   332,    -1,   332,    -1,   333,    -1,   327,    -1,
     337,    -1,   338,    -1,     1,   223,    -1,    -1,   122,   226,
     335,   334,   223,    -1,   335,   227,   336,    -1,   336,    -1,
     105,    -1,   105,   171,   105,    -1,    62,   226,   123,   223,
      -1,    57,   226,   123,   223,    -1,    -1,    48,   340,   225,
     341,   224,   223,    -1,   341,   342,    -1,   342,    -1,   343,
      -1,   344,    -1,   345,    -1,   347,    -1,   351,    -1,   352,
      -1,   353,    -1,   346,    -1,     1,   223,    -1,   214,   226,
     123,   223,    -1,   118,   226,   123,   223,    -1,    17,   226,
     123,   223,    -1,    32,   226,   167,   223,    -1,    -1,    36,
     348,   226,   349,   223,    -1,   349,   227,   350,    -1,   350,
      -1,   161,    -1,    33,    -1,    66,    -1,    49,    -1,    13,
      -1,   104,    -1,    43,    -1,   142,    -1,   207,    -1,    96,
      -1,   160,   226,   123,   223,    -1,   127,   226,   123,   223,
      -1,   126,   226,   105,   223,    -1,    -1,   141,   355,   225,
     356,   224,   223,    -1,   356,   357,    -1,   357,    -1,   358,
      -1,   359,    -1,   360,    -1,     1,   223,    -1,   125,   226,
     123,   223,    -1,    14,   226,   123,   223,    -1,    99,   226,
     123,   223,    -1,   209,   225,   362,   224,   223,    -1,   362,
     363,    -1,   363,    -1,   364,    -1,     1,    -1,    95,   226,
     123,   223,    -1,    -1,   156,   366,   225,   367,   224,   223,
      -1,   367,   368,    -1,   368,    -1,   369,    -1,   370,    -1,
     371,    -1,     1,   223,    -1,    95,   226,   123,   223,    -1,
     214,   226,   123,   223,    -1,    -1,   158,   372,   226,   373,
     223,    -1,   373,   227,   374,    -1,   374,    -1,    65,    -1,
     213,    -1,   181,    -1,   201,    -1,   219,    -1,   204,    -1,
     141,    -1,   203,    -1,   187,    -1,   172,    -1,    -1,   157,
     376,   225,   377,   224,   223,    -1,   377,   378,    -1,   378,
      -1,   379,    -1,   380,    -1,     1,   223,    -1,    95,   226,
     123,   223,    -1,    -1,   158,   381,   226,   382,   223,    -1,
     382,   227,   383,    -1,   383,    -1,    65,    -1,   213,    -1,
     181,    -1,   201,    -1,   219,    -1,   204,    -1,   141,    -1,
     203,    -1,   187,    -1,   172,    -1,    -1,    18,   385,   225,
     386,   224,   223,    -1,   386,   387,    -1,   387,    -1,   388,
      -1,   389,    -1,   390,    -1,   391,    -1,   392,    -1,   394,
      -1,   393,    -1,   403,    -1,   395,    -1,   400,    -1,   401,
      -1,   402,    -1,   399,    -1,     1,   223,    -1,    95,   226,
     123,   223,    -1,    57,   226,   123,   223,    -1,   217,   226,
     123,   223,    -1,   151,   226,   123,   223,    -1,     3,   226,
     123,   223,    -1,   122,   226,   105,   223,    -1,     5,   226,
     185,   223,    -1,     5,   226,   186,   223,    -1,    -1,    36,
     396,   226,   397,   223,    -1,   397,   227,   398,    -1,   398,
      -1,     8,    -1,   198,    -1,    32,   226,   167,   223,    -1,
      59,   226,   123,   223,    -1,    69,   226,   123,   223,    -1,
      17,   226,   123,   223,    -1,   178,   226,   123,   223,    -1,
      -1,    63,   405,   225,   410,   224,   223,    -1,    -1,   158,
     407,   226,   408,   223,    -1,   408,   227,   409,    -1,   409,
      -1,   128,    -1,   410,   411,    -1,   411,    -1,   412,    -1,
     413,    -1,   406,    -1,     1,    -1,   214,   226,   123,   223,
      -1,   125,   226,   123,   223,    -1,    -1,    23,   415,   225,
     416,   224,   223,    -1,   416,   417,    -1,   417,    -1,   418,
      -1,   419,    -1,     1,    -1,    62,   226,   123,   223,    -1,
     125,   226,   123,   223,    -1,    34,   225,   421,   224,   223,
      -1,   421,   422,    -1,   422,    -1,   423,    -1,     1,    -1,
      62,   226,   123,   223,    -1,    -1,    38,   425,   225,   430,
     224,   223,    -1,    -1,   158,   427,   226,   428,   223,    -1,
     428,   227,   429,    -1,   429,    -1,   128,    -1,   430,   431,
      -1,   431,    -1,   432,    -1,   433,    -1,   426,    -1,     1,
      -1,    95,   226,   123,   223,    -1,   125,   226,   123,   223,
      -1,    39,   225,   435,   224,   223,    -1,   435,   436,    -1,
     436,    -1,   445,    -1,   446,    -1,   448,    -1,   449,    -1,
     450,    -1,   451,    -1,   452,    -1,   453,    -1,   454,    -1,
     455,    -1,   444,    -1,   457,    -1,   458,    -1,   472,    -1,
     460,    -1,   462,    -1,   464,    -1,   463,    -1,   467,    -1,
     461,    -1,   468,    -1,   469,    -1,   470,    -1,   471,    -1,
     484,    -1,   473,    -1,   474,    -1,   475,    -1,   480,    -1,
     465,    -1,   466,    -1,   490,    -1,   488,    -1,   489,    -1,
     447,    -1,   479,    -1,   456,    -1,   477,    -1,   478,    -1,
     443,    -1,   438,    -1,   439,    -1,   440,    -1,   441,    -1,
     442,    -1,   459,    -1,   437,    -1,   476,    -1,     1,    -1,
      86,   226,   105,   223,    -1,    42,   226,   167,   223,    -1,
      41,   226,   232,   223,    -1,    44,   226,   232,   223,    -1,
      45,   226,   105,   223,    -1,    46,   226,   105,   223,    -1,
     155,   226,   167,   223,    -1,    64,   226,   232,   223,    -1,
      56,   226,   167,   223,    -1,    60,   226,   167,   223,    -1,
      28,   226,   167,   223,    -1,    35,   226,   167,   223,    -1,
       6,   226,   167,   223,    -1,    82,   226,   232,   223,    -1,
      80,   226,   105,   223,    -1,    73,   226,   105,   223,    -1,
       7,   226,   232,   223,    -1,   170,   226,   232,   223,    -1,
     169,   226,   232,   223,    -1,    50,   226,   105,   223,    -1,
      61,   226,   167,   223,    -1,   220,   226,   167,   223,    -1,
     162,   226,   167,   223,    -1,   165,   226,   167,   223,    -1,
     166,   226,   167,   223,    -1,   164,   226,   167,   223,    -1,
     164,   226,   168,   223,    -1,   163,   226,   167,   223,    -1,
     163,   226,   168,   223,    -1,   116,   226,   232,   223,    -1,
      12,   226,   232,   223,    -1,   109,   226,   167,   223,    -1,
     117,   226,   232,   223,    -1,   159,   226,   167,   223,    -1,
     103,   226,   167,   223,    -1,   212,   226,   167,   223,    -1,
     111,   226,   167,   223,    -1,    29,   226,   105,   223,    -1,
      84,   226,   105,   223,    -1,   215,   226,   167,   223,    -1,
      30,   226,   123,   223,    -1,   210,   226,   123,   223,    -1,
     120,   226,   167,   223,    -1,    26,   226,   167,   223,    -1,
     211,   226,   232,   223,    -1,    -1,   113,   481,   226,   482,
     223,    -1,   482,   227,   483,    -1,   483,    -1,   173,    -1,
     176,    -1,   177,    -1,   179,    -1,   180,    -1,   183,    -1,
      51,    -1,   196,    -1,   189,    -1,   192,    -1,   200,    -1,
     197,    -1,   182,    -1,   190,    -1,   194,    -1,   184,    -1,
     206,    -1,   174,    -1,   175,    -1,   187,    -1,    -1,   110,
     485,   226,   486,   223,    -1,   486,   227,   487,    -1,   487,
      -1,   173,    -1,   176,    -1,   177,    -1,   179,    -1,   180,
      -1,   183,    -1,   196,    -1,    51,    -1,   189,    -1,   192,
      -1,   200,    -1,   197,    -1,   182,    -1,   190,    -1,   194,
      -1,   184,    -1,   206,    -1,   174,    -1,   175,    -1,   187,
      -1,    87,   226,   105,   223,    -1,    88,   226,   105,   223,
      -1,    20,   226,   105,   223,    -1,    14,   225,   492,   224,
     223,    -1,   492,   493,    -1,   493,    -1,   501,    -1,   496,
      -1,   497,    -1,   498,    -1,   499,    -1,   500,    -1,   502,
      -1,   503,    -1,   504,    -1,   495,    -1,   505,    -1,   506,
      -1,   507,    -1,   494,    -1,     1,    -1,    27,   226,   167,
     223,    -1,   132,   226,   167,   223,    -1,    67,   226,   232,
     223,    -1,    68,   226,   232,   223,    -1,    76,   226,   105,
     223,    -1,    75,   226,   105,   223,    -1,   124,   226,   167,
     223,    -1,    74,   226,   105,   223,    -1,    22,   226,   105,
     223,    -1,    21,   226,   105,   223,    -1,   101,   226,   167,
     223,    -1,   102,   226,   167,   223,    -1,   114,   226,   105,
     223,    -1,   115,   226,   232,   223,    -1,   152,   225,   509,
     224,   223,    -1,   509,   510,    -1,   510,    -1,   511,    -1,
     512,    -1,   513,    -1,   515,    -1,   516,    -1,   514,    -1,
     517,    -1,     1,    -1,    37,   226,   167,   223,    -1,    54,
     226,   167,   223,    -1,    55,   226,   167,   223,    -1,    52,
     226,   123,   223,    -1,    70,   226,   232,   223,    -1,    51,
     226,   167,   223,    -1,    53,   226,   167,   223,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   364,   364,   365,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   393,   393,   394,   398,
     402,   406,   410,   414,   418,   422,   428,   428,   429,   430,
     431,   432,   439,   442,   442,   443,   443,   443,   445,   451,
     458,   460,   460,   461,   461,   462,   462,   463,   463,   464,
     464,   465,   465,   466,   466,   467,   467,   468,   468,   469,
     470,   473,   474,   476,   476,   477,   483,   491,   491,   492,
     498,   506,   548,   607,   635,   643,   658,   673,   682,   696,
     705,   733,   763,   788,   810,   832,   841,   843,   843,   844,
     844,   845,   845,   847,   856,   865,   877,   878,   878,   880,
     880,   881,   883,   890,   890,   903,   904,   906,   906,   907,
     907,   909,   917,   920,   926,   925,   931,   931,   932,   936,
     940,   944,   948,   952,   956,   967,   966,  1043,  1043,  1044,
    1044,  1044,  1045,  1045,  1045,  1046,  1046,  1046,  1048,  1054,
    1060,  1066,  1077,  1083,  1090,  1089,  1095,  1095,  1096,  1100,
    1104,  1108,  1112,  1116,  1120,  1124,  1128,  1132,  1136,  1140,
    1144,  1148,  1152,  1156,  1160,  1164,  1168,  1172,  1179,  1178,
    1184,  1184,  1185,  1189,  1193,  1197,  1201,  1205,  1209,  1213,
    1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,  1249,  1253,
    1257,  1268,  1267,  1328,  1328,  1329,  1330,  1330,  1331,  1332,
    1333,  1334,  1335,  1336,  1337,  1338,  1339,  1339,  1340,  1341,
    1342,  1343,  1345,  1351,  1357,  1363,  1369,  1375,  1381,  1387,
    1393,  1399,  1406,  1412,  1418,  1424,  1433,  1443,  1442,  1448,
    1448,  1449,  1453,  1464,  1463,  1470,  1469,  1474,  1474,  1475,
    1479,  1483,  1489,  1489,  1490,  1490,  1490,  1490,  1490,  1492,
    1492,  1494,  1494,  1496,  1510,  1530,  1536,  1546,  1545,  1587,
    1587,  1588,  1588,  1588,  1588,  1589,  1589,  1589,  1590,  1590,
    1592,  1598,  1604,  1610,  1622,  1621,  1627,  1627,  1628,  1632,
    1636,  1640,  1644,  1648,  1652,  1656,  1660,  1664,  1670,  1684,
    1693,  1707,  1706,  1721,  1721,  1722,  1722,  1722,  1722,  1724,
    1730,  1736,  1745,  1747,  1747,  1748,  1748,  1750,  1766,  1765,
    1790,  1790,  1791,  1791,  1791,  1791,  1793,  1799,  1819,  1818,
    1824,  1824,  1825,  1829,  1833,  1837,  1841,  1845,  1849,  1853,
    1857,  1861,  1871,  1870,  1891,  1891,  1892,  1892,  1892,  1894,
    1901,  1900,  1906,  1906,  1907,  1911,  1915,  1919,  1923,  1927,
    1931,  1935,  1939,  1943,  1953,  1952,  2018,  2018,  2019,  2019,
    2019,  2020,  2020,  2021,  2021,  2021,  2022,  2022,  2022,  2023,
    2023,  2024,  2026,  2032,  2038,  2044,  2057,  2070,  2076,  2080,
    2089,  2088,  2093,  2093,  2094,  2098,  2104,  2115,  2121,  2127,
    2133,  2149,  2148,  2211,  2210,  2216,  2216,  2217,  2223,  2223,
    2224,  2224,  2224,  2224,  2226,  2246,  2256,  2255,  2282,  2282,
    2283,  2283,  2283,  2285,  2291,  2300,  2302,  2302,  2303,  2303,
    2305,  2323,  2322,  2368,  2367,  2373,  2373,  2374,  2380,  2380,
    2381,  2381,  2381,  2381,  2383,  2389,  2398,  2401,  2401,  2402,
    2402,  2403,  2403,  2404,  2404,  2405,  2405,  2406,  2406,  2407,
    2408,  2409,  2409,  2410,  2410,  2411,  2411,  2412,  2412,  2413,
    2413,  2414,  2414,  2415,  2415,  2416,  2416,  2417,  2417,  2418,
    2418,  2419,  2419,  2420,  2421,  2421,  2422,  2423,  2424,  2424,
    2425,  2425,  2426,  2427,  2428,  2429,  2429,  2430,  2433,  2438,
    2444,  2450,  2456,  2461,  2466,  2471,  2476,  2481,  2486,  2491,
    2496,  2501,  2506,  2511,  2516,  2521,  2526,  2532,  2543,  2548,
    2553,  2558,  2563,  2568,  2571,  2576,  2579,  2584,  2589,  2594,
    2599,  2604,  2609,  2614,  2619,  2624,  2629,  2634,  2639,  2648,
    2657,  2662,  2667,  2673,  2672,  2677,  2677,  2678,  2681,  2684,
    2687,  2690,  2693,  2696,  2699,  2702,  2705,  2708,  2711,  2714,
    2717,  2720,  2723,  2726,  2729,  2732,  2735,  2741,  2740,  2745,
    2745,  2746,  2749,  2752,  2755,  2758,  2761,  2764,  2767,  2770,
    2773,  2776,  2779,  2782,  2785,  2788,  2791,  2794,  2797,  2800,
    2803,  2808,  2813,  2818,  2827,  2830,  2830,  2831,  2832,  2832,
    2833,  2833,  2834,  2834,  2835,  2836,  2836,  2837,  2838,  2838,
    2839,  2839,  2841,  2846,  2851,  2856,  2861,  2866,  2871,  2876,
    2881,  2886,  2891,  2896,  2901,  2906,  2914,  2917,  2917,  2918,
    2918,  2919,  2920,  2921,  2921,  2922,  2923,  2925,  2931,  2937,
    2943,  2952,  2966,  2972
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ADMIN", "AFTYPE",
  "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", "AUTOCONN", "BYTES",
  "KBYTES", "MBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL",
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS", "CONNECT",
  "CONNECTFREQ", "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT",
  "EGDPOOL_PATH", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "GLINE", "GLINE_DURATION", "GLINE_ENABLE", "GLINE_EXEMPT",
  "GLINE_REQUEST_DURATION", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_NAME", "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SERVICES",
  "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS",
  "INVISIBLE_ON_CONNECT", "IP", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE",
  "KLINE_EXEMPT", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "T_LOG", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT",
  "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MIN_IDLE", "MAX_IDLE",
  "RANDOM_IDLE", "HIDE_IDLE_FROM_OPERS", "MODULE", "MODULES", "NAME",
  "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT",
  "REDIRSERV", "REGEX_T", "REHASH", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE",
  "SSL_CERTIFICATE_FILE", "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD",
  "T_SSL_SERVER_METHOD", "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SENDQ", "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
  "T_SSL_CIPHER_LIST", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_SERVER",
  "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES",
  "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_GLOBOPS", "T_WALLOP", "T_WEBIRC", "T_RESTART", "T_SERVICE",
  "T_SERVICES_NAME", "THROTTLE_TIME", "TRUE_NO_OPER_FLOOD", "UNKLINE",
  "USER", "USE_EGD", "USE_LOGGING", "VHOST", "VHOST6", "XLINE",
  "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'", "'}'", "'{'", "'='", "','",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_client_method",
  "serverinfo_ssl_server_method", "client_method_types",
  "client_method_type_item", "server_method_types",
  "server_method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_hub", "admin_entry",
  "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "logging_entry", "logging_items", "logging_item",
  "logging_use_logging", "logging_file_entry", "$@1", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@2", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@3", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "$@4",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@5",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@6",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_recvq", "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@7", "class_flags_items", "class_flags_item",
  "listen_entry", "$@8", "listen_flags", "$@9", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@10", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@11", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@12",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@13", "resv_items", "resv_item",
  "resv_reason", "resv_channel", "resv_nick", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@14",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@15", "shared_types", "shared_type_item",
  "cluster_entry", "$@16", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@17", "cluster_types", "cluster_type_item",
  "connect_entry", "$@18", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_flags", "$@19", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_ssl_cipher_list", "kill_entry", "$@20",
  "kill_type", "$@21", "kill_type_items", "kill_type_item", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@22",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@23",
  "gecos_flags", "$@24", "gecos_flags_items", "gecos_flags_item",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_max_watch",
  "general_gline_enable", "general_gline_duration",
  "general_gline_request_duration", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_disable_remote_commands",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_havent_read_conf", "general_invisible_on_connect",
  "general_warn_no_nline", "general_stats_e_disabled",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood",
  "general_true_no_oper_flood", "general_oper_pass_resv",
  "general_dots_in_ident", "general_max_targets", "general_use_egd",
  "general_egdpool_path", "general_services_name", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "$@25", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@26", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_restrict_channels",
  "channel_knock_delay", "channel_knock_delay_channel",
  "channel_max_chans_per_user", "channel_max_chans_per_oper",
  "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_links_delay", "serverhide_hidden",
  "serverhide_hide_server_ips", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   228,   229,   229,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   231,   231,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   233,   234,   234,
     234,   234,   235,   236,   236,   237,   237,   237,   238,   239,
     240,   241,   241,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   243,   244,   245,   245,   246,   246,   247,   247,   248,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   265,   266,
     266,   266,   266,   267,   268,   269,   270,   271,   271,   272,
     272,   272,   273,   275,   274,   276,   276,   277,   277,   277,
     277,   278,   279,   279,   281,   280,   282,   282,   283,   283,
     283,   283,   283,   283,   283,   285,   284,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   288,   289,
     290,   291,   292,   293,   295,   294,   296,   296,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   299,   298,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   303,   302,   304,   304,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   322,   321,   323,
     323,   324,   324,   326,   325,   328,   327,   329,   329,   330,
     330,   330,   331,   331,   332,   332,   332,   332,   332,   334,
     333,   335,   335,   336,   336,   337,   338,   340,   339,   341,
     341,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     343,   344,   345,   346,   348,   347,   349,   349,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   350,   351,   352,
     353,   355,   354,   356,   356,   357,   357,   357,   357,   358,
     359,   360,   361,   362,   362,   363,   363,   364,   366,   365,
     367,   367,   368,   368,   368,   368,   369,   370,   372,   371,
     373,   373,   374,   374,   374,   374,   374,   374,   374,   374,
     374,   374,   376,   375,   377,   377,   378,   378,   378,   379,
     381,   380,   382,   382,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   385,   384,   386,   386,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   387,   387,
     387,   387,   388,   389,   390,   391,   392,   393,   394,   394,
     396,   395,   397,   397,   398,   398,   399,   400,   401,   402,
     403,   405,   404,   407,   406,   408,   408,   409,   410,   410,
     411,   411,   411,   411,   412,   413,   415,   414,   416,   416,
     417,   417,   417,   418,   419,   420,   421,   421,   422,   422,
     423,   425,   424,   427,   426,   428,   428,   429,   430,   430,
     431,   431,   431,   431,   432,   433,   434,   435,   435,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   462,   463,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   481,   480,   482,   482,   483,   483,   483,
     483,   483,   483,   483,   483,   483,   483,   483,   483,   483,
     483,   483,   483,   483,   483,   483,   483,   485,   484,   486,
     486,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   488,   489,   490,   491,   492,   492,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   509,   510,
     510,   510,   510,   510,   510,   510,   510,   511,   512,   513,
     514,   515,   516,   517
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     0,     1,     2,     3,
       3,     3,     5,     2,     1,     1,     1,     2,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     3,     1,     1,     1,     3,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     1,     1,
       1,     2,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     0,     6,     0,     5,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     0,
       5,     3,     1,     1,     3,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     4,     4,     4,     4,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   201,   364,   416,     0,
     431,     0,   267,   401,   243,     0,     0,   135,   301,     0,
       0,   318,   342,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   101,   100,   611,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   596,   610,   606,   598,   599,   600,   601,   602,
     597,   603,   604,   605,   607,   608,   609,     0,     0,     0,
     429,     0,     0,   427,   428,     0,   497,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   567,     0,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,   495,   489,   490,
     491,   492,   493,   488,   459,   449,   450,   483,   451,   452,
     453,   454,   455,   456,   457,   458,   485,   460,   461,   494,
     463,   468,   464,   466,   465,   478,   479,   467,   469,   470,
     471,   472,   462,   474,   475,   476,   496,   486,   487,   484,
     477,   473,   481,   482,   480,     0,     0,     0,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,    44,
      45,    46,     0,     0,   636,     0,     0,     0,     0,     0,
       0,     0,     0,   628,   629,   630,   631,   634,   632,   633,
     635,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    67,    68,    66,    63,    62,    69,    53,    65,    56,
      57,    58,    54,    64,    59,    60,    61,    55,     0,     0,
     316,     0,     0,   314,   315,   102,     0,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   595,     0,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   204,   205,   208,   210,   211,
     212,   213,   214,   215,   216,   217,   206,   207,   209,   218,
     219,   220,     0,     0,     0,     0,     0,   390,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   367,   368,   369,
     370,   371,   372,   374,   373,   376,   380,   377,   378,   379,
     375,   422,     0,     0,     0,   419,   420,   421,     0,     0,
     426,   443,     0,     0,   433,   442,     0,   439,   440,   441,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   447,
       0,     0,     0,   284,     0,     0,     0,     0,     0,     0,
     270,   271,   272,   273,   278,   274,   275,   276,   277,   413,
       0,   403,     0,   412,     0,   409,   410,   411,     0,   245,
       0,     0,     0,   255,     0,   253,   254,   256,   257,   111,
       0,     0,   107,     0,    47,     0,     0,     0,    43,     0,
       0,     0,   178,     0,     0,     0,   154,     0,     0,   138,
     139,   140,   141,   144,   145,   143,   142,   146,     0,     0,
       0,     0,     0,   304,   305,   306,   307,     0,     0,     0,
       0,     0,     0,     0,     0,   627,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,   328,     0,
       0,   321,   322,   323,   324,     0,     0,   350,     0,   345,
     346,   347,     0,     0,   313,     0,     0,     0,    96,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   594,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   203,   381,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   366,
       0,     0,     0,   418,     0,   425,     0,     0,     0,     0,
     438,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   446,   279,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   269,     0,     0,     0,     0,   408,   258,     0,
       0,     0,     0,     0,   252,     0,   106,     0,     0,     0,
      42,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,   308,     0,     0,     0,     0,   303,     0,     0,
       0,     0,     0,     0,     0,   626,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,    74,
      79,    80,     0,    78,     0,     0,     0,     0,     0,    50,
     325,     0,     0,     0,     0,   320,   348,     0,     0,     0,
     344,     0,   312,   105,   104,   103,   621,   620,   612,    26,
      26,    26,    26,    26,    26,    26,    28,    27,   614,   615,
     619,   617,   616,   622,   623,   624,   625,   618,   613,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,     0,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   365,     0,     0,   417,   430,     0,     0,     0,   432,
     510,   514,   528,   593,   541,   508,   535,   538,   509,   500,
     499,   501,   502,   503,   517,   506,   507,   518,   505,   513,
     512,   511,   536,   498,   591,   592,   532,   529,   578,   571,
     588,   589,   572,   573,   574,   575,   583,   576,   586,   590,
     579,   584,   580,   585,   577,   582,   581,   587,     0,   570,
     534,   553,   547,   564,   565,   548,   549,   550,   551,   559,
     552,   562,   566,   555,   560,   556,   561,   554,   558,   557,
     563,     0,   546,   527,   530,   540,   504,   531,   520,   525,
     526,   523,   524,   521,   522,   516,   515,   539,   542,   533,
     537,   519,     0,     0,     0,     0,     0,     0,     0,     0,
     268,     0,     0,     0,   402,     0,     0,     0,   263,   259,
     262,   244,   112,     0,     0,   124,     0,     0,   116,   117,
     119,   118,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,   302,   637,   642,   640,
     643,   638,   639,   641,    87,    95,    93,    94,    85,    89,
      88,    82,    81,    83,    71,     0,    72,     0,    86,    84,
      92,    90,    91,     0,     0,     0,   319,     0,     0,   343,
     317,    29,    30,    31,    32,    33,    34,    35,   232,   233,
     225,   241,   242,     0,   240,   227,   229,   228,   226,   235,
     236,   222,   234,   224,   223,    36,    36,    36,    38,    37,
     230,   231,   386,   388,   389,   399,   396,   394,   395,     0,
     393,   383,   397,   398,   382,   387,   385,   400,   384,   423,
     424,   444,   445,   437,     0,   436,   568,     0,   544,     0,
     282,   283,   292,   289,   294,   291,   290,   297,   293,   295,
     288,   296,     0,   287,   281,   300,   299,   298,   280,   415,
     407,     0,   406,   414,   250,   251,   249,     0,   248,   266,
     265,     0,     0,     0,   120,     0,     0,     0,     0,   115,
     153,   151,   193,   190,   189,   182,   184,   200,   194,   197,
     192,   183,   198,   186,   195,   199,   187,   196,   191,   185,
     188,     0,   181,   148,   150,   152,   164,   158,   175,   176,
     159,   160,   161,   162,   170,   163,   173,   177,   166,   171,
     167,   172,   165,   169,   168,   174,     0,   157,   149,   310,
     311,   309,    73,    77,   326,   332,   338,   341,   334,   340,
     335,   339,   337,   333,   336,     0,   331,   327,   349,   354,
     360,   363,   356,   362,   357,   361,   359,   355,   358,     0,
     353,   238,     0,    39,    40,    41,   391,     0,   434,     0,
     569,   545,   285,     0,   404,     0,   246,     0,   264,   261,
     260,     0,     0,     0,     0,   114,   179,     0,   155,     0,
     329,     0,   351,     0,   239,   392,   435,   286,   405,   247,
     121,   130,   133,   132,   129,   134,   131,   128,     0,   127,
     123,   122,   180,   156,   330,   352,   125,     0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   796,   797,  1048,  1049,    25,   228,   229,
     230,   231,    26,   269,   270,   271,   272,   758,   759,   762,
     763,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,    27,    71,    72,    73,
      74,    75,    28,   220,   221,   222,   223,   224,   967,   968,
     969,   970,   971,  1116,  1248,  1249,    29,    60,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   728,  1166,  1167,
     517,   724,  1141,  1142,    30,    49,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   599,  1033,  1034,    31,    57,   483,
     709,  1107,  1108,   484,   485,   486,  1113,   959,   960,   487,
     488,    32,    55,   459,   460,   461,   462,   463,   464,   465,
     695,  1092,  1093,   466,   467,   468,    33,    61,   522,   523,
     524,   525,   526,    34,   292,   293,   294,    35,    64,   560,
     561,   562,   563,   564,   772,  1185,  1186,    36,    65,   568,
     569,   570,   571,   778,  1199,  1200,    37,    50,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   619,  1059,
    1060,   376,   377,   378,   379,   380,    38,    56,   473,   704,
    1101,  1102,   474,   475,   476,   477,    39,    51,   384,   385,
     386,   387,    40,   112,   113,   114,    41,    53,   395,   638,
    1074,  1075,   396,   397,   398,   399,    42,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   430,   921,   922,   211,   428,   898,   899,
     212,   213,   214,    43,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      44,   242,   243,   244,   245,   246,   247,   248,   249,   250
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -967
static const yytype_int16 yypact[] =
{
    -967,   613,  -967,    -1,  -219,  -207,  -967,  -967,  -967,  -202,
    -967,  -189,  -967,  -967,  -967,  -182,  -173,  -967,  -967,  -165,
    -162,  -967,  -967,  -160,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,    33,   852,  -134,
    -121,  -110,    13,  -107,   360,  -105,   -79,   -67,    76,    72,
     -62,   -46,   536,   406,   -43,   -31,    28,   -90,   -18,    38,
      50,     8,  -967,  -967,  -967,  -967,  -967,    56,    67,    71,
      73,    75,    83,    88,    92,    95,   104,   108,   112,   126,
     128,   151,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,   641,   426,    49,
    -967,   130,    44,  -967,  -967,    10,  -967,   131,   132,   133,
     134,   136,   138,   139,   142,   143,   144,   148,   152,   153,
     159,   161,   165,   168,   170,   171,   172,   182,   185,   186,
     187,   189,   191,   192,   196,  -967,   197,  -967,   199,   200,
     202,   206,   209,   213,   219,   223,   224,   225,   226,   228,
     229,   233,   234,   235,   240,   125,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,   436,    32,   319,   -20,   241,
      47,  -967,  -967,  -967,   122,   154,   248,   249,    15,  -967,
    -967,  -967,   402,   201,  -967,   252,   253,   255,   258,   260,
     262,   263,    16,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,   259,   267,   268,   270,   272,   273,   274,   279,   280,
     282,   283,   284,   285,   286,   288,   290,   291,   292,   175,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,    48,    29,
    -967,   301,    27,  -967,  -967,  -967,   379,   405,   409,   310,
    -967,   150,   246,   215,   309,   309,   430,   435,   440,   380,
     383,   446,   309,   385,   386,   332,  -967,   335,   333,   338,
     339,  -967,   341,   342,   343,   352,   353,   355,   357,   359,
     366,   367,   369,   371,     6,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,   363,   372,   374,   377,   381,  -967,   382,   384,
     389,   392,   393,   394,   396,   399,   314,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,   400,   408,    55,  -967,  -967,  -967,   438,   388,
    -967,  -967,   415,   418,  -967,  -967,    19,  -967,  -967,  -967,
     445,   309,   309,   500,   465,   468,   540,   525,   479,   309,
     486,   309,   549,   550,   553,   495,   496,   498,   309,   554,
     569,   309,   573,   575,   576,   577,   516,   519,   461,   522,
     466,   309,   309,   524,   530,   531,   534,   118,   156,   535,
     539,   309,   309,   580,   309,   541,   542,   545,   477,  -967,
     490,   489,   497,  -967,   499,   501,   503,   506,   507,    23,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
     508,  -967,   511,  -967,    34,  -967,  -967,  -967,   512,  -967,
     513,   515,   517,  -967,    25,  -967,  -967,  -967,  -967,  -967,
     559,   521,  -967,   520,  -967,   615,   619,   526,  -967,   527,
     529,   532,  -967,   537,   538,   557,  -967,   558,    30,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   528,   560,
     563,   567,    37,  -967,  -967,  -967,  -967,   579,   585,   630,
     589,   590,   593,   309,   544,  -967,  -967,   638,   601,   671,
     674,   673,   676,   677,   678,   679,   680,   188,   193,   682,
     683,   692,   684,   685,   586,  -967,   592,   597,  -967,   599,
      43,  -967,  -967,  -967,  -967,   595,   602,  -967,    26,  -967,
    -967,  -967,   707,   623,  -967,   627,   628,   633,  -967,   635,
     640,   644,   523,   645,   646,   647,   649,   653,   654,   655,
     657,   666,   667,   668,  -967,  -967,   731,   755,   309,   670,
     759,   787,   788,   789,   309,   309,   776,   795,   796,   309,
     797,   797,   681,  -967,  -967,   780,   157,   782,   739,   686,
     785,   786,   791,   792,   805,   793,   794,   798,   688,  -967,
     799,   800,   695,  -967,   701,  -967,   802,   806,   704,   708,
    -967,   709,   710,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   720,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   732,   733,   734,   735,   736,   737,   738,   598,
     740,   637,   741,   742,   745,   746,   747,   748,   749,   750,
     751,   752,   754,   756,   757,   758,   760,   762,   763,   764,
     765,  -967,  -967,   839,   811,   766,   859,   884,   867,   868,
     870,   771,  -967,   872,   770,   874,   775,  -967,  -967,   773,
     877,   878,   897,   781,  -967,   783,  -967,     3,   784,   790,
    -967,  -967,   880,   838,   801,   885,   886,   887,   803,   888,
     807,  -967,  -967,   889,   891,   892,   808,  -967,   809,   810,
     812,   813,   814,   815,   816,  -967,   817,   818,   819,   820,
     821,   822,   823,   824,   825,   826,  -967,  -967,  -215,  -967,
    -967,  -967,  -208,  -967,   827,   828,   829,   830,   831,  -967,
    -967,   893,   832,   894,   833,  -967,  -967,   895,   834,   836,
    -967,   840,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   309,
     309,   309,   309,   309,   309,   309,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   841,
     842,   843,   256,   844,   845,   846,   847,   848,   849,   850,
     851,   853,   854,   295,   855,   856,  -967,   857,   858,   860,
     861,   862,    -3,   863,   864,   865,   866,   869,   871,   873,
     875,  -967,   876,   879,  -967,  -967,   881,   882,   896,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -186,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -169,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,   883,   890,   533,   898,   899,   900,   901,   902,
    -967,   903,   906,   904,  -967,    -5,   905,   907,   911,   835,
    -967,  -967,  -967,   908,   909,  -967,   910,   101,  -967,  -967,
    -967,  -967,  -967,  -967,   914,   915,   509,   916,   917,   918,
     665,   919,  -967,   920,   921,   922,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,   188,  -967,   193,  -967,  -967,
    -967,  -967,  -967,   923,   492,   924,  -967,   925,   694,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -151,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,   797,   797,   797,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -149,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -135,  -967,  -967,   598,  -967,   637,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -133,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -130,  -967,  -967,  -967,  -967,  -967,   -23,  -967,  -967,
    -967,   950,   897,   926,  -967,   934,   927,   -92,   928,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,   -13,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,    -7,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,    -6,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,    51,
    -967,  -967,   256,  -967,  -967,  -967,  -967,    -3,  -967,   896,
    -967,  -967,  -967,   533,  -967,   906,  -967,    -5,  -967,  -967,
    -967,   929,   276,   931,   932,  -967,  -967,   509,  -967,   665,
    -967,   492,  -967,   694,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,    54,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,   276,  -967
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -967,  -967,  -967,    93,  -302,  -966,  -610,  -967,  -967,   930,
    -967,  -967,  -967,  -967,   753,  -967,  -967,  -967,    14,  -967,
      18,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,   949,  -967,
    -967,  -967,  -967,  -967,   912,  -967,  -967,  -967,  -967,    59,
    -967,  -967,  -967,  -967,  -967,  -236,  -967,  -967,  -967,   582,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -206,
    -967,  -967,  -967,  -199,  -967,  -967,  -967,   761,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -141,  -967,  -967,  -967,
    -967,  -967,  -142,  -967,   607,  -967,  -967,  -967,   -19,  -967,
    -967,  -967,  -967,  -967,   642,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -116,  -967,  -967,  -967,  -967,  -967,  -967,   578,
    -967,  -967,  -967,  -967,  -967,   837,  -967,  -967,  -967,  -967,
     543,  -967,  -967,  -967,  -967,  -967,  -124,  -967,  -967,  -967,
     546,  -967,  -967,  -967,  -967,  -125,  -967,  -967,  -967,   743,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
     -97,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -104,  -967,   643,  -967,  -967,  -967,  -967,  -967,   772,
    -967,  -967,  -967,  -967,  1000,  -967,  -967,  -967,  -967,  -967,
    -967,   -94,  -967,   767,  -967,  -967,  -967,  -967,   951,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,    39,  -967,  -967,  -967,    42,
    -967,  -967,  -967,  -967,  -967,  1029,  -967,  -967,  -967,  -967,
    -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,  -967,
    -967,  -967,   933,  -967,  -967,  -967,  -967,  -967,  -967,  -967
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
     824,   825,   583,   584,   963,  1057,    47,   317,  1004,    67,
     591,   391,  1005,   823,   110,  1006,   225,   234,    48,  1007,
     391,   318,   319,    52,   450,   320,   478,   565,   290,   290,
     565,   499,    68,   469,    67,   469,    54,  1076,   518,    69,
     451,  1077,   321,    58,   556,   110,  1104,   500,   218,   556,
     381,   519,    59,   235,  1078,   452,   381,    68,  1079,   453,
      62,   479,   501,    63,    69,    66,   502,   236,   237,   238,
     239,   240,  1201,   225,  1206,   111,  1202,   218,  1207,  1203,
    1204,  1205,   480,   322,   323,   324,   241,   481,  1208,   325,
    1212,   107,  1209,  1214,  1213,   326,   327,  1215,   964,   642,
     643,   328,   963,    70,   108,   392,   111,   650,   226,   652,
    1223,   382,   329,   330,   392,   109,   659,   382,   115,   662,
     215,   566,   291,   291,   566,   503,   116,   331,    70,   672,
     673,   117,   118,   295,   227,   393,   520,   119,   557,   684,
     685,   454,   687,   557,   393,   120,   216,   482,   504,   455,
     456,   121,    76,   122,   123,   124,   332,   470,   217,   470,
     125,   965,   521,   232,   505,   226,   126,   127,   394,   128,
     129,   130,    77,    78,   383,   131,   251,   394,    79,   233,
     383,   132,   288,   457,   567,   133,   134,   567,  1105,   135,
     471,   227,   471,  1106,   289,  1058,   964,   333,   136,   252,
    1216,   558,   518,   489,  1217,   137,   558,   138,   296,   139,
    1226,   140,   141,   142,  1227,   519,  1228,  1230,    80,    81,
    1229,  1231,    45,    46,   966,    82,    83,    84,   143,   506,
     612,   744,   299,   253,   144,   145,   146,   458,   147,   497,
     534,   148,   149,   639,   507,   150,   472,   701,   472,   713,
     779,   573,    85,    86,   730,   579,   254,   559,   706,   965,
     255,   736,   559,   219,   297,    87,    88,   774,   389,  -113,
     256,   491,   257,   258,  1232,    89,   298,  1256,  1233,   632,
     151,  1257,   301,    90,   152,   678,   679,   153,   154,   155,
     156,   157,   219,   302,   158,   159,   811,   303,  -113,   304,
     520,   305,   817,   818,  1045,  1046,  1047,   822,   259,   306,
     260,   261,   262,   263,   307,   352,  1241,   353,   308,   354,
     478,   309,   966,   680,   681,  1118,   521,   756,   757,   264,
     310,   355,   760,   761,   311,   160,   161,   162,   312,  1242,
     163,  1243,   828,   829,   493,   164,   356,  1031,  1032,   448,
     357,   580,   313,   265,   314,   479,   388,   400,   401,   402,
     403,   116,   404,   266,   405,   406,   117,   118,   407,   408,
     409,   358,   119,   359,   410,   315,   480,   494,   411,   412,
     120,   481,   581,   360,  1244,   413,   121,   414,   122,   123,
     124,   415,   267,   268,   416,   125,   417,   418,   419,   554,
     823,   126,   127,   499,   128,   129,   130,   251,   420,   361,
     131,   421,   422,   423,   582,   424,   132,   425,   426,   500,
     133,   134,   427,   429,   135,   431,   432,   352,   433,   353,
     252,   354,   434,   136,   501,   435,   362,   450,   502,   436,
     137,   482,   138,   355,   139,   437,   140,   141,   142,   438,
     439,   440,   441,   451,   442,   443,  1245,  1246,   356,   444,
     445,   446,   357,   143,   253,   363,   447,   490,   452,   144,
     145,   146,   453,   147,   495,   496,   148,   149,   527,   528,
     150,   529,   536,   358,   530,   359,   531,   254,   532,   533,
    1247,   255,   364,   537,   538,   360,   539,   503,   540,   541,
     542,   256,   575,   257,   258,   543,   544,  1224,   545,   546,
     547,   548,   549,  1122,   550,   151,   551,   552,   553,   152,
     504,   361,   153,   154,   155,   156,   157,   572,   576,   158,
     159,   365,   577,   578,  1123,   585,   505,   234,   628,   259,
     586,   260,   261,   262,   263,   587,  1082,   588,   362,  1124,
     589,   590,   592,   593,   454,   594,  1125,  1175,   595,   596,
     264,   634,   455,   456,   597,   598,  1083,   600,   601,   602,
     160,   161,   162,   235,  1126,   163,  1084,   363,   603,   604,
     164,   605,  1085,   606,   265,   607,   614,   236,   237,   238,
     239,   240,   608,   609,   266,   610,   457,   611,   615,  1086,
     616,   506,  1127,   617,   364,   644,   241,   618,   620,  1128,
     621,   635,   641,     2,     3,   622,   507,     4,   623,   624,
     625,  1129,   626,   267,   268,   627,   630,     5,   582,  1087,
       6,     7,   645,  1176,   631,   646,     8,  1088,  1130,  1131,
    1132,   636,   317,   365,   637,   647,   649,     9,   648,   878,
     458,    10,    11,   651,   653,   654,   318,   319,   655,   660,
     320,    12,   656,   657,  1177,   658,   789,   790,   791,   792,
     793,   794,   795,  1178,   661,  1089,    13,   321,   663,  1179,
     664,   665,   666,   667,    14,    15,   668,   669,   901,   670,
    1133,   674,   671,  1180,  1090,  1181,  1182,   675,   676,  1134,
     691,   677,   682,   686,  1135,  1183,   683,    16,   688,   689,
    1136,  1184,   690,   692,  1137,   693,  1146,  1138,   322,   323,
     324,    17,  1139,   694,   325,   696,   715,   697,  1140,   698,
     326,   327,   699,   700,   703,   708,   328,   705,   718,   710,
    1091,   711,   719,   712,   716,   717,   738,   329,   330,   720,
     721,   732,   739,   740,    18,   722,   741,   742,   723,  1189,
     743,   746,   331,   725,   726,    19,    20,   745,   747,    21,
      22,   879,   880,   881,   882,   883,   748,   884,   885,   749,
     886,   887,   888,   727,   729,   889,   733,   890,   891,   734,
     892,   332,   893,   735,   894,   895,   750,   766,   896,   751,
     752,   753,   754,   755,   897,   764,   765,   767,   768,   769,
     902,   903,   904,   905,   906,   770,   907,   908,   776,   909,
     910,   911,    23,   771,   912,   773,   913,   914,   777,   915,
     781,   916,   333,   917,   918,  1190,   809,   919,  1147,  1148,
    1149,  1150,  1151,   920,  1152,  1153,   782,  1154,  1155,  1156,
     783,   784,  1157,    76,  1158,  1159,   785,  1160,   786,  1161,
     810,  1162,  1163,   787,   813,  1164,  1191,   788,   798,   799,
     800,  1165,   801,    77,    78,  1192,   802,   803,   804,    79,
     805,  1193,  1021,  1022,  1023,  1024,  1025,  1026,  1027,   806,
     807,   808,   814,   815,   816,  1194,   812,  1195,  1196,   819,
     820,   821,   823,   827,   826,   830,   831,  1197,   833,   834,
     837,   841,   832,  1198,   835,   836,   838,   839,   844,    80,
      81,   840,   842,   843,   845,   846,    82,    83,    84,   847,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   860,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,    85,    86,   871,   872,   873,   874,   875,
     876,   877,   942,   900,   923,   924,    87,    88,   925,   926,
     927,   928,   929,   930,   931,   932,    89,   933,   943,   934,
     935,   936,   945,   937,    90,   938,   939,   940,   941,   946,
     947,   948,   944,   949,   950,   951,   952,   953,   954,   955,
     956,   957,   958,   974,   961,   975,   962,   972,   977,   978,
     979,   981,   983,   973,   984,   985,  1013,  1015,  1017,  1172,
     300,  1258,   555,  1253,  1073,  1173,  1119,   976,  1252,   980,
     982,   986,   987,   988,  1100,   989,   990,   991,   992,   993,
     994,   995,   996,   997,   998,   999,  1000,  1001,  1002,  1003,
    1008,  1009,  1010,  1011,  1012,  1218,  1016,  1221,  1014,  1019,
    1018,  1234,  1112,  1020,  1028,  1029,  1030,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1239,  1043,  1044,  1050,  1051,
    1052,  1053,  1111,  1054,  1055,  1056,  1061,  1062,  1063,  1064,
     731,   714,  1065,  1219,  1066,   613,  1067,  1237,  1068,  1069,
     737,   702,  1070,   775,  1071,  1072,  1080,  1254,  1255,   629,
    1235,  1238,   390,  1081,   780,  1236,   449,   707,  1211,  1210,
     316,  1094,  1095,  1096,  1097,  1098,  1099,  1103,  1109,   574,
    1110,  1114,   492,     0,     0,  1115,  1117,  1120,  1121,  1143,
    1144,  1145,  1168,  1169,  1170,  1171,  1174,  1187,  1188,  1220,
       0,  1225,  1240,  1222,  1250,  1251,   633,     0,   498,     0,
       0,     0,     0,   640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   535
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-967)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     610,   611,   304,   305,     1,     8,   225,     1,   223,     1,
     312,     1,   227,   105,     1,   223,     1,     1,   225,   227,
       1,    15,    16,   225,     1,    19,     1,     1,     1,     1,
       1,     1,    24,     1,     1,     1,   225,   223,     1,    31,
      17,   227,    36,   225,     1,     1,    51,    17,     1,     1,
       1,    14,   225,    37,   223,    32,     1,    24,   227,    36,
     225,    36,    32,   225,    31,   225,    36,    51,    52,    53,
      54,    55,   223,     1,   223,    62,   227,     1,   227,  1045,
    1046,  1047,    57,    77,    78,    79,    70,    62,   223,    83,
     223,   225,   227,   223,   227,    89,    90,   227,    95,   401,
     402,    95,     1,    95,   225,    95,    62,   409,    93,   411,
     202,    62,   106,   107,    95,   225,   418,    62,   225,   421,
     225,    95,    95,    95,    95,    95,     1,   121,    95,   431,
     432,     6,     7,   223,   119,   125,    99,    12,    95,   441,
     442,   118,   444,    95,   125,    20,   225,   122,   118,   126,
     127,    26,     1,    28,    29,    30,   150,   125,   225,   125,
      35,   158,   125,   225,   134,    93,    41,    42,   158,    44,
      45,    46,    21,    22,   125,    50,     1,   158,    27,   225,
     125,    56,   225,   160,   158,    60,    61,   158,   193,    64,
     158,   119,   158,   198,   225,   198,    95,   191,    73,    24,
     223,   158,     1,   223,   227,    80,   158,    82,   226,    84,
     223,    86,    87,    88,   227,    14,   223,   223,    67,    68,
     227,   227,   223,   224,   221,    74,    75,    76,   103,   199,
     224,   533,   224,    58,   109,   110,   111,   214,   113,   224,
     224,   116,   117,   224,   214,   120,   214,   224,   214,   224,
     224,   224,   101,   102,   224,   105,    81,   214,   224,   158,
      85,   224,   214,   216,   226,   114,   115,   224,   224,   222,
      95,   224,    97,    98,   223,   124,   226,   223,   227,   224,
     155,   227,   226,   132,   159,   167,   168,   162,   163,   164,
     165,   166,   216,   226,   169,   170,   598,   226,   222,   226,
      99,   226,   604,   605,     9,    10,    11,   609,   133,   226,
     135,   136,   137,   138,   226,     1,    40,     3,   226,     5,
       1,   226,   221,   167,   168,   224,   125,   139,   140,   154,
     226,    17,   139,   140,   226,   210,   211,   212,   226,    63,
     215,    65,   185,   186,   222,   220,    32,    91,    92,   224,
      36,   105,   226,   178,   226,    36,   226,   226,   226,   226,
     226,     1,   226,   188,   226,   226,     6,     7,   226,   226,
     226,    57,    12,    59,   226,   224,    57,   223,   226,   226,
      20,    62,   167,    69,   108,   226,    26,   226,    28,    29,
      30,   226,   217,   218,   226,    35,   226,   226,   226,   224,
     105,    41,    42,     1,    44,    45,    46,     1,   226,    95,
      50,   226,   226,   226,   105,   226,    56,   226,   226,    17,
      60,    61,   226,   226,    64,   226,   226,     1,   226,     3,
      24,     5,   226,    73,    32,   226,   122,     1,    36,   226,
      80,   122,    82,    17,    84,   226,    86,    87,    88,   226,
     226,   226,   226,    17,   226,   226,   180,   181,    32,   226,
     226,   226,    36,   103,    58,   151,   226,   226,    32,   109,
     110,   111,    36,   113,   226,   226,   116,   117,   226,   226,
     120,   226,   223,    57,   226,    59,   226,    81,   226,   226,
     214,    85,   178,   226,   226,    69,   226,    95,   226,   226,
     226,    95,   123,    97,    98,   226,   226,  1117,   226,   226,
     226,   226,   226,     4,   226,   155,   226,   226,   226,   159,
     118,    95,   162,   163,   164,   165,   166,   226,   123,   169,
     170,   217,   123,   223,    25,   105,   134,     1,   224,   133,
     105,   135,   136,   137,   138,   105,    13,   167,   122,    40,
     167,   105,   167,   167,   118,   223,    47,    65,   223,   226,
     154,   123,   126,   127,   226,   226,    33,   226,   226,   226,
     210,   211,   212,    37,    65,   215,    43,   151,   226,   226,
     220,   226,    49,   226,   178,   226,   223,    51,    52,    53,
      54,    55,   226,   226,   188,   226,   160,   226,   226,    66,
     226,   199,    93,   226,   178,   105,    70,   226,   226,   100,
     226,   223,   167,     0,     1,   226,   214,     4,   226,   226,
     226,   112,   226,   217,   218,   226,   226,    14,   105,    96,
      17,    18,   167,   141,   226,   167,    23,   104,   129,   130,
     131,   226,     1,   217,   226,   105,   167,    34,   123,    51,
     214,    38,    39,   167,   105,   105,    15,    16,   105,   105,
      19,    48,   167,   167,   172,   167,   143,   144,   145,   146,
     147,   148,   149,   181,   105,   142,    63,    36,   105,   187,
     105,   105,   105,   167,    71,    72,   167,   226,    51,   167,
     181,   167,   226,   201,   161,   203,   204,   167,   167,   190,
     223,   167,   167,   123,   195,   213,   167,    94,   167,   167,
     201,   219,   167,   223,   205,   226,    51,   208,    77,    78,
      79,   108,   213,   226,    83,   226,   167,   226,   219,   226,
      89,    90,   226,   226,   226,   223,    95,   226,   123,   226,
     207,   226,   123,   226,   223,   225,   167,   106,   107,   223,
     223,   223,   167,   123,   141,   226,   167,   167,   226,    65,
     167,   123,   121,   226,   226,   152,   153,   223,   167,   156,
     157,   173,   174,   175,   176,   177,   105,   179,   180,   105,
     182,   183,   184,   226,   226,   187,   226,   189,   190,   226,
     192,   150,   194,   226,   196,   197,   123,   105,   200,   123,
     123,   123,   123,   123,   206,   123,   123,   123,   123,   223,
     173,   174,   175,   176,   177,   223,   179,   180,   223,   182,
     183,   184,   209,   226,   187,   226,   189,   190,   226,   192,
     123,   194,   191,   196,   197,   141,   105,   200,   173,   174,
     175,   176,   177,   206,   179,   180,   223,   182,   183,   184,
     223,   223,   187,     1,   189,   190,   223,   192,   223,   194,
     105,   196,   197,   223,   105,   200,   172,   223,   223,   223,
     223,   206,   223,    21,    22,   181,   223,   223,   223,    27,
     223,   187,   789,   790,   791,   792,   793,   794,   795,   223,
     223,   223,   105,   105,   105,   201,   226,   203,   204,   123,
     105,   105,   105,   123,   223,   123,   167,   213,   123,   123,
     105,   223,   226,   219,   123,   123,   123,   123,   223,    67,
      68,   123,   123,   123,   223,   123,    74,    75,    76,   123,
     226,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   101,   102,   223,   223,   223,   223,   223,
     223,   223,   123,   223,   223,   223,   114,   115,   223,   223,
     223,   223,   223,   223,   223,   223,   124,   223,   167,   223,
     223,   223,   123,   223,   132,   223,   223,   223,   223,   105,
     123,   123,   226,   123,   223,   123,   226,   123,   223,   226,
     123,   123,   105,   123,   223,   167,   223,   223,   123,   123,
     123,   123,   123,   223,   123,   123,   123,   123,   123,  1005,
      71,  1257,   269,  1229,   128,  1007,   967,   226,  1227,   226,
     223,   223,   223,   223,   128,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   105,   223,   123,   226,   223,
     226,  1202,   227,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,  1217,   223,   223,   223,   223,
     223,   223,   171,   223,   223,   223,   223,   223,   223,   223,
     508,   484,   223,  1112,   223,   334,   223,  1213,   223,   223,
     522,   459,   223,   560,   223,   223,   223,  1231,  1233,   366,
    1207,  1215,   112,   223,   568,  1209,   165,   474,  1079,  1077,
      91,   223,   223,   223,   223,   223,   223,   223,   223,   292,
     223,   223,   220,    -1,    -1,   226,   226,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
      -1,   223,   223,   226,   223,   223,   384,    -1,   228,    -1,
      -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   242
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   229,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    63,    71,    72,    94,   108,   141,   152,
     153,   156,   157,   209,   230,   235,   240,   264,   270,   284,
     302,   325,   339,   354,   361,   365,   375,   384,   404,   414,
     420,   424,   434,   491,   508,   223,   224,   225,   225,   303,
     385,   415,   225,   425,   225,   340,   405,   326,   225,   225,
     285,   355,   225,   225,   366,   376,   225,     1,    24,    31,
      95,   265,   266,   267,   268,   269,     1,    21,    22,    27,
      67,    68,    74,    75,    76,   101,   102,   114,   115,   124,
     132,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   225,   225,   225,
       1,    62,   421,   422,   423,   225,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    56,    60,    61,    64,    73,    80,    82,    84,
      86,    87,    88,   103,   109,   110,   111,   113,   116,   117,
     120,   155,   159,   162,   163,   164,   165,   166,   169,   170,
     210,   211,   212,   215,   220,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   484,   488,   489,   490,   225,   225,   225,     1,   216,
     271,   272,   273,   274,   275,     1,    93,   119,   236,   237,
     238,   239,   225,   225,     1,    37,    51,    52,    53,    54,
      55,    70,   509,   510,   511,   512,   513,   514,   515,   516,
     517,     1,    24,    58,    81,    85,    95,    97,    98,   133,
     135,   136,   137,   138,   154,   178,   188,   217,   218,   241,
     242,   243,   244,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   225,   225,
       1,    95,   362,   363,   364,   223,   226,   226,   226,   224,
     266,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   224,   493,     1,    15,    16,
      19,    36,    77,    78,    79,    83,    89,    90,    95,   106,
     107,   121,   150,   191,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,     1,     3,     5,    17,    32,    36,    57,    59,
      69,    95,   122,   151,   178,   217,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   399,   400,   401,   402,
     403,     1,    62,   125,   416,   417,   418,   419,   226,   224,
     422,     1,    95,   125,   158,   426,   430,   431,   432,   433,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   485,   226,
     481,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   224,   436,
       1,    17,    32,    36,   118,   126,   127,   160,   214,   341,
     342,   343,   344,   345,   346,   347,   351,   352,   353,     1,
     125,   158,   214,   406,   410,   411,   412,   413,     1,    36,
      57,    62,   122,   327,   331,   332,   333,   337,   338,   223,
     226,   224,   272,   222,   223,   226,   226,   224,   237,     1,
      17,    32,    36,    95,   118,   134,   199,   214,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   298,     1,    14,
      99,   125,   356,   357,   358,   359,   360,   226,   226,   226,
     226,   226,   226,   226,   224,   510,   223,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   224,   242,     1,    95,   158,   214,
     367,   368,   369,   370,   371,     1,    95,   158,   377,   378,
     379,   380,   226,   224,   363,   123,   123,   123,   223,   105,
     105,   167,   105,   232,   232,   105,   105,   105,   167,   167,
     105,   232,   167,   167,   223,   223,   226,   226,   226,   322,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   224,   305,   223,   226,   226,   226,   226,   396,
     226,   226,   226,   226,   226,   226,   226,   226,   224,   387,
     226,   226,   224,   417,   123,   223,   226,   226,   427,   224,
     431,   167,   232,   232,   105,   167,   167,   105,   123,   167,
     232,   167,   232,   105,   105,   105,   167,   167,   167,   232,
     105,   105,   232,   105,   105,   105,   105,   167,   167,   226,
     167,   226,   232,   232,   167,   167,   167,   167,   167,   168,
     167,   168,   167,   167,   232,   232,   123,   232,   167,   167,
     167,   223,   223,   226,   226,   348,   226,   226,   226,   226,
     226,   224,   342,   226,   407,   226,   224,   411,   223,   328,
     226,   226,   226,   224,   332,   167,   223,   225,   123,   123,
     223,   223,   226,   226,   299,   226,   226,   226,   295,   226,
     224,   287,   223,   226,   226,   226,   224,   357,   167,   167,
     123,   167,   167,   167,   232,   223,   123,   167,   105,   105,
     123,   123,   123,   123,   123,   123,   139,   140,   245,   246,
     139,   140,   247,   248,   123,   123,   105,   123,   123,   223,
     223,   226,   372,   226,   224,   368,   223,   226,   381,   224,
     378,   123,   223,   223,   223,   223,   223,   223,   223,   143,
     144,   145,   146,   147,   148,   149,   231,   232,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   105,
     105,   232,   226,   105,   105,   105,   105,   232,   232,   123,
     105,   105,   232,   105,   234,   234,   223,   123,   185,   186,
     123,   167,   226,   123,   123,   123,   123,   105,   123,   123,
     123,   223,   123,   123,   223,   223,   123,   123,   226,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,    51,   173,
     174,   175,   176,   177,   179,   180,   182,   183,   184,   187,
     189,   190,   192,   194,   196,   197,   200,   206,   486,   487,
     223,    51,   173,   174,   175,   176,   177,   179,   180,   182,
     183,   184,   187,   189,   190,   192,   194,   196,   197,   200,
     206,   482,   483,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   123,   167,   226,   123,   105,   123,   123,   123,
     223,   123,   226,   123,   223,   226,   123,   123,   105,   335,
     336,   223,   223,     1,    95,   158,   221,   276,   277,   278,
     279,   280,   223,   223,   123,   167,   226,   123,   123,   123,
     226,   123,   223,   123,   123,   123,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   227,   223,   227,   223,   223,
     223,   223,   223,   123,   226,   123,   223,   123,   226,   223,
     223,   231,   231,   231,   231,   231,   231,   231,   223,   223,
     223,    91,    92,   323,   324,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,     9,    10,    11,   233,   234,
     223,   223,   223,   223,   223,   223,   223,     8,   198,   397,
     398,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   128,   428,   429,   223,   227,   223,   227,
     223,   223,    13,    33,    43,    49,    66,    96,   104,   142,
     161,   207,   349,   350,   223,   223,   223,   223,   223,   223,
     128,   408,   409,   223,    51,   193,   198,   329,   330,   223,
     223,   171,   227,   334,   223,   226,   281,   226,   224,   277,
     223,   223,     4,    25,    40,    47,    65,    93,   100,   112,
     129,   130,   131,   181,   190,   195,   201,   205,   208,   213,
     219,   300,   301,   223,   223,   223,    51,   173,   174,   175,
     176,   177,   179,   180,   182,   183,   184,   187,   189,   190,
     192,   194,   196,   197,   200,   206,   296,   297,   223,   223,
     223,   223,   246,   248,   223,    65,   141,   172,   181,   187,
     201,   203,   204,   213,   219,   373,   374,   223,   223,    65,
     141,   172,   181,   187,   201,   203,   204,   213,   219,   382,
     383,   223,   227,   233,   233,   233,   223,   227,   223,   227,
     487,   483,   223,   227,   223,   227,   223,   227,   105,   336,
     223,   123,   226,   202,   234,   223,   223,   227,   223,   227,
     223,   227,   223,   227,   324,   398,   429,   350,   409,   330,
     223,    40,    63,    65,   108,   180,   181,   214,   282,   283,
     223,   223,   301,   297,   374,   383,   223,   227,   283
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 26:
/* Line 1787 of yacc.c  */
#line 393 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 395 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 399 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 403 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 407 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 411 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 415 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 419 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 423 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 428 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 429 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 430 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 431 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 432 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 446 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 478 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 484 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 493 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 499 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 507 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      conf_error_report("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.server_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_certificate_file(ServerInfo.client_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not open/read certificate file");
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ServerInfo.client_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ServerInfo.client_ctx))
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }
  }
#endif
}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 549 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 1)
  {
    BIO *file;

    if (ServerInfo.rsa_private_key)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;
    }

    if (ServerInfo.rsa_private_key_file)
    {
      MyFree(ServerInfo.rsa_private_key_file);
      ServerInfo.rsa_private_key_file = NULL;
    }

    ServerInfo.rsa_private_key_file = xstrdup(yylval.string);

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
    {
      conf_error_report("File open failed, ignoring");
      break;
    }

    ServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

    if (ServerInfo.rsa_private_key == NULL)
    {
      conf_error_report("Couldn't extract key, ignoring");
      break;
    }

    if (!RSA_check_key(ServerInfo.rsa_private_key))
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      conf_error_report("Invalid key, ignoring");
      break;
    }

    /* require 2048 bit (256 byte) key */
    if (RSA_size(ServerInfo.rsa_private_key) != 256)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      conf_error_report("Not a 2048 bit key, ignoring");
    }
  }
#endif
}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 608 "conf_parser.y"
    {
/* TBD - XXX: error reporting */
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
  {
    BIO *file = BIO_new_file(yylval.string, "r");

    if (file)
    {
      DH *dh = PEM_read_bio_DHparams(file, NULL, NULL, NULL);

      BIO_free(file);

      if (dh)
      {
        if (DH_size(dh) < 128)
          conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- need at least a 1024 bit DH prime size");
        else
          SSL_CTX_set_tmp_dh(ServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
  }
#endif
}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 636 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 644 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      ServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 659 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      ServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 674 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 683 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    ServerInfo.network_name = xstrdup(yylval.string);
  }
}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 697 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    ServerInfo.network_desc = xstrdup(yylval.string);
  }
}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 706 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 734 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 764 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    conf_error_report(buf);
    ServerInfo.max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[(3) - (4)].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ServerInfo.max_clients = MAXCLIENTS_MAX;
  }
  else
    ServerInfo.max_clients = (yyvsp[(3) - (4)].number);
}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 789 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].number) < 9)
  {
    conf_error_report("max_nick_length too low, setting to 9");
    ServerInfo.max_nick_length = 9;
  }
  else if ((yyvsp[(3) - (4)].number) > NICKLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);
    ServerInfo.max_nick_length = NICKLEN;
  }
  else
    ServerInfo.max_nick_length = (yyvsp[(3) - (4)].number);
}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 811 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].number) < 80)
  {
    conf_error_report("max_topic_length too low, setting to 80");
    ServerInfo.max_topic_length = 80;
  }
  else if ((yyvsp[(3) - (4)].number) > TOPICLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);
    ServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ServerInfo.max_topic_length = (yyvsp[(3) - (4)].number);
}
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 833 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 848 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    AdminInfo.name = xstrdup(yylval.string);
  }
}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 857 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    AdminInfo.email = xstrdup(yylval.string);
  }
}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 866 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    AdminInfo.description = xstrdup(yylval.string);
  }
}
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 884 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 890 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 894 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 918 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 921 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 933 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 937 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 941 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 945 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 949 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 953 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 957 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 967 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 974 "conf_parser.y"
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;
#ifdef HAVE_LIBCRYPTO
  if (!(block_state.file.buf[0] ||
        block_state.rpass.buf[0]))
    break;
#else
  if (!block_state.rpass.buf[0])
    break;
#endif

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf        = conf_make(CONF_OPER);
    conf->name  = xstrdup(block_state.name.buf);
    conf->user  = xstrdup(block_state.user.buf);
    conf->host  = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, &conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);

#ifdef HAVE_LIBCRYPTO
    if (block_state.file.buf[0])
    {
      BIO *file = NULL;
      RSA *pkey = NULL;

      if ((file = BIO_new_file(block_state.file.buf, "r")) == NULL)
      {
        conf_error_report("Ignoring rsa_public_key_file -- file doesn't exist");
        break;
      }

      if ((pkey = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL)) == NULL)
        conf_error_report("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");

      conf->rsa_public_key = pkey;
      BIO_set_close(file, BIO_CLOSE);
      BIO_free(file);
    }
#endif /* HAVE_LIBCRYPTO */
  }
}
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1049 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1055 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1061 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1067 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1078 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1084 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1090 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1097 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1101 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1105 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN_FULL;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1109 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1113 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1117 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1121 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1129 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1133 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1137 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1145 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1149 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1157 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1179 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1186 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1190 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1194 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1198 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1202 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1206 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1210 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1218 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1222 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1226 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1230 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1234 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_N;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPER_SPY;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1250 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1268 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_total.value = MAXIMUM_LINKS_DEFAULT;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1280 "conf_parser.y"
    {
  struct ClassItem *class = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  if (!(class = class_find(block_state.class.buf, 0)))
    class = class_make();

  class->active = 1;
  MyFree(class->name);
  class->name = xstrdup(block_state.class.buf);
  class->ping_freq = block_state.ping_freq.value;
  class->max_perip = block_state.max_perip.value;
  class->con_freq = block_state.con_freq.value;
  class->max_total = block_state.max_total.value;
  class->max_global = block_state.max_global.value;
  class->max_local = block_state.max_local.value;
  class->max_ident = block_state.max_ident.value;
  class->max_sendq = block_state.max_sendq.value;
  class->max_recvq = block_state.max_recvq.value;

  if (block_state.min_idle.value > block_state.max_idle.value)
  {
    block_state.min_idle.value = 0;
    block_state.max_idle.value = 0;
    block_state.flags.value &= ~CLASS_FLAGS_FAKE_IDLE;
  }

  class->flags = block_state.flags.value;
  class->min_idle = block_state.min_idle.value;
  class->max_idle = block_state.max_idle.value;

  if (class->number_per_cidr && block_state.number_per_cidr.value)
    if ((class->cidr_bitlen_ipv4 && block_state.cidr_bitlen_ipv4.value) ||
        (class->cidr_bitlen_ipv6 && block_state.cidr_bitlen_ipv6.value))
      if ((class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value) ||
          (class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value))
        rebuild_cidr_list(class);

  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;
}
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1346 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1352 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1358 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1364 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1370 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1376 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1382 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1388 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1394 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 1400 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1407 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1413 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1419 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1425 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1434 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 1443 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 1450 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1454 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1464 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1470 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1476 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1480 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1484 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 1492 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 1497 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (block_state.flags.value & LISTENER_SSL)
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        conf_error_report("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[(1) - (1)].number), block_state.addr.buf, block_state.flags.value);
  }
}
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 1511 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    int i;

    if (block_state.flags.value & LISTENER_SSL)
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        conf_error_report("SSL not available - port closed");
	break;
      }

    for (i = (yyvsp[(1) - (3)].number); i <= (yyvsp[(3) - (3)].number); ++i)
      add_listener(i, block_state.addr.buf, block_state.flags.value);
  }
}
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 1531 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1537 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 1546 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1550 "conf_parser.y"
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf        = conf_make(CONF_CLIENT);
    conf->user  = xstrdup(collapse(block_state.user.buf));
    conf->host  = xstrdup(collapse(block_state.host.buf));

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->passwd = xstrdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port  = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1593 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 1599 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1605 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1611 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1622 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 1629 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 1633 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 1637 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 1641 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 1645 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1649 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1653 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 1657 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 1661 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 1665 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 1671 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (strlen(yylval.string) <= HOSTLEN && valid_hostname(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1685 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1694 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1707 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1714 "conf_parser.y"
    {
  if (IsChanPrefix(block_state.name.buf[0]))
    create_channel_resv(block_state.name.buf, block_state.rpass.buf);
  else if (block_state.name.buf[0])
    create_nick_resv(block_state.name.buf, block_state.rpass.buf);
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1725 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1731 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1737 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1751 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (valid_servname(yylval.string))
    {
      struct MaskItem *conf = conf_make(CONF_SERVICE);
      conf->name = xstrdup(yylval.string);
    }
  }
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1766 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1777 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_ULINE);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
  conf->user = xstrdup(block_state.user.buf);
  conf->user = xstrdup(block_state.host.buf);
}
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 1794 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 1800 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 1819 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 1826 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 1830 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 1834 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 1838 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 1842 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 1846 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1850 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1854 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1858 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 1862 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 1871 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 1880 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 1895 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 1901 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 1908 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 1912 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 1916 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 1920 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 1924 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 1928 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 1932 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 1936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 1940 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 1944 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 1953 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 1961 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;
  struct addrinfo hints, *res;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!(block_state.rpass.buf[0] ||
        block_state.spass.buf[0]))
    break;

  if (has_wildcards(block_state.name.buf) ||
      has_wildcards(block_state.host.buf))
    break;

  conf = conf_make(CONF_SERVER);
  conf->port = block_state.port.value;
  conf->flags = block_state.flags.value;
  conf->aftype = block_state.aftype.value;
  conf->host = xstrdup(block_state.host.buf);
  conf->name = xstrdup(block_state.name.buf);
  conf->passwd = xstrdup(block_state.rpass.buf);
  conf->spasswd = xstrdup(block_state.spass.buf);
  conf->cipher_list = xstrdup(block_state.ciph.buf);

  dlinkMoveList(&block_state.leaf.list, &conf->leaf_list);
  dlinkMoveList(&block_state.hub.list, &conf->hub_list);

  if (block_state.bind.buf[0])
  {
    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(block_state.bind.buf, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", block_state.bind.buf);
    else
    {
      assert(res != NULL);

      memcpy(&conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind.ss.ss_family = res->ai_family;
      conf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  lookup_confhost(conf);
}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2027 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 2033 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2039 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 2045 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 2058 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 2071 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 2077 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 2081 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 2089 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 2095 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 2099 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 2105 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 2116 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 2122 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 2128 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2134 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2149 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 2153 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;


  if (block_state.port.value == 1)
  {
#ifdef HAVE_LIBPCRE
    void *exp_user = NULL;
    void *exp_host = NULL;
    const char *errptr = NULL;
 
    if (!(exp_user = ircd_pcre_compile(block_state.user.buf, &errptr)) ||
        !(exp_host = ircd_pcre_compile(block_state.host.buf, &errptr)))
    {
      ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: %s",
           errptr);
      break;
    }

    conf = conf_make(CONF_RKLINE);
    conf->regexuser = exp_user;
    conf->regexhost = exp_host;

    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
#else
    ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: no PCRE support");
    break;
#endif
  }
  else
  {
    conf = conf_make(CONF_KLINE);

    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_KLINE, conf);
  }
}
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2211 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 2218 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2227 "conf_parser.y"
    {

  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2247 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2256 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2260 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 2286 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 2292 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 2306 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = xstrdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 2323 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 2327 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  if (block_state.port.value == 1)
  {
#ifdef HAVE_LIBPCRE
    void *exp_p = NULL;
    const char *errptr = NULL;

    if (!(exp_p = ircd_pcre_compile(block_state.name.buf, &errptr)))
    {
      ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: %s",
           errptr);
      break;
    }

    conf = conf_make(CONF_RXLINE);
    conf->regexuser = exp_p;
#else
    conf_error_report("Failed to add regular expression based X-Line: no PCRE support");
    break;
#endif
  }
  else
    conf = conf_make(CONF_XLINE);

  conf->name = xstrdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
}
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 2368 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 2375 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 2384 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 2390 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2434 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2439 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2445 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2451 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2457 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2462 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2467 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2472 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2477 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2482 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2487 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2492 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2497 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2502 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2507 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2512 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2517 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2522 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2527 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2533 "conf_parser.y"
    {
  if (((yyvsp[(3) - (4)].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2544 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2549 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2554 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2559 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2564 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2569 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2572 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2577 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2580 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2585 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2595 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2600 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2605 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2615 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2620 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2625 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2630 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2635 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2640 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2649 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2658 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2663 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2673 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2679 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2682 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2688 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2691 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2694 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2697 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2703 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2706 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2712 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2730 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2733 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2741 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2747 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2750 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2753 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2756 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2759 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2762 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2768 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2771 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2774 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2777 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2780 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2783 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2786 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2789 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2792 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2795 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2798 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 2804 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 591:
/* Line 1787 of yacc.c  */
#line 2809 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 592:
/* Line 1787 of yacc.c  */
#line 2814 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 593:
/* Line 1787 of yacc.c  */
#line 2819 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 2842 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 2847 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 2857 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 2862 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 2867 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 2872 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 2877 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 2882 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 2887 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 2892 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 2897 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 2902 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 2907 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 637:
/* Line 1787 of yacc.c  */
#line 2926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 638:
/* Line 1787 of yacc.c  */
#line 2932 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 639:
/* Line 1787 of yacc.c  */
#line 2938 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 640:
/* Line 1787 of yacc.c  */
#line 2944 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 641:
/* Line 1787 of yacc.c  */
#line 2953 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (((yyvsp[(3) - (4)].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, (yyvsp[(3) - (4)].number));
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 642:
/* Line 1787 of yacc.c  */
#line 2967 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 643:
/* Line 1787 of yacc.c  */
#line 2973 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6782 "conf_parser.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


