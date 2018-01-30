/*
 * libheif example application "heif".
 * Copyright (c) 2017 struktur AG, Dirk Farin <farin@struktur.de>
 *
 * This file is part of heif, an example application using libheif.
 *
 * heif is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * heif is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with heif.  If not, see <http://www.gnu.org/licenses/>.
 */
#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif

#include <errno.h>
#include <string.h>

#include "bitstream.h"
#include "box.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <getopt.h>

using namespace heif;


int main(int argc, char** argv)
{
  StreamWriter writer;
  writer.write32(0x12345678);

  BoxHeader hdr;
  hdr.set_short_type( fourcc("abcd") );
  hdr.prepend_header(writer, true);

  std::ofstream ostr("out.heic");
  const auto& data = writer.get_data();
  ostr.write( (const char*)data.data(), data.size() );

  return 0;
}
