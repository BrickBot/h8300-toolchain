// Copyright (C) 2004 Free Software Foundation
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// 22.2.2.2.1  num_put members

#include <locale>
#include <sstream>
#include <testsuite_hooks.h>

// libstdc++/15565
void test01()
{
  using namespace std;
  bool test __attribute__((unused)) = true;

  // basic construction
  locale loc_c = locale::classic();

  // sanity check the data is correct.
  const string empty;

  // cache the num_put facet
  ostringstream oss;
  oss.imbue(loc_c);
  const num_put<char>& np = use_facet<num_put<char> >(oss.getloc());

  unsigned long ul1 = 42UL;
  oss.str(empty);
  oss.clear();
  oss.setf(ios_base::showpos);
  np.put(oss.rdbuf(), oss, ' ', ul1);
  VERIFY( oss.str() == "42" );

#ifdef _GLIBCXX_USE_LONG_LONG
  unsigned long long ull1 = 31ULL;
  oss.str(empty);
  oss.clear();
  oss.setf(ios_base::showpos);
  np.put(oss.rdbuf(), oss, ' ', ull1);
  VERIFY( oss.str() == "31" );
#endif
}

int main()
{
  test01();
  return 0;
}
