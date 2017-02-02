program TestLib
  use testlib_mod

  integer err
  integer foo
  real*8 arg

  call testlib_create_foo(foo)
  call testlib_foo_do_something1(foo, err)
  call testlib_foo_do_something2(foo, arg, err)

  call testlib_foo_create_bar(foo, 'b1', err)
  call testlib_bar_do_something_else1(foo, 'b1', err)
  call testlib_bar_do_something_else2(foo, 'b1', 'Things', arg, err)

  call testlib_foo_create_bar(foo, 'b2', err)
  call testlib_bar_do_something_else1(foo, 'b2', err)
  call testlib_bar_do_something_else2(foo, 'b2', 'Stuff', arg, err)

  call testlib_destroy_foo(foo, err)
end program

