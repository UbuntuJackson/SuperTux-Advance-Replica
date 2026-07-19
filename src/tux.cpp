#include <string>
#include <camera.h>
#include <ufo_maths.h>
#include <console.h>
#include <tile_map.h>
#include <animation.h>
#include <control_settings.h>
#include <functional>
#include <collision_grid.h>
#include "platformer_rectangle_collision.ufo.h"
#include "check_point.ufo.h"
#include "level_transition_trigger.ufo.h"
#include <ufo_benchmarker.h>
#include "tux.ufo.h"
#include "pause_menu.ufo.h"
#include "../generated.h"
#include "level_transition_trigger.ufo.h"

Tux::Tux(Vector2f _) : custom::PlatformerRectangleCollision(_){}

void Tux::OnSpawn(){

    custom::PlatformerRectangleCollision::OnSpawn();

    gravity *= 2.583f;

    //speed_loss_by_slope = 0.0f;

    Console::PrintLine("Tux Spawned");

    //Fetch components and miscellaneous level objects

    try{
        tile_map = parent->parent->DynamicCast<ufo::TileMap>();
    }
    catch(const std::exception& _error){
        Console::PrintLine("Could not find TileMap");
    }

    try{
        collision_grid = parent->DynamicCast<ufo::CollisionGrid>();
    }
    catch(const std::exception& _error){
        Console::PrintLine("Could not find InstCollisionGrid");
    }

    camera = GetActor("InstanceCamera");

    animation = GetActor("InstanceAnimation")->DynamicCast<ufo::Animation>();

    controls = level->GetControls();
    if(!controls) Console::PrintLine("Error, no controls object found");

    //Other stuff

    get_standing_shape = [this](){
        return ufo::Rectangle(GetGlobalPosition() + Vector2f(8.0f-16.0f,8.0f-18.0f),size);
    };

    get_crawling_shape = [this](){
        return ufo::Rectangle(GetGlobalPosition() + Vector2f(8.0f-16.0f-2.0f,8.0f-18.0f+10.0f),Vector2f(24.0f,14.0f));
    };

    get_current_shape = get_standing_shape;

}

void Tux::OnUpdate(float _delta_time){
    Console::Print("Tux dt:",1.0f/_delta_time,"\n");

    //Experimenting with normals

    /*auto result = GetTileCollisionRayCast(tile_map, SOLID, ufo::Ray2(GetGlobalPosition()+GetRectangle().size/2.0f,GetGlobalPosition()+GetRectangle().size/2.0f+velocity));

    if(result.is_hit){
        Console::PrintLine("ct",result.intersection_point);
    }*/

    Vector2f towards_player = (GetGlobalPosition()-camera->GetGlobalPosition()+original_camera_position)*1.5f;

    camera->local_position += towards_player*1.0f*_delta_time*Vector2f(1.0f, 10.0f);
    camera->local_position += (local_position-former_local_position)*_delta_time*16.0f;

    if(tux_died) return;

    if(level_cleared){
        InactiveUpdate(_delta_time);
        return;
    }

    //ufoBenchMarker u;

    int index = collision_grid->GetDivisionFromPosition(local_position);
    if(index != ufo::CollisionGrid::Errors::OUT_OF_BOUNDS){
        std::vector<Actor*>& nearby_actors = collision_grid->divisions[index];
        for(Actor* actor : nearby_actors){
            if(actor == this) continue;
            if(actor->class_name == "Coin"){
                if(ufo::Maths::RectangleVsCircle(GetRectangle(), ufo::Circle(actor->local_position+Vector2f(8.0f, 8.0f), 8.0f))){

                    actor->is_dead = true;
                }
            }
            else if(actor->class_name == "FireFlower"){
                if(ufo::Maths::RectangleVsCircle(GetRectangle(), ufo::Circle(actor->local_position+Vector2f(8.0f, 8.0f), 8.0f))){

                    actor->is_dead = true;
                    SetPowerUp(PowerUps::POWER_UP_FIRE);
                    animation->key = animations_fire_tux[current_costume];
                    AddActorUniquePtr(ufo::Generated::SpawnPowerUpEffect(Vector2f(0.0f, 0.0f)));
                }
            }
            else if(actor->class_name == "IceFlower"){
                if(ufo::Maths::RectangleVsCircle(GetRectangle(), ufo::Circle(actor->local_position+Vector2f(8.0f, 8.0f), 8.0f))){

                    actor->is_dead = true;
                    SetPowerUp(PowerUps::POWER_UP_ICE);
                    animation->key = animations_ice_tux[current_costume];
                    AddActorUniquePtr(ufo::Generated::SpawnPowerUpEffect(Vector2f(0.0f, 0.0f)));
                }
            }
            else if(actor->class_name == "CheckPoint"){
                if(ufo::Maths::RectangleVsCircle(GetRectangle(), ufo::Circle(actor->local_position+Vector2f(8.0f, 8.0f), 8.0f))){
                    auto check_point = actor->DynamicCast<CheckPoint>();
                    check_point->preview = true;
                }
            }
            else if(actor->class_name == "test::LevelTransitionTrigger"){
                if(ufo::Maths::RectangleVsCircle(GetRectangle(), ufo::Circle(actor->local_position+Vector2f(8.0f, 8.0f), 8.0f))){
                    auto trigger = actor->DynamicCast<test::LevelTransitionTrigger>();
                    trigger->timer.Start(3000.0f);
                    level_cleared = true;
                    Console::PrintLine("trigger->level_path");
                }
            }
            else if(actor->class_name == "LevelGoalTrigger"){
                auto trigger = actor->DynamicCast<LevelGoalTrigger>();
                if(ufo::Maths::RectangleVsRectangle(GetRectangle(), trigger->GetRectangle())){

                    trigger->timer.Start(3000.0f);
                    level_cleared = true;
                    Console::PrintLine("trigger->level_path");
                }
            }
        }
    }

    //For comparison purposes
    /*for(const auto& actor : parent->actors){
        if(actor.get() == this) continue;
        if(actor->class_name == "Coin"){
            if(ufoMaths::RectangleVsCircle(GetRectangle(), Circle(actor->local_position, 8.0f))){

                actor->is_dead = true;
            }
        }
        }*/

    //Console::Print(u.Stop(),"\n");

    ActiveUpdate(_delta_time);
}

void Tux::ActiveUpdate(float _delta_time){

    if(engine->keyboard.GetKey(SDLK_ESCAPE).is_pressed){
        //Really need to have some sort of more sophisticated spawn function

        level->AddActorUniquePtr(ufo::Generated::SpawnPauseMenu(Vector2f(200.0f, 200.0f)));

		level->is_paused = true;
    }

    if(state != States::SLIDE) dir_x = int(engine->keyboard.GetKey(controls->GetControl("right")).is_held) - int(engine->keyboard.GetKey(controls->GetControl("left")).is_held);

    if(state != States::SLIDE) if((std::abs(velocity.x) < max_speed_walk) || engine->keyboard.GetKey(controls->GetControl("run")).is_held && std::abs(velocity.x) < max_speed_run) velocity.x += dir_x * horizontal_acceleration * _delta_time;

    float former_x_velocity = velocity.x;

    if(hit_floor){
        if(state != States::SLIDE) velocity.x -= ufo::Maths::PreciseSignFloat(velocity.x) * _delta_time * friction;
        else velocity.x -= ufo::Maths::PreciseSignFloat(velocity.x) * _delta_time * friction*0.5f;
    }
    else if(state != States::SLIDE) velocity.x -= ufo::Maths::PreciseSignFloat(velocity.x) * _delta_time * friction*0.7f;

    if(former_x_velocity * velocity.x < 0.0f) velocity.x = 0.0f;

    Collision(tile_map,SOLID,_delta_time);

    //Animation related code.

    //Run or stay idle?
    if(hit_floor && state == States::RUN){
        if(std::abs(velocity.x) < 0.1f){
            if(current_costume != ANIMATION_IDLE) SetCostume(ANIMATION_IDLE);

        }
        else{

            //If acceleration is the opposite sign of the velocity, then Tux is trying to stop or change direction.
            //Maybe increase acceleration for this case?
            if(velocity.x * dir_x < 0.0f && std::abs(velocity.x) > 50.0f && hit_floor){
                if(current_costume != ANIMATION_BREAK) SetCostume(ANIMATION_BREAK);
                animation->current_frame_index = 0.0f;

            }

            if(!(velocity.x * dir_x < 0.0f && std::abs(velocity.x) > 50.0f && hit_floor)){
                if(current_costume != ANIMATION_RUN) SetCostume(ANIMATION_RUN);
            }

            if(current_costume != ANIMATION_BREAK){
                if(std::abs(velocity.x) >= 0.1f){
                    if(current_costume != ANIMATION_RUN) SetCostume(ANIMATION_RUN);
                }

                if(current_costume == ANIMATION_RUN){
                    if(power_up != PowerUps::POWER_UP_ICE) animation->animation_speed = std::abs(velocity.x) * 0.2f;
                    else animation->animation_speed = std::abs(velocity.x) * 0.07f;
                }
            }
        }
    }

    if(state == States::RUN){
        //Controlling jump and fall animation.
        if(velocity.y < 0.0f && !hit_floor){
            if(current_costume != ANIMATION_JUMP){
                SetCostume(ANIMATION_JUMP);
            }
            else{
                if(animation->current_frame_index > 1.0f) animation->current_frame_index = 1.0f;
            }
        }
        if(velocity.y > 0.0f && !hit_floor){

            if(current_costume != ANIMATION_FALL){
                SetCostume(ANIMATION_FALL);
            }
            else{
                if(animation->current_frame_index > 3.0f) animation->current_frame_index = 3.0f;
            }
        }
    }

    if(std::abs(velocity.x) > 0.01f && velocity.x != 0.0f) face_direction = ufo::Maths::PreciseSignFloat(velocity.x);

    if(engine->keyboard.GetKey(SDLK_X).is_pressed){
        if(power_up == PowerUps::POWER_UP_FIRE){
            auto fire_ball = ufo::Generated::SpawnFireBall(GetGlobalPosition());

            fire_ball->velocity.x = velocity.x + face_direction*120.0f;
            fire_ball->direction = face_direction;

            collision_grid->AddActorUniquePtr(std::move(fire_ball));
        }
        else if(power_up == PowerUps::POWER_UP_ICE){

        }
    }

    if(engine->keyboard.GetKey(controls->GetControl("down")).is_pressed && hit_floor){
        float how_far_in_front_to_check = 8.0f;

        if(velocity.x*_delta_time > how_far_in_front_to_check) how_far_in_front_to_check = velocity.x*_delta_time;

        Vector2f slope_check_position_right = GetRectangle().position + Vector2f(how_far_in_front_to_check, 1.0f);
        bool place_free_right = GetTileCollisionData(tile_map,SOLID,ufo::Rectangle(slope_check_position_right, GetRectangle().size)).place_free;

        Vector2f slope_check_position_left = GetRectangle().position + Vector2f(-how_far_in_front_to_check, 1.0f);
        bool place_free_left = GetTileCollisionData(tile_map,SOLID,ufo::Rectangle(slope_check_position_left, GetRectangle().size)).place_free;

        if(std::abs(velocity.x) > 5.0f || place_free_right || place_free_left){
            state = States::SLIDE;

            float slide_direction = 0.0f;
            if(place_free_right) velocity.x += 60.0f*face_direction;
            if(place_free_left) velocity.x -= 60.0f*face_direction;
            SetCostume(ANIMATION_SLIDE);
        }
        else{
            state = States::CRAWL;
            velocity.x = 10.0f*face_direction;
            SetCostume(ANIMATION_CRAWL);
        }

        if(GetTileCollisionData(tile_map,SOLID,get_crawling_shape()).place_free){
            get_current_shape = get_crawling_shape;
        }
    }

    if((state == States::SLIDE || state == States::CRAWL) && !engine->keyboard.GetKey(controls->GetControl("down")).is_held){
        if(GetTileCollisionData(tile_map,SOLID,get_standing_shape()).place_free){
            get_current_shape = get_standing_shape;
            state = States::RUN;
        }
    }

    if((state == States::SLIDE) && (hit_floor)){

        float how_far_in_front_to_check = 8.0f;

        if(velocity.x*_delta_time > how_far_in_front_to_check) how_far_in_front_to_check = velocity.x*_delta_time;

        Vector2f slope_check_position_right = GetRectangle().position + Vector2f(how_far_in_front_to_check, 1.0f);
        bool place_free_right = GetTileCollisionData(tile_map,SOLID,ufo::Rectangle(slope_check_position_right, GetRectangle().size)).place_free;

        Vector2f slope_check_position_left = GetRectangle().position + Vector2f(-how_far_in_front_to_check, 1.0f);
        bool place_free_left = GetTileCollisionData(tile_map,SOLID,ufo::Rectangle(slope_check_position_left, GetRectangle().size)).place_free;

        if(place_free_right){
            velocity.x += 450.0f*_delta_time;
        }
        if(place_free_left){
            velocity.x += -450.0f*_delta_time;
        }

    }

    animation->scale.x = face_direction;

    if(hit_wall && !hit_floor && dir_x != 0 && velocity.y >= 0.0f){
        SetCostume(ANIMATION_WALL_JUMP);
        //animation->frame_counter = 0.0f;
        animation->scale.x = -dir_x;
        velocity.y = 40.0f;
    }

    //Jump logic. Causiously changing y velocity here.

    if((engine->keyboard.GetKey(controls->GetControl("jump")).is_pressed && hit_floor) || (will_jump && hit_floor)){
        velocity.y = -jump_velocity;
        jumped = true;
    }

    if(velocity.y < 0.0f && engine->keyboard.GetKey(controls->GetControl("jump")).is_released){
        velocity.y /= 2.6f;
    }

    if(engine->keyboard.GetKey(controls->GetControl("jump")).is_pressed && hit_wall && !hit_floor){
        velocity.x = -dir_x * 150.0f;
        velocity.y = -jump_velocity*0.9f;
        SetCostume(ANIMATION_JUMP);
        //animation->frame_counter = 1.0f;
        animation->scale.x = -dir_x;
        wall_kicked = true;
    }

    //Coyote jump
    will_jump = false;
    Vector2f coyote_jump_check_position = GetRectangle().position;
    will_jump = !(GetTileCollisionData(tile_map,SOLID,ufo::Rectangle(coyote_jump_check_position, GetRectangle().size+Vector2f(0.0f,12.0f))).place_free) && engine->keyboard.GetKey(controls->GetControl("jump")).is_pressed;

    //if(jumped) AssetManager::Get().PlayAudio("jump", false);
    jumped = false;
    //if(wall_kicked) AssetManager::Get().PlayAudio("wallkick", false);
    wall_kicked = false;
    //if(did_slide) AssetManager::Get().PlayAudio("slide", false);
    did_slide = false;

    //Fell out of level
    if(local_position.y > level->size.y+16.0f) Die();
}

void Tux::InactiveUpdate(float _delta_time){

    float former_x_velocity = velocity.x;

    velocity.x -= ufo::Maths::PreciseSignFloat(velocity.x) * _delta_time * friction;
    if(former_x_velocity * velocity.x < 0.0f) velocity.x = 0.0f;

    Collision(tile_map,SOLID,_delta_time);

    //Animation related code.

    //Run or stay idle?
    if(hit_floor && state == States::RUN){
        if(std::abs(velocity.x) < 0.1f){
            if(current_costume != ANIMATION_IDLE) SetCostume(ANIMATION_IDLE);

        }
        else{

            //If acceleration is the opposite sign of the velocity, then Tux is trying to stop or change direction.
            //Maybe increase acceleration for this case?
            if(velocity.x * dir_x < 0.0f && std::abs(velocity.x) > 50.0f && hit_floor){
                if(current_costume != ANIMATION_BREAK) SetCostume(ANIMATION_BREAK);
                animation->current_frame_index = 0.0f;

            }

            if(!(velocity.x * dir_x < 0.0f && std::abs(velocity.x) > 50.0f && hit_floor)){
                if(current_costume != ANIMATION_RUN) SetCostume(ANIMATION_RUN);
            }

            if(current_costume == ANIMATION_BREAK){
                //if(animation->current_frame_index > 1.0f) animation->current_frame_index = 1.0f;
            }

            if(current_costume != ANIMATION_BREAK){
                if(std::abs(velocity.x) >= 0.1f){
                    if(current_costume != ANIMATION_RUN) SetCostume(ANIMATION_RUN);
                }

                if(current_costume == ANIMATION_RUN){
                    animation->animation_speed = std::abs(velocity.x) * 0.2f;

                }
            }
        }
    }

    if(state == States::RUN){
        //Controlling jump and fall animation.
        if(velocity.y < 0.0f && !hit_floor){
            if(current_costume != ANIMATION_JUMP){
                SetCostume(ANIMATION_JUMP);
            }
            else{
                if(animation->current_frame_index > 1.0f) animation->current_frame_index = 1.0f;
            }
        }
        if(velocity.y > 0.0f && !hit_floor){

            if(current_costume != ANIMATION_FALL){
                SetCostume(ANIMATION_FALL);
            }
            else{
                if(animation->current_frame_index > 3.0f) animation->current_frame_index = 3.0f;
            }
        }
    }

    if(std::abs(velocity.x) > 0.01f && velocity.x != 0.0f) face_direction = ufo::Maths::PreciseSignFloat(velocity.x);

    if((state == States::SLIDE || state == States::CRAWL)){
        if(GetTileCollisionData(tile_map,SOLID,get_standing_shape()).place_free){
            get_current_shape = get_standing_shape;
            state = States::RUN;
        }
    }

    if(state == States::SLIDE || state == States::CRAWL){

        if(dir_x == 0.0f) dir_x = face_direction;

        float how_far_in_front_to_check = 32.0f;

        Vector2f slope_check_position_front = GetRectangle().position + Vector2f(how_far_in_front_to_check*dir_x, 3.0f);
        bool place_free_front = GetTileCollisionData(tile_map,SOLID,ufo::Rectangle(slope_check_position_front, GetRectangle().size)).place_free;

        Vector2f slope_check_position_back = GetRectangle().position + Vector2f(-how_far_in_front_to_check*dir_x, 3.0f);
        bool place_free_back = GetTileCollisionData(tile_map,SOLID,ufo::Rectangle(slope_check_position_back, GetRectangle().size)).place_free;

        if(place_free_front){
            velocity.x += dir_x*300.0f*_delta_time;
            if(velocity.y > 0.0f) velocity.y += 900.0f*_delta_time;
        }
        if(place_free_back){
            dir_x *= -1.0f;
            //velocity.x -= ufoMaths::PreciseSignFloat(velocity_x_dt)*30.0f;
        }

    }

    animation->scale.x = face_direction;

    //Fell out of level
    if(local_position.y > level->size.y+16.0f && !is_dead) Die();
}

void Tux::Die(){

    is_dead = true;
    auto next_camera = level->AddActor<ufo::Camera>(camera->GetGlobalPosition());

    next_camera->scale = 4.0f;

    //level->AddNewActors();

    level->AddActorUniquePtr(std::move(ufo::Generated::SpawnDeadTux(GetGlobalPosition())));
}
