#pragma once

#include <ufo_macros.h>
#include <ufo_maths.h>
#include <tile_map.h>
#include <camera.h>
#include <animation.h>
#include <level.h>
#include <engine.h>
#include <control_settings.h>
#include "world_map_level.ufo.h"

ufo_comment("Player represented on the worldmap")
ufo_category("STA-Replica") ufo_actor_config("src/player_overworld.ason")
class PlayerOverworld : public ufo::Actor{
public:
    PlayerOverworld(Vector2f _) : ufo::Actor(_){}

private:

    ufo::TileMap* paths_tile_map = nullptr;
    ufo::Camera* camera = nullptr;
    ufo::CollisionGrid* collision_grid = nullptr;
    ufo::Controls* controls = nullptr;
    ufo::Animation* animation = nullptr;

    void OnSpawn(){
        paths_tile_map = parent->parent->DynamicCast<ufo::TileMap>();
        camera = GetActor("InstCamera")->DynamicCast<ufo::Camera>();
        collision_grid = parent->DynamicCast<ufo::CollisionGrid>();
        controls = level->GetControls();
        animation = GetActor("InstAnim")->DynamicCast<ufo::Animation>();

        local_position+=Vector2f(8.0f, 8.0f);

        //Console::PrintLine(ufo::Maths::RotateVector(Vector2f(0.0f, 1.0f), ufo::Maths::PI/2.0f));
    }

    const Vector2i DIRECTION_RIGHT = Vector2i(1, 0);
    const Vector2i DIRECTION_LEFT = Vector2i(-1, 0);
    const Vector2i DIRECTION_UP = Vector2i(0, -1);
    const Vector2i DIRECTION_DOWN = Vector2i(0, 1);
    const Vector2i DIRECTION_NONE = Vector2i(0, 0);
    const Vector2i UNDECIDED = Vector2i(0, 0);

    Vector2i direction = DIRECTION_NONE;
    Vector2i last_direction = DIRECTION_NONE;

    float speed = 100.0f;

    bool hit_level = false;

    const float ANGLE_90_DEGREES = ufo::Maths::PI/2.0f;

    void OnUpdate(float _delta_time) override {
        camera->local_position = Vector2f(8.0f, 8.0f);

        const Vector2f path_detecting_position = Vector2f(9.5f, 9.5f);
        const Vector2f centre_of_tile = Vector2f(8.0f,8.0f);

        bool already_hit_level = hit_level;
        hit_level = false;

        WorldMapLevel* world_map_level = nullptr;

        int index = collision_grid->GetDivisionFromPosition(local_position);
        if(index != ufo::CollisionGrid::Errors::OUT_OF_BOUNDS){
            std::vector<Actor*>& nearby_actors = collision_grid->divisions[index];
            for(Actor* actor : nearby_actors){
                if(actor != this){
                    if(ufo::Maths::Distance2(local_position, actor->local_position+centre_of_tile) < 9.0f){
                        hit_level = true;
                    }

                    world_map_level = actor->DynamicCast<WorldMapLevel>();

                    if(hit_level && engine->keyboard.GetKey(SDLK_RETURN).is_pressed){

                        engine->GoToLevel(world_map_level->level_path);
                        return;
                    }
                }
            }

            //if(nearby_actors.size() != 0) Console::PrintLine("Nearby actors:", nearby_actors.size());

        }

        if(hit_level) Console::PrintLine("Hit Level");
        else Console::PrintLine("Did not hit Level");

        Vector2f relevant_position = local_position;

        Vector2f current_tile;
        current_tile.x = std::floor(relevant_position.x/16.0f);
        current_tile.y = std::floor(relevant_position.y/16.0f);

        Vector2f tile_check_position = current_tile*16.0f+centre_of_tile;

        //Input

        Vector2i direction_from_input = DIRECTION_NONE;

        if(engine->keyboard.GetKey(controls->GetControl("right")).is_held){
            direction_from_input = DIRECTION_RIGHT;
        }
        if(engine->keyboard.GetKey(controls->GetControl("left")).is_held){
            direction_from_input = DIRECTION_LEFT;
        }
        if(engine->keyboard.GetKey(controls->GetControl("up")).is_held){
            direction_from_input = DIRECTION_UP;
        }
        if(engine->keyboard.GetKey(controls->GetControl("down")).is_held){
            direction_from_input = DIRECTION_DOWN;
        }

        int tile_ahead_for_direction_from_input = paths_tile_map->GetTileID_AtLevelPosition(
            tile_check_position+  direction_from_input *path_detecting_position
        );

        //if(tile_ahead_for_direction_from_input) Console::PrintLine(tile_ahead_for_direction_from_input);

        if(!tile_ahead_for_direction_from_input){
            //direction = DIRECTION_NONE;
            //Console::PrintLine("direction set to DIRECTION_NONE");
        }
        else if(direction_from_input != DIRECTION_NONE){
            if(hit_level){
                if((!world_map_level->cleared && direction_from_input != last_direction) || world_map_level->cleared){
                    direction = direction_from_input;
                }
            }
            else{

                direction = direction_from_input;

            }
            //Console::PrintLine("direction set",direction);
        }

        const Vector2i DIRECTION_RIGHT_HAND_SIDE = ufo::Maths::RotateVector(direction, -ANGLE_90_DEGREES);
        const Vector2i DIRECTION_LEFT_HAND_SIDE =  ufo::Maths::RotateVector(direction,  ANGLE_90_DEGREES);

        bool passed_middle = false;

        if(direction == DIRECTION_RIGHT){

            if(relevant_position.x + direction.x*speed*_delta_time > tile_check_position.x &&
               relevant_position.x                                 < tile_check_position.x
            ){
                local_position = tile_check_position;
                passed_middle = true;
                Console::PrintLine("Right");
            }
        }
        if(direction == DIRECTION_LEFT){
            if(relevant_position.x + direction.x*speed*_delta_time < tile_check_position.x &&
               relevant_position.x                                 > tile_check_position.x
            ){

                local_position = tile_check_position;
                passed_middle = true;
                Console::PrintLine("Left");
            }
        }
        if(direction == DIRECTION_UP){
            if(relevant_position.y + direction.y*speed*_delta_time < tile_check_position.y &&
               relevant_position.y                                 > tile_check_position.y
            ){
                local_position = tile_check_position;
                passed_middle = true;
                Console::PrintLine("Up");

            }
        }
        if(direction == DIRECTION_DOWN){
            if(relevant_position.y + direction.y*speed*_delta_time > tile_check_position.y &&
               relevant_position.y                                 < tile_check_position.y
            ){
                local_position = tile_check_position;
                Console::PrintLine("Down");
                passed_middle = true;
            }
        }

        if(passed_middle){
            Console::PrintLine("local position",local_position);

            int tile_ahead =              paths_tile_map->GetTileID_AtLevelPosition(local_position+direction *               path_detecting_position);
            int tile_to_right_hand_side = paths_tile_map->GetTileID_AtLevelPosition(local_position+DIRECTION_RIGHT_HAND_SIDE*path_detecting_position);
            int tile_to_left_hand_side =  paths_tile_map->GetTileID_AtLevelPosition(local_position+DIRECTION_LEFT_HAND_SIDE *path_detecting_position);

            int tile_in_directions[] = {tile_to_left_hand_side, tile_to_right_hand_side, tile_ahead};

            int number_of_available_directions = 0;

            for(int i : tile_in_directions){
                if(i != 0) number_of_available_directions++;
            }

            if(number_of_available_directions != 1 || (hit_level)){

                last_direction = direction;
                direction = DIRECTION_NONE;

            }
            else{
                if(tile_to_left_hand_side)  direction = DIRECTION_LEFT_HAND_SIDE;
                if(tile_to_right_hand_side) direction = DIRECTION_RIGHT_HAND_SIDE;

            }
        }

        Console::PrintLine("direction",direction);

        local_position += speed * (Vector2f)direction * _delta_time;

    }
};
