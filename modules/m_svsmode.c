/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *
 *  Copyright (C) 1999 by the Bahamut Development Team.
 *  Copyright (C) 2011 by the Hybrid Development Team.
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
 */

/*! \file m_svsmode.c
 * \brief Includes required functions for processing the SVSMODE command.
 * \version $Id$
 */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "channel_mode.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "irc_string.h"
#include "s_user.h"

static void ms_svsmode(struct Client *, struct Client *, int, char *[]);

struct Message svsmode_msgtab = {
  "SVSMODE", 0, 0, 3, MAXPARA, MFLG_SLOW | MFLG_UNREG, 0,
  {m_ignore, m_ignore, ms_svsmode, m_ignore, m_ignore, m_ignore}
};

const char *_version = "$Revision$";

void
_modinit(void)
{
  mod_add_cmd(&svsmode_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&svsmode_msgtab);
}


/*! \brief SVSMODE command handler (called by services)
 *
 * \param client_p Pointer to allocated Client struct with physical connection
 *                 to this server, i.e. with an open socket connected.
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = sender prefix
 *      - parv[1] = nickname
 *      - parv[2] = TS (or mode, depending on svs version)
 *      - parv[3] = mode (or services id if old svs version)
 *      - parv[4] = optional arguement (services id)
 */
static void
ms_svsmode(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;
  int what = MODE_ADD;
  unsigned int flag = 0, setflags = 0;
  char *m = NULL, *modes = NULL, *extarg = NULL;
  time_t ts = 0;

  if (!HasFlag(source_p, FLAGS_SERVICE))
    return;

  if ((parc >= 4) && ((*parv[3] == '+') || (*parv[3] == '-')))
  {
    ts     = atol(parv[2]);
    modes  = parv[3];
    extarg = (parc > 4) ? parv[4] : NULL;
  }
  else
  {
    modes  = parv[2];
    extarg = (parc > 3) ? parv[3] : NULL;
  }

  if ((target_p = find_person(client_p, parv[1])) == NULL)
    return;

  if (ts && (ts != target_p->tsinfo))
    return;

  setflags = target_p->umodes;

  for (m = modes; *m; ++m)
  {
    switch (*m)
    {
      case '+':
        what = MODE_ADD;
        break;
      case '-':
        what = MODE_DEL;
        break;

      case 'd':
        if (extarg && IsDigit(*extarg))
          target_p->servicestamp = strtoul(extarg, NULL, 0);
        break;

      case 'o':
        if (what == MODE_DEL && HasUMode(target_p, UMODE_OPER))
        {
          ClearOper(target_p);
          Count.oper--;

          if (MyConnect(target_p))
          {
            dlink_node *dm = NULL;

            detach_conf(target_p, OPER_TYPE);
            ClrOFlag(target_p);
            DelUMode(target_p, ConfigFileEntry.oper_only_umodes);
 
           if ((dm = dlinkFindDelete(&oper_list, target_p)) != NULL)
             free_dlink_node(dm);
          }
        }

        break;

      case 'i':
        if (what == MODE_ADD && !HasUMode(target_p, UMODE_INVISIBLE))
        {
          AddUMode(target_p, UMODE_INVISIBLE);
          ++Count.invisi;
        }

        if (what == MODE_DEL && HasUMode(target_p, UMODE_INVISIBLE))
        {
          DelUMode(target_p, UMODE_INVISIBLE);
          --Count.invisi;
        }

        break;

      case ' ':
      case '\n':
      case '\r':
      case '\t':
        break;
      default:
        if ((flag = user_modes[(unsigned char)*m]))
          execute_callback(umode_cb, client_p, target_p, what, flag);
        break;
    }
  }

  if (extarg)
  {
    sendto_server(client_p, NULL, CAP_TS6, NOCAPS,
                  ":%s SVSMODE %s %lu %s %s", ID(source_p),
                  ID(target_p), (unsigned long)target_p->tsinfo, modes, extarg);
    sendto_server(client_p, NULL, NOCAPS, CAP_TS6,
                  ":%s SVSMODE %s %lu %s %s", source_p->name,
                  target_p->name, (unsigned long)target_p->tsinfo, modes, extarg);
  }
  else
  {
    sendto_server(client_p, NULL, CAP_TS6, NOCAPS,
                  ":%s SVSMODE %s %lu %s", ID(source_p),
                  ID(target_p), (unsigned long)target_p->tsinfo, modes);
    sendto_server(client_p, NULL, NOCAPS, CAP_TS6,
                  ":%s SVSMODE %s %lu %s", source_p->name,
                  target_p->name, (unsigned long)target_p->tsinfo, modes);
  }

  if (MyConnect(target_p) && (setflags != target_p->umodes))
  {
    char modebuf[IRCD_BUFSIZE];

    send_umode(target_p, target_p, setflags, 0xffffffff, modebuf);
  }
}
