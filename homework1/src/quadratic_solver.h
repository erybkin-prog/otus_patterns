#pragma once

#include <vector>

namespace hw1
{
class QuadraticSolver
{
public:
    static bool equals(double lhv, double rhv);
    static std::vector<double> solve(double a, double b, double c);
private:
    static constexpr auto _epsilon = 1.0e-05f;
    static void checkParameters(double a, double b, double c);
};

}