#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>

#include "find_stone_pair.h"

namespace longlong {

std::string double_to_string(double data) {
    std::ostringstream oss;
    oss << data;
    return oss.str();
}

/**
 * function: find one stone pair whose weight difference is D
 * input: 
 * ***@stones_weights: array of stone's weight, weight should > 0, if stone weight <= 0 while be filtered
 * ***@difference: weight difference
 * output:
 * ***if success return pair of shone's index
 * ***if failed return pair <-1, -1>
*/
std::pair<size_t, size_t> find_stone_pair(const std::vector<double>& stones_weights, double difference) {
    if (stones_weights.empty() || stones_weights.size() < 2) {
        return { -1, -1 };
    }

    std::unordered_map<std::string, size_t> stones;
    // avoid rehash
    stones.reserve(stones_weights.size() * 2);
    for (size_t idx = 0; idx < stones_weights.size(); ++idx) {
        if (stones_weights[idx] <= 0) {
            continue;
        }
        std::string key = double_to_string(stones_weights[idx] + difference);
        if (stones.find(key) != stones.end()) {
            return { stones[key], idx };
        }
        key = double_to_string(stones_weights[idx] - difference);
        if (stones.find(key) != stones.end()) {
            return { stones[key], idx };
        }
        stones[double_to_string(stones_weights[idx])] = idx;
    }
    return { -1, -1 };
}

/**
 * function: find all stone pairs whose weight difference is D
 * input: 
 * ***@stones_weights: array of stone's weight, weight should > 0, if stone weight <= 0 while be filtered
 * ***@difference: weight difference
 * output:
 * ***if find stone pair, return an vector with all stone pairs
 * ***if not find any stone pair, return an empty vector
*/
std::vector<std::pair<size_t, size_t>> find_all_stone_pairs(const std::vector<double>& stones_weights, double difference) {
    if (stones_weights.empty() || stones_weights.size() < 2) {
        return {};
    }
    std::unordered_map<std::string, std::vector<size_t>> stones;
    // avoid rehash
    stones.reserve(stones_weights.size() * 2);
    std::vector<std::pair<size_t, size_t>> stone_pairs;
    //for_each(stones_weights.begin(), stones_weights.end(), [difference, &stones, &stone_pairs](double weight)
    for (size_t idx = 0; idx < stones_weights.size(); ++idx) {
        if (stones_weights[idx] <= 0) {
            continue;
        }
        std::string key = double_to_string(stones_weights[idx] + difference);
        if (stones.count(key) > 0) {
            for (size_t stone_idx : stones[key]) {
                stone_pairs.emplace_back(idx, stone_idx);
            }
        }
        key = double_to_string(stones_weights[idx] - difference);
        if (stones.count(key) > 0) {
            for (size_t stone_idx : stones[key]) {
                stone_pairs.emplace_back(idx, stone_idx);
            }
        }
        stones[double_to_string(stones_weights[idx])].emplace_back(idx);
    };
    return stone_pairs;
}

} // namespace longlong