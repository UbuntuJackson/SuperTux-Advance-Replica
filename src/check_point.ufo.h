#pragma once

#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>

ufo_comment("A checkpoint, you respawn here when you die.")
ufo_actor_config("src/check_point.ason")
ufo_category("STA-Replica")
class CheckPoint : public ufo::Animation{
public:

    CheckPoint(Vector2f _) : ufo::Animation(_){}

    void OnSpawn(){
        ufo::Animation::OnSpawn();
    }

};
