#include "pickup.h"
#include "utils.h"

Pickup::Pickup(Game* game, const Vector2& position)
: m_position(position), EntityBase(game, TypeId<Pickup>::Value) {}

float Pickup::DistanceTo(const Vector2& pos) const {
    return fabsf(pos.x - m_position.x) + fabsf(pos.y - m_position.y);
}

void Pickup::Tick() {
    DrawCircleV(m_position, Radius, DARKBLUE);
}
