/* Definitions of target machine for GCC,
   for ARM with targetting the VXWorks run time environment. 
   Copyright (C) 1999, 2000, 2003 Free Software Foundation, Inc.

   Contributed by: Mike Stump <mrs@wrs.com>
   Brought up to date by CodeSourcery, LLC.
   
This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */


#define TARGET_OS_CPP_BUILTINS()		\
  do {						\
    builtin_define ("__vxworks");		\
    if (TARGET_BIG_END)				\
      builtin_define ("ARMEB");			\
    else					\
      builtin_define ("ARMEL");			\
						\
    if (arm_is_xscale)				\
      builtin_define ("CPU=XSCALE");		\
    else if (arm_arch5)				\
      builtin_define ("CPU=ARMARCH5");		\
    else if (arm_arch4)				\
      {						\
	if (thumb_code)				\
	  builtin_define ("CPU=ARMARCH4_T");	\
	else					\
	  builtin_define ("CPU=ARMARCH4");	\
      }						\
  } while (0)

#undef  CC1_SPEC
#define CC1_SPEC							\
"%{t4:        -mapcs-32 -mlittle-endian -march=armv4 ;			\
   t4be:      -mapcs-32 -mbig-endian -march=armv4 ;			\
   t4t:       -mthumb -mthumb-interwork -mlittle-endian -march=armv4t ;	\
   t4tbe:     -mthumb -mthumb-interwork -mbig-endian -march=armv4t ;	\
   t5:        -mapcs-32 -mlittle-endian -march=armv5 ;			\
   t5be:      -mapcs-32 -mbig-endian -march=armv5 ;			\
   t5t:       -mthumb -mthumb-interwork -mlittle-endian -march=armv5 ;	\
   t5tbe:     -mthumb -mthumb-interwork -mbig-endian -march=armv5 ;	\
   txscale:   -mapcs-32 -mlittle-endian -mcpu=xscale ;			\
   txscalebe: -mapcs-32 -mbig-endian -mcpu=xscale ;			\
            : -march=armv4}"

/* The -Q options from svr4.h aren't understood and must be removed.  */
#undef  ASM_SPEC
#define ASM_SPEC \
  "%{v:-V} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*}"

/* VxWorks does all the library stuff itself.  */
#undef  LIB_SPEC
#define LIB_SPEC 	""

/* VxWorks uses object files, not loadable images.  make linker just
   combine objects.  */
#undef  LINK_SPEC
#define LINK_SPEC 	"-r"

/* VxWorks provides the functionality of crt0.o and friends itself.  */
#undef  STARTFILE_SPEC
#define STARTFILE_SPEC 	""

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC 	""

#undef  TARGET_VERSION
#define TARGET_VERSION	fputs (" (ARM/VxWorks)", stderr);

/* There is no default multilib.  */
#undef MULTILIB_DEFAULTS

#undef  ASM_FILE_START
#define ASM_FILE_START(STREAM) 						\
  do 									\
    {									\
      fprintf (STREAM, "%s Generated by GCC %s for ARM/VxWorks\n",	\
	       ASM_COMMENT_START, version_string);			\
    }									\
  while (0)
