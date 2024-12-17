#ifndef MOONDREAM_H
#define MOONDREAM_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef EXPORT_MY_LIBRARY
#if defined(_WIN32) || defined(_WIN64)
#define MOONDREAM_API __declspec(dllexport)
#else
#define MOONDREAM_API __attribute__((visibility("default")))
#endif
#else
#if defined(_WIN32) || defined(_WIN64)
#define MOONDREAM_API __declspec(dllimport)
#else
#define MOONDREAM_API
#endif
#endif

  typedef struct
  {
    void (*message)(const char *expr);
  } cxxle_api;

  // Public API declarations
  MOONDREAM_API cxxle_api *cxxle();

#ifdef __cplusplus
}
#endif

#endif // MOONDREAM_H