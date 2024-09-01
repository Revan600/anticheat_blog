#include "pickup_controller.h"

#include "game.h"
#include "entities/local_player.h"
#include "entities/pickup.h"

#include "utils.h"

PickupController::PickupController(Game* game)
: EntityBase(game, TypeId<PickupController>::Value) {}

void PickupController::Tick() {
    m_pickups.clear();

    m_game->FindEntitiesOfType(m_pickups);

    if (m_pickups.size() < PickpupsCount) {
        auto px = RandomFloat(0.0f, Game::ScreenWidth);
        auto py = RandomFloat(0.0f, Game::ScreenHeight);
        Vector2 pos{px, py};

        m_pickups.push_back(m_game->AddEntity<Pickup>(pos));
    }

    auto* player = m_game->FindEntityOfType<LocalPlayer>();

    for (auto* pickup : m_pickups) {
        auto distance = pickup->DistanceTo(player->GetPosition());

        if (distance > LocalPlayer::Radius) {
            continue;
        }

        player->ConsumePickup(pickup);
    }
}
