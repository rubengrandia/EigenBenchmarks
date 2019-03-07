/*
 *    Example2.cpp
 *      - Shows the usage of DoNotOptimize
 *      - Benchmarking
 *           c = a + b
 */

#include <benchmark/benchmark.h>
#include <Eigen/Dense>

static void AddSimple(benchmark::State& state) {
  double a = 1.0;
  double b = 2.0;
  double c;
  for (auto _ : state) {
       c = a + b;
  }
}
BENCHMARK(AddSimple);

static void AddSimple_DoNotOptimize_1(benchmark::State& state) {
  double a = 1.0;
  double b = 2.0;
  double c;
  for (auto _ : state) {
      benchmark::DoNotOptimize( c = a + b );
  }
}
BENCHMARK(AddSimple_DoNotOptimize_1);

static void AddSimple_DoNotOptimize_2(benchmark::State& state) {
  double a = 1.0;
  double b = 2.0;
  double c;
  for (auto _ : state) {
    benchmark::DoNotOptimize( a + b );
  }
}
BENCHMARK(AddSimple_DoNotOptimize_2);


BENCHMARK_MAIN();