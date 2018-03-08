#ifndef UNIQ_POLYGON_EDGE_ITER_H
#define UNIQ_POLYGON_EDGE_ITER_H
#include <vector>
#include "vec2.h"

namespace uniq {
    template <typename Real>
    class polygon_edge_iterator : public std::iterator<std::input_iterator_tag, struct vec2<Real>> {
        using vertex_iter = typename std::vector<vec2<Real>>::const_iterator;
        const std::vector<vec2<Real>>& vertices_array_;
        vertex_iter cur_;
        vec2<Real> cur_edge_{0, 0};

        void calculate_cur_edge() {
            if (cur_ != vertices_array_.end()) {
                if (cur_ + 1 == vertices_array_.end()) {
                    // the last edge, last vertex connect to first vertex
                    cur_edge_ = (vertices_array_.front()) - (*cur_);
                } else {
                    // current vertex connect to next vertex
                    cur_edge_ = (*cur_) - (*(cur_ + 1));
                }
            }
        }

    public:
        polygon_edge_iterator() = default;

        explicit polygon_edge_iterator(const std::vector<vec2<Real>>& vertices)
            : vertices_array_(vertices)
            , cur_(vertices_array_.begin()) {
            calculate_cur_edge();
        }

        explicit polygon_edge_iterator(const std::vector<vec2<Real>>& vertices,
                                       typename std::vector<vec2<Real>>::const_iterator iter)
            : vertices_array_(vertices)
            , cur_(iter) {
            calculate_cur_edge();
        }

        const vec2<Real>& operator*() const {
            assert(cur_ != vertices_array_.end());
            // if iterator pointer last element of vertices container
            return cur_edge_;
        }

        const vec2<Real>* operator->() const {
            return &cur_edge_;
        }

        const polygon_edge_iterator& operator++(int) {
            auto ret = *this;
            ++cur_;
            calculate_cur_edge();
            return ret;
        }

        const polygon_edge_iterator& operator++() {
            ++cur_;
            calculate_cur_edge();
            return *this;
        }

        bool operator==(const polygon_edge_iterator& rhs) const {
            return cur_ == rhs.cur_;
        }

        bool operator!=(const polygon_edge_iterator& rhs) const {
            return !((*this) == rhs);
        }
    };
}

#endif // UNIQ_POLYGON_EDGE_ITER_H
