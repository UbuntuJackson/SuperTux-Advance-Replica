#pragma once

#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>
#include <sprite.h>
#include "platformer_rectangle_collision.ufo.h"
#include "../generated_base_classes.h"

ufo_comment("Gives Tux the power to spit fire!")
ufo_actor_config("src/ice_flower.ason")
ufo_category("STA-Replica")
class IceFlower : public custom::PlatformerRectangleCollision{
public:

    const std::string SOLID = "res/gfx/solid.png";

    IceFlower(Vector2f _) : custom::PlatformerRectangleCollision(_){}

    ufo::TileMap* tile_map = nullptr;

    void OnSpawn(){
        custom::PlatformerRectangleCollision::OnSpawn();

        try{
            tile_map = parent->parent->DynamicCast<ufo::TileMap>();
        }
        catch(const std::exception& _error){
            Console::PrintLine("Could not find TileMap");
        }

        get_current_shape = [this](){
            return ufo::Rectangle(GetGlobalPosition() + Vector2f(1.0f, 1.0f),Vector2f(14.0f,14.0f));
        };
    }

    float gravity = 100.0f;

    void OnUpdate(float _delta_time){
        Collision(tile_map, SOLID, _delta_time);

    }



};
