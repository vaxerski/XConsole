#include "vector.h"

Vector2D::Vector2D(double xx, double yy) {
    x = xx;
    y = yy;
}

Vector2D::~Vector2D() {}

double Vector2D::normalize() {
    //get max abs
    const auto max = abs(x) > abs(y) ? abs(x) : abs(y);

    x /= max;
    y /= max;

    return max;
}