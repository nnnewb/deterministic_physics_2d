#ifndef UNIQ_VEC2_H
#define UNIQ_VEC2_H
#include <ostream>
#include "m.h"

namespace uniq {
    template <typename Real>
    struct vec2 {
        Real x, y, length;

        vec2() = default;

        vec2(Real x, Real y)
            : x(x)
            , y(y)
            , length(math::hypot(x, y)) { }

        vec2 operator*(Real rhs) const {
            return {x * rhs, y * rhs};
        }

        vec2 operator/(Real rhs) const {
            return {x / rhs, y / rhs};
        }

        vec2 operator-(vec2 rhs) const {
            return {x - rhs.x, y - rhs.y};
        }

        vec2 operator+(vec2 rhs) const {
            return {x + rhs.x, y + rhs.y};
        }

        friend std::ostream& operator<<(std::ostream& os, const vec2& obj) {
            return os
                   << "x: " << obj.x
                   << " y: " << obj.y;
        }

        vec2 norml() const {
            return {y, -x};
        }

        Real distance(vec2 v) const {
            return math::hypot(x - v.x, y - v.y);
        }

        Real dot(vec2 rhs) const {
            return x * rhs.x + y * rhs.y;
        }

        // 求向量到另一个向量的投影点
        // 公式推导过程如下
        //
        // dot(self, v) = mod(self) * mod(v) * cos(theta)
        // direction = normalize(v)
        // normalize = v / mod(v)
        // distance = mod(self) * cos(theta)
        // distance = dot(self, v) / mod(v)
        // project(self, v) = distance * direction
        // project = (dot(self, v) / mod(v)) * (v / mod(v))
        // project = (dot(self, v) / mod(v)^2) * v
        vec2 project(vec2 v) const {
            return (dot(v) / v.length * v.length) * v;
        }
    };
}

#endif // UNIQ_VEC2_H
