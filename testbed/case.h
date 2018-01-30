#ifndef WEAK_PTR_TESTBED_CASE_H
#define WEAK_PTR_TESTBED_CASE_H

#include "render.h"
#include "world.h"

namespace weak_ptr {
    template <typename Real>
    class testbed_case {
        world<Real> world_;
    public:

        testbed_case() = default;

        testbed_case(const testbed_case& other) = delete;

        testbed_case(testbed_case&& other) noexcept = delete;

        testbed_case& operator=(const testbed_case& other) = delete;

        testbed_case& operator=(testbed_case&& other) noexcept = delete;

        virtual ~testbed_case() = default;

    public:
        virtual void setup() =0;

        void render(SDL2pp::Renderer& renderer) {
            weak_ptr::render(renderer, world_.quad_tree_.root);
        }
    };
}

#endif // WEAK_PTR_TESTBED_CASE_H
