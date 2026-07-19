#pragma once

#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>
#include <level.h>

ufo_comment("Custom TileMap class")
ufo_actor_config("src/sta_tile_map.ason")
ufo_category("STA-Replica") class STA_TileMap : public ufo::TileMap{
public:
    STA_TileMap(Vector2f _) : ufo::TileMap(_){}

private:
    void OnSpawn() override{

    }
};
