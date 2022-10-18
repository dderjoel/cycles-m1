
#include "fast_float/fast_float.h"
#include "m1cycles.h"
#include <algorithm>
#include <charconv>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale.h>
#include <random>
#include <sstream>
#include <stdio.h>
#include <vector>

#include "random_generators.h"

std::uint64_t sum(std::uint64_t s) {

  std::uint64_t sum = 0;
  for (uint64_t i = 0; i < s; i++) {
    sum += i;
    if (sum % 1023 == 0) {
      // just to make it more unpredictable
      // otherwise, the cycle count is like 89 or something
      printf("whoo\n");
      sum /= 24;
    }
  }
  return sum;
}

int main() {
  setup_performance_counters();

  uint64_t s = 10000;
  // warm up the cache:
  for (size_t i = 0; i < 100; i++) {
    double ts = sum(s);
    if (ts == 0) {
      printf("bug\n");
    }
  }

  uint64_t start = get_cycles();
  double ts = sum(s);
  if (ts == 0) {
    printf("bug\n");
  }
  uint64_t end = get_cycles();

  printf("diff in cycles  %ld \n", end - start);

  return EXIT_SUCCESS;
}
