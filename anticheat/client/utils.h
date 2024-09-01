#pragma once

#include <random>

__forceinline float RandomFloat(const float a, const float b) {
    const float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    const float diff = b - a;
    const float r = random * diff;
    return a + r;
}

class TypeIdStorage {
public:
    static int GetNextId() {
        static int counter = 0;
        return ++counter;
    }
};

template <typename T>
struct TypeId {
    static inline int Value = TypeIdStorage::GetNextId();
};
