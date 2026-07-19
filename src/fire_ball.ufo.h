#pragma once

#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>
#include <level.h>
#include <collision_grid.h>
#include "platformer_rectangle_collision.ufo.h"

ufo_hide_from_editor()
ufo_comment("The fireball that tux spawns when fire powerup")
ufo_actor_config("src/fire_ball.ason")
ufo_category("STA-Replica") class FireBall : public custom::PlatformerRectangleCollision{
public:

    const std::string SOLID = "res/gfx/solid.png";

    FireBall(Vector2f _);

    ufo::TileMap* tile_map = nullptr;
    ufo::CollisionGrid* collision_grid = nullptr;

    float direction = 1.0f;

    void OnSpawn() override;

    void OnUpdate(float _delta_time) override;

};
