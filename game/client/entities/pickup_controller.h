#pragma once

#include <cstdint>
#include <vector>

#include "entity_base.h"

class PickupController : public EntityBase {
    static constexpr int PickpupsCount = 3;

    std::vector<class Pickup*> m_pickups;

public:
    explicit PickupController(Game* game);

    void Tick() override;
};
