#ifndef TestLib_C_h_
#define TestLib_C_h_

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct TestLibFoo TestLibFoo;
typedef struct TestLibBar TestLibBar;

TestLibFoo* TestLibCreateFoo();
int TestLibDestroyFoo(TestLibFoo *foo);

int TestLibFooDoSomething1(TestLibFoo *foo);
int TestLibFooDoSomething2(TestLibFoo *foo, double *arg);
TestLibBar* TestLibFooCreateBar(TestLibFoo *foo, const char *name);

int TestLibBarDoSomethingElse1(TestLibBar *bar);
int TestLibBarDoSomethingElse2(TestLibBar *bar, const char *in, double *out);

#ifdef __cplusplus
}
#endif

#endif
