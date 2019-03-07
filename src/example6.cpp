/*
 *    Example6.cpp
 *      - Eigen products and aliasing, avoiding temp variables
 *      - Benchmarking
 *           - C = A * B + C
 *           - D = A * B + C
 */

#include <benchmark/benchmark.h>
#include <Eigen/Dense>

const int reps = 5;

/*
 *    Benchmarking    C = A * B + C
 */
static void AtimesBplusC_1(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n), C(n,n);
  A.setIdentity();
  B.setIdentity();
  C.setIdentity();
  for (auto _ : state) {
    C += A * B;
  }
}

static void AtimesBplusC_2(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n), C(n,n);
  A.setIdentity();
  B.setIdentity();
  C.setIdentity();
  for (auto _ : state) {
    C.noalias() += A * B;
  }
}

BENCHMARK(AtimesBplusC_1)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(AtimesBplusC_2)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);

/*
 *    Benchmarking    D = A * B + C
 */
static void DisAtimesBplusC_1(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n), C(n,n), D(n,n);
  A.setIdentity();
  B.setIdentity();
  C.setIdentity();
  D.setIdentity();
  for (auto _ : state) {
    D = A * B + C;
  }
}

static void DisAtimesBplusC_2(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n), B(n, n), C(n,n), D(n,n);
  A.setIdentity();
  B.setIdentity();
  C.setIdentity();
  D.setIdentity();
  for (auto _ : state) {
    D = C;
    D.noalias() += A * B;
  }
}

BENCHMARK(DisAtimesBplusC_1)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(DisAtimesBplusC_2)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);

BENCHMARK_MAIN();