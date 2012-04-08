// Copyright (C) 2008 by Vinnie Falco, this file is part of VFLib.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file BOOST_LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// This file incorporates work covered by the following copyright
// and permission notice:
//
//   Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton,
//   Mateusz Loskot, Pawel Aleksander Fedorynski, David Courtney,
//   Rafal Bobrowski, Julian Taylor, Henning Basold, Ilia Barahovski,
//   Denis Arnaud, Daniel Lidstr�m, Matthieu Kermagoret, Artyom Beilis,
//   Cory Bennett, Chris Weed, Michael Davidsaver, Jakub Stachowski,
//   Alex Ott, Rainer Bauer, Martin Muenstermann, Philip Pemberton,
//   Eli Green, Frederic Chateau, Artyom Tonkikh, Roger Orr,
//   Robert Massaioli, Sergey Nikulov, Shridhar Daithankar,
//   S�ren Meyer-Eppler, Mario Valesco
//
//   Distributed under the Boost Software License, Version 1.0.
//   (See accompanying file BOOST_LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt)
//

namespace db {

namespace detail {

once_type::once_type (const once_type& other)
  : m_session (other.m_session)
  , m_error (other.m_error)
{
}

once_temp_type::once_temp_type(session& s, Error& error)
  : m_rcst (new ref_counted_statement(s, error))
{
  // new query
  s.get_query_stream().str("");
}

once_temp_type::once_temp_type(once_temp_type const& o)
  : m_rcst (o.m_rcst)
{
  m_rcst->addref();
}

once_temp_type& once_temp_type::operator= (once_temp_type const& o)
{
  o.m_rcst->addref();
  m_rcst->release();
  m_rcst = o.m_rcst;
  return *this;
}

once_temp_type::~once_temp_type()
{
  m_rcst->release();
}

once_temp_type& once_temp_type::operator,(into_type_ptr const& i)
{
  m_rcst->exchange(i);
  return *this;
}

once_temp_type& once_temp_type::operator,(use_type_ptr const& u)
{
  m_rcst->exchange(u);
  return *this;
}

//------------------------------------------------------------------------------

once_type::once_type(session* s, Error& error)
: m_session (*s)
, m_error (error)
{
}

}

}
