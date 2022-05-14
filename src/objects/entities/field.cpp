#include "field.h"
#include "../../Game.h"

namespace pong {
  Field::Field(GameDataRef _data) : VisibleObject("assets/field.png", _data) {}
}