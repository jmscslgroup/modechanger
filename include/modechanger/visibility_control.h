#ifndef MODECHANGER__VISIBILITY_CONTROL_H_
#define MODECHANGER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MODECHANGER_EXPORT __attribute__ ((dllexport))
    #define MODECHANGER_IMPORT __attribute__ ((dllimport))
  #else
    #define MODECHANGER_EXPORT __declspec(dllexport)
    #define MODECHANGER_IMPORT __declspec(dllimport)
  #endif
  #ifdef MODECHANGER_BUILDING_LIBRARY
    #define MODECHANGER_PUBLIC MODECHANGER_EXPORT
  #else
    #define MODECHANGER_PUBLIC MODECHANGER_IMPORT
  #endif
  #define MODECHANGER_PUBLIC_TYPE MODECHANGER_PUBLIC
  #define MODECHANGER_LOCAL
#else
  #define MODECHANGER_EXPORT __attribute__ ((visibility("default")))
  #define MODECHANGER_IMPORT
  #if __GNUC__ >= 4
    #define MODECHANGER_PUBLIC __attribute__ ((visibility("default")))
    #define MODECHANGER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MODECHANGER_PUBLIC
    #define MODECHANGER_LOCAL
  #endif
  #define MODECHANGER_PUBLIC_TYPE
#endif
#endif  // MODECHANGER__VISIBILITY_CONTROL_H_
// Generated 26-Nov-2024 17:27:42
// Copyright 2019-2020 The MathWorks, Inc.
