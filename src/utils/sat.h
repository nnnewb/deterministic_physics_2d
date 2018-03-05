// Seprating-Axis-Theorem
#ifndef WEAK_PTR_SAT_H
#define WEAK_PTR_SAT_H
#include <vector>
#include "vec2.h"

namespace weak_ptr {
    template <typename Real>
    struct projection {
        Real minimum, maximum;

        bool overlap(const projection& proj) {
            return (proj.minimum > minimum && proj.minimum < maximum)
                   || (proj.maximum > minimum && proj.maximum < maximum)
                   || (minimum > proj.minimum && minimum < proj.maximum)
                   || (maximum > proj.minimum && maximum < proj.minimum);
        }
    };

    template <typename Real>
    bool sat_test(polygon<Real>) { }
}
#endif // WEAK_PTR_SAT_H
