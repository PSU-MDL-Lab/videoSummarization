#ifndef ONNX_POOL_PKG__VISIBILITY_CONTROL_H_
#define ONNX_POOL_PKG__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ONNX_POOL_PKG_EXPORT __attribute__ ((dllexport))
    #define ONNX_POOL_PKG_IMPORT __attribute__ ((dllimport))
  #else
    #define ONNX_POOL_PKG_EXPORT __declspec(dllexport)
    #define ONNX_POOL_PKG_IMPORT __declspec(dllimport)
  #endif
  #ifdef ONNX_POOL_PKG_BUILDING_LIBRARY
    #define ONNX_POOL_PKG_PUBLIC ONNX_POOL_PKG_EXPORT
  #else
    #define ONNX_POOL_PKG_PUBLIC ONNX_POOL_PKG_IMPORT
  #endif
  #define ONNX_POOL_PKG_PUBLIC_TYPE ONNX_POOL_PKG_PUBLIC
  #define ONNX_POOL_PKG_LOCAL
#else
  #define ONNX_POOL_PKG_EXPORT __attribute__ ((visibility("default")))
  #define ONNX_POOL_PKG_IMPORT
  #if __GNUC__ >= 4
    #define ONNX_POOL_PKG_PUBLIC __attribute__ ((visibility("default")))
    #define ONNX_POOL_PKG_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ONNX_POOL_PKG_PUBLIC
    #define ONNX_POOL_PKG_LOCAL
  #endif
  #define ONNX_POOL_PKG_PUBLIC_TYPE
#endif

#endif  // ONNX_POOL_PKG__VISIBILITY_CONTROL_H_
