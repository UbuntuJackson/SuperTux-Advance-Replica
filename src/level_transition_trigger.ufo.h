#pragma once
#include <string>
#include <actor.h>
#include <ufo_maths.h>
#include <ufo_macros.h>
#include <animation.h>
#include <timer.h>
#include <engine.h>

namespace test{

ufo_category("Test")
class LevelTransitionTrigger : public ufo::Actor{
public:
    ufo::Timer timer;

    ufo_variable() ufo_alias("Level Path") std::string level_path = "";

    LevelTransitionTrigger(Vector2f _) : ufo::Actor(_){}

    void OnUpdate(float _delta_time){
        if(timer.is_started){
            if(timer.GetTimeLeft() < 0.0f) engine->GoToLevel(level_path);
        }
    }

};


}
