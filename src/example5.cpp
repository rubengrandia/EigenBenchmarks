/*
 *    Example5.cpp
 *      - Eigen products and nesting, does order matter?
 *      - Benchmarking
 *           c = A * B * v
 */


#include <benchmark/benchmark.h>
#include <Eigen/Dense>

const int reps = 5;

static void MatrixMatrixVector_1(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n);
  Eigen::VectorXd v(n), c(n);
  A.setIdentity();
  B.setIdentity();
  v.setOnes();
  for (auto _ : state) {
    c = A * B * v;
  }
}

static void MatrixMatrixVector_2(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n);
  Eigen::VectorXd v(n), c(n);
  A.setIdentity();
  B.setIdentity();
  v.setOnes();
  for (auto _ : state) {
    c = A * (B * v);
  }
}

static void MatrixMatrixVector_3(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n);
  Eigen::VectorXd v(n), c(n);
  A.setIdentity();
  B.setIdentity();
  v.setOnes();
  for (auto _ : state) {
    c = v.transpose() * A * B;
  }
}

BENCHMARK(MatrixMatrixVector_1)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(MatrixMatrixVector_2)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(MatrixMatrixVector_3)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);


BENCHMARK_MAIN();