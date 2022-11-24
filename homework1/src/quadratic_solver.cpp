#include <cmath>
#include <stdexcept>
#include "quadratic_solver.h"

namespace hw1
{

void checkValue(double value)
{
    auto category = std::fpclassify(value);

    if ((category != FP_NORMAL)
     && (category != FP_ZERO)) {
        throw std::invalid_argument("Invalid category of double type");
    }
}

bool QuadraticSolver::equals(double lhv, double rhv) {
    auto diffAbs = std::abs(lhv - rhv);

    if (diffAbs <= _epsilon) {
        return true;
    }

    auto diff = _epsilon * std::max(std::abs(lhv), std::abs(rhv));

    return diffAbs <= diff;
}

std::vector<double> QuadraticSolver::solve(double a, double b, double c) {
    checkParameters(a, b, c);

    auto result = std::vector<double>{};

    auto discriminant = (b * b) - (4 * a * c);

    if (discriminant < -_epsilon) {
        return result;
    } else if (std::abs(discriminant) < _epsilon) {
        double root = -b / (2 * a);
        result.push_back(root);
    } else {
        auto discriminant_sqrt = std::sqrt(discriminant);
        auto x1 = (-b + discriminant_sqrt) / (2 * a);
        auto x2 = (-b - discriminant_sqrt) / (2 * a);
        result.push_back(x1);
        result.push_back(x2);
    }

    return result;
}

void QuadraticSolver::checkParameters(double a, double b, double c) {
    if (std::abs(a) < _epsilon) {
        throw std::invalid_argument("Invalid coefficient: a is zero");
    }

    checkValue(a);
    checkValue(b);
    checkValue(c);
}

}