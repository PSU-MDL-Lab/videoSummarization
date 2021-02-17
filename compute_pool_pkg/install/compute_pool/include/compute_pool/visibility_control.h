#ifndef COMPUTE_POOL__VISIBILITY_CONTROL_H_
#define COMPUTE_POOL__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define COMPUTE_POOL_EXPORT __attribute__ ((dllexport))
    #define COMPUTE_POOL_IMPORT __attribute__ ((dllimport))
  #else
    #define COMPUTE_POOL_EXPORT __declspec(dllexport)
    #define COMPUTE_POOL_IMPORT __declspec(dllimport)
  #endif
  #ifdef COMPUTE_POOL_BUILDING_DLL
    #define COMPUTE_POOL_PUBLIC COMPUTE_POOL_EXPORT
  #else
    #define COMPUTE_POOL_PUBLIC COMPUTE_POOL_IMPORT
  #endif
  #define COMPUTE_POOL_PUBLIC_TYPE COMPUTE_POOL_PUBLIC
  #define COMPUTE_POOL_LOCAL
#else
  #define COMPUTE_POOL_EXPORT __attribute__ ((visibility("default")))
  #define COMPUTE_POOL_IMPORT
  #if __GNUC__ >= 4
    #define COMPUTE_POOL_PUBLIC __attribute__ ((visibility("default")))
    #define COMPUTE_POOL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define COMPUTE_POOL_PUBLIC
    #define COMPUTE_POOL_LOCAL
  #endif
  #define COMPUTE_POOL_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // COMPUTE_POOL__VISIBILITY_CONTROL_H_