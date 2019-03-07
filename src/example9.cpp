/*
 *    Example9.cpp
 *      - Fixed vs X
 */

#include <benchmark/benchmark.h>
#include <Eigen/Dense>

const int reps = 5;
const int64_t n = 4;

static void MatrixMatrixXd(benchmark::State& state) {
  Eigen::MatrixXd A(n, n), B(n, n), C(n, n);
  A.setRandom();
  B.setRandom();
  C.setRandom();
  for (auto _ : state) {
    C = A * B;
  }
}

static void MatrixMatrixFixed(benchmark::State& state) {
  Eigen::Matrix<double, n, n> A, B, C;
  A.setRandom();
  B.setRandom();
  C.setRandom();
  for (auto _ : state) {
    C = A * B;
  }
}


BENCHMARK(MatrixMatrixXd)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(MatrixMatrixFixed)->Repetitions(reps)->DisplayAggregatesOnly(true);

BENCHMARK_MAIN();