#pragma once
#include <string>
#include <rectangular_area.h>
#include <ufo_maths.h>
#include <ufo_macros.h>
#include <animation.h>
#include <timer.h>
#include <engine.h>
#include "sta_save_file.h"

ufo_category("STA-Replica")
class LevelGoalTrigger : public ufo::RectangularArea{
public:
    ufo::Timer timer;

    LevelGoalTrigger(Vector2f _) : ufo::RectangularArea(_){}

    void OnUpdate(float _delta_time){
        if(timer.is_started){
            if(timer.GetTimeLeft() < 0.0f){
                STASaveFile* save_file = dynamic_cast<STASaveFile*>(engine->save_file.get());
                engine->pending_levels.push_back(save_file->overworld);
            }
        }
    }

};
