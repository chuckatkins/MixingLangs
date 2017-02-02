#include "TestLib_Fortran.h"
#include "TestLib.h"

//******************************************************************************
void testlib_create_foo_(void **foo)
{
  try
  {
    *foo = new TestLib::Foo;
  }
  catch(const std::exception &)
  {
    *reinterpret_cast<int*>(*foo) = -1;
  }
}

void testlib_destroy_foo_(void *foo, int *err)
{
  delete reinterpret_cast<TestLib::Foo*>(foo);
  *err = 0;
}

void testlib_foo_do_something1_(void *foo, int *err)
{
  *err = reinterpret_cast<TestLib::Foo*>(foo)->DoSomething1();
}

void testlib_foo_do_something2_(void *foo, double *arg, int *err)
{
  reinterpret_cast<TestLib::Foo*>(foo)->DoSomething2(*arg);
  *err = 0;
}

void testlib_foo_create_bar_(void *foo, const char *name, int *err,
  size_t nlen)
{
  try
  { 
    TestLib::Bar& bar =
      reinterpret_cast<TestLib::Foo*>(foo)->CreateBar(std::string(name, nlen));
    *err = 0;
  }
  catch(const std::runtime_error &)
  {
    *err = -1;
  }
}

//******************************************************************************

void testlib_bar_do_something_else1_(void *foo, const char *bname, int *err,
  size_t bnlen)
{
  try
  {
    TestLib::Bar& bar =
      reinterpret_cast<TestLib::Foo*>(foo)->GetBar(std::string(bname, bnlen));
    bar.DoSomethingElse1();
    *err = 0;
  }
  catch(const std::out_of_range&)
  {
    *err = -1;
  }
}

void testlib_bar_do_something_else2_(void *foo,
  const char *bname, const char *in, double *out, int *err,
  size_t bnlen, size_t ilen)
{
  try
  {
    TestLib::Bar& bar =
      reinterpret_cast<TestLib::Foo*>(foo)->GetBar(std::string(bname, bnlen));
    *out = bar.DoSomethingElse2(std::string(in, ilen));
    *err = 0;
  }
  catch(const std::out_of_range&)
  {
    *err = -1;
  }
}
