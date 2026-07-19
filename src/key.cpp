#include <ufo_macros.h>
#include <ufo_maths.h>
#include <console.h>
#include <actor.h>
//#include <animation.h>
//#include <sprite.h>
#include "../generated_base_classes.h"
#include "key.ufo.h"

Key::Key(Vector2f _) : ufo::Generated::Key_BaseClass(_){}

// Called when actor enters level
void Key::OnSpawn() {
    ufo::Generated::Key_BaseClass::OnSpawn();

    Console::PrintLine("MyActor Spawned");
}

// Called every time engine updates level
void Key::OnUpdate(float _delta_time) {
    ufo::Generated::Key_BaseClass::OnUpdate(_delta_time);

    Console::PrintLine("MyActor Delta Time:",_delta_time);
}
