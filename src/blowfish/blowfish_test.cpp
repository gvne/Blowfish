#include <gtest/gtest.h>

#include <iostream>
#include <random>
#include <vector>

#include "blowfish/blowfish.h"

std::random_device g_random_device;

std::vector<char> MakeRandomBytes(uint64_t size) {
  std::default_random_engine rd(g_random_device());
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> uniform_dist(
      std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
  std::vector<char> output;
  for (auto index = 0; index < size; index++) {
    output.push_back(static_cast<char>(uniform_dist(gen)));
  }
  return output;
}

TEST(Blowfish, Basic) {
  // initialize random bytes
  auto key = MakeRandomBytes(64);

  auto data = MakeRandomBytes(1024 * 1024);
  Blowfish b(key);
  auto encrypted_data = b.Encrypt(data);
  auto decrypted_data = b.Decrypt(encrypted_data);
  
  ASSERT_NE(data, encrypted_data);
  ASSERT_EQ(data, decrypted_data);
}
