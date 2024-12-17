#ifndef CXXLE_H
#define CXXLE_H

#ifdef EXPORT_MY_LIBRARY
#if defined(_WIN32) || defined(_WIN64)
#define CXXLE_API __declspec(dllexport)
#else
#define CXXLE_API __attribute__((visibility("default")))
#endif
#else
#if defined(_WIN32) || defined(_WIN64)
#define CXXLE_API __declspec(dllimport)
#else
#define CXXLE_API
#endif
#endif

typedef struct
{
  void (*message)(const char *expr);
} cxxle_api;

// Public API declarations
CXXLE_API cxxle_api *cxxle();

#endif // CXXLE_H