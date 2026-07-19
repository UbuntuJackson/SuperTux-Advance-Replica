#pragma once

#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>

ufo_hide_from_editor()
ufo_comment("Flame effect when fire ball hits things")
ufo_actor_config("src/flame_effect.ason")
ufo_category("STA-Replica")
class FlameEffect : public ufo::Animation{
public:

    FlameEffect(Vector2f _) : ufo::Animation(_){}

    void OnSpawn(){
        ufo::Animation::OnSpawn();

    }

    void OnUpdate(float _delta_time) override{
        ufo::Animation::OnUpdate(_delta_time);

        if(current_frame_index >= number_of_frames-1.0f) is_dead = true;

    }

};
