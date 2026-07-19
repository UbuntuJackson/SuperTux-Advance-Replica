#pragma once

#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>

ufo_hide_from_editor()
ufo_comment("The effect that plays when Tux gets a power-up")
ufo_actor_config("src/power_up_effect.ason")
ufo_category("STA-Replica")
class PowerUpEffect : public ufo::Animation{
public:

    PowerUpEffect(Vector2f _) : ufo::Animation(_){}
private:

    void OnUpdate(float _delta_time) override{
        ufo::Animation::OnUpdate(_delta_time);

        if(current_frame_index >= number_of_frames-1.0f) is_dead = true;

    }

};
