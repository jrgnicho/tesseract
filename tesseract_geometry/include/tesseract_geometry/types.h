/**
 * @file types.h
 * @brief Tesseract Geometry Types
 *
 * @author Levi Armstrong
 * @date January 18, 2018
 * @version TODO
 * @bug No known bugs
 *
 * @copyright Copyright (c) 2017, Southwest Research Institute
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef TESSERACT_GEOMETRY_TYPES_H
#define TESSERACT_GEOMETRY_TYPES_H

#include <tesseract_geometry/macros.h>
TESSERACT_GEOMETRY_IGNORE_WARNINGS_PUSH
#include <Eigen/Geometry>
#include <memory>
#include <octomap/octomap.h>
#include <console_bridge/console.h>
#include <unordered_map>
TESSERACT_GEOMETRY_IGNORE_WARNINGS_POP

namespace tesseract_geometry
{
  template <typename T>
  using AlignedVector = std::vector<T, Eigen::aligned_allocator<T>>;

  template <typename Key, typename Value>
  using AlignedMap = std::map<Key, Value, std::less<Key>, Eigen::aligned_allocator<std::pair<const Key, Value>>>;

  template <typename Key, typename Value>
  using AlignedUnorderedMap = std::unordered_map<Key,
                                                 Value,
                                                 std::hash<Key>,
                                                 std::equal_to<Key>,
                                                 Eigen::aligned_allocator<std::pair<const Key, Value>>>;

  using VectorIsometry3d = AlignedVector<Eigen::Isometry3d>;
  using VectorVector4d = AlignedVector<Eigen::Vector4d>;
  using VectorVector3d = std::vector<Eigen::Vector3d>;
  using TransformMap = AlignedMap<std::string, Eigen::Isometry3d>;
}
#endif
