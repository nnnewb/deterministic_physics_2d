#ifndef UNIQ_POLYGON_H
#define UNIQ_POLYGON_H

#include "shape.h"

namespace uniq {
    template <typename Real>
    class polygon : public shape<Real> {
        std::vector<vec2<Real>> vertices_;
        aabb<Real> aabb_;

        static aabb<Real> build_aabb(const std::vector<vec2<Real>>& vertices) {
            assert(vertices.size() >= 3);
            vec2<Real> min = vertices[0], max = vertices[0];
            for (auto v : vertices) {
                if (v.x < min.x) min.x = v.x;
                if (v.x > max.x) max.x = v.x;
                if (v.y < min.y) min.y = v.y;
                if (v.y > max.y) max.y = v.y;
            }
            return uniq::aabb<Real>{min, max};
        }

    public:
        explicit polygon(const std::vector<vec2<Real>>& vertices)
            : vertices_(vertices)
            , aabb_(build_aabb(vertices)) { }

        polygon(const polygon& other) = default;

        polygon(polygon&& other) noexcept = default;

        polygon& operator=(const polygon& other) = default;

        polygon& operator=(polygon&& other) noexcept = default;

        ~polygon() override = default;

        aabb<Real> compute_aabb() const override {
            return aabb_;
        }

        const std::vector<vec2<Real>>& compute_vertices() const override {
            return vertices_;
        }

        std::pair<Real, Real> project(vec2<Real> axis) const override {
            // 理论依据是这样的
            // 有向量a和b，夹角为 theta
            //
            // 已知点乘的定义如下
            // dot(a,b) = |a||b|cos theta
            //
            // a到b的投影长度 
            // d = |a|cos theta 
            // 分子分母同时乘上 |b|
            // d = |a||b|cos theta / |b|
            // 简化分子为 dot(a,b)
            // d = dot(a,b)/|b|
            //
            // 对应这个函数就是
            // project(v, axis) = dot(v, axis) / |axis|
            //
            // 多边形投影到某个轴就是挨个计算每个顶点的投影，找出最大和最小。
            //
            Real min = vertices_[0].dot(axis) / axis.length,
                 max = vertices_[0].dot(axis) / axis.length;
            for (const auto& vertex : vertices_) {
                Real result = vertex.dot(axis) / axis.length;
                if (result < min)min = result;
                if (result > max)max = result;
            }
            return {min, max};
        }

        void translate(const transform<Real>& xf) override {
            for (auto& vertex : vertices_) {
                vertex + xf.motion;
                // todo: rotation transform need implement
            }

            // rebuild aabb
            aabb_ = build_aabb(vertices_);
        }
    };
}

#endif // UNIQ_POLYGON_H
