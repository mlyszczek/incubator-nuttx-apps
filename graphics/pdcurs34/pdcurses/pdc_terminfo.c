/****************************************************************************
 * apps/graphics/pdcurs34/pdcurses/pdc_terminfo.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Adapted from the original public domain pdcurses by Gregory Nutt
 ****************************************************************************/

/* Name: terminfo
 *
 * Synopsis:
 *       int mvcur(int oldrow, int oldcol, int newrow, int newcol);
 *       int vidattr(chtype attr);
 *       int vid_attr(attr_t attr, short color_pair, void *opt);
 *       int vidputs(chtype attr, int (*putfunc)(int));
 *       int vid_puts(attr_t attr, short color_pair, void *opt,
 *               int (*putfunc)(int));
 *
 *       int del_curterm(TERMINAL *);
 *       int putp(const char *);
 *       int restartterm(const char *, int, int *);
 *       TERMINAL *set_curterm(TERMINAL *);
 *       int setterm(const char *term);
 *       int setupterm(const char *, int, int *);
 *       int tgetent(char *, const char *);
 *       int tgetflag(const char *);
 *       int tgetnum(const char *);
 *       char *tgetstr(const char *, char **);
 *       char *tgoto(const char *, int, int);
 *       int tigetflag(const char *);
 *       int tigetnum(const char *);
 *       char *tigetstr(const char *);
 *       char *tparm(const char *,long, long, long, long, long, long,
 *               long, long, long);
 *       int tputs(const char *, int, int (*)(int));
 *
 * Description:
 *       mvcur() lets you move the physical cursor without updating any
 *       window cursor positions. It returns OK or ERR.
 *
 *       The rest of these functions are currently implemented as stubs,
 *       returning the appropriate errors and doing nothing else.
 *
 * Portability                                X/Open    BSD    SYS V
 *       mvcur                                   Y       Y       Y
 */

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdlib.h>
#include "term.h"
#include "curspriv.h"

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifndef CONFIG_PDCURSES_MULTITHREAD
TERMINAL *cur_term = NULL;
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

#ifdef CONFIG_PDCURSES_MULTITHREAD
void *pdc_alloc_term_ctx(void)
{
  return zalloc(sizeof(TERMINAL));
}
#endif

int mvcur(int oldrow, int oldcol, int newrow, int newcol)
{
#ifdef CONFIG_PDCURSES_MULTITHREAD
  FAR struct pdc_context_s *ctx = PDC_ctx();
#endif
  PDC_LOG(("mvcur() - called: oldrow %d oldcol %d newrow %d newcol %d\n",
           oldrow, oldcol, newrow, newcol));

  if ((newrow >= LINES) || (newcol >= COLS) || (newrow < 0) || (newcol < 0))
    {
      return ERR;
    }

  PDC_gotoyx(newrow, newcol);
  SP->cursrow = newrow;
  SP->curscol = newcol;
  return OK;
}

int vidattr(chtype attr)
{
  PDC_LOG(("vidattr() - called: attr %d\n", attr));

  return ERR;
}

int vid_attr(attr_t attr, short color_pair, void *opt)
{
  PDC_LOG(("vid_attr() - called\n"));

  return ERR;
}

int vidputs(chtype attr, int (*putfunc) (int))
{
  PDC_LOG(("vidputs() - called: attr %d\n", attr));

  return ERR;
}

int vid_puts(attr_t attr, short color_pair, void *opt, int (*putfunc) (int))
{
  PDC_LOG(("vid_puts() - called\n"));

  return ERR;
}

int del_curterm(TERMINAL * oterm)
{
  PDC_LOG(("del_curterm() - called\n"));

  return ERR;
}

int putp(const char *str)
{
  PDC_LOG(("putp() - called: str %s\n", str));

  return ERR;
}

int restartterm(const char *term, int filedes, int *errret)
{
  PDC_LOG(("restartterm() - called\n"));

  if (errret)
    {
      *errret = -1;
    }

  return ERR;
}

TERMINAL *set_curterm(TERMINAL * nterm)
{
  PDC_LOG(("set_curterm() - called\n"));

  return NULL;
}

int setterm(const char *term)
{
  PDC_LOG(("setterm() - called\n"));

  return ERR;
}

int setupterm(const char *term, int filedes, int *errret)
{
  PDC_LOG(("setupterm() - called\n"));

  if (errret)
    {
      *errret = -1;
    }
  else
    {
      fprintf(stderr, "There is no terminfo database\n");
    }

  return ERR;
}

int tgetent(char *bp, const char *name)
{
  PDC_LOG(("tgetent() - called: name %s\n", name));

  return ERR;
}

int tgetflag(const char *id)
{
  PDC_LOG(("tgetflag() - called: id %s\n", id));

  return ERR;
}

int tgetnum(const char *id)
{
  PDC_LOG(("tgetnum() - called: id %s\n", id));

  return ERR;
}

char *tgetstr(const char *id, char **area)
{
  PDC_LOG(("tgetstr() - called: id %s\n", id));

  return NULL;
}

char *tgoto(const char *cap, int col, int row)
{
  PDC_LOG(("tgoto() - called\n"));

  return NULL;
}

int tigetflag(const char *capname)
{
  PDC_LOG(("tigetflag() - called: capname %s\n", capname));

  return -1;
}

int tigetnum(const char *capname)
{
  PDC_LOG(("tigetnum() - called: capname %s\n", capname));

  return -2;
}

char *tigetstr(const char *capname)
{
  PDC_LOG(("tigetstr() - called: capname %s\n", capname));

  return NULL;
}

char *tparm(const char *cap, long p1, long p2, long p3, long p4,
            long p5, long p6, long p7, long p8, long p9)
{
  PDC_LOG(("tparm() - called: cap %s\n", cap));

  return NULL;
}

int tputs(const char *str, int affcnt, int (*putfunc) (int))
{
  PDC_LOG(("tputs() - called\n"));

  return ERR;
}
