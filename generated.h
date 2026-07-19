#pragma once
#include <functional>
#include <memory>
#include <ufo_maths.h>

#include "UFO-Engine/ufo_garbage_collector/gc_json.h"
#include "UFO-Engine/src/generic_generator.h"
#include "UFO-Engine/src/actor.h"
#include "UFO-Engine/src/sprite.h"
#include "UFO-Engine/src/animation.h"
#include "UFO-Engine/src/widget.h"
#include "UFO-Engine/src/button.h"
#include "UFO-Engine/src/camera.h"
#include "UFO-Engine/src/platformer_rectangle_collision.h"
#include "src/check_point.ufo.h"
#include "src/coin.ufo.h"
#include "src/dead_tux.ufo.h"
#include "src/fire_ball.ufo.h"
#include "src/fire_flower.ufo.h"
#include "src/flame_effect.ufo.h"
#include "src/game_start.ufo.h"
#include "src/ice_ball.ufo.h"
#include "src/ice_cap.ufo.h"
#include "src/ice_crusher.ufo.h"
#include "src/ice_flower.ufo.h"
#include "src/item_box.ufo.h"
#include "src/key.ufo.h"
#include "src/level_goal_trigger.ufo.h"
#include "src/level_transition_trigger.ufo.h"
#include "src/main_menu.ufo.h"
#include "src/middle_man.ufo.h"
#include "src/pause_menu.ufo.h"
#include "src/platformer_rectangle_collision.ufo.h"
#include "src/player_overworld.ufo.h"
#include "src/power_up_effect.ufo.h"
#include "src/sta_tile_map.ufo.h"
#include "src/tux.ufo.h"
#include "src/wood_box.ufo.h"
#include "src/world_map_level.ufo.h"

namespace ufo::Generated{

inline std::unique_ptr<CheckPoint> SpawnCheckPoint(Vector2f _local_position){
    std::unique_ptr<CheckPoint> instance1 = std::make_unique<CheckPoint>(_local_position);
    instance1->class_name = "CheckPoint";
    instance1->AddCostume("res/gfx/bell.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(16,16),Vector2f(1,1),0,0,6);
    instance1->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance1->preview = bool(1);
    instance1->key ="res/gfx/bell.png";
    return std::move(instance1);
}

inline std::unique_ptr<Coin> SpawnCoin(Vector2f _local_position){
    std::unique_ptr<Coin> instance2 = std::make_unique<Coin>(_local_position);
    instance2->class_name = "Coin";
    instance2->AddCostume("res/gfx/coin.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(16,16),Vector2f(1,1),0,0,10);
    instance2->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance2->preview = bool(1);
    instance2->key ="res/gfx/coin.png";
    return std::move(instance2);
}

inline std::unique_ptr<DeadTux> SpawnDeadTux(Vector2f _local_position){
    std::unique_ptr<DeadTux> instance3 = std::make_unique<DeadTux>(_local_position);
    instance3->class_name = "DeadTux";
    instance3->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance3->AddCostume("res/gfx/tux_anim/tux_die.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,6);
    instance3->preview = bool(1);
    instance3->key ="res/gfx/tux_anim/tux_die.png";
    return std::move(instance3);
}

inline std::unique_ptr<FireBall> SpawnFireBall(Vector2f _local_position){
    std::unique_ptr<FireBall> instance4 = std::make_unique<FireBall>(_local_position);
    instance4->class_name = "FireBall";
    auto instance5 = instance4->AddActor<ufo::Animation>(Vector2f(0,0));
    instance5->editor_name = "InstAnim";
    instance5->class_name = "ufo::Animation";
    instance5->AddCostume("res/gfx/fireball.png",Vector2f(0.0f,0.0f),Vector2f(4,4),Vector2f(8,8),Vector2f(1,1),0,0,12);
    instance5->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance5->preview = bool(1);
    instance5->key ="res/gfx/fireball.png";
    return std::move(instance4);
}

inline std::unique_ptr<FireFlower> SpawnFireFlower(Vector2f _local_position){
    std::unique_ptr<FireFlower> instance6 = std::make_unique<FireFlower>(_local_position);
    instance6->class_name = "FireFlower";
    auto instance7 = instance6->AddActor<ufo::Animation>(Vector2f(0,0));
    instance7->editor_name = "InstAnimation";
    instance7->class_name = "ufo::Animation";
    instance7->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance7->AddCostume("res/gfx/fireflower.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(16,16),Vector2f(1,1),0,0,3);
    instance7->preview = bool(1);
    instance7->key ="res/gfx/fireflower.png";
    return std::move(instance6);
}

inline std::unique_ptr<FlameEffect> SpawnFlameEffect(Vector2f _local_position){
    std::unique_ptr<FlameEffect> instance8 = std::make_unique<FlameEffect>(_local_position);
    instance8->class_name = "FlameEffect";
    instance8->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance8->AddCostume("res/gfx/flame.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(14,20),Vector2f(1,1),0,0,16);
    instance8->preview = bool(1);
    instance8->key ="res/gfx/flame.png";
    return std::move(instance8);
}

inline std::unique_ptr<GameStart> SpawnGameStart(Vector2f _local_position){
    std::unique_ptr<GameStart> instance9 = std::make_unique<GameStart>(_local_position);
    instance9->class_name = "GameStart";
    return std::move(instance9);
}

inline std::unique_ptr<IceBall> SpawnIceBall(Vector2f _local_position){
    std::unique_ptr<IceBall> instance10 = std::make_unique<IceBall>(_local_position);
    instance10->class_name = "IceBall";
    auto instance11 = instance10->AddActor<ufo::Animation>(Vector2f(0,0));
    instance11->editor_name = "InstAnim";
    instance11->class_name = "ufo::Animation";
    instance11->AddCostume("res/gfx/iceball.png",Vector2f(0.0f,0.0f),Vector2f(3,3),Vector2f(6,6),Vector2f(1,1),0,0,0);
    instance11->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance11->preview = bool(1);
    instance11->key ="res/gfx/iceball.png";
    return std::move(instance10);
}

inline std::unique_ptr<IceCap> SpawnIceCap(Vector2f _local_position){
    std::unique_ptr<IceCap> instance12 = std::make_unique<IceCap>(_local_position);
    instance12->class_name = "IceCap";
    instance12->get_current_shape = [=](){return ufo::Rectangle(Vector2f(-5.58746337890625,-7.93598747253418), Vector2f(9.79124164581299,12.5983190536499));};    auto instance13 = instance12->AddActor<ufo::Animation>(Vector2f(-1.1043949127197266,-2.163883686065674));
    instance13->editor_name = "InstanceAnim";
    instance13->class_name = "ufo::Animation";
    instance13->AddCostume("res/gfx/ice_cap_anim/ice_cap_walk.png",Vector2f(0.0f,0.0f),Vector2f(8,8),Vector2f(16,16),Vector2f(1,1),0,0,10);
    instance13->AddCostume("res/gfx/ice_cap_anim/ice_cap_squish.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(16,16),Vector2f(1,1),0,0,5);
    instance13->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance13->preview = bool(1);
    instance13->key ="res/gfx/ice_cap_anim/ice_cap_walk.png";
    return std::move(instance12);
}

inline std::unique_ptr<IceCrusher> SpawnIceCrusher(Vector2f _local_position){
    std::unique_ptr<IceCrusher> instance14 = std::make_unique<IceCrusher>(_local_position);
    instance14->class_name = "IceCrusher";
    instance14->get_current_shape = [=](){return ufo::Rectangle(Vector2f(-6,-0.23495548963546753), Vector2f(30.85325050354004,29.892126083374023));};    auto instance15 = instance14->AddActor<ufo::Animation>(Vector2f(-6.527015686035156,-1.8248281478881836));
    instance15->editor_name = "InstanceAnim";
    instance15->class_name = "ufo::Animation";
    instance15->AddCostume("res/gfx/icecrusher.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance15->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance15->preview = bool(0);
    instance15->key ="res/gfx/icecrusher.png";
    return std::move(instance14);
}

inline std::unique_ptr<IceFlower> SpawnIceFlower(Vector2f _local_position){
    std::unique_ptr<IceFlower> instance16 = std::make_unique<IceFlower>(_local_position);
    instance16->class_name = "IceFlower";
    auto instance17 = instance16->AddActor<ufo::Animation>(Vector2f(0,0));
    instance17->editor_name = "Anim";
    instance17->class_name = "ufo::Animation";
    instance17->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance17->AddCostume("res/gfx/iceflower.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(16,16),Vector2f(1,1),0,0,6);
    instance17->preview = bool(1);
    instance17->key ="res/gfx/iceflower.png";
    return std::move(instance16);
}

inline std::unique_ptr<ItemBox> SpawnItemBox(Vector2f _local_position){
    std::unique_ptr<ItemBox> instance18 = std::make_unique<ItemBox>(_local_position);
    instance18->class_name = "ItemBox";
    instance18->AddCostume("res/gfx/itembox.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(16,16),Vector2f(1,1),0,0,10);
    instance18->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance18->preview = bool(1);
    instance18->key ="res/gfx/itembox.png";
    return std::move(instance18);
}

inline std::unique_ptr<Key> SpawnKey(Vector2f _local_position){
    std::unique_ptr<Key> instance19 = std::make_unique<Key>(_local_position);
    instance19->class_name = "Key";
    instance19->AddCostume("res/gfx/key-gold.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(16,16),Vector2f(1,1),0,0,10);
    instance19->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance19->preview = bool(1);
    instance19->key ="res/gfx/key-gold.png";
    return std::move(instance19);
}

inline std::unique_ptr<LevelGoalTrigger> SpawnLevelGoalTrigger(Vector2f _local_position){
    std::unique_ptr<LevelGoalTrigger> instance20 = std::make_unique<LevelGoalTrigger>(_local_position);
    instance20->class_name = "LevelGoalTrigger";
    return std::move(instance20);
}

inline std::unique_ptr<test::LevelTransitionTrigger> Spawntest_LevelTransitionTrigger(Vector2f _local_position){
    std::unique_ptr<test::LevelTransitionTrigger> instance21 = std::make_unique<test::LevelTransitionTrigger>(_local_position);
    instance21->class_name = "test::LevelTransitionTrigger";
    return std::move(instance21);
}

inline std::unique_ptr<MainMenu> SpawnMainMenu(Vector2f _local_position){
    std::unique_ptr<MainMenu> instance22 = std::make_unique<MainMenu>(_local_position);
    instance22->class_name = "MainMenu";
    instance22->rectangle = ufo::Rectangle(Vector2f(-33.72674560546875,20.868743896484375),Vector2f(633.7269287109375,179.13125610351562));
    auto instance23 = instance22->AddActor<ufo::Button>(Vector2f(1.897918701171875,-39.519287109375));
    instance23->editor_name = "InstButtonNewGame";
    instance23->class_name = "ufo::Button";
    instance23->language_to_text["English"] = "New Game";
    instance23->is_wrapping = bool(0);
    auto instance24 = instance22->AddActor<ufo::Button>(Vector2f(2.09539794921875,15.170669555664062));
    instance24->editor_name = "InstButtonLoadGame";
    instance24->class_name = "ufo::Button";
    instance24->language_to_text["English"] = "Load Game";
    instance24->is_wrapping = bool(0);
    auto instance25 = instance22->AddActor<ufo::Button>(Vector2f(-43.32232666015625,134.2574462890625));
    instance25->editor_name = "InstButtonOptions";
    instance25->class_name = "ufo::Button";
    instance25->language_to_text["English"] = "Options";
    instance25->is_wrapping = bool(0);
    auto instance26 = instance22->AddActor<ufo::Button>(Vector2f(0,0));
    instance26->editor_name = "InstButtonQuit";
    instance26->class_name = "ufo::Button";
    instance26->language_to_text["English"] = "Quit";
    instance26->is_wrapping = bool(0);
    return std::move(instance22);
}

inline std::unique_ptr<test::MiddleMan> Spawntest_MiddleMan(Vector2f _local_position){
    std::unique_ptr<test::MiddleMan> instance27 = std::make_unique<test::MiddleMan>(_local_position);
    instance27->class_name = "test::MiddleMan";
    return std::move(instance27);
}

inline std::unique_ptr<PauseMenu> SpawnPauseMenu(Vector2f _local_position){
    std::unique_ptr<PauseMenu> instance28 = std::make_unique<PauseMenu>(_local_position);
    instance28->class_name = "PauseMenu";
    instance28->rectangle = ufo::Rectangle(Vector2f(-223.56674194335938,-203.4741668701172),Vector2f(542.5819702148438,346.7060852050781));
    auto instance29 = instance28->AddActor<ufo::Button>(Vector2f(58.0086669921875,-23.054443359375));
    instance29->editor_name = "InstButtonResume";
    instance29->class_name = "ufo::Button";
    instance29->language_to_text["English"] = "Resume";
    instance29->is_wrapping = bool(0);
    auto instance30 = instance28->AddActor<ufo::Button>(Vector2f(71.30105590820312,75.74542236328125));
    instance30->editor_name = "InstButtonExit";
    instance30->class_name = "ufo::Button";
    instance30->language_to_text["English"] = "Exit";
    instance30->is_wrapping = bool(0);
    return std::move(instance28);
}

inline std::unique_ptr<custom::PlatformerRectangleCollision> Spawncustom_PlatformerRectangleCollision(Vector2f _local_position){
    std::unique_ptr<custom::PlatformerRectangleCollision> instance31 = std::make_unique<custom::PlatformerRectangleCollision>(_local_position);
    instance31->class_name = "custom::PlatformerRectangleCollision";
    return std::move(instance31);
}

inline std::unique_ptr<PlayerOverworld> SpawnPlayerOverworld(Vector2f _local_position){
    std::unique_ptr<PlayerOverworld> instance32 = std::make_unique<PlayerOverworld>(_local_position);
    instance32->class_name = "PlayerOverworld";
    auto instance33 = instance32->AddActor<ufo::Animation>(Vector2f(0,0));
    instance33->editor_name = "InstAnim";
    instance33->class_name = "ufo::Animation";
    instance33->AddCostume("res/gfx/tuxO.png",Vector2f(0.0f,0.0f),Vector2f(8,8),Vector2f(14,17),Vector2f(1,1),0,0,8);
    instance33->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance33->preview = bool(1);
    instance33->key ="res/gfx/tuxO.png";
    auto instance34 = instance32->AddActor<ufo::Camera>(Vector2f(8,8));
    instance34->editor_name = "InstCamera";
    instance34->class_name = "ufo::Camera";
    instance34->scale = 4;
    instance34->clamp = bool(1);
    return std::move(instance32);
}

inline std::unique_ptr<PowerUpEffect> SpawnPowerUpEffect(Vector2f _local_position){
    std::unique_ptr<PowerUpEffect> instance35 = std::make_unique<PowerUpEffect>(_local_position);
    instance35->class_name = "PowerUpEffect";
    instance35->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance35->AddCostume("../res/gfx/tfFlash.png",Vector2f(0.0f,0.0f),Vector2f(16,20),Vector2f(32,40),Vector2f(1,1),0,0,10);
    instance35->preview = bool(1);
    instance35->key ="../res/gfx/tfFlash.png";
    return std::move(instance35);
}

inline std::unique_ptr<STA_TileMap> SpawnSTA_TileMap(Vector2f _local_position){
    std::unique_ptr<STA_TileMap> instance36 = std::make_unique<STA_TileMap>(_local_position);
    instance36->class_name = "STA_TileMap";
    return std::move(instance36);
}

inline std::unique_ptr<Tux> SpawnTux(Vector2f _local_position){
    std::unique_ptr<Tux> instance37 = std::make_unique<Tux>(_local_position);
    instance37->class_name = "Tux";
    auto instance38 = instance37->AddActor<ufo::Camera>(Vector2f(43.43994140625,34.1912841796875));
    instance38->editor_name = "InstanceCamera";
    instance38->class_name = "ufo::Camera";
    instance38->scale = 4;
    instance38->clamp = bool(1);
    auto instance39 = instance37->AddActor<ufo::Animation>(Vector2f(-2.12664794921875,-0.464111328125));
    instance39->editor_name = "InstanceAnimation";
    instance39->class_name = "ufo::Animation";
    instance39->AddCostume("res/gfx/tux_anim/tux_break.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_sneak.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_swim_right.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_damage.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,5);
    instance39->AddCostume("res/gfx/tux_anim/tux_swim_down.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_die.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,5);
    instance39->AddCostume("res/gfx/tux_anim/tux_wave.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_swim_right_down.png",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_climb.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("placeholder_icon",Vector2f(0.0f,0.0f),Vector2f(0,0),Vector2f(32,32),Vector2f(1,1),0,0,0);
    instance39->AddCostume("res/gfx/tux_anim/tux_enter_slide.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,5);
    instance39->AddCostume("res/gfx/tux_anim/tux_wall_jump.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,5);
    instance39->AddCostume("res/gfx/tux_anim/tux_crawl.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_run.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,16);
    instance39->AddCostume("res/gfx/tux_anim/tux_ground_pound.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_jump.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,3);
    instance39->AddCostume("res/gfx/tux_anim/tux_fall.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,8);
    instance39->AddCostume("res/gfx/tux_anim/tux_slide.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_belly_rub.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,7);
    instance39->AddCostume("res/gfx/tux_anim/tux_swim_right_up.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->AddCostume("res/gfx/tux_anim/tux_idle.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,5);
    instance39->AddCostume("res/gfx/tux_anim/tux_swim_up.png",Vector2f(0.0f,0.0f),Vector2f(16,16),Vector2f(32,32),Vector2f(1,1),0,0,10);
    instance39->preview = bool(1);
    instance39->key ="res/gfx/tux_anim/tux_jump.png";
    return std::move(instance37);
}

inline std::unique_ptr<WoodBox> SpawnWoodBox(Vector2f _local_position){
    std::unique_ptr<WoodBox> instance40 = std::make_unique<WoodBox>(_local_position);
    instance40->class_name = "WoodBox";
    instance40->key = "res/gfx/woodbox.png";
    instance40->offset.x = 0;
    instance40->offset.y = 0;
    instance40->frame_size.x = 16;
    instance40->frame_size.y = 16;
    instance40->scale.x = 1;
    instance40->scale.y = 1;
    instance40->rotation = 0;
    instance40->current_frame_index = 0;
    return std::move(instance40);
}

inline std::unique_ptr<WorldMapLevel> SpawnWorldMapLevel(Vector2f _local_position){
    std::unique_ptr<WorldMapLevel> instance41 = std::make_unique<WorldMapLevel>(_local_position);
    instance41->class_name = "WorldMapLevel";
    instance41->key = "res/gfx/levelicons.png";
    instance41->offset.x = 0;
    instance41->offset.y = 0;
    instance41->frame_size.x = 16;
    instance41->frame_size.y = 16;
    instance41->scale.x = 1;
    instance41->scale.y = 1;
    instance41->rotation = 0;
    instance41->current_frame_index = 0;
    auto instance42 = instance41->AddActor<ufo::Sprite>(Vector2f(0,0));
    instance42->editor_name = "IconAllCoins";
    instance42->class_name = "ufo::Sprite";
    instance42->key = "res/gfx/levelicons.png";
    instance42->offset.x = 0;
    instance42->offset.y = 0;
    instance42->frame_size.x = 16;
    instance42->frame_size.y = 16;
    instance42->scale.x = 1;
    instance42->scale.y = 1;
    instance42->rotation = 0;
    instance42->current_frame_index = 2;
    auto instance43 = instance41->AddActor<ufo::Sprite>(Vector2f(0,0));
    instance43->editor_name = "IconAllEnemies";
    instance43->class_name = "ufo::Sprite";
    instance43->key = "res/gfx/levelicons.png";
    instance43->offset.x = 0;
    instance43->offset.y = 0;
    instance43->frame_size.x = 16;
    instance43->frame_size.y = 16;
    instance43->scale.x = 1;
    instance43->scale.y = 1;
    instance43->rotation = 0;
    instance43->current_frame_index = 3;
    auto instance44 = instance41->AddActor<ufo::Sprite>(Vector2f(0,0));
    instance44->editor_name = "IconAllSecrets";
    instance44->class_name = "ufo::Sprite";
    instance44->key = "res/gfx/levelicons.png";
    instance44->offset.x = 0;
    instance44->offset.y = 0;
    instance44->frame_size.x = 16;
    instance44->frame_size.y = 16;
    instance44->scale.x = 1;
    instance44->scale.y = 1;
    instance44->rotation = 0;
    instance44->current_frame_index = 4;
    return std::move(instance41);
}

class ActorGenerator : public ufo::GenericGenerator{

    public:
    std::unique_ptr<Actor> FromJson(ufo::gc::JsonMap* _json){return std::move(FromJsonInGame(_json));}
    void Initialise(){
        GenericGenerator::Initialise();
        factory_map.emplace(
            "CheckPoint",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<CheckPoint>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "Coin",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<Coin>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "DeadTux",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<DeadTux>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                instance->a = (bool)(custom_properties.at("a")->AsMap().at("value")->AsFloat());
                instance->b = custom_properties.at("b")->AsMap().at("value")->AsString();
                instance->c = (custom_properties.at("c")->AsMap().at("value")->AsFloat());
                instance->d = (int)(custom_properties.at("d")->AsMap().at("value")->AsFloat());
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "FireBall",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<FireBall>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "FireFlower",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<FireFlower>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "FlameEffect",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<FlameEffect>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "GameStart",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<GameStart>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                instance->start_level = custom_properties.at("start_level")->AsMap().at("value")->AsString();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "IceBall",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<IceBall>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "IceCap",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<IceCap>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                instance->smart = (bool)(custom_properties.at("smart")->AsMap().at("value")->AsFloat());
                instance->f = (custom_properties.at("f")->AsMap().at("value")->AsFloat());
                instance->name = custom_properties.at("name")->AsMap().at("value")->AsString();
                instance->direction = (custom_properties.at("direction")->AsMap().at("value")->AsFloat());
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "IceCrusher",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<IceCrusher>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "IceFlower",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<IceFlower>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "ItemBox",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<ItemBox>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                instance->item = custom_properties.at("item")->AsMap().at("value")->AsString();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "Key",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<Key>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "LevelGoalTrigger",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<LevelGoalTrigger>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "test::LevelTransitionTrigger",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<test::LevelTransitionTrigger>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                instance->level_path = custom_properties.at("level_path")->AsMap().at("value")->AsString();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "MainMenu",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<MainMenu>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "test::MiddleMan",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<test::MiddleMan>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "PauseMenu",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<PauseMenu>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "custom::PlatformerRectangleCollision",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<custom::PlatformerRectangleCollision>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "PlayerOverworld",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<PlayerOverworld>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "PowerUpEffect",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<PowerUpEffect>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "STA_TileMap",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<STA_TileMap>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "Tux",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<Tux>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "WoodBox",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<WoodBox>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
        factory_map.emplace(
            "WorldMapLevel",
            [](ufo::gc::JsonMap* _json){
                float _x = _json->map.at("x")->AsFloat();
                float _y = _json->map.at("y")->AsFloat();
                auto instance = std::make_unique<WorldMapLevel>(Vector2f(_x, _y));
                try{
                auto custom_properties = _json->map.at("custom_editor_properties")->AsMap();
                instance->level_path = custom_properties.at("level_path")->AsMap().at("value")->AsString();
                } catch(const std::exception& _error){Console::PrintLine("[UFO-Engine] Generated::ActorGenerator:", _error.what());}
                return std::move(instance);
            }
        );
    }
};

}
