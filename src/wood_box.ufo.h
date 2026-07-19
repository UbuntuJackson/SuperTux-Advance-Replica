#pragma once

#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>
#include <sprite.h>

ufo_comment("If you hit this block, you get an item!")
ufo_actor_config("src/wood_box.ason")
ufo_category("STA-Replica")
class WoodBox : public ufo::Sprite{
public:

    std::string item;

    WoodBox(Vector2f _) : Sprite(_, "", Vector2f(0.0f, 0.0f),Vector2f(100.0f, 100.0f), Vector2f(1.0f, 1.0f), 0.0f, 0.0f){}

    void OnSpawn(){
        ufo::Sprite::OnSpawn();

        ufo::TileMap* solid_map = parent->parent->DynamicCast<ufo::TileMap>();

        int tile_map_x = int(local_position.x)/solid_map->tile_width;
        int tile_map_y = int(local_position.y)/solid_map->tile_height;

        ufo::TilesetData data = level->tileset_manager.GetTilesetData("res/gfx/solid.png");

        solid_map->tilemap_data[tile_map_y*solid_map->number_of_columns+tile_map_x] = data.tileset_start_id;

    }

    void OnHit(){

        //

    }

};
