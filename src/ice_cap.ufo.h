#pragma once
#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>
#include "../generated_base_classes.h"

ufo_comment("Non-smart ice cap. Walks off ledges.")
ufo_actor_config("src/ice_cap.ason") ufo_category("STA-Replica")
class IceCap : public ufo::Generated::IceCap_BaseClass{
public:

    ufo::Animation* anim = nullptr;

    IceCap(Vector2f _) : ufo::Generated::IceCap_BaseClass(_){}

    const std::string ANIM_SQUISH = "res/gfx/ice_cap_anim/ice_cap_squish.png";

    ufo_alias("Smart") ufo_variable() bool smart = false;

    ufo_float_slider(-10.0, 10.0, 0.1) float f = -1.0f;

    ufo_variable() std::string name = "";

    ufo_variable() float direction = -1.0f;

    float speed = 48.0f;
    float max_speed = 50.0f;

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

        if(smart) Console::PrintLine("I'm a smart icecap");

        velocity.x = speed * direction;
        anim->scale.x = direction;

    }

    void OnUpdate(const float _delta_time) override{

        Collision(tile_map,SOLID,_delta_time);

        if(hit_wall){
            velocity.x = speed * direction*-1.0f;
            direction*=-1.0f;
            anim->scale.x *= -1.0f;
        }

        if(std::abs(velocity.x) < max_speed) velocity.x += 60.0f*_delta_time*direction;

        if(anim->key == ANIM_SQUISH)
            if(anim->current_frame_index > 1.0f){
                anim->current_frame_index = 1.0f;
            }

        if(/*stepped on by player*/ false){
            anim->SetCostume(ANIM_SQUISH);
        }
    }

};
