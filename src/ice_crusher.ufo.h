#pragma once
#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>
#include <animation.h>
#include "../generated_base_classes.h"

ufo_comment("IceCrusher.")
ufo_actor_config("src/ice_crusher.ason") ufo_category("STA-Replica")
class IceCrusher : public ufo::Generated::IceCrusher_BaseClass{
public:

    IceCrusher(Vector2f _) : ufo::Generated::IceCrusher_BaseClass(_){}

    ufo::Animation* anim = nullptr;

    ufo::TileMap* tile_map = nullptr;
    const std::string SOLID = "res/gfx/solid.png";

    void OnSpawn(){
        //ufo::Generated::IceCap_BaseClass::OnSpawn();

        try{
            tile_map = parent->parent->DynamicCast<ufo::TileMap>();
        }
        catch(const std::exception& _error){
            Console::PrintLine("Could not find TileMap");
        }



        anim = GetActor("InstanceAnim")->DynamicCast<ufo::Animation>();

    }

    void OnUpdate(const float _delta_time) override{

        Collision(tile_map,SOLID,_delta_time);

    }

};
