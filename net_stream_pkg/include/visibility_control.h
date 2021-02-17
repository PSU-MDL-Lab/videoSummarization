#ifndef NET_STREAM_PKG__VISIBILITY_CONTROL_H_
#define NET_STREAM_PKG__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define NET_STREAM_PKG_EXPORT __attribute__ ((dllexport))
    #define NET_STREAM_PKG_IMPORT __attribute__ ((dllimport))
  #else
    #define NET_STREAM_PKG_EXPORT __declspec(dllexport)
    #define NET_STREAM_PKG_IMPORT __declspec(dllimport)
  #endif
  #ifdef NET_STREAM_PKG_BUILDING_LIBRARY
    #define NET_STREAM_PKG_PUBLIC NET_STREAM_PKG_EXPORT
  #else
    #define NET_STREAM_PKG_PUBLIC NET_STREAM_PKG_IMPORT
  #endif
  #define NET_STREAM_PKG_PUBLIC_TYPE NET_STREAM_PKG_PUBLIC
  #define NET_STREAM_PKG_LOCAL
#else
  #define NET_STREAM_PKG_EXPORT __attribute__ ((visibility("default")))
  #define NET_STREAM_PKG_IMPORT
  #if __GNUC__ >= 4
    #define NET_STREAM_PKG_PUBLIC __attribute__ ((visibility("default")))
    #define NET_STREAM_PKG_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define NET_STREAM_PKG_PUBLIC
    #define NET_STREAM_PKG_LOCAL
  #endif
  #define NET_STREAM_PKG_PUBLIC_TYPE
#endif

#endif  // NET_STREAM_PKG__VISIBILITY_CONTROL_H_
