#include <cstdlib>

#include "base_lib.h"

namespace external_values {

    constexpr size_t kMaxExternalParsers = 64;
    const ExternaValue* external_values[kMaxExternalParsers];
    size_t num_parsers = 0;

    int register_external_parser(const ExternaValue *parser) {
        if (num_parsers >= kMaxExternalParsers) {
            return 1;
        }
        external_values[num_parsers++] = parser;
        return 0;
    }

    const ExternaValue * get_external_parser(const char* type) {
        for (size_t i = 0; i < num_parsers; i++) {
            if (external_values[i]->is_type(type)) {
                return external_values[i];
            }
        }
        return nullptr;
    }

} // namespace external_values
