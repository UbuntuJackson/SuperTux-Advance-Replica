#pragma once
#include <ufo_macros.h>
#include <widget.h>
#include <button.h>
#include <ufo_maths.h>
#include <console.h>
#include <engine.h>
#include "sta_save_file.h"

ufo_category("STA-Replica")
ufo_actor_config("src/pause_menu.ason")
ufo_comment("Menu that appears when pausing.")
class PauseMenu : public ufo::Widget{
public:
    PauseMenu(Vector2f _) : ufo::Widget(_){}

    ufo::Button* b_resume = nullptr;
    ufo::Button* b_settings = nullptr;
    ufo::Button* b_exit = nullptr;

    void OnSpawn(){

        b_resume = GetActor("InstButtonResume")->DynamicCast<ufo::Button>();
        b_exit = GetActor("InstButtonExit")->DynamicCast<ufo::Button>();

    }

    void OnPause(float _delta_time){

        if(b_resume->IsPressed()){
            level->is_paused = false;
            is_dead = true;
        }

        if(b_exit->IsPressed()){
            STASaveFile* save_file = dynamic_cast<STASaveFile*>(engine->save_file.get());
            engine->pending_levels.push_back(save_file->overworld);
        }

    }

};
