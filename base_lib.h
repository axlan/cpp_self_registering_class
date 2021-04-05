/**
 * Copyright (C) 2020 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SWIFTLETS_CONFIG_PARSER_SWIFTLET_EXTERNAL_CONFIG_PARSER_H
#define SWIFTLETS_CONFIG_PARSER_SWIFTLET_EXTERNAL_CONFIG_PARSER_H

namespace external_values {
  class ExternaValue {
   public:
    virtual int get_val() const = 0;

    virtual bool is_type(const char* type) const noexcept = 0;
  };

  int register_external_parser(const ExternaValue *);
  const ExternaValue * get_external_parser(const char* type);

} //namespace external_values

#endif
