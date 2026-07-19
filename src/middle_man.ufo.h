#pragma once
#include <actor.h>
#include <ufo_maths.h>
#include <ufo_macros.h>
#include <animation.h>

namespace test{

ufo_category("Test")
class MiddleMan : public ufo::Actor{
public:
    MiddleMan(Vector2f _) : ufo::Actor(_){}
};


}
