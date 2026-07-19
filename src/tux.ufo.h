#pragma once
#include <string>
#include <array>
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <functional>
#include "platformer_rectangle_collision.ufo.h"

#define TUX_UFO_H_NUMBER_OF_COSTUMES 21

namespace ufo{class CollisionGrid; class Controls; class Animation; class TileMap; class Camera;}

ufo_comment("This is the player object")
ufo_actor_config("src/tux.ason")
ufo_category("STA-Replica") class Tux : public custom::PlatformerRectangleCollision{
public:

    Tux(Vector2f _);

    //The solid tileset
    const std::string SOLID = "res/gfx/solid.png";

    enum PowerUps{
        POWER_UP_NONE,
        POWER_UP_FIRE,
        POWER_UP_ICE,
        POWER_UP_FEATHER,
        POWER_UP_EARTH
    };
private:
    PowerUps power_up = PowerUps::POWER_UP_NONE;

public:
    void SetPowerUp(PowerUps _power_up){
        power_up = _power_up;
        switch(_power_up){
            case PowerUps::POWER_UP_NONE:
                SetAnimations(animations_normal_tux);
                max_speed_walk = max_speed_walk_no_power_up;
                max_speed_run = max_speed_run_no_power_up;
                break;
            case PowerUps::POWER_UP_FIRE:
                SetAnimations(animations_fire_tux);
                max_speed_walk = max_speed_walk_no_power_up;
                max_speed_run = max_speed_run_no_power_up;
                break;
            case PowerUps::POWER_UP_ICE:
                SetAnimations(animations_ice_tux);
                max_speed_run = max_speed_run_ice;
                max_speed_walk = max_speed_walk_ice;
                break;
            case PowerUps::POWER_UP_FEATHER:
                SetAnimations(animations_feather_tux);
                max_speed_walk = max_speed_walk_no_power_up;
                max_speed_run = max_speed_run_no_power_up;
                break;
            case PowerUps::POWER_UP_EARTH:
                SetAnimations(animations_earth_tux);
                max_speed_walk = max_speed_walk_no_power_up;
                max_speed_run = max_speed_run_no_power_up;
                break;
        }
    }

    //Shorthands. Yes, this is how it needs to be done for now, let's not overcomplicate things.

    enum Animations{
        ANIMATION_BELLY_RUB,
        ANIMATION_BREAK,
        ANIMATION_CLIMB,
        ANIMATION_CRAWL,
        ANIMATION_DAMAGE,
        ANIMATION_DIE,
        ANIMATION_ENTER_SLIDE,
        ANIMATION_FALL,
        ANIMATION_GROUND_POUND,
        ANIMATION_IDLE,
        ANIMATION_JUMP,
        ANIMATION_RUN,
        ANIMATION_SLIDE,
        ANIMATION_SNEAK,
        ANIMATION_SWIM_DOWN,
        ANIMATION_SWIM_RIGHT,
        ANIMATION_SWIM_RIGHT_DOWN,
        ANIMATION_SWIM_RIGHT_UP,
        ANIMATION_SWIM_UP,
        ANIMATION_WALL_JUMP,
        ANIMATION_WAVE
    };

    std::array<std::string, 21> animations_normal_tux = {
        "res/gfx/tux_anim/tux_belly_rub.png",
        "res/gfx/tux_anim/tux_break.png",
        "res/gfx/tux_anim/tux_climb.png",
        "res/gfx/tux_anim/tux_crawl.png",
        "res/gfx/tux_anim/tux_damage.png",
        "res/gfx/tux_anim/tux_die.png",
        "res/gfx/tux_anim/tux_enter_slide.png",
        "res/gfx/tux_anim/tux_fall.png",
        "res/gfx/tux_anim/tux_ground_pound.png",
        "res/gfx/tux_anim/tux_idle.png",
        "res/gfx/tux_anim/tux_jump.png",
        "res/gfx/tux_anim/tux_run.png",
        "res/gfx/tux_anim/tux_slide.png",
        "res/gfx/tux_anim/tux_sneak.png",
        "res/gfx/tux_anim/tux_swim_down.png",
        "res/gfx/tux_anim/tux_swim_right.png",
        "res/gfx/tux_anim/tux_swim_right_down.png",
        "res/gfx/tux_anim/tux_swim_right_up.png",
        "res/gfx/tux_anim/tux_swim_up.png",
        "res/gfx/tux_anim/tux_wall_jump.png",
        "res/gfx/tux_anim/tux_wave.png",
    };

    std::array<std::string, 21> animations_fire_tux = {
        "res/gfx/tux_anim_fire/tux_belly_rub_fire.png",
        "res/gfx/tux_anim_fire/tux_break_fire.png",
        "res/gfx/tux_anim_fire/tux_climb_fire.png",
        "res/gfx/tux_anim_fire/tux_crawl_fire.png",
        "res/gfx/tux_anim_fire/tux_damage_fire.png",
        "res/gfx/tux_anim_fire/tux_die_fire.png",
        "res/gfx/tux_anim_fire/tux_enter_slide_fire.png",
        "res/gfx/tux_anim_fire/tux_fall_fire.png",
        "res/gfx/tux_anim_fire/tux_ground_pound_fire.png",
        "res/gfx/tux_anim_fire/tux_idle_fire.png",
        "res/gfx/tux_anim_fire/tux_jump_fire.png",
        "res/gfx/tux_anim_fire/tux_run_fire.png",
        "res/gfx/tux_anim_fire/tux_slide_fire.png",
        "res/gfx/tux_anim_fire/tux_sneak_fire.png",
        "res/gfx/tux_anim_fire/tux_swim_down_fire.png",
        "res/gfx/tux_anim_fire/tux_swim_right_fire.png",
        "res/gfx/tux_anim_fire/tux_swim_right_down_fire.png",
        "res/gfx/tux_anim_fire/tux_swim_right_up_fire.png",
        "res/gfx/tux_anim_fire/tux_swim_up_fire.png",
        "res/gfx/tux_anim_fire/tux_wall_jump_fire.png",
        "res/gfx/tux_anim_fire/tux_wave_fire.png",
    };

    std::array<std::string, 21> animations_ice_tux = {
        "res/gfx/tux_anim_ice/tux_belly_rub_ice.png",
        "res/gfx/tux_anim_ice/tux_break_ice.png",
        "res/gfx/tux_anim_ice/tux_climb_ice.png",
        "res/gfx/tux_anim_ice/tux_crawl_ice.png",
        "res/gfx/tux_anim_ice/tux_damage_ice.png",
        "res/gfx/tux_anim_ice/tux_die_ice.png",
        "res/gfx/tux_anim_ice/tux_enter_slide_ice.png",
        "res/gfx/tux_anim_ice/tux_fall_ice.png",
        "res/gfx/tux_anim_ice/tux_ground_pound_ice.png",
        "res/gfx/tux_anim_ice/tux_idle_ice.png",
        "res/gfx/tux_anim_ice/tux_jump_ice.png",
        "res/gfx/tux_anim_ice/tux_run_ice.png",
        "res/gfx/tux_anim_ice/tux_slide_ice.png",
        "res/gfx/tux_anim_ice/tux_sneak_ice.png",
        "res/gfx/tux_anim_ice/tux_swim_down_ice.png",
        "res/gfx/tux_anim_ice/tux_swim_right_ice.png",
        "res/gfx/tux_anim_ice/tux_swim_right_down_ice.png",
        "res/gfx/tux_anim_ice/tux_swim_right_up_ice.png",
        "res/gfx/tux_anim_ice/tux_swim_up_ice.png",
        "res/gfx/tux_anim_ice/tux_wall_jump_ice.png",
        "res/gfx/tux_anim_ice/tux_wave_ice.png",
    };

    std::array<std::string, 21> animations_feather_tux = {
        "res/gfx/tux_anim_feather/tux_belly_rub_feather.png",
        "res/gfx/tux_anim_feather/tux_break_feather.png",
        "res/gfx/tux_anim_feather/tux_climb_feather.png",
        "res/gfx/tux_anim_feather/tux_crawl_feather.png",
        "res/gfx/tux_anim_feather/tux_damage_feather.png",
        "res/gfx/tux_anim_feather/tux_die_feather.png",
        "res/gfx/tux_anim_feather/tux_enter_slide_feather.png",
        "res/gfx/tux_anim_feather/tux_fall_feather.png",
        "res/gfx/tux_anim_feather/tux_ground_pound_feather.png",
        "res/gfx/tux_anim_feather/tux_idle_feather.png",
        "res/gfx/tux_anim_feather/tux_jump_feather.png",
        "res/gfx/tux_anim_feather/tux_run_feather.png",
        "res/gfx/tux_anim_feather/tux_slide_feather.png",
        "res/gfx/tux_anim_feather/tux_sneak_feather.png",
        "res/gfx/tux_anim_feather/tux_swim_down_feather.png",
        "res/gfx/tux_anim_feather/tux_swim_right_feather.png",
        "res/gfx/tux_anim_feather/tux_swim_right_down_feather.png",
        "res/gfx/tux_anim_feather/tux_swim_right_up_feather.png",
        "res/gfx/tux_anim_feather/tux_swim_up_feather.png",
        "res/gfx/tux_anim_feather/tux_wall_jump_feather.png",
        "res/gfx/tux_anim_feather/tux_wave_feather.png",
    };

    std::array<std::string, 21> animations_earth_tux = {
        "res/gfx/tux_anim_earth/tux_belly_rub_earth.png",
        "res/gfx/tux_anim_earth/tux_break_earth.png",
        "res/gfx/tux_anim_earth/tux_climb_earth.png",
        "res/gfx/tux_anim_earth/tux_crawl_earth.png",
        "res/gfx/tux_anim_earth/tux_damage_earth.png",
        "res/gfx/tux_anim_earth/tux_die_earth.png",
        "res/gfx/tux_anim_earth/tux_enter_slide_earth.png",
        "res/gfx/tux_anim_earth/tux_fall_earth.png",
        "res/gfx/tux_anim_earth/tux_ground_pound_earth.png",
        "res/gfx/tux_anim_earth/tux_idle_earth.png",
        "res/gfx/tux_anim_earth/tux_jump_earth.png",
        "res/gfx/tux_anim_earth/tux_run_earth.png",
        "res/gfx/tux_anim_earth/tux_slide_earth.png",
        "res/gfx/tux_anim_earth/tux_sneak_earth.png",
        "res/gfx/tux_anim_earth/tux_swim_down_earth.png",
        "res/gfx/tux_anim_earth/tux_swim_right_earth.png",
        "res/gfx/tux_anim_earth/tux_swim_right_down_earth.png",
        "res/gfx/tux_anim_earth/tux_swim_right_up_earth.png",
        "res/gfx/tux_anim_earth/tux_swim_up_earth.png",
        "res/gfx/tux_anim_earth/tux_wall_jump_earth.png",
        "res/gfx/tux_anim_earth/tux_wave_earth.png",
    };

    std::array<std::string, 21> animations = animations_normal_tux;

    void SetAnimations(std::array<std::string,21>& _animations){
        for(int i = 0; i < _animations.size(); i++){
            animation->costumes.at(animations_normal_tux[i]).key = _animations[i];
        }
    }

    void SetCostume(Animations _costume){
        current_costume = _costume;
        animation->SetCostume(animations[_costume]);
    }

    void SetKey(Animations _costume){
        current_costume = _costume;
        animation->key = animations[_costume];

    }

    Animations current_costume = Animations::ANIMATION_FALL;

    enum States{
        RUN,
        JUMP,
        SWIM,
        WALK,
        SLIDE,
        CRAWL
    };

    int state = States::RUN;

    std::function<ufo::Rectangle()> get_standing_shape;

    std::function<ufo::Rectangle()> get_crawling_shape;

    float face_direction = 1.0f;

    const float horizontal_speed = 500.0f;

    const float friction = 70.0f;
    const float horizontal_acceleration = 400.0f;
    const float jump_velocity = 220.0f*1.7f;
    float max_speed_walk = 100.0f;
    float max_speed_run = 200.0f;

    float max_speed_walk_ice = 120.0f;
    float max_speed_run_ice = 250.0f;

    float max_speed_walk_no_power_up = 100.0f;
    float max_speed_run_no_power_up = 200.0f;

    //Just to activate soundeffects
    bool jumped = false;
    bool wall_kicked = false;
    bool did_slide = false;
    bool tux_died = false;
    int dir_x = 1;

    bool level_cleared = false;
    //Pointers to various components and level objects presumed to exist
    ufo::Actor* camera = nullptr;

    Vector2f original_camera_position = Vector2f(0.0f, 0.0f);

    ufo::Animation* animation = nullptr;
    ufo::Controls* controls = nullptr;
    ufo::TileMap* tile_map = nullptr;
    ufo::CollisionGrid* collision_grid = nullptr;

private:
    void OnSpawn() override;

    void OnUpdate(float _delta_time) override;

    void ActiveUpdate(float _delta_time);

    void InactiveUpdate(float _delta_time);

    void Die();
};
