#pragma once

#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>

ufo_comment("1 Coin")
ufo_actor_config("src/coin.ason")
ufo_category("STA-Replica")
class Coin : public ufo::Animation{
public:

    bool taken = false;

    Coin(Vector2f _) : ufo::Animation(_){}

    void OnSpawn(){
        ufo::Animation::OnSpawn();
    }



};
