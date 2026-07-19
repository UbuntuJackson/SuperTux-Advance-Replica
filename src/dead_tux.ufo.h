#pragma once
#include <animation.h>
#include <ufo_maths.h>
#include <ufo_macros.h>
#include <camera.h>
#include "sta_save_file.h"

ufo_hide_from_editor()
ufo_actor_config("src/dead_tux.ason")
ufo_category("STA-Replica")
class DeadTux : public ufo::Animation{
public:
    float gravity = 100.0f;
    float vertical_velocity = -200.0f;

    ufo_variable() bool a = false;
    ufo_variable() std::string b = "George";
    ufo_variable() float c = 567.0f;
    ufo_variable() int d = 99;

    DeadTux(Vector2f _) : ufo::Animation(_){

    }

    void OnSpawn(){
        ufo::Animation::OnSpawn();

    }

    void OnUpdate(float _delta_time){

        vertical_velocity += gravity * _delta_time;

        local_position.y += vertical_velocity * _delta_time;

        if(GetGlobalPosition().y > level->size.y && vertical_velocity > 0.0f){
            STASaveFile* save_file = dynamic_cast<STASaveFile*>(engine->save_file.get());
            engine->pending_levels.push_back(save_file->overworld);
            is_dead = true;
        }

    }
};
