/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  log.h: A header for the logger functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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

#ifndef INCLUDED_s_log_h
#define INCLUDED_s_log_h

#define LOG_BUFSIZE 1024

enum log_type {
  LOG_TYPE_IRCD,
  LOG_TYPE_KILL,
  LOG_TYPE_KLINE,
  LOG_TYPE_DLINE,
  LOG_TYPE_GLINE,
  LOG_TYPE_OPER,
  LOG_TYPE_USER,
  LOG_TYPE_DEBUG,
  LOG_TYPE_LAST
};

extern void log_set_file(enum log_type, size_t, const char *);
extern void log_del_all(void);
extern void log_reopen_all(void);
extern void ilog(enum log_type, const char *, ...);

#endif /* INCLUDED_s_log_h */
