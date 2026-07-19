#include <actor.h>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <engine.h>
#include <tile_map.h>
#include <level.h>
#include <collision_grid.h>
#include "platformer_rectangle_collision.ufo.h"
#include "../generated.h"
#include "ice_ball.ufo.h"

IceBall::IceBall(Vector2f _) : custom::PlatformerRectangleCollision(_){}

void IceBall::OnSpawn(){
    custom::PlatformerRectangleCollision::OnSpawn();

    try{
        collision_grid = parent->DynamicCast<ufo::CollisionGrid>();
    }
    catch(const std::exception& _error){
        Console::PrintLine("Could not find InstCollisionGrid");
    }

    try{
        tile_map = parent->parent->DynamicCast<ufo::TileMap>();
    }
    catch(const std::exception& _error){
        Console::PrintLine("Could not find TileMap");
    }

    get_current_shape = [this](){
        return ufo::Rectangle(GetGlobalPosition() + Vector2f(-4.0f, -4.0f),Vector2f(8.0f,8.0f));
    };
}

void IceBall::OnUpdate(float _delta_time){
    Collision(tile_map, SOLID, _delta_time);

    if(hit_floor) velocity.y = -100.0f;

    if(hit_wall) is_dead = true;

    int index = collision_grid->GetDivisionFromPosition(local_position);
    if(index != ufo::CollisionGrid::Errors::OUT_OF_BOUNDS){
        std::vector<Actor*>& nearby_actors = collision_grid->divisions[index];
        for(Actor* actor : nearby_actors){
            if(actor == this) continue;
            if(actor->class_name != "Tux"){
                if(ufo::Maths::RectangleVsCircle(GetRectangle(), ufo::Circle(actor->local_position+Vector2f(8.0f, 8.0f), 8.0f))){
                    level->AddActorUniquePtr(ufo::Generated::SpawnFlameEffect(GetGlobalPosition()));

                    actor->is_dead = true;
                    is_dead = true;
                }
            }
        }
    }

}
