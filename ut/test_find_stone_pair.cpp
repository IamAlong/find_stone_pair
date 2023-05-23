#include "find_stone_pair.h"
#include "gtest/gtest.h"

using namespace longlong;

// test find stone pair
TEST(FindStonePairTest, TestFindStonePairSuccess) {
    auto stone_pair = find_stone_pair({ 1, 4, 5, 7 }, 3);
    EXPECT_EQ(0, stone_pair.first);
    EXPECT_EQ(1, stone_pair.second);

    stone_pair = find_stone_pair({ 4, 1, 5, 7 }, 3);
    EXPECT_EQ(0, stone_pair.first);
    EXPECT_EQ(1, stone_pair.second);

    stone_pair = find_stone_pair({ 4.5, 1, 5, 7 }, 0.5);
    EXPECT_EQ(0, stone_pair.first);
    EXPECT_EQ(2, stone_pair.second);

    stone_pair = find_stone_pair({ 2, 4.1, 1.1, 5, 7 }, 3);
    EXPECT_EQ(1, stone_pair.first);
    EXPECT_EQ(2, stone_pair.second);

    stone_pair = find_stone_pair({ -1, 2, 4, 1, 5 }, 3);
    EXPECT_EQ(2, stone_pair.first);
    EXPECT_EQ(3, stone_pair.second);

    stone_pair = find_stone_pair({ -1, 2, 4, 1, 5 }, -3);
    EXPECT_EQ(2, stone_pair.first);
    EXPECT_EQ(3, stone_pair.second);
}

TEST(FindStonePairTest, TestFindStonePairFail) {
    auto stone_pair = find_stone_pair({ }, 3);
    EXPECT_EQ(-1, stone_pair.first);
    EXPECT_EQ(-1, stone_pair.second);

    stone_pair = find_stone_pair({ 1 }, 3);
    EXPECT_EQ(-1, stone_pair.first);
    EXPECT_EQ(-1, stone_pair.second);

    stone_pair = find_stone_pair({ 1, 2, 3 }, 3);
    EXPECT_EQ(-1, stone_pair.first);
    EXPECT_EQ(-1, stone_pair.second);

    stone_pair = find_stone_pair({ -1, -2, -3, 2 }, 3);
    EXPECT_EQ(-1, stone_pair.first);
    EXPECT_EQ(-1, stone_pair.second);
}

// test find all stone pairs
TEST(FindAllStonePairsTest, TestFindAllStonePairsSuccess) {
    auto stone_pairs = find_all_stone_pairs({ 1, 3, 4, 5, 7 }, 3);
    EXPECT_EQ(2, stone_pairs.size());
    EXPECT_EQ(2, stone_pairs[0].first);
    EXPECT_EQ(0, stone_pairs[0].second);
    EXPECT_EQ(4, stone_pairs[1].first);
    EXPECT_EQ(2, stone_pairs[1].second);

    stone_pairs = find_all_stone_pairs({ 1, 1, 4 }, 3);
    EXPECT_EQ(2, stone_pairs.size());
    EXPECT_EQ(2, stone_pairs[0].first);
    EXPECT_EQ(0, stone_pairs[0].second);
    EXPECT_EQ(2, stone_pairs[1].first);
    EXPECT_EQ(1, stone_pairs[1].second);

    stone_pairs = find_all_stone_pairs({ 1.5, 1.1, 1.6, 2, 2.1 }, 0.5);
    EXPECT_EQ(3, stone_pairs.size());
    EXPECT_EQ(2, stone_pairs[0].first);
    EXPECT_EQ(1, stone_pairs[0].second);
    EXPECT_EQ(3, stone_pairs[1].first);
    EXPECT_EQ(0, stone_pairs[1].second);
    EXPECT_EQ(4, stone_pairs[2].first);
    EXPECT_EQ(2, stone_pairs[2].second);

    stone_pairs = find_all_stone_pairs({ 1.1, 4.1, 1.1 }, 3);
    EXPECT_EQ(2, stone_pairs.size());
    EXPECT_EQ(1, stone_pairs[0].first);
    EXPECT_EQ(0, stone_pairs[0].second);
    EXPECT_EQ(2, stone_pairs[1].first);
    EXPECT_EQ(1, stone_pairs[1].second);
}

TEST(FindAllStonePairsTest, TestFindAllStonePairsFailed) {
    auto stone_pairs = find_all_stone_pairs({ }, 3);
    EXPECT_EQ(0, stone_pairs.size());

    stone_pairs = find_all_stone_pairs({ 1 }, 3);
    EXPECT_EQ(0, stone_pairs.size());

    stone_pairs = find_all_stone_pairs({ 1, 2, 3 }, 3);
    EXPECT_EQ(0, stone_pairs.size());

    stone_pairs = find_all_stone_pairs({ -1, -2, -3, 2 }, 3);
    EXPECT_EQ(0, stone_pairs.size());
}