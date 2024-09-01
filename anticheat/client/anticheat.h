#pragma once

#include "violation.h"

namespace anticheat {
    using ViolationCallback = void(*)(Violation*);

    void Init(ViolationCallback Callback);

    void Report(Violation& Violation);
}
