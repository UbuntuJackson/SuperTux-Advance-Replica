#pragma once
#include <sprite.h>
#include <ufo_maths.h>
#include <ufo_macros.h>
#include <camera.h>


ufo_actor_config("src/world_map_level.ason")
ufo_category("STA-Replica") class WorldMapLevel : public ufo::Sprite{
public:
    ufo_variable() std::string level_path = "";

    bool cleared = false;

    bool all_coins = false;
    bool all_enemies = false;
    bool all_secrets = false;

    ufo::Sprite* icon_all_coins = nullptr;
    ufo::Sprite* icon_all_enemies = nullptr;
    ufo::Sprite* icon_all_secrets = nullptr;

    WorldMapLevel(Vector2f _) : ufo::Sprite(_){

    }

    ufo::Rectangle GetRectangle() override{
        return ufo::Rectangle(GetGlobalPosition()-Vector2f(0.0f, 0.0f), Vector2f(16.0f, 16.0f));
    }

    void OnSpawn(){
        ufo::Sprite::OnSpawn();

        icon_all_coins = GetActor("IconAllCoins")->DynamicCast<ufo::Sprite>();
        icon_all_enemies = GetActor("IconAllEnemies")->DynamicCast<ufo::Sprite>();
        icon_all_secrets = GetActor("IconAllSecrets")->DynamicCast<ufo::Sprite>();

    }

    void OnUpdate(float _delta_time){
        current_frame_index = (int)cleared;
    }

};
