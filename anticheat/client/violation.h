#pragma once

namespace anticheat {
    enum class ViolationType {
        None = 0,
        ProtectedValue = 1
    };

    struct Violation {
        ViolationType Type = ViolationType::None;
        const void* Data = nullptr;
    };
}
