#include <cstring>
#include <cassert>

#include "test.h"
#include "base_lib.h"

int test() {
  assert(external_values::get_external_parser("foo") != nullptr);
  return external_values::get_external_parser("foo")->get_val();
}

namespace external_values {

class Bar : public ExternaValue {
 public:
  virtual int get_val() const override {
    return 456;
  }

  virtual bool is_type(const char* type) const noexcept override {
    return strcmp(type, "bar") == 0;
  }
private:
  static const Bar _instance;
  Bar() {
    register_external_parser(this);
  }
};

const Bar Bar::_instance;

}
