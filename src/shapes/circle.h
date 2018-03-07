#ifndef UNIQ_CIRCLE_H
#define UNIQ_CIRCLE_H

#include <vector>
#include "shape.h"
#include "aabb.h"
#include "transform.h"

namespace uniq {
    template <typename Real>
    class circle : public shape<Real> {
        vec2<Real> center_;
        Real radius_;
        aabb<Real> aabb_;
        std::vector<vec2<Real>> vertices_;

    public:
        circle(vec2<Real> circle_center, Real circle_radius)
            : center_(circle_center)
            , radius_(circle_radius)
            , aabb_(center_ - vec2<Real>(radius_, radius_), center_ + vec2<Real>(radius_, radius_)) {
            vertices_.emplace_back(center_);
        }

        circle(const circle& other) = default;

        circle(circle&& other) noexcept = default;

        circle& operator=(const circle& other) = default;

        circle& operator=(circle&& other) noexcept = default;

        ~circle() override = default;

        vec2<Real> center() const {
            return center_;
        }

        Real radius() const {
            return radius_;
        }

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
            Real min = center_.dot(axis) / axis.length - radius_,
                 max = center_.dot(axis) / axis.length + radius_;
            return {min, max};
        }

        void translate(const transform<Real>& xf) override {
            center_ += xf.motion;
            // todo: rotation transform need implement
            // rebuild aabb
            aabb_ = {
                center_ - vec2<Real>(radius_, radius_),
                center_ + vec2<Real>(radius_, radius_)
            };
        }
    };
}

#endif // UNIQ_CIRCLE_H
