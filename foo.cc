#include "base_lib.h"
#include <cstring>

namespace external_values {

class Foo : public ExternaValue {
 public:
  virtual int get_val() const override {
    return 123;
  }

  virtual bool is_type(const char* type) const noexcept override {
    return strcmp(type, "foo") == 0;
  }
private:
  static const Foo _instance;
  Foo() {
    register_external_parser(this);
  }
};

const Foo Foo::_instance;

}