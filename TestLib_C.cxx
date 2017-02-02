#include "TestLib_C.h"
#include "TestLib.h"

//******************************************************************************

TestLibFoo* TestLibCreateFoo()
{
  return reinterpret_cast<TestLibFoo*>(new TestLib::Foo);
}

int TestLibDestroyFoo(TestLibFoo *foo)
{
  if(!foo) return -1;
  delete reinterpret_cast<TestLib::Foo*>(foo);
  return 0;
}

int TestLibFooDoSomething1(TestLibFoo *foo)
{
  if(!foo) return -1;
  return reinterpret_cast<TestLib::Foo*>(foo)->DoSomething1();
}

int TestLibFooDoSomething2(TestLibFoo *foo, double *arg)
{
  if(!foo || !arg) return -1;
  reinterpret_cast<TestLib::Foo*>(foo)->DoSomething2(*arg);
  return 0;
}

TestLibBar* TestLibFooCreateBar(TestLibFoo *foo, const char *name)
{
  if(!foo) return NULL;

  try
  { 
    TestLib::Bar& bar = reinterpret_cast<TestLib::Foo*>(foo)->CreateBar(name);
    return reinterpret_cast<TestLibBar*>(&bar);
  }
  catch(const std::runtime_error &)
  {
    return NULL;
  }
}

TestLibBar* TestLibFooGetBar(TestLibFoo *foo, const char *name)
{
  if(!foo) return NULL;

  try
  { 
    TestLib::Bar& bar = reinterpret_cast<TestLib::Foo*>(foo)->GetBar(name);
    return reinterpret_cast<TestLibBar*>(&bar);
  }
  catch(const std::out_of_range &)
  {
    return NULL;
  }
}

//******************************************************************************

int TestLibBarDoSomethingElse1(TestLibBar *bar)
{
  if(!bar) return -1;
  reinterpret_cast<TestLib::Bar*>(bar)->DoSomethingElse1();
  return 0;
}

int TestLibBarDoSomethingElse2(TestLibBar *bar, const char *in, double *out)
{
  if(!bar || ! out) return -1;
  *out = reinterpret_cast<TestLib::Bar*>(bar)->DoSomethingElse2(in);
  return 0;
}
