/*
 *    Example4.cpp
 *      - Eigen products and nesting
 *      - Show rangemultiplier
 *      - Benchmarking
 *           C = ( A * B ) ^ T
 */

#include <benchmark/benchmark.h>
#include <Eigen/Dense>

const int reps = 5;

static void ABtranspose(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n), C(n, n);
  A.setIdentity();
  B.setIdentity();
  for (auto _ : state) {
    C = (A * B).transpose();
  }
}


static void BtransposeAtranspose(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n), C(n, n);
  A.setIdentity();
  B.setIdentity();
  for (auto _ : state) {
    C = B.transpose() * A.transpose();
  }
}

BENCHMARK(ABtranspose)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(BtransposeAtranspose)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);

BENCHMARK_MAIN();