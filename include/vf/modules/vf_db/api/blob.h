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

#ifndef VF_DB_BLOB_VFHEADER
#define VF_DB_BLOB_VFHEADER

namespace db {

// BLOB interface
class blob
{
public:
  blob();
  ~blob();

  Error select (session& s,
                char const* zTable,
                char const* zColumn,
                rowid id,
                bool readAndWrite = false) noexcept;

  std::size_t get_len();
  Error read (std::size_t offset, void* buf, std::size_t toRead);
  Error write (std::size_t offset, void const* buf, std::size_t toWrite);
  void close ();

private:
  session* m_session;
  sqlite3_blob* m_blob;
};

}

#endif
