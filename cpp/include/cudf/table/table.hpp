/*
 * Copyright (c) 2019, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <cudf/column/column.hpp>
#include <cudf/table/table_view.hpp>

#include <memory>
#include <vector>

namespace cudf {
class table {
 public:
  table() = delete;
  ~table() = default;
  table(table&&) = default;
  table& operator=(table const&) = delete;
  table& operator=(table&&) = delete;

  /**---------------------------------------------------------------------------*
   * @brief Construct a new table by copying the contents of another table.
   *---------------------------------------------------------------------------**/
  table(table const& other);

  /**---------------------------------------------------------------------------*
   * @brief Moves the contents from a vector of `unique_ptr`s to columns to
   * construct a new table.
   *
   * @param columns The vector of `unique_ptr`s to columns whose contents will
   * be moved into the new table.
   *---------------------------------------------------------------------------**/
  table(std::vector<std::unique_ptr<column>>&& columns);

 private:
  std::vector<std::unique_ptr<column>> _columns;
};

}  // namespace cudf