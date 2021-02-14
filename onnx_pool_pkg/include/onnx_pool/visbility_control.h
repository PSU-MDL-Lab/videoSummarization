#ifndef ONNX_POOL__VISIBILITY_CONTROL_H_
#define ONNX_POOL__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ONNX_POOL_EXPORT __attribute__ ((dllexport))
    #define ONNX_POOL_IMPORT __attribute__ ((dllimport))
  #else
    #define ONNX_POOL_EXPORT __declspec(dllexport)
    #define ONNX_POOL_IMPORT __declspec(dllimport)
  #endif
  #ifdef ONNX_POOL_BUILDING_DLL
    #define ONNX_POOL_PUBLIC ONNX_POOL_EXPORT
  #else
    #define ONNX_POOL_PUBLIC ONNX_POOL_IMPORT
  #endif
  #define ONNX_POOL_PUBLIC_TYPE ONNX_POOL_PUBLIC
  #define ONNX_POOL_LOCAL
#else
  #define ONNX_POOL_EXPORT __attribute__ ((visibility("default")))
  #define ONNX_POOL_IMPORT
  #if __GNUC__ >= 4
    #define ONNX_POOL_PUBLIC __attribute__ ((visibility("default")))
    #define ONNX_POOL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ONNX_POOL_PUBLIC
    #define ONNX_POOL_LOCAL
  #endif
  #define ONNX_POOL_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // ONNX_POOL__VISIBILITY_CONTROL_H_