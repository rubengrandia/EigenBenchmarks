/*
 *    Example3.cpp
 *      - Eigen and DoNotOptimize
 *      - Show repetitions of benchmarks
 *      - Benchmarking
 *           c = a + b
 */

#include <benchmark/benchmark.h>
#include <Eigen/Dense>

// Globals are allowed today!
const int reps = 5;
const int n = 100;

static void AddEigen(benchmark::State& state) {
  Eigen::VectorXd a(n), b(n), c(n);
  a.setConstant(1.0);
  b.setConstant(2.0);
  for (auto _ : state) {
    c = a + b;
  }
}

static void AddEigen_DoNotOptimize_1(benchmark::State& state) {
  Eigen::VectorXd a(n), b(n), c(n);
  a.setConstant(1.0);
  b.setConstant(2.0);
  for (auto _ : state) {
    benchmark::DoNotOptimize( c = a + b );
  }
}

static void AddEigen_DoNotOptimize_2(benchmark::State& state) {
  Eigen::VectorXd a(n), b(n), c(n);
  a.setConstant(1.0);
  b.setConstant(2.0);
  for (auto _ : state) {
    benchmark::DoNotOptimize( a + b );
  }
}

BENCHMARK(AddEigen)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(AddEigen_DoNotOptimize_1)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(AddEigen_DoNotOptimize_2)->Repetitions(reps)->DisplayAggregatesOnly(true);


BENCHMARK_MAIN();