#include <gtest/gtest.h>
#include "quadratic_solver.h"

using namespace hw1;

TEST(solve, no_roots)
{
    std::vector<double> result;

    ASSERT_NO_THROW(
        result = QuadraticSolver::solve(1.0, 0.0, 1.0);
    );

    ASSERT_TRUE(result.empty());
}

TEST(solve, two_roots)
{
    std::vector<double> result;

    ASSERT_NO_THROW(
        result = QuadraticSolver::solve(1.0, 0.0, -1.0);
    );

    ASSERT_EQ(result.size(), 2);

    ASSERT_FALSE(QuadraticSolver::equals(result[0], result[1]));

    ASSERT_TRUE(
        QuadraticSolver::equals(result[0], -1.0)
        || QuadraticSolver::equals(result[0], 1.0)
    );

    ASSERT_TRUE(
        QuadraticSolver::equals(result[1], -1.0)
        || QuadraticSolver::equals(result[1], 1.0)
    );
}

TEST(solve, one_root)
{
    std::vector<double> result;

    ASSERT_NO_THROW(
        result = QuadraticSolver::solve(1.0, 2.0, 1.0);
    );

    ASSERT_EQ(result.size(), 1);

    ASSERT_TRUE(QuadraticSolver::equals(result[0], -1.0));
}

TEST(solve, one_root_epsilon)
{
    std::vector<double> result;

    ASSERT_NO_THROW(
        result = QuadraticSolver::solve(1.0, 1.999998, 1.0);
    );

    ASSERT_EQ(result.size(), 1);

    ASSERT_TRUE(QuadraticSolver::equals(result[0], -1.0));
}

TEST(solve, coeff_a_is_zero)
{
    std::vector<double> result;

    ASSERT_THROW({result = QuadraticSolver::solve(0.0, 2.0, 1.0);}
                 , std::invalid_argument
    );

    ASSERT_THROW({result = QuadraticSolver::solve(-0.0, 2.0, 1.0);}
                 , std::invalid_argument
    );
}

TEST(solve, coeff_a_is_abnormal)
{
    std::vector<double> result;

    ASSERT_THROW({result = QuadraticSolver::solve(1 / 0.0, 2.0, 1.0);}
                 , std::invalid_argument
    );

    ASSERT_THROW({result = QuadraticSolver::solve(0.0 / 0.0, 2.0, 1.0);}
                 , std::invalid_argument
    );

    ASSERT_THROW({result = QuadraticSolver::solve(DBL_MIN / 2, 2.0, 1.0);}
                 , std::invalid_argument
    );
}

TEST(solve, coeff_b_is_abnormal)
{
    std::vector<double> result;

    ASSERT_THROW({result = QuadraticSolver::solve(1.0, 1 / 0.0, 1.0);}
                 , std::invalid_argument
    );

    ASSERT_THROW({result = QuadraticSolver::solve(1.0, 0.0 / 0.0, 1.0);}
                 , std::invalid_argument
    );

    ASSERT_THROW({result = QuadraticSolver::solve(1.0, DBL_MIN / 2, 1.0);}
                 , std::invalid_argument
    );

    ASSERT_NO_THROW(
        result = QuadraticSolver::solve(1.0, 0.0, 1.0);
    );

    ASSERT_NO_THROW(
        result = QuadraticSolver::solve(1.0, -0.0, 1.0);
    );
}

TEST(solve, coeff_c_is_abnormal)
{
    std::vector<double> result;

    ASSERT_THROW({result = QuadraticSolver::solve(1.0, 2.0, 1 / 0.0);}
                 , std::invalid_argument
    );

    ASSERT_THROW({result = QuadraticSolver::solve(1.0, 2.0, 0.0 / 0.0);}
                 , std::invalid_argument
    );

    ASSERT_THROW({result = QuadraticSolver::solve(1.0, 2.0, DBL_MIN / 2);}
                 , std::invalid_argument
    );

    ASSERT_NO_THROW(
        result = QuadraticSolver::solve(1.0, 2.0, 0.0);
    );

    ASSERT_NO_THROW(
        result = QuadraticSolver::solve(1.0, 2.0, -0.0);
    );
}

TEST(solve, failed)
{
    FAIL();
}