#pragma once

#include <cstdint>
#include <raylib.h>

#include <memory/protected_value.h>

#include "entity_base.h"
#include "entities/pickup.h"

class LocalPlayer : public EntityBase {
    Vector2 m_position;
    anticheat::ProtectedValue<int32_t> m_score = 0;

public:
    static constexpr int Radius = 50;

    LocalPlayer(Game* game);

    void Tick() override;

    Vector2& GetPosition() {
        return m_position;
    }

    void ConsumePickup(Pickup* pickup);
};
