#pragma once
#include "DungeonRoom.h"
#include "UnityEngine.h"
#include <System/System.h>

using namespace System;
namespace BS {
namespace Levels {
namespace Generator {
class DungeonEndRoom : public virtual DungeonRoom, public virtual Object {
public:
	DungeonEndRoom(int x, int y, int width, int height);

public:
	virtual void WriteRoom(ArrayND<char, 2> *dungeon);
};
} // namespace Generator
} // namespace Levels
} // namespace BS
