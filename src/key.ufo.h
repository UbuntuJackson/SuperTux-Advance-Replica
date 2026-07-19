/* Author: UbuntuJackson, 2026 */

#pragma once
#include <ufo_macros.h>
#include <ufo_maths.h>
#include <console.h>
#include <actor.h>
#include "../generated_base_classes.h"

ufo_category("STA-Replica")
ufo_comment("It's a key to remove those weird key blocks")
ufo_actor_config("src/key.ason")
ufo_class() class Key : public ufo::Generated::Key_BaseClass{
public:

    // Mandatory constructor
    Key(Vector2f _);

    // Called when actor enters level
    void OnSpawn() override;

    // Called every time engine updates level
    void OnUpdate(float _delta_time) override;

};
