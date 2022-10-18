
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
  }
  return sum;
}

void process(uint64_t s) {

  // warm up the cache:
  for (size_t i = 0; i < 10; i++) {
    double ts = sum(s);
    if (ts == 0) {
      printf("bug\n");
    }
  }

  performance_counters start = get_counters();
  double ts = sum(s);
  if (ts == 0) {
    printf("bug\n");
  }
  performance_counters end = get_counters();

  uint64_t diff = end.cycles - start.cycles;

  printf("diff in cycles  %ld \n", diff);
  printf("\n");
}

int main() {
  setup_performance_counters();

  process(10000000);

  return EXIT_SUCCESS;
}
