/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
     HIDE_SPOOF_IPS = 310,
     HOST = 311,
     HUB = 312,
     HUB_MASK = 313,
     IGNORE_BOGUS_TS = 314,
     INVISIBLE_ON_CONNECT = 315,
     IP = 316,
     KILL = 317,
     KILL_CHASE_TIME_LIMIT = 318,
     KLINE = 319,
     KLINE_EXEMPT = 320,
     KNOCK_DELAY = 321,
     KNOCK_DELAY_CHANNEL = 322,
     LEAF_MASK = 323,
     LINKS_DELAY = 324,
     LISTEN = 325,
     T_LOG = 326,
     MAX_ACCEPT = 327,
     MAX_BANS = 328,
     MAX_CHANS_PER_OPER = 329,
     MAX_CHANS_PER_USER = 330,
     MAX_GLOBAL = 331,
     MAX_IDENT = 332,
     MAX_LOCAL = 333,
     MAX_NICK_CHANGES = 334,
     MAX_NICK_LENGTH = 335,
     MAX_NICK_TIME = 336,
     MAX_NUMBER = 337,
     MAX_TARGETS = 338,
     MAX_TOPIC_LENGTH = 339,
     MAX_WATCH = 340,
     MESSAGE_LOCALE = 341,
     MIN_NONWILDCARD = 342,
     MIN_NONWILDCARD_SIMPLE = 343,
     MODULE = 344,
     MODULES = 345,
     NAME = 346,
     NEED_PASSWORD = 347,
     NETWORK_DESC = 348,
     NETWORK_NAME = 349,
     NICK = 350,
     NICK_CHANGES = 351,
     NO_CREATE_ON_SPLIT = 352,
     NO_JOIN_ON_SPLIT = 353,
     NO_OPER_FLOOD = 354,
     NO_TILDE = 355,
     NUMBER = 356,
     NUMBER_PER_CIDR = 357,
     NUMBER_PER_IP = 358,
     OPERATOR = 359,
     OPERS_BYPASS_CALLERID = 360,
     OPER_ONLY_UMODES = 361,
     OPER_PASS_RESV = 362,
     OPER_SPY_T = 363,
     OPER_UMODES = 364,
     JOIN_FLOOD_COUNT = 365,
     JOIN_FLOOD_TIME = 366,
     PACE_WAIT = 367,
     PACE_WAIT_SIMPLE = 368,
     PASSWORD = 369,
     PATH = 370,
     PING_COOKIE = 371,
     PING_TIME = 372,
     PING_WARNING = 373,
     PORT = 374,
     QSTRING = 375,
     QUIET_ON_BAN = 376,
     REASON = 377,
     REDIRPORT = 378,
     REDIRSERV = 379,
     REGEX_T = 380,
     REHASH = 381,
     REMOTE = 382,
     REMOTEBAN = 383,
     RESTRICT_CHANNELS = 384,
     RSA_PRIVATE_KEY_FILE = 385,
     RSA_PUBLIC_KEY_FILE = 386,
     SSL_CERTIFICATE_FILE = 387,
     SSL_DH_PARAM_FILE = 388,
     T_SSL_CLIENT_METHOD = 389,
     T_SSL_SERVER_METHOD = 390,
     T_SSLV3 = 391,
     T_TLSV1 = 392,
     RESV = 393,
     RESV_EXEMPT = 394,
     SECONDS = 395,
     MINUTES = 396,
     HOURS = 397,
     DAYS = 398,
     WEEKS = 399,
     SENDQ = 400,
     SEND_PASSWORD = 401,
     SERVERHIDE = 402,
     SERVERINFO = 403,
     IRCD_SID = 404,
     TKLINE_EXPIRE_NOTICES = 405,
     T_SHARED = 406,
     T_CLUSTER = 407,
     TYPE = 408,
     SHORT_MOTD = 409,
     SPOOF = 410,
     SPOOF_NOTICE = 411,
     STATS_E_DISABLED = 412,
     STATS_I_OPER_ONLY = 413,
     STATS_K_OPER_ONLY = 414,
     STATS_O_OPER_ONLY = 415,
     STATS_P_OPER_ONLY = 416,
     TBOOL = 417,
     TMASKED = 418,
     TS_MAX_DELTA = 419,
     TS_WARN_DELTA = 420,
     TWODOTS = 421,
     T_ALL = 422,
     T_BOTS = 423,
     T_SOFTCALLERID = 424,
     T_CALLERID = 425,
     T_CCONN = 426,
     T_CCONN_FULL = 427,
     T_SSL_CIPHER_LIST = 428,
     T_DEAF = 429,
     T_DEBUG = 430,
     T_DLINE = 431,
     T_EXTERNAL = 432,
     T_FULL = 433,
     T_INVISIBLE = 434,
     T_IPV4 = 435,
     T_IPV6 = 436,
     T_LOCOPS = 437,
     T_MAX_CLIENTS = 438,
     T_NCHANGE = 439,
     T_OPERWALL = 440,
     T_RECVQ = 441,
     T_REJ = 442,
     T_SERVER = 443,
     T_SERVNOTICE = 444,
     T_SET = 445,
     T_SKILL = 446,
     T_SPY = 447,
     T_SSL = 448,
     T_UMODES = 449,
     T_UNAUTH = 450,
     T_UNDLINE = 451,
     T_UNLIMITED = 452,
     T_UNRESV = 453,
     T_UNXLINE = 454,
     T_GLOBOPS = 455,
     T_WALLOP = 456,
     T_RESTART = 457,
     T_SERVICE = 458,
     T_SERVICES_NAME = 459,
     THROTTLE_TIME = 460,
     TRUE_NO_OPER_FLOOD = 461,
     UNKLINE = 462,
     USER = 463,
     USE_EGD = 464,
     USE_LOGGING = 465,
     VHOST = 466,
     VHOST6 = 467,
     XLINE = 468,
     WARN_NO_NLINE = 469,
     T_SIZE = 470,
     T_FILE = 471
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
#define HIDE_SPOOF_IPS 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define IP 316
#define KILL 317
#define KILL_CHASE_TIME_LIMIT 318
#define KLINE 319
#define KLINE_EXEMPT 320
#define KNOCK_DELAY 321
#define KNOCK_DELAY_CHANNEL 322
#define LEAF_MASK 323
#define LINKS_DELAY 324
#define LISTEN 325
#define T_LOG 326
#define MAX_ACCEPT 327
#define MAX_BANS 328
#define MAX_CHANS_PER_OPER 329
#define MAX_CHANS_PER_USER 330
#define MAX_GLOBAL 331
#define MAX_IDENT 332
#define MAX_LOCAL 333
#define MAX_NICK_CHANGES 334
#define MAX_NICK_LENGTH 335
#define MAX_NICK_TIME 336
#define MAX_NUMBER 337
#define MAX_TARGETS 338
#define MAX_TOPIC_LENGTH 339
#define MAX_WATCH 340
#define MESSAGE_LOCALE 341
#define MIN_NONWILDCARD 342
#define MIN_NONWILDCARD_SIMPLE 343
#define MODULE 344
#define MODULES 345
#define NAME 346
#define NEED_PASSWORD 347
#define NETWORK_DESC 348
#define NETWORK_NAME 349
#define NICK 350
#define NICK_CHANGES 351
#define NO_CREATE_ON_SPLIT 352
#define NO_JOIN_ON_SPLIT 353
#define NO_OPER_FLOOD 354
#define NO_TILDE 355
#define NUMBER 356
#define NUMBER_PER_CIDR 357
#define NUMBER_PER_IP 358
#define OPERATOR 359
#define OPERS_BYPASS_CALLERID 360
#define OPER_ONLY_UMODES 361
#define OPER_PASS_RESV 362
#define OPER_SPY_T 363
#define OPER_UMODES 364
#define JOIN_FLOOD_COUNT 365
#define JOIN_FLOOD_TIME 366
#define PACE_WAIT 367
#define PACE_WAIT_SIMPLE 368
#define PASSWORD 369
#define PATH 370
#define PING_COOKIE 371
#define PING_TIME 372
#define PING_WARNING 373
#define PORT 374
#define QSTRING 375
#define QUIET_ON_BAN 376
#define REASON 377
#define REDIRPORT 378
#define REDIRSERV 379
#define REGEX_T 380
#define REHASH 381
#define REMOTE 382
#define REMOTEBAN 383
#define RESTRICT_CHANNELS 384
#define RSA_PRIVATE_KEY_FILE 385
#define RSA_PUBLIC_KEY_FILE 386
#define SSL_CERTIFICATE_FILE 387
#define SSL_DH_PARAM_FILE 388
#define T_SSL_CLIENT_METHOD 389
#define T_SSL_SERVER_METHOD 390
#define T_SSLV3 391
#define T_TLSV1 392
#define RESV 393
#define RESV_EXEMPT 394
#define SECONDS 395
#define MINUTES 396
#define HOURS 397
#define DAYS 398
#define WEEKS 399
#define SENDQ 400
#define SEND_PASSWORD 401
#define SERVERHIDE 402
#define SERVERINFO 403
#define IRCD_SID 404
#define TKLINE_EXPIRE_NOTICES 405
#define T_SHARED 406
#define T_CLUSTER 407
#define TYPE 408
#define SHORT_MOTD 409
#define SPOOF 410
#define SPOOF_NOTICE 411
#define STATS_E_DISABLED 412
#define STATS_I_OPER_ONLY 413
#define STATS_K_OPER_ONLY 414
#define STATS_O_OPER_ONLY 415
#define STATS_P_OPER_ONLY 416
#define TBOOL 417
#define TMASKED 418
#define TS_MAX_DELTA 419
#define TS_WARN_DELTA 420
#define TWODOTS 421
#define T_ALL 422
#define T_BOTS 423
#define T_SOFTCALLERID 424
#define T_CALLERID 425
#define T_CCONN 426
#define T_CCONN_FULL 427
#define T_SSL_CIPHER_LIST 428
#define T_DEAF 429
#define T_DEBUG 430
#define T_DLINE 431
#define T_EXTERNAL 432
#define T_FULL 433
#define T_INVISIBLE 434
#define T_IPV4 435
#define T_IPV6 436
#define T_LOCOPS 437
#define T_MAX_CLIENTS 438
#define T_NCHANGE 439
#define T_OPERWALL 440
#define T_RECVQ 441
#define T_REJ 442
#define T_SERVER 443
#define T_SERVNOTICE 444
#define T_SET 445
#define T_SKILL 446
#define T_SPY 447
#define T_SSL 448
#define T_UMODES 449
#define T_UNAUTH 450
#define T_UNDLINE 451
#define T_UNLIMITED 452
#define T_UNRESV 453
#define T_UNXLINE 454
#define T_GLOBOPS 455
#define T_WALLOP 456
#define T_RESTART 457
#define T_SERVICE 458
#define T_SERVICES_NAME 459
#define THROTTLE_TIME 460
#define TRUE_NO_OPER_FLOOD 461
#define UNKLINE 462
#define USER 463
#define USE_EGD 464
#define USE_LOGGING 465
#define VHOST 466
#define VHOST6 467
#define XLINE 468
#define WARN_NO_NLINE 469
#define T_SIZE 470
#define T_FILE 471



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 111 "conf_parser.y"

  int number;
  char *string;


/* Line 2058 of yacc.c  */
#line 495 "conf_parser.h"
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
