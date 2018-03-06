#ifndef UNIQ_VEC2_H
#define UNIQ_VEC2_H

#include "m.h"

namespace uniq {
    template <typename Real>
    struct vec2 {
    public:
        Real x, y, length;

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
