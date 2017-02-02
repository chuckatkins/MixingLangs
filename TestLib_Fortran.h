#ifndef TestLib_Fortran_h_
#define TestLib_Fortran_h_

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

void testlib_create_foo_(void **foo);
void testlib_destroy_foo_(void *foo, int *err);

void testlib_foo_do_something1_(void *foo, int *err);
void testlib_foo_do_something2_(void *foo, double *arg, int *err);
void testlib_foo_create_bar_(void *foo, const char *name, int *err,
  size_t len);

void testlib_bar_do_something_else1_(void *foo, const char *bar, int *err,
  size_t blen);
void testlib_bar_do_something_else2_(void *foo,
  const char *bar, const char *in, double *out, int *err,
  size_t blen, size_t ilen);

#ifdef __cplusplus
}
#endif

#endif
