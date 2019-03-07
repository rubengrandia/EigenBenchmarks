/*
 *    Example7.cpp
 *      - Eigen inverses and caching
 *      - Benchmarking
 *          - c0 = A^(-1) b0
 *          - c1 = A^(-1) b1
 */

#include <benchmark/benchmark.h>
#include <Eigen/Dense>

const int reps = 5;

static void CachedInverse(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n);
  Eigen::VectorXd b0(n), b1(n), c0(n), c1(n);
  A.setIdentity();
  b0.setOnes();
  b1.setOnes();
  c0.setOnes();
  c1.setOnes();
  for (auto _ : state) {
    Eigen::MatrixXd Ainv = A.inverse();
    c0 = Ainv * b0;
    c1 = Ainv * b1;
  }
}

static void DirectInverse(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n);
  Eigen::VectorXd b0(n), b1(n), c0(n), c1(n);
  A.setIdentity();
  b0.setOnes();
  b1.setOnes();
  c0.setOnes();
  c1.setOnes();
  for (auto _ : state) {
    c0 = A.lu().solve(b0);
    c1 = A.lu().solve(b1);
  }
}

static void CachedLUInverse(benchmark::State& state) {
  const int64_t n = state.range(0);
  Eigen::MatrixXd A(n, n);
  Eigen::VectorXd b0(n), b1(n), c0(n), c1(n);
  A.setIdentity();
  b0.setOnes();
  b1.setOnes();
  c0.setOnes();
  c1.setOnes();
  for (auto _ : state) {
    Eigen::PartialPivLU<Eigen::MatrixXd> Alu(A);
    c0 = Alu.solve(b0);
    c1 = Alu.solve(b1);
  }
}

BENCHMARK(CachedInverse)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(DirectInverse)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);
BENCHMARK(CachedLUInverse)->RangeMultiplier(2)->Range(4, 64)->Repetitions(reps)->DisplayAggregatesOnly(true);

BENCHMARK_MAIN();