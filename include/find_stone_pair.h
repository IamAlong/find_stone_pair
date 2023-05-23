#ifndef __FIND_STONE_PAIR_H__
#define __FIND_STONE_PAIR_H__

#include <utility>
#include <vector>

namespace longlong {

std::pair<size_t, size_t> find_stone_pair(const std::vector<double>& stones_weights, double difference);
std::vector<std::pair<size_t, size_t>> find_all_stone_pairs(const std::vector<double>& stones_weights, double difference);

} // namespace longlong

#endif // __FIND_STONE_PAIR_H__