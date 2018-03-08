#ifndef UNIQ_M_H
#define UNIQ_M_H

#include <cmath>

namespace uniq {
    namespace math {

        inline auto abs(float val) -> decltype(std::abs(val)) {
            return std::abs(val);
        }

        inline auto abs(double val) -> decltype(std::abs(val)) {
            return std::abs(val);
        }

        inline auto abs(short val) -> decltype(std::abs(val)) {
            return std::abs(val);
        }

        inline auto abs(int val) -> decltype(std::abs(val)) {
            return std::abs(val);
        }

        inline auto abs(long val) -> decltype(std::abs(val)) {
            return std::abs(val);
        }

        inline auto abs(long long val) -> decltype(std::abs(val)) {
            return std::abs(val);
        }

        template <typename Real>
        bool contains(Real val, Real min, Real max) {
            return val > min && val < max;
        }

        template <typename Real>
        bool overlap(Real min1, Real max1, Real min2, Real max2) {
            return contains(min1, min2, max2) || contains(min2, min1, max1);
        }

        template <typename Real>
        Real cover(Real min1, Real max1, Real min2, Real max2) {
            if (overlap(min1, max1, min2, max2)) {
                return abs(min1 - min2);
            }
            return 0;
        }

        inline auto sqrt(float f) -> decltype(std::sqrt(f)) {
            return std::sqrt(f);
        }

        inline auto sqrt(double f) -> decltype(std::sqrt(f)) {
            return std::sqrt(f);
        }

        inline auto sqrt(short f) -> decltype(std::sqrt(f)) {
            return std::sqrt(f);
        }

        inline auto sqrt(int f) -> decltype(std::sqrt(f)) {
            return std::sqrt(f);
        }

        inline auto sqrt(long f) -> decltype(std::sqrt(f)) {
            return std::sqrt(f);
        }

        inline auto sqrt(long long f) -> decltype(std::sqrt(f)) {
            return std::sqrt(f);
        }

        inline auto hypot(float x, float y) -> decltype(std::hypot(x, y)) {
            return std::hypot(x, y);
        }

        inline auto hypot(double x, double y) -> decltype(std::hypot(x, y)) {
            return std::hypot(x, y);
        }

        inline auto hypot(short x, short y) -> decltype(std::hypot(x, y)) {
            return std::hypot(x, y);
        }

        inline auto hypot(int x, int y) -> decltype(std::hypot(x, y)) {
            return std::hypot(x, y);
        }

        inline auto hypot(long x, long y) -> decltype(std::hypot(x, y)) {
            return std::hypot(x, y);
        }

        inline auto hypot(long long x, long long y) -> decltype(std::hypot(x, y)) {
            return std::hypot(x, y);
        }
    }
}

#endif // UNIQ_M_H
