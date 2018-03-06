#ifndef UNIQ_M_H
#define UNIQ_M_H

#include <cmath>

namespace uniq {
    namespace math {
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
