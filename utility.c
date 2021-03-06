/*
 * Part of Very Secure FTPd
 * Licence: GPL v2
 * Author: Chris Evans
 * utility.c
 */

#include "utility.h"
#include "sysutil.h"
#include "str.h"
#include "defs.h"

#pragma CHECKED_SCOPE on

#define DIE_DEBUG

void
die(const char *p_text : itype(_Nt_array_ptr<const char>))
{
#ifdef DIE_DEBUG
  bug(p_text);
#endif
  vsf_sysutil_exit(2);
}

void
die2(const char *p_text1 : itype(_Nt_array_ptr<const char>), const char *p_text2 : itype(_Nt_array_ptr<const char>))
{
  struct mystr die_str = INIT_MYSTR;
  str_alloc_text(&die_str, p_text1);
  if (p_text2)
  {
    str_append_text(&die_str, p_text2);
  }
  else
  {
    str_append_text(&die_str, "(null)");
  }
  die(((_Nt_array_ptr<const char> )str_getbuf(&die_str)));
}

void
bug(const char *p_text : itype(_Nt_array_ptr<const char>))
{
  /* Rats. Try and write the reason to the network for diagnostics */
  vsf_sysutil_activate_noblock(VSFTP_COMMAND_FD);
  (void) vsf_sysutil_write_loop<char>(VSFTP_COMMAND_FD, "500 OOPS: ", 10);

  unsigned int len = vsf_sysutil_strlen(p_text);
  _Nt_array_ptr<const char> p_text_len : count(len) = 0;
  _Unchecked { p_text_len = _Assume_bounds_cast<_Nt_array_ptr<const char>>(p_text, count(len)); }
  (void) vsf_sysutil_write_loop<const char>(VSFTP_COMMAND_FD, p_text_len,
                                len);
  (void) vsf_sysutil_write_loop<char>(VSFTP_COMMAND_FD, "\r\n", 2);
  vsf_sysutil_exit(2);
}


void
vsf_exit(const char *p_text : itype(_Nt_array_ptr<const char>))
{
  unsigned int len = vsf_sysutil_strlen(p_text);
  _Nt_array_ptr<const char> p_text_len : count(len) = 0;
  _Unchecked { p_text_len = _Assume_bounds_cast<_Nt_array_ptr<const char>>(p_text, count(len)); }
  (void) vsf_sysutil_write_loop<const char>(VSFTP_COMMAND_FD, p_text_len,
                                len);
  vsf_sysutil_exit(0);
}

