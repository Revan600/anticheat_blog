#include "local_player.h"

#include <string>

#include "utils.h"

#include "game.h"

LocalPlayer::LocalPlayer(Game* game)
: EntityBase(game, TypeId<LocalPlayer>::Value),
  m_position({
      static_cast<float>(Game::ScreenWidth) / 2,
      static_cast<float>(Game::ScreenHeight) / 2
  }) {}

void LocalPlayer::Tick() {
    Vector2 movementVector{0.0f, 0.0f};

    if (IsKeyDown(KEY_RIGHT)) movementVector.x = 2.0f;
    if (IsKeyDown(KEY_LEFT)) movementVector.x = -2.0f;
    if (IsKeyDown(KEY_UP)) movementVector.y = -2.0f;
    if (IsKeyDown(KEY_DOWN)) movementVector.y = 2.0f;

    m_position.x += movementVector.x;
    m_position.y += movementVector.y;

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
    const std::string score = "Score: " + std::to_string(*m_score);
    DrawText(score.c_str(), 10, 30, 20, DARKGRAY);

    DrawCircleV(m_position, Radius, MAROON);
}

void LocalPlayer::ConsumePickup(Pickup* pickup) {
    m_score = m_score + 100;
    m_game->DeleteEntity(pickup);
}
