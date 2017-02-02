This is a basic example of a C++ library with a C and Fortran interface.

TestLib.{h,cxx}
The C++ implementation and header.  This is the primary API for the library.

TestLib_C.{h,cxx}
The C wrapper API.  This API creates a struct for each C++ object and uses it as a handle to the C functions.

TestLib_Fortran.{h,cxx}
The Fortran wrapper API.  This API operates a bit differently since it's more natural for Fortran libraries to use a single handle instead of many different handles.  To that end, the Fortran wrapper uses a simple "everything's a string" interface with a single handle for the main object.
