#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "functions.h"

// Проверяем что upper_bound правильно работает до точки x=4
TEST_CASE("test_upper_bound_before_4") {
    CHECK(upper_bound(3.0) == 3.0);
    CHECK(upper_bound(3.5) == 3.5);
}

// Проверяем что upper_bound правильно работает после точки x=4
TEST_CASE("test_upper_bound_after_4") {
    CHECK(upper_bound(5.0) == 3.0);
    CHECK(upper_bound(6.0) == 2.0);
}

// Проверяем что на границах фигуры интеграл равен 0
TEST_CASE("test_integral_bounds") {
    CHECK(integral(3.0) == 0.0);
    CHECK(integral(5.0) == 0.0);
}

// Проверяем что результат близок к 1
TEST_CASE("test_simpson_result") {
    double result = simpson_rule(integral, 3.0, 5.0, 100);
    CHECK(result > 0.99);
    CHECK(result < 1.01);
}

// При увеличении n результат должен быть точнее
TEST_CASE("test_accuracy_grows") {
    double result_small = simpson_rule(integral, 3.0, 5.0, 10);
    double result_large = simpson_rule(integral, 3.0, 5.0, 100);
    
    double err_small = result_small - 1.0;
    double err_large = result_large - 1.0;
    
    CHECK(err_large < err_small);
}
