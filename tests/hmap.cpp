#include <gtest/gtest.h>
#include <iostream>

extern "C" {
    #include <neolib/hmap.h>
}

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    size_t hash = _hash("key", 51);
    ASSERT_EQ(hash, 29);
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
