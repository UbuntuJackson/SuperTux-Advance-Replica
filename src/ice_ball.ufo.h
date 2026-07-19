#pragma once
#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>
#include <level.h>
#include <collision_grid.h>
#include "platformer_rectangle_collision.ufo.h"

ufo_comment("The iceball that tux spawns when ice powerup")
ufo_actor_config("src/ice_ball.ason")
ufo_category("STA-Replica") class IceBall : public custom::PlatformerRectangleCollision{
public:

    const std::string SOLID = "res/gfx/solid.png";

    IceBall(Vector2f _);

    ufo::TileMap* tile_map = nullptr;
    ufo::CollisionGrid* collision_grid = nullptr;

    float direction = 1.0f;

    void OnSpawn() override;

    void OnUpdate(float _delta_time) override;

};
