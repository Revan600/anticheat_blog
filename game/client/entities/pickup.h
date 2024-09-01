#pragma once

#include <raylib.h>

#include "entity_base.h"

class Pickup : public EntityBase {
    Vector2 m_position;
public:
    static constexpr int Radius = 5;

    explicit Pickup(Game* game, const Vector2& position);

    float DistanceTo(const Vector2& pos) const;

    void Tick() override;
};
