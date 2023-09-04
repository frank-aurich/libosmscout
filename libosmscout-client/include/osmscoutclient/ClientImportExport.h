#ifndef OSMSCOUT_CLIENT_PRIVATE_IMPORT_EXPORT_H
#define OSMSCOUT_CLIENT_PRIVATE_IMPORT_EXPORT_H

/*
  This source is part of the libosmscout library
  Copyright (C) 2023  Tim Teulings

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

#include <osmscoutclient/ClientFeatures.h>

// Shared library support
#if defined _WIN32 || defined __CYGWIN__
#  define OSMSCOUT_IMPORT __declspec(dllimport)
#  define OSMSCOUT_EXPORT __declspec(dllexport)
#  define OSMSCOUT_LOCAL
#else
#  if __GNUC__ >= 4
#    define OSMSCOUT_IMPORT __attribute__ ((visibility ("default")))
#    define OSMSCOUT_EXPORT __attribute__ ((visibility ("default")))
#    define OSMSCOUT_LOCAL  __attribute__ ((visibility ("hidden")))
#  else
#    define OSMSCOUT_IMPORT
#    define OSMSCOUT_EXPORT
#    define OSMSCOUT_LOCAL
#  endif
#endif
#ifndef OSMSCOUT_STATIC
#  ifdef OSMScoutClient_EXPORTS
#    define OSMSCOUT_CLIENT_API OSMSCOUT_EXPORT
#  else
#    define OSMSCOUT_CLIENT_API OSMSCOUT_IMPORT
#  endif
#  define OSMSCOUT_CLIENT_DLLLOCAL OSMSCOUT_LOCAL
#  else
#    define OSMSCOUT_CLIENT_API
#    define OSMSCOUT_CLIENT_DLLLOCAL
#endif

// Throwable classes must always be visible on GCC in all binaries
#if defined(_WIN32)
  #define OSMSCOUT_CLIENT_EXCEPTIONAPI(api) api
#elif defined(OSMScoutClient_EXPORTS)
  #define OSMSCOUT_CLIENT_EXCEPTIONAPI(api) OSMSCOUT_EXPORT
#else
  #define OSMSCOUT_CLIENT_EXCEPTIONAPI(api)
#endif

#if defined(_MSC_VER)
  #define OSMSCOUT_CLIENT_INSTANTIATE_TEMPLATES
#endif
#endif