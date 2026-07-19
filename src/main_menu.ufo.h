#pragma once
#include <ufo_macros.h>
#include <widget.h>
#include <button.h>
#include <ufo_maths.h>
#include <console.h>
#include <engine.h>

ufo_category("STA-Replica") ufo_actor_config("src/main_menu.ason")
ufo_comment("Main menu object") class MainMenu : public ufo::Widget{
public:
    MainMenu(Vector2f _) : ufo::Widget(_){}

    ufo::Button* b_new_game = nullptr;
    ufo::Button* b_load_game = nullptr;
    ufo::Button* b_options = nullptr;
    ufo::Button* b_quit = nullptr;

    void OnSpawn(){

        b_new_game = GetActor("InstButtonNewGame")->DynamicCast<ufo::Button>();
        b_load_game = GetActor("InstButtonLoadGame")->DynamicCast<ufo::Button>();
        b_options = GetActor("InstButtonOptions")->DynamicCast<ufo::Button>();
        b_quit = GetActor("InstButtonQuit")->DynamicCast<ufo::Button>();

    }

    void OnPause(float _delta_time){

        if(b_new_game->IsPressed()){}

        if(b_load_game->IsPressed()){}

        if(b_options->IsPressed()){}

        if(b_quit->IsPressed()){
            engine->quit = true;
        }

    }

};
