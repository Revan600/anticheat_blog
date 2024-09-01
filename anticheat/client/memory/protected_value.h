#pragma once

#include "violation.h"
#include "anticheat.h"
#include "utils.h"

namespace anticheat {
    // replace 0xDEADBEEF with compile-time random
    template <typename TValue, TValue Shift = sizeof(TValue) / 2, TValue Key = 0xDEADBEEF>
    class ProtectedValue {
        TValue m_value{};
        TValue m_crc{};

    public:
        ProtectedValue() {}

        ProtectedValue(const TValue& value) : m_value(value ^ Key) {
            m_crc = m_value << Shift | m_value >> Shift;
        }

        __forceinline operator TValue() {
            EnsureIntegrity();

            return TValue(m_value ^ Key);
        }

        __forceinline ProtectedValue& operator=(const TValue& value) {
            EnsureIntegrity();

            m_value = value ^ Key;
            m_crc = m_value << Shift | m_value >> Shift;

            return *this;
        }

        __forceinline TValue operator*() {
            EnsureIntegrity();

            return m_value ^ Key;
        }

    private:
        __forceinline void EnsureIntegrity() const {
            if ((m_value << Shift | m_value >> Shift) != m_crc) {
                Violation violation;
                violation.Type = ViolationType::ProtectedValue;
                violation.Data = static_cast<const void*>(this);

                Report(violation);
            }
        }
    };
}
