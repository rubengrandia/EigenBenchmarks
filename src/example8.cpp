/*
 *    Example8.cpp
 *      - Floats vs doubles
 */

#include <benchmark/benchmark.h>
#include <Eigen/Dense>

const int reps = 5;

static void FloatMatrixMatrix(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXf A(n, n), B(n, n), C(n, n);
  A.setIdentity();
  B.setIdentity();
  C.setIdentity();
  for (auto _ : state) {
    C = A * B;
  }
}

static void DoubleMatrixMatrix(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n), C(n, n);
  A.setIdentity();
  B.setIdentity();
  C.setIdentity();
  for (auto _ : state) {
    C = A * B;
  }
}


BENCHMARK(FloatMatrixMatrix)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(DoubleMatrixMatrix)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);

BENCHMARK_MAIN();