#include <cassert>
#include <cstdio>

#include "test.h"
#include "base_lib.h"


int main() {


  assert(external_values::get_external_parser("bar") != nullptr);
  int bar = external_values::get_external_parser("bar")->get_val();

  printf("bar %d\n", bar);

  int foo = test();

  printf("foo %d\n", foo);
}
