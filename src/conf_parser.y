/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  conf_parser.y: Parses the ircd configuration file.
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

%{

#define YY_NO_UNPUT
#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "event.h"
#include "log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "irc_string.h"
#include "sprintf_irc.h"
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

int yylex(void);

static char *class_name = NULL;
static struct ConfItem *yy_conf = NULL;
static struct AccessItem *yy_aconf = NULL;
static struct MatchItem *yy_match_item = NULL;
static struct ClassItem *yy_class = NULL;
static char *yy_class_name = NULL;

static dlink_list col_conf_list  = { NULL, NULL, 0 };
static unsigned int listener_flags = 0;
static unsigned int regex_ban = 0;
static char userbuf[IRCD_BUFSIZE];
static char hostbuf[IRCD_BUFSIZE];
static char reasonbuf[REASONLEN + 1];
static char gecos_name[REALLEN * 4];
static char lfile[IRCD_BUFSIZE];
static unsigned int ltype = 0;
static unsigned int lsize = 0;
static char *resv_reason = NULL;
static char *listener_address = NULL;

struct CollectItem
{
  dlink_node node;
  char *name;
  char *user;
  char *host;
  char *passwd;
  int  port;
  int  flags;
#ifdef HAVE_LIBCRYPTO
  char *rsa_public_key_file;
  RSA *rsa_public_key;
#endif
};

static void
free_collect_item(struct CollectItem *item)
{
  MyFree(item->name);
  MyFree(item->user);
  MyFree(item->host);
  MyFree(item->passwd);
#ifdef HAVE_LIBCRYPTO
  MyFree(item->rsa_public_key_file);
#endif
  MyFree(item);
}

%}

%union {
  int number;
  char *string;
}

%token  ACCEPT_PASSWORD
%token  ADMIN
%token  AFTYPE
%token  ANTI_NICK_FLOOD
%token  ANTI_SPAM_EXIT_MESSAGE_TIME
%token  AUTOCONN
%token  BYTES KBYTES MBYTES
%token  CALLER_ID_WAIT
%token  CAN_FLOOD
%token  CHANNEL
%token	CIDR_BITLEN_IPV4
%token	CIDR_BITLEN_IPV6
%token  CLASS
%token  CONNECT
%token  CONNECTFREQ
%token  DEFAULT_FLOODCOUNT
%token  DEFAULT_SPLIT_SERVER_COUNT
%token  DEFAULT_SPLIT_USER_COUNT
%token  DENY
%token  DESCRIPTION
%token  DIE
%token  DISABLE_AUTH
%token  DISABLE_FAKE_CHANNELS
%token  DISABLE_REMOTE_COMMANDS
%token  DOTS_IN_IDENT
%token  EGDPOOL_PATH
%token  EMAIL
%token  ENCRYPTED
%token  EXCEED_LIMIT
%token  EXEMPT
%token  FAILED_OPER_NOTICE
%token  IRCD_FLAGS
%token  FLATTEN_LINKS
%token  GECOS
%token  GENERAL
%token  GLINE
%token  GLINE_DURATION
%token  GLINE_ENABLE
%token  GLINE_EXEMPT
%token  GLINE_REQUEST_DURATION
%token  GLINE_MIN_CIDR
%token  GLINE_MIN_CIDR6
%token  GLOBAL_KILL
%token  IRCD_AUTH
%token  NEED_IDENT
%token  HAVENT_READ_CONF
%token  HIDDEN
%token	HIDDEN_NAME
%token  HIDE_SERVER_IPS
%token  HIDE_SERVERS
%token	HIDE_SPOOF_IPS
%token  HOST
%token  HUB
%token  HUB_MASK
%token  IGNORE_BOGUS_TS
%token  INVISIBLE_ON_CONNECT
%token  IP
%token  KILL
%token	KILL_CHASE_TIME_LIMIT
%token  KLINE
%token  KLINE_EXEMPT
%token  KLINE_REASON
%token  KLINE_WITH_REASON
%token  KNOCK_DELAY
%token  KNOCK_DELAY_CHANNEL
%token  LEAF_MASK
%token  LINKS_DELAY
%token  LISTEN
%token  T_LOG
%token  MAX_ACCEPT
%token  MAX_BANS
%token  MAX_CHANS_PER_OPER
%token  MAX_CHANS_PER_USER
%token  MAX_GLOBAL
%token  MAX_IDENT
%token  MAX_LOCAL
%token  MAX_NICK_CHANGES
%token  MAX_NICK_TIME
%token  MAX_NUMBER
%token  MAX_TARGETS
%token  MAX_WATCH
%token  MESSAGE_LOCALE
%token  MIN_NONWILDCARD
%token  MIN_NONWILDCARD_SIMPLE
%token  MODULE
%token  MODULES
%token  NAME
%token  NEED_PASSWORD
%token  NETWORK_DESC
%token  NETWORK_NAME
%token  NICK
%token  NICK_CHANGES
%token  NO_CREATE_ON_SPLIT
%token  NO_JOIN_ON_SPLIT
%token  NO_OPER_FLOOD
%token  NO_TILDE
%token  NUMBER
%token  NUMBER_PER_CIDR
%token  NUMBER_PER_IP
%token  OPERATOR
%token  OPERS_BYPASS_CALLERID
%token  OPER_ONLY_UMODES
%token  OPER_PASS_RESV
%token  OPER_SPY_T
%token  OPER_UMODES
%token  JOIN_FLOOD_COUNT
%token  JOIN_FLOOD_TIME
%token  PACE_WAIT
%token  PACE_WAIT_SIMPLE
%token  PASSWORD
%token  PATH
%token  PING_COOKIE
%token  PING_TIME
%token  PING_WARNING
%token  PORT
%token  QSTRING
%token  QUIET_ON_BAN
%token  REASON
%token  REDIRPORT
%token  REDIRSERV
%token  REGEX_T
%token  REHASH
%token  TREJECT_HOLD_TIME
%token  REMOTE
%token  REMOTEBAN
%token  RESTRICT_CHANNELS
%token  RSA_PRIVATE_KEY_FILE
%token  RSA_PUBLIC_KEY_FILE
%token  SSL_CERTIFICATE_FILE
%token  SSL_DH_PARAM_FILE
%token  T_SSL_CLIENT_METHOD
%token  T_SSL_SERVER_METHOD
%token  T_SSLV3
%token  T_TLSV1
%token  RESV
%token  RESV_EXEMPT
%token  SECONDS MINUTES HOURS DAYS WEEKS
%token  SENDQ
%token  SEND_PASSWORD
%token  SERVERHIDE
%token  SERVERINFO
%token  IRCD_SID
%token	TKLINE_EXPIRE_NOTICES
%token  T_SHARED
%token  T_CLUSTER
%token  TYPE
%token  SHORT_MOTD
%token  SPOOF
%token  SPOOF_NOTICE
%token  STATS_E_DISABLED
%token  STATS_I_OPER_ONLY
%token  STATS_K_OPER_ONLY
%token  STATS_O_OPER_ONLY
%token  STATS_P_OPER_ONLY
%token  TBOOL
%token  TMASKED
%token  TS_MAX_DELTA
%token  TS_WARN_DELTA
%token  TWODOTS
%token  T_ALL
%token  T_BOTS
%token  T_SOFTCALLERID
%token  T_CALLERID
%token  T_CCONN
%token  T_CCONN_FULL
%token  T_SSL_CIPHER_LIST
%token  T_DEAF
%token  T_DEBUG
%token  T_DLINE
%token  T_EXTERNAL
%token  T_FULL
%token  T_INVISIBLE
%token  T_IPV4
%token  T_IPV6
%token  T_LOCOPS
%token  T_MAX_CLIENTS
%token  T_NCHANGE
%token  T_OPERWALL
%token  T_RECVQ
%token  T_REJ
%token  T_SERVER
%token  T_SERVNOTICE
%token  T_SET
%token  T_SKILL
%token  T_SPY
%token  T_SSL
%token  T_UMODES
%token  T_UNAUTH
%token  T_UNDLINE
%token  T_UNLIMITED
%token  T_UNRESV
%token  T_UNXLINE
%token  T_GLOBOPS
%token  T_WALLOP
%token  T_RESTART
%token  T_SERVICE
%token  T_SERVICES_NAME
%token  THROTTLE_TIME
%token  TRUE_NO_OPER_FLOOD
%token  UNKLINE
%token  USER
%token  USE_EGD
%token  USE_LOGGING
%token  USE_WHOIS_ACTUALLY
%token  VHOST
%token  VHOST6
%token  XLINE
%token  WARN_NO_NLINE
%token  T_SIZE
%token  T_FILE

%type <string> QSTRING
%type <number> NUMBER
%type <number> timespec
%type <number> timespec_
%type <number> sizespec
%type <number> sizespec_

%%
conf:   
        | conf conf_item
        ;

conf_item:        admin_entry
                | logging_entry
                | oper_entry
		| channel_entry
                | class_entry 
                | listen_entry
                | auth_entry
                | serverinfo_entry
		| serverhide_entry
                | resv_entry
                | service_entry
                | shared_entry
		| cluster_entry
                | connect_entry
                | kill_entry
                | deny_entry
		| exempt_entry
		| general_entry
                | gecos_entry
                | modules_entry
                | error ';'
                | error '}'
        ;


timespec_: { $$ = 0; } | timespec;
timespec:	NUMBER timespec_
		{
			$$ = $1 + $2;
		}
		| NUMBER SECONDS timespec_
		{
			$$ = $1 + $3;
		}
		| NUMBER MINUTES timespec_
		{
			$$ = $1 * 60 + $3;
		}
		| NUMBER HOURS timespec_
		{
			$$ = $1 * 60 * 60 + $3;
		}
		| NUMBER DAYS timespec_
		{
			$$ = $1 * 60 * 60 * 24 + $3;
		}
		| NUMBER WEEKS timespec_
		{
			$$ = $1 * 60 * 60 * 24 * 7 + $3;
		}
		;

sizespec_:	{ $$ = 0; } | sizespec;
sizespec:	NUMBER sizespec_ { $$ = $1 + $2; }
		| NUMBER BYTES sizespec_ { $$ = $1 + $3; }
		| NUMBER KBYTES sizespec_ { $$ = $1 * 1024 + $3; }
		| NUMBER MBYTES sizespec_ { $$ = $1 * 1024 * 1024 + $3; }
		;


/***************************************************************************
 *  section modules
 ***************************************************************************/
modules_entry: MODULES
  '{' modules_items '}' ';';

modules_items:  modules_items modules_item | modules_item;
modules_item:   modules_module | modules_path | error ';' ;

modules_module: MODULE '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
};

modules_path: PATH '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
};


serverinfo_entry: SERVERINFO '{' serverinfo_items '}' ';';

serverinfo_items:       serverinfo_items serverinfo_item | serverinfo_item ;
serverinfo_item:        serverinfo_name | serverinfo_vhost |
                        serverinfo_hub | serverinfo_description |
                        serverinfo_network_name | serverinfo_network_desc |
                        serverinfo_max_clients | serverinfo_ssl_dh_param_file |
                        serverinfo_rsa_private_key_file | serverinfo_vhost6 |
                        serverinfo_sid | serverinfo_ssl_certificate_file |
                        serverinfo_ssl_client_method | serverinfo_ssl_server_method |
                        serverinfo_ssl_cipher_list |
			error ';' ;


serverinfo_ssl_client_method: T_SSL_CLIENT_METHOD '=' client_method_types ';' ;
serverinfo_ssl_server_method: T_SSL_SERVER_METHOD '=' server_method_types ';' ;

client_method_types: client_method_types ',' client_method_type_item | client_method_type_item;
client_method_type_item: T_SSLV3
{
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
} | T_TLSV1
{
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
};

server_method_types: server_method_types ',' server_method_type_item | server_method_type_item;
server_method_type_item: T_SSLV3
{
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
} | T_TLSV1
{
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
};

serverinfo_ssl_certificate_file: SSL_CERTIFICATE_FILE '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      yyerror("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.server_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_certificate_file(ServerInfo.client_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ServerInfo.client_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ServerInfo.client_ctx))
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }
  }
#endif
};

serverinfo_rsa_private_key_file: RSA_PRIVATE_KEY_FILE '=' QSTRING ';'
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

    DupString(ServerInfo.rsa_private_key_file, yylval.string);

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
    {
      yyerror("File open failed, ignoring");
      break;
    }

    ServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

    if (ServerInfo.rsa_private_key == NULL)
    {
      yyerror("Couldn't extract key, ignoring");
      break;
    }

    if (!RSA_check_key(ServerInfo.rsa_private_key))
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Invalid key, ignoring");
      break;
    }

    /* require 2048 bit (256 byte) key */
    if (RSA_size(ServerInfo.rsa_private_key) != 256)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Not a 2048 bit key, ignoring");
    }
  }
#endif
};

serverinfo_ssl_dh_param_file: SSL_DH_PARAM_FILE '=' QSTRING ';'
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
          ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_dh_param_file -- need at least a 1024 bit DH prime size");
        else
          SSL_CTX_set_tmp_dh(ServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
  }
#endif
};

serverinfo_ssl_cipher_list: T_SSL_CIPHER_LIST '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
};

serverinfo_name: NAME '=' QSTRING ';' 
{
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      DupString(ServerInfo.name, yylval.string);
    else
    {
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
};

serverinfo_sid: IRCD_SID '=' QSTRING ';' 
{
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      DupString(ServerInfo.sid, yylval.string);
    else
    {
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
};

serverinfo_description: DESCRIPTION '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
};

serverinfo_network_name: NETWORK_NAME '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    DupString(ServerInfo.network_name, yylval.string);
  }
};

serverinfo_network_desc: NETWORK_DESC '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
};

serverinfo_vhost: VHOST '=' QSTRING ';'
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
};

serverinfo_vhost6: VHOST6 '=' QSTRING ';'
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
};

serverinfo_max_clients: T_MAX_CLIENTS '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    recalc_fdlimit(NULL);

    if ($3 < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
      yyerror(buf);
    }
    else if ($3 > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
      yyerror(buf);
    }
    else
      ServerInfo.max_clients = $3;
  }
};

serverinfo_hub: HUB '=' TBOOL ';' 
{
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
};

/***************************************************************************
 * admin section
 ***************************************************************************/
admin_entry: ADMIN  '{' admin_items '}' ';' ;

admin_items: admin_items admin_item | admin_item;
admin_item:  admin_name | admin_description |
             admin_email | error ';' ;

admin_name: NAME '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
};

admin_email: EMAIL '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
};

admin_description: DESCRIPTION '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
};

/***************************************************************************
 *  section logging
 ***************************************************************************/
logging_entry:          T_LOG  '{' logging_items '}' ';' ;
logging_items:          logging_items logging_item | logging_item ;

logging_item:   	logging_use_logging | logging_file_entry |
			error ';' ;

logging_use_logging: USE_LOGGING '=' TBOOL ';'
{
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
};

logging_file_entry:
{
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
} T_FILE  '{' logging_file_items '}' ';'
{
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
};

logging_file_items: logging_file_items logging_file_item |
                    logging_file_item ;

logging_file_item:  logging_file_name | logging_file_type |
                    logging_file_size | error ';' ;

logging_file_name: NAME '=' QSTRING ';'
{
  strlcpy(lfile, yylval.string, sizeof(lfile));
}

logging_file_size: T_SIZE '=' sizespec ';'
{
  lsize = $3;
} | T_SIZE '=' T_UNLIMITED ';'
{
  lsize = 0;
};

logging_file_type: TYPE
{
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
} '='  logging_file_type_items ';' ;

logging_file_type_items: logging_file_type_items ',' logging_file_type_item | logging_file_type_item;
logging_file_type_item:  USER
{
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
} | OPERATOR
{
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
} | GLINE
{
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
} | T_DLINE
{
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
} | KLINE
{
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
} | KILL
{
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
} | T_DEBUG
{
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
};


/***************************************************************************
 * section oper
 ***************************************************************************/
oper_entry: OPERATOR 
{
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(OPER_TYPE);
    yy_aconf = map_to_conf(yy_conf);
    SetConfEncrypted(yy_aconf); /* Yes, the default is encrypted */
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
} '{' oper_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp;
    dlink_node *ptr;
    dlink_node *next_ptr;

    conf_add_class_to_conf(yy_conf, class_name);

    /* Now, make sure there is a copy of the "base" given oper
     * block in each of the collected copies
     */

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;
      yy_tmp = ptr->data;

      new_conf = make_conf_item(OPER_TYPE);
      new_aconf = (struct AccessItem *)map_to_conf(new_conf);

      new_aconf->flags = yy_aconf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_tmp->user != NULL)
	DupString(new_aconf->user, yy_tmp->user);
      else
	DupString(new_aconf->user, "*");
      if (yy_tmp->host != NULL)
	DupString(new_aconf->host, yy_tmp->host);
      else
	DupString(new_aconf->host, "*");

      new_aconf->type = parse_netmask(new_aconf->host, &new_aconf->addr,
                                     &new_aconf->bits);

      conf_add_class_to_conf(new_conf, class_name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->port = yy_aconf->port;
#ifdef HAVE_LIBCRYPTO
      if (yy_aconf->rsa_public_key_file != NULL)
      {
        BIO *file;

        DupString(new_aconf->rsa_public_key_file,
		  yy_aconf->rsa_public_key_file);

        file = BIO_new_file(yy_aconf->rsa_public_key_file, "r");
        new_aconf->rsa_public_key = PEM_read_bio_RSA_PUBKEY(file, 
							   NULL, 0, NULL);
        BIO_set_close(file, BIO_CLOSE);
        BIO_free(file);
      }
#endif

#ifdef HAVE_LIBCRYPTO
      if (yy_tmp->name && (yy_tmp->passwd || yy_aconf->rsa_public_key)
	  && yy_tmp->host)
#else
      if (yy_tmp->name && yy_tmp->passwd && yy_tmp->host)
#endif
      {
        conf_add_class_to_conf(new_conf, class_name);
	if (yy_tmp->name != NULL)
	  DupString(new_conf->name, yy_tmp->name);
      }

      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    yy_conf = NULL;
    yy_aconf = NULL;


    MyFree(class_name);
    class_name = NULL;
  }
}; 

oper_items:     oper_items oper_item | oper_item;
oper_item:      oper_name | oper_user | oper_password |
                oper_umodes | oper_class | oper_encrypted |
		oper_rsa_public_key_file | oper_flags | error ';' ;

oper_name: NAME '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

oper_user: USER '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->user, userbuf);
      DupString(yy_aconf->host, hostbuf);

      yy_aconf->type = parse_netmask(yy_aconf->host, &yy_aconf->addr,
                                    &yy_aconf->bits);
    }
    else
    {
      struct CollectItem *yy_tmp = MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->user, userbuf);
      DupString(yy_tmp->host, hostbuf);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
};

oper_password: PASSWORD '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
};

oper_encrypted: ENCRYPTED '=' TBOOL ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
};

oper_rsa_public_key_file: RSA_PUBLIC_KEY_FILE '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    BIO *file;

    if (yy_aconf->rsa_public_key != NULL)
    {
      RSA_free(yy_aconf->rsa_public_key);
      yy_aconf->rsa_public_key = NULL;
    }

    if (yy_aconf->rsa_public_key_file != NULL)
    {
      MyFree(yy_aconf->rsa_public_key_file);
      yy_aconf->rsa_public_key_file = NULL;
    }

    DupString(yy_aconf->rsa_public_key_file, yylval.string);
    file = BIO_new_file(yylval.string, "r");

    if (file == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- file doesn't exist");
      break;
    }

    yy_aconf->rsa_public_key = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

    if (yy_aconf->rsa_public_key == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);
  }
#endif /* HAVE_LIBCRYPTO */
};

oper_class: CLASS '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
};

oper_umodes: T_UMODES
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
} '='  oper_umodes_items ';' ;

oper_umodes_items: oper_umodes_items ',' oper_umodes_item | oper_umodes_item;
oper_umodes_item:  T_BOTS
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
} | T_CCONN
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
} | T_CCONN_FULL
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
} | T_DEAF
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
} | T_DEBUG
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
} | T_FULL
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
} | HIDDEN
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
} | T_SKILL
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
} | T_NCHANGE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
} | T_REJ
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
} | T_UNAUTH
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
} | T_SPY
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
} | T_EXTERNAL
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
} | T_OPERWALL
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
} | T_SERVNOTICE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
} | T_INVISIBLE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
} | T_WALLOP
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
} | T_SOFTCALLERID
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
} | T_CALLERID
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
} | T_LOCOPS
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
};

oper_flags: IRCD_FLAGS
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
} '='  oper_flags_items ';';

oper_flags_items: oper_flags_items ',' oper_flags_item | oper_flags_item;
oper_flags_item: GLOBAL_KILL
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
} | REMOTE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
} | KLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
} | UNKLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
} | T_DLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
} | T_UNDLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
} | XLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
} | GLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
} | DIE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
} | T_RESTART
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
} | REHASH
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
} | ADMIN
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
} | NICK_CHANGES
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
} | T_OPERWALL
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
} | T_GLOBOPS
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
} | OPER_SPY_T
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
} | REMOTEBAN
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
} | T_SET
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
} | MODULE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
};


/***************************************************************************
 *  section class
 ***************************************************************************/
class_entry: CLASS
{
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
} '{' class_items '}' ';'
{
  if (conf_parser_ctx.pass == 1)
  {
    struct ConfItem *cconf = NULL;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
      delete_conf_item(yy_conf);
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, NULL, yy_class_name, NULL, NULL);

      if (cconf != NULL)		/* The class existed already */
      {
        int user_count = 0;

        rebuild_cidr_class(cconf, yy_class);

        class = map_to_conf(cconf);

        user_count = class->curr_user_count;
        memcpy(class, yy_class, sizeof(*class));
        class->curr_user_count = user_count;
        class->active = 1;

        delete_conf_item(yy_conf);

        MyFree(cconf->name);            /* Allows case change of class name */
        cconf->name = yy_class_name;
      }
      else	/* Brand new class */
      {
        MyFree(yy_conf->name);          /* just in case it was allocated */
        yy_conf->name = yy_class_name;
        yy_class->active = 1;
      }
    }

    yy_class_name = NULL;
  }
};

class_items:    class_items class_item | class_item;
class_item:     class_name |
		class_cidr_bitlen_ipv4 | class_cidr_bitlen_ipv6 |
                class_ping_time |
		class_ping_warning |
		class_number_per_cidr |
                class_number_per_ip |
                class_connectfreq |
                class_max_number |
		class_max_global |
		class_max_local |
		class_max_ident |
                class_sendq | class_recvq |
		error ';' ;

class_name: NAME '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
};

class_ping_time: PING_TIME '=' timespec ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = $3;
};

class_ping_warning: PING_WARNING '=' timespec ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = $3;
};

class_number_per_ip: NUMBER_PER_IP '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = $3;
};

class_connectfreq: CONNECTFREQ '=' timespec ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = $3;
};

class_max_number: MAX_NUMBER '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = $3;
};

class_max_global: MAX_GLOBAL '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = $3;
};

class_max_local: MAX_LOCAL '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = $3;
};

class_max_ident: MAX_IDENT '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = $3;
};

class_sendq: SENDQ '=' sizespec ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = $3;
};

class_recvq: T_RECVQ '=' sizespec ';'
{
  if (conf_parser_ctx.pass == 1)
    if ($3 >= CLIENT_FLOOD_MIN && $3 <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = $3;
};

class_cidr_bitlen_ipv4: CIDR_BITLEN_IPV4 '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = $3 > 32 ? 32 : $3;
};

class_cidr_bitlen_ipv6: CIDR_BITLEN_IPV6 '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = $3 > 128 ? 128 : $3;
};

class_number_per_cidr: NUMBER_PER_CIDR '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = $3;
};

/***************************************************************************
 *  section listen
 ***************************************************************************/
listen_entry: LISTEN
{
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
} '{' listen_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
};

listen_flags: IRCD_FLAGS
{
  listener_flags = 0;
} '='  listen_flags_items ';';

listen_flags_items: listen_flags_items ',' listen_flags_item | listen_flags_item;
listen_flags_item: T_SSL
{
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
} | HIDDEN
{
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
} | T_SERVER
{
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
};



listen_items:   listen_items listen_item | listen_item;
listen_item:    listen_port | listen_flags | listen_address | listen_host | error ';';

listen_port: PORT '=' port_items { listener_flags = 0; } ';';

port_items: port_items ',' port_item | port_item;

port_item: NUMBER
{
  if (conf_parser_ctx.pass == 2)
  {
    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }
    add_listener($1, listener_address, listener_flags);
  }
} | NUMBER TWODOTS NUMBER
{
  if (conf_parser_ctx.pass == 2)
  {
    int i;

    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }

    for (i = $1; i <= $3; ++i)
      add_listener(i, listener_address, listener_flags);
  }
};

listen_address: IP '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
};

listen_host: HOST '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
};

/***************************************************************************
 *  section auth
 ***************************************************************************/
auth_entry: IRCD_AUTH
{
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLIENT_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
} '{' auth_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr = NULL, *next_ptr = NULL;

    if (yy_aconf->user && yy_aconf->host)
    {
      conf_add_class_to_conf(yy_conf, class_name);
      add_conf_by_address(CONF_CLIENT, yy_aconf);
    }
    else
      delete_conf_item(yy_conf);

    /* copy over settings from first struct */
    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      new_conf = make_conf_item(CLIENT_TYPE);
      new_aconf = map_to_conf(new_conf);

      yy_tmp = ptr->data;

      assert(yy_tmp->user && yy_tmp->host);

      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);
      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->flags = yy_aconf->flags;
      new_aconf->port  = yy_aconf->port;

      DupString(new_aconf->user, yy_tmp->user);
      collapse(new_aconf->user);

      DupString(new_aconf->host, yy_tmp->host);
      collapse(new_aconf->host);

      conf_add_class_to_conf(new_conf, class_name);
      add_conf_by_address(CONF_CLIENT, new_aconf);
      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}; 

auth_items:     auth_items auth_item | auth_item;
auth_item:      auth_user | auth_passwd | auth_class | auth_flags |
                auth_spoof | auth_redir_serv | auth_redir_port |
                auth_encrypted | error ';' ;

auth_user: USER '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->user, userbuf);
      DupString(yy_aconf->host, hostbuf);
    }
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->user, userbuf);
      DupString(yy_tmp->host, hostbuf);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
};

auth_passwd: PASSWORD '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    /* be paranoid */
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
};

auth_class: CLASS '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
};

auth_encrypted: ENCRYPTED '=' TBOOL ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
};

auth_flags: IRCD_FLAGS
{
} '='  auth_flags_items ';';

auth_flags_items: auth_flags_items ',' auth_flags_item | auth_flags_item;
auth_flags_item: SPOOF_NOTICE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
} | EXCEED_LIMIT
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
} | KLINE_EXEMPT
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
} | NEED_IDENT
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
} | CAN_FLOOD
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
} | NO_TILDE
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
} | GLINE_EXEMPT
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
} | RESV_EXEMPT
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
} | NEED_PASSWORD
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
};

/* XXX - need check for illegal hostnames here */
auth_spoof: SPOOF '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) < HOSTLEN)
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(LOG_TYPE_IRCD, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
};

auth_redir_serv: REDIRSERV '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

auth_redir_port: REDIRPORT '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = $3;
  }
};


/***************************************************************************
 *  section resv
 ***************************************************************************/
resv_entry: RESV
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
} '{' resv_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
};

resv_items:	resv_items resv_item | resv_item;
resv_item:	resv_creason | resv_channel | resv_nick | error ';' ;

resv_creason: REASON '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
};

resv_channel: CHANNEL '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (IsChanPrefix(*yylval.string))
    {
      char def_reason[] = "No reason";

      create_channel_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
    }
  }
  /* ignore it for now.. but we really should make a warning if
   * its an erroneous name --fl_ */
};

resv_nick: NICK '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
};

/***************************************************************************
 *  section service
 ***************************************************************************/
service_entry: T_SERVICE '{' service_items '}' ';';

service_items:     service_items service_item | service_item;
service_item:      service_name | error;

service_name: NAME '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (valid_servname(yylval.string))
    {
      yy_conf = make_conf_item(SERVICE_TYPE);
      DupString(yy_conf->name, yylval.string);
    }
  }
};

/***************************************************************************
 *  section shared, for sharing remote klines etc.
 ***************************************************************************/
shared_entry: T_SHARED
{
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
} '{' shared_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
};

shared_items: shared_items shared_item | shared_item;
shared_item:  shared_name | shared_user | shared_type | error ';' ;

shared_name: NAME '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

shared_user: USER '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    DupString(yy_match_item->user, userbuf);
    DupString(yy_match_item->host, hostbuf);
  }
};

shared_type: TYPE
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
} '=' shared_types ';' ;

shared_types: shared_types ',' shared_type_item | shared_type_item;
shared_type_item: KLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
} | UNKLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
} | T_DLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
} | T_UNDLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
} | XLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
} | T_UNXLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
} | RESV
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
} | T_UNRESV
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
} | T_LOCOPS
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
} | T_ALL
{
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
};

/***************************************************************************
 *  section cluster
 ***************************************************************************/
cluster_entry: T_CLUSTER
{
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
} '{' cluster_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
};

cluster_items:	cluster_items cluster_item | cluster_item;
cluster_item:	cluster_name | cluster_type | error ';' ;

cluster_name: NAME '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
};

cluster_type: TYPE
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
} '=' cluster_types ';' ;

cluster_types:	cluster_types ',' cluster_type_item | cluster_type_item;
cluster_type_item: KLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
} | UNKLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
} | T_DLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
} | T_UNDLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
} | XLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
} | T_UNXLINE
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
} | RESV
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
} | T_UNRESV
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
} | T_LOCOPS
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
} | T_ALL
{
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
};

/***************************************************************************
 *  section connect
 ***************************************************************************/
connect_entry: CONNECT   
{
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = map_to_conf(yy_conf);

    /* defaults */
    yy_aconf->port = PORTNUM;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
} '{' connect_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_aconf->host && yy_aconf->passwd && yy_aconf->spasswd)
    {
      if (conf_add_server(yy_conf, class_name) == -1)
        delete_conf_item(yy_conf);
    }
    else
    {
      if (yy_conf->name != NULL)
      {
        if (yy_aconf->host == NULL)
          yyerror("Ignoring connect block -- missing host");
        else if (!yy_aconf->passwd || !yy_aconf->spasswd)
          yyerror("Ignoring connect block -- missing password");
      }

      /* XXX
       * This fixes a try_connections() core (caused by invalid class_ptr
       * pointers) reported by metalrock. That's an ugly fix, but there
       * is currently no better way. The entire config subsystem needs an
       * rewrite ASAP. make_conf_item() shouldn't really add things onto
       * a doubly linked list immediately without any sanity checks!  -Michael
       */
      delete_conf_item(yy_conf);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
    yy_aconf = NULL;
  }
};

connect_items:  connect_items connect_item | connect_item;
connect_item:   connect_name | connect_host | connect_vhost |
		connect_send_password | connect_accept_password |
		connect_aftype | connect_port | connect_ssl_cipher_list |
		connect_flags | connect_hub_mask | connect_leaf_mask |
		connect_class | connect_encrypted | 
                error ';' ;

connect_name: NAME '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
};

connect_host: HOST '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
};

connect_vhost: VHOST '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
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

      memcpy(&yy_aconf->bind, res->ai_addr, res->ai_addrlen);
      yy_aconf->bind.ss.ss_family = res->ai_family;
      yy_aconf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }
};
 
connect_send_password: SEND_PASSWORD '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if ($3[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr($3, ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->spasswd != NULL)
        memset(yy_aconf->spasswd, 0, strlen(yy_aconf->spasswd));

      MyFree(yy_aconf->spasswd);
      DupString(yy_aconf->spasswd, yylval.string);
    }
  }
};

connect_accept_password: ACCEPT_PASSWORD '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if ($3[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr($3, ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->passwd != NULL)
        memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

      MyFree(yy_aconf->passwd);
      DupString(yy_aconf->passwd, yylval.string);
    }
  }
};

connect_port: PORT '=' NUMBER ';'
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = $3;
};

connect_aftype: AFTYPE '=' T_IPV4 ';'
{
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
} | AFTYPE '=' T_IPV6 ';'
{
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
};

connect_flags: IRCD_FLAGS
{
} '='  connect_flags_items ';';

connect_flags_items: connect_flags_items ',' connect_flags_item | connect_flags_item;
connect_flags_item: AUTOCONN
{
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
} | T_SSL
{
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
};

connect_encrypted: ENCRYPTED '=' TBOOL ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ENCRYPTED;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ENCRYPTED;
  }
};

connect_hub_mask: HUB_MASK '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->hub_list);
  }
};

connect_leaf_mask: LEAF_MASK '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->leaf_list);
  }
};

connect_class: CLASS '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
};

connect_ssl_cipher_list: T_SSL_CIPHER_LIST '=' QSTRING ';'
{
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->cipher_list);
    DupString(yy_aconf->cipher_list, yylval.string);
  }
#else
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring connect::ciphers -- no OpenSSL support");
#endif
};


/***************************************************************************
 *  section kill
 ***************************************************************************/
kill_entry: KILL
{
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
} '{' kill_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (userbuf[0] && hostbuf[0])
    {
      if (regex_ban)
      {
#ifdef HAVE_LIBPCRE
        void *exp_user = NULL;
        void *exp_host = NULL;
        const char *errptr = NULL;

        if (!(exp_user = ircd_pcre_compile(userbuf, &errptr)) ||
            !(exp_host = ircd_pcre_compile(hostbuf, &errptr)))
        {
          ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: %s",
               errptr);
          break;
        }

        yy_aconf = map_to_conf(make_conf_item(RKLINE_TYPE));
        yy_aconf->regexuser = exp_user;
        yy_aconf->regexhost = exp_host;

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
#else
        ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: no PCRE support");
        break;
#endif
      }
      else
      {
        find_and_delete_temporary(userbuf, hostbuf, CONF_KLINE);

        yy_aconf = map_to_conf(make_conf_item(KLINE_TYPE));

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KLINE, yy_aconf);
      }
    }

    yy_aconf = NULL;
  }
}; 

kill_type: TYPE
{
} '='  kill_type_items ';';

kill_type_items: kill_type_items ',' kill_type_item | kill_type_item;
kill_type_item: REGEX_T
{
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
};

kill_items:     kill_items kill_item | kill_item;
kill_item:      kill_user | kill_reason | kill_type | error;

kill_user: USER '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);
  }
};

kill_reason: REASON '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
};

/***************************************************************************
 *  section deny
 ***************************************************************************/
deny_entry: DENY 
{
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
} '{' deny_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (hostbuf[0] && parse_netmask(hostbuf, NULL, NULL) != HM_HOST)
    {
      find_and_delete_temporary(NULL, hostbuf, CONF_DLINE);

      yy_aconf = map_to_conf(make_conf_item(DLINE_TYPE));
      DupString(yy_aconf->host, hostbuf);

      if (reasonbuf[0])
        DupString(yy_aconf->reason, reasonbuf);
      else
        DupString(yy_aconf->reason, "No reason");
      add_conf_by_address(CONF_DLINE, yy_aconf);
      yy_aconf = NULL;
    }
  }
}; 

deny_items:     deny_items deny_item | deny_item;
deny_item:      deny_ip | deny_reason | error;

deny_ip: IP '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
};

deny_reason: REASON '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
};

/***************************************************************************
 *  section exempt
 ***************************************************************************/
exempt_entry: EXEMPT '{' exempt_items '}' ';';

exempt_items:     exempt_items exempt_item | exempt_item;
exempt_item:      exempt_ip | error;

exempt_ip: IP '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      yy_aconf = map_to_conf(make_conf_item(EXEMPTDLINE_TYPE));
      DupString(yy_aconf->host, yylval.string);

      add_conf_by_address(CONF_EXEMPTDLINE, yy_aconf);
      yy_aconf = NULL;
    }
  }
};

/***************************************************************************
 *  section gecos
 ***************************************************************************/
gecos_entry: GECOS
{
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
} '{' gecos_items '}' ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (gecos_name[0])
    {
      if (regex_ban)
      {
#ifdef HAVE_LIBPCRE
        void *exp_p = NULL;
        const char *errptr = NULL;

        if (!(exp_p = ircd_pcre_compile(gecos_name, &errptr)))
        {
          ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: %s",
               errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
#else
        ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: no PCRE support");
        break;
#endif
      }
      else
        yy_conf = make_conf_item(XLINE_TYPE);

      yy_match_item = map_to_conf(yy_conf);
      DupString(yy_conf->name, gecos_name);

      if (reasonbuf[0])
        DupString(yy_match_item->reason, reasonbuf);
      else
        DupString(yy_match_item->reason, "No reason");
    }
  }
};

gecos_flags: TYPE
{
} '='  gecos_flags_items ';';

gecos_flags_items: gecos_flags_items ',' gecos_flags_item | gecos_flags_item;
gecos_flags_item: REGEX_T
{
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
};

gecos_items: gecos_items gecos_item | gecos_item;
gecos_item:  gecos_name | gecos_reason | gecos_flags | error;

gecos_name: NAME '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
};

gecos_reason: REASON '=' QSTRING ';' 
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
};

/***************************************************************************
 *  section general
 ***************************************************************************/
general_entry: GENERAL
  '{' general_items '}' ';';

general_items:      general_items general_item | general_item;
general_item:       general_hide_spoof_ips | general_ignore_bogus_ts |
		    general_failed_oper_notice | general_anti_nick_flood |
		    general_max_nick_time | general_max_nick_changes |
		    general_max_accept | general_anti_spam_exit_message_time |
                    general_ts_warn_delta | general_ts_max_delta |
                    general_kill_chase_time_limit | general_kline_with_reason |
                    general_kline_reason | general_invisible_on_connect |
                    general_warn_no_nline | general_dots_in_ident |
                    general_stats_o_oper_only | general_stats_k_oper_only |
                    general_pace_wait | general_stats_i_oper_only |
                    general_pace_wait_simple | general_stats_P_oper_only |
                    general_short_motd | general_no_oper_flood |
                    general_true_no_oper_flood | general_oper_pass_resv |
                    general_message_locale |
                    general_oper_only_umodes | general_max_targets |
                    general_use_egd | general_egdpool_path |
                    general_oper_umodes | general_caller_id_wait |
                    general_opers_bypass_callerid | general_default_floodcount |
                    general_min_nonwildcard | general_min_nonwildcard_simple |
                    general_disable_remote_commands |
                    general_throttle_time | general_havent_read_conf |
                    general_ping_cookie |
                    general_disable_auth | 
		    general_tkline_expire_notices | general_gline_enable |
                    general_gline_duration | general_gline_request_duration |
                    general_gline_min_cidr |
                    general_gline_min_cidr6 | general_use_whois_actually |
		    general_reject_hold_time | general_stats_e_disabled |
		    general_max_watch | general_services_name |
		    error;


general_max_watch: MAX_WATCH '=' NUMBER ';'
{
  ConfigFileEntry.max_watch = $3;
};

general_gline_enable: GLINE_ENABLE '=' TBOOL ';'
{
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
};

general_gline_duration: GLINE_DURATION '=' timespec ';'
{
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = $3;
};

general_gline_request_duration: GLINE_REQUEST_DURATION '=' timespec ';'
{
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = $3;
};

general_gline_min_cidr: GLINE_MIN_CIDR '=' NUMBER ';'
{
  ConfigFileEntry.gline_min_cidr = $3;
};

general_gline_min_cidr6: GLINE_MIN_CIDR6 '=' NUMBER ';'
{
  ConfigFileEntry.gline_min_cidr6 = $3;
};

general_use_whois_actually: USE_WHOIS_ACTUALLY '=' TBOOL ';'
{
  ConfigFileEntry.use_whois_actually = yylval.number;
};

general_reject_hold_time: TREJECT_HOLD_TIME '=' timespec ';'
{
  GlobalSetOptions.rejecttime = yylval.number;
};

general_tkline_expire_notices: TKLINE_EXPIRE_NOTICES '=' TBOOL ';'
{
  ConfigFileEntry.tkline_expire_notices = yylval.number;
};

general_kill_chase_time_limit: KILL_CHASE_TIME_LIMIT '=' timespec ';'
{
  ConfigFileEntry.kill_chase_time_limit = $3;
};

general_hide_spoof_ips: HIDE_SPOOF_IPS '=' TBOOL ';'
{
  ConfigFileEntry.hide_spoof_ips = yylval.number;
};

general_ignore_bogus_ts: IGNORE_BOGUS_TS '=' TBOOL ';'
{
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
};

general_disable_remote_commands: DISABLE_REMOTE_COMMANDS '=' TBOOL ';'
{
  ConfigFileEntry.disable_remote = yylval.number;
};

general_failed_oper_notice: FAILED_OPER_NOTICE '=' TBOOL ';'
{
  ConfigFileEntry.failed_oper_notice = yylval.number;
};

general_anti_nick_flood: ANTI_NICK_FLOOD '=' TBOOL ';'
{
  ConfigFileEntry.anti_nick_flood = yylval.number;
};

general_max_nick_time: MAX_NICK_TIME '=' timespec ';'
{
  ConfigFileEntry.max_nick_time = $3; 
};

general_max_nick_changes: MAX_NICK_CHANGES '=' NUMBER ';'
{
  ConfigFileEntry.max_nick_changes = $3;
};

general_max_accept: MAX_ACCEPT '=' NUMBER ';'
{
  ConfigFileEntry.max_accept = $3;
};

general_anti_spam_exit_message_time: ANTI_SPAM_EXIT_MESSAGE_TIME '=' timespec ';'
{
  ConfigFileEntry.anti_spam_exit_message_time = $3;
};

general_ts_warn_delta: TS_WARN_DELTA '=' timespec ';'
{
  ConfigFileEntry.ts_warn_delta = $3;
};

general_ts_max_delta: TS_MAX_DELTA '=' timespec ';'
{
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = $3;
};

general_havent_read_conf: HAVENT_READ_CONF '=' NUMBER ';'
{
  if (($3 > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
};

general_kline_with_reason: KLINE_WITH_REASON '=' TBOOL ';'
{
  ConfigFileEntry.kline_with_reason = yylval.number;
};

general_kline_reason: KLINE_REASON '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
};

general_invisible_on_connect: INVISIBLE_ON_CONNECT '=' TBOOL ';'
{
  ConfigFileEntry.invisible_on_connect = yylval.number;
};

general_warn_no_nline: WARN_NO_NLINE '=' TBOOL ';'
{
  ConfigFileEntry.warn_no_nline = yylval.number;
};

general_stats_e_disabled: STATS_E_DISABLED '=' TBOOL ';'
{
  ConfigFileEntry.stats_e_disabled = yylval.number;
};

general_stats_o_oper_only: STATS_O_OPER_ONLY '=' TBOOL ';'
{
  ConfigFileEntry.stats_o_oper_only = yylval.number;
};

general_stats_P_oper_only: STATS_P_OPER_ONLY '=' TBOOL ';'
{
  ConfigFileEntry.stats_P_oper_only = yylval.number;
};

general_stats_k_oper_only: STATS_K_OPER_ONLY '=' TBOOL ';'
{
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
} | STATS_K_OPER_ONLY '=' TMASKED ';'
{
  ConfigFileEntry.stats_k_oper_only = 1;
};

general_stats_i_oper_only: STATS_I_OPER_ONLY '=' TBOOL ';'
{
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
} | STATS_I_OPER_ONLY '=' TMASKED ';'
{
  ConfigFileEntry.stats_i_oper_only = 1;
};

general_pace_wait: PACE_WAIT '=' timespec ';'
{
  ConfigFileEntry.pace_wait = $3;
};

general_caller_id_wait: CALLER_ID_WAIT '=' timespec ';'
{
  ConfigFileEntry.caller_id_wait = $3;
};

general_opers_bypass_callerid: OPERS_BYPASS_CALLERID '=' TBOOL ';'
{
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
};

general_pace_wait_simple: PACE_WAIT_SIMPLE '=' timespec ';'
{
  ConfigFileEntry.pace_wait_simple = $3;
};

general_short_motd: SHORT_MOTD '=' TBOOL ';'
{
  ConfigFileEntry.short_motd = yylval.number;
};
  
general_no_oper_flood: NO_OPER_FLOOD '=' TBOOL ';'
{
  ConfigFileEntry.no_oper_flood = yylval.number;
};

general_true_no_oper_flood: TRUE_NO_OPER_FLOOD '=' TBOOL ';'
{
  ConfigFileEntry.true_no_oper_flood = yylval.number;
};

general_oper_pass_resv: OPER_PASS_RESV '=' TBOOL ';'
{
  ConfigFileEntry.oper_pass_resv = yylval.number;
};

general_message_locale: MESSAGE_LOCALE '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
};

general_dots_in_ident: DOTS_IN_IDENT '=' NUMBER ';'
{
  ConfigFileEntry.dots_in_ident = $3;
};

general_max_targets: MAX_TARGETS '=' NUMBER ';'
{
  ConfigFileEntry.max_targets = $3;
};

general_use_egd: USE_EGD '=' TBOOL ';'
{
  ConfigFileEntry.use_egd = yylval.number;
};

general_egdpool_path: EGDPOOL_PATH '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
};

general_services_name: T_SERVICES_NAME '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
};

general_ping_cookie: PING_COOKIE '=' TBOOL ';'
{
  ConfigFileEntry.ping_cookie = yylval.number;
};

general_disable_auth: DISABLE_AUTH '=' TBOOL ';'
{
  ConfigFileEntry.disable_auth = yylval.number;
};

general_throttle_time: THROTTLE_TIME '=' timespec ';'
{
  ConfigFileEntry.throttle_time = yylval.number;
};

general_oper_umodes: OPER_UMODES
{
  ConfigFileEntry.oper_umodes = 0;
} '='  umode_oitems ';' ;

umode_oitems:    umode_oitems ',' umode_oitem | umode_oitem;
umode_oitem:     T_BOTS
{
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
} | T_CCONN
{
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
} | T_CCONN_FULL
{
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
} | T_DEAF
{
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
} | T_DEBUG
{
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
} | T_FULL
{
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
} | HIDDEN
{
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
} | T_SKILL
{
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
} | T_NCHANGE
{
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
} | T_REJ
{
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
} | T_UNAUTH
{
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
} | T_SPY
{
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
} | T_EXTERNAL
{
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
} | T_OPERWALL
{
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
} | T_SERVNOTICE
{
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
} | T_INVISIBLE
{
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
} | T_WALLOP
{
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
} | T_SOFTCALLERID
{
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
} | T_CALLERID
{
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
} | T_LOCOPS
{
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
};

general_oper_only_umodes: OPER_ONLY_UMODES 
{
  ConfigFileEntry.oper_only_umodes = 0;
} '='  umode_items ';' ;

umode_items:	umode_items ',' umode_item | umode_item;
umode_item:	T_BOTS 
{
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
} | T_CCONN
{
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
} | T_CCONN_FULL
{
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
} | T_DEAF
{
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
} | T_DEBUG
{
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
} | T_FULL
{ 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
} | T_SKILL
{
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
} | HIDDEN
{
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
} | T_NCHANGE
{
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
} | T_REJ
{
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
} | T_UNAUTH
{
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
} | T_SPY
{
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
} | T_EXTERNAL
{
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
} | T_OPERWALL
{
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
} | T_SERVNOTICE
{
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
} | T_INVISIBLE
{
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
} | T_WALLOP
{
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
} | T_SOFTCALLERID
{
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
} | T_CALLERID
{
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
} | T_LOCOPS
{
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
};

general_min_nonwildcard: MIN_NONWILDCARD '=' NUMBER ';'
{
  ConfigFileEntry.min_nonwildcard = $3;
};

general_min_nonwildcard_simple: MIN_NONWILDCARD_SIMPLE '=' NUMBER ';'
{
  ConfigFileEntry.min_nonwildcard_simple = $3;
};

general_default_floodcount: DEFAULT_FLOODCOUNT '=' NUMBER ';'
{
  ConfigFileEntry.default_floodcount = $3;
};


/***************************************************************************
 *  section channel
 ***************************************************************************/
channel_entry: CHANNEL
  '{' channel_items '}' ';';

channel_items:      channel_items channel_item | channel_item;
channel_item:       channel_max_bans |
                    channel_knock_delay | channel_knock_delay_channel |
                    channel_max_chans_per_user | channel_max_chans_per_oper |
                    channel_quiet_on_ban | channel_default_split_user_count |
                    channel_default_split_server_count |
                    channel_no_create_on_split | channel_restrict_channels |
                    channel_no_join_on_split |
                    channel_jflood_count | channel_jflood_time |
                    channel_disable_fake_channels | error;

channel_disable_fake_channels: DISABLE_FAKE_CHANNELS '=' TBOOL ';'
{
  ConfigChannel.disable_fake_channels = yylval.number;
};

channel_restrict_channels: RESTRICT_CHANNELS '=' TBOOL ';'
{
  ConfigChannel.restrict_channels = yylval.number;
};

channel_knock_delay: KNOCK_DELAY '=' timespec ';'
{
  ConfigChannel.knock_delay = $3;
};

channel_knock_delay_channel: KNOCK_DELAY_CHANNEL '=' timespec ';'
{
  ConfigChannel.knock_delay_channel = $3;
};

channel_max_chans_per_user: MAX_CHANS_PER_USER '=' NUMBER ';'
{
  ConfigChannel.max_chans_per_user = $3;
};

channel_max_chans_per_oper: MAX_CHANS_PER_OPER '=' NUMBER ';'
{
  ConfigChannel.max_chans_per_oper = $3;
};

channel_quiet_on_ban: QUIET_ON_BAN '=' TBOOL ';'
{
  ConfigChannel.quiet_on_ban = yylval.number;
};

channel_max_bans: MAX_BANS '=' NUMBER ';'
{
  ConfigChannel.max_bans = $3;
};

channel_default_split_user_count: DEFAULT_SPLIT_USER_COUNT '=' NUMBER ';'
{
  ConfigChannel.default_split_user_count = $3;
};

channel_default_split_server_count: DEFAULT_SPLIT_SERVER_COUNT '=' NUMBER ';'
{
  ConfigChannel.default_split_server_count = $3;
};

channel_no_create_on_split: NO_CREATE_ON_SPLIT '=' TBOOL ';'
{
  ConfigChannel.no_create_on_split = yylval.number;
};

channel_no_join_on_split: NO_JOIN_ON_SPLIT '=' TBOOL ';'
{
  ConfigChannel.no_join_on_split = yylval.number;
};

channel_jflood_count: JOIN_FLOOD_COUNT '=' NUMBER ';'
{
  GlobalSetOptions.joinfloodcount = yylval.number;
};

channel_jflood_time: JOIN_FLOOD_TIME '=' timespec ';'
{
  GlobalSetOptions.joinfloodtime = yylval.number;
};

/***************************************************************************
 *  section serverhide
 ***************************************************************************/
serverhide_entry: SERVERHIDE
  '{' serverhide_items '}' ';';

serverhide_items:   serverhide_items serverhide_item | serverhide_item;
serverhide_item:    serverhide_flatten_links | serverhide_hide_servers |
		    serverhide_links_delay |
		    serverhide_hidden | serverhide_hidden_name |
		    serverhide_hide_server_ips |
                    error;

serverhide_flatten_links: FLATTEN_LINKS '=' TBOOL ';'
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
};

serverhide_hide_servers: HIDE_SERVERS '=' TBOOL ';'
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
};

serverhide_hidden_name: HIDDEN_NAME '=' QSTRING ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
};

serverhide_links_delay: LINKS_DELAY '=' timespec ';'
{
  if (conf_parser_ctx.pass == 2)
  {
    if (($3 > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, $3);
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = $3;
  }
};

serverhide_hidden: HIDDEN '=' TBOOL ';'
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
};

serverhide_hide_server_ips: HIDE_SERVER_IPS '=' TBOOL ';'
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
};
