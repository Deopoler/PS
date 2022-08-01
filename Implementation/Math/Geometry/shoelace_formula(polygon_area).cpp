#include <bits/stdc++.h>
using namespace std;

double polygon_area(const vector<pair<double, double>> &points)
{
    double result = 0;
    for (int i = 0; i < points.size() - 1; i++)
    {
        result += points[i].first * points[i + 1].second; // x_i * y_(i+1)
        result -= points[i].second * points[i + 1].first; // x_(i+1) * y_i
    }
    result += points.back().first * points[0].second; // x_(n-1)*y_0
    result -= points.back().second * points[0].first; // x_0 * y_(n-1)
    return 0.5 * abs(result);
}