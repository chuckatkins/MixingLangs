module testlib_mod
  interface
    subroutine testlib_create_foo(foo)
      implicit none
      integer, intent(out) :: foo
    end subroutine

    subroutine testlib_destroy_foo(foo, err)
      implicit none
      integer, value, intent(in)  :: foo
      integer,        intent(out) :: err
    end subroutine

    subroutine testlib_foo_do_something1(foo, err)
      implicit none
      integer, value, intent(in)  :: foo
      integer,        intent(out) :: err
    end subroutine

    subroutine testlib_foo_do_something2(foo, arg, err)
      implicit none
      integer, value, intent(in)  :: foo
      real*8,         intent(out) :: arg
      integer,        intent(out) :: err
    end subroutine

    subroutine testlib_foo_create_bar(foo, name, err)
      implicit none
      integer,       value, intent(in)  :: foo
      character*(*),        intent(in)  :: name
      integer,              intent(out) :: err
    end subroutine

    subroutine testlib_bar_do_something_else1(foo, bar, err)
      implicit none
      integer,       value, intent(in)  :: foo
      character*(*),        intent(in)  :: bar
      integer,              intent(out) :: err
    end subroutine

    subroutine testlib_bar_do_something_else2(foo, bar, in, out, err)
      implicit none
      integer,       value, intent(in)  :: foo
      character*(*),        intent(in)  :: bar
      character*(*),        intent(in)  :: in
      real*8,               intent(out) :: out
      integer,              intent(out) :: err
    end subroutine
  end interface
end module
