#include <math.h>
#include <cmath>

class Vector2D {
   public:
    Vector2D(double, double);
    ~Vector2D();

    double x = 0;
    double y = 0;

    // returns the scale
    double normalize();
};