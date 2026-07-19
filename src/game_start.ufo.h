#pragma once

#include <ufo_macros.h>
#include <actor.h>
#include <ufo_maths.h>
#include <string>
#include <engine.h>
#include <level.h>
#include <level_loader.h>
#include "sta_save_file.h"

namespace ufo::Generated{
    class ActorGenerator;
}

ufo_comment("An object used to select the first level without recompiling")
ufo_category("STA-Replica") class GameStart : public ufo::Actor{
protected:
    friend class ufo::Generated::ActorGenerator;

    ufo_alias("Start Level")
    ufo_variable() std::string start_level = "../overworld.ason";

public:
    GameStart(Vector2f _) : Actor(_){}

private:
    void OnSpawn() override{

        auto u_save_file = std::make_unique<STASaveFile>("../save/save0.json");
        engine->loaded_levels.push_back(std::move(ufo::LevelLoader().LoadLevel(engine, start_level)));
        engine->pending_levels.push_back(engine->loaded_levels.back().get());

        engine->loaded_levels.push_back(std::move(ufo::LevelLoader().LoadLevel(engine, "../overworld.ason")));
        u_save_file->overworld = engine->loaded_levels.back()->DynamicCast<ufo::Level>();
        u_save_file->overworld->persistent_on_level_transition = true;

        engine->save_file = std::move(u_save_file);
        engine->save_file->Load();

    }

};
