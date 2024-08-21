/* This testcase is part of GDB, the GNU debugger.

   Copyright 2014-2017 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <sys/types.h>
#include <unistd.h>

volatile int should_exit = 0;
int mypid;

static void
setup_done (void)
{
}

int
main (void)
{
  unsigned int counter = 1;

  mypid = getpid ();
  setup_done ();

  for (counter = 0; !should_exit && counter < 100; counter++)
    sleep (1);
  return 0;
}
