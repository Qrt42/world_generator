#ifndef DUNGEON_ROOM_DATA_H
#define DUNGEON_ROOM_DATA_H

#include "core/resource.h"

#include "../main/dungeon_room.h"
#include "prop_data.h"
#include "../../voxelman/world/environment_data.h"

#include "../../entity_spell_system/entities/data/entity_data.h"

class DungeonRoomData : public Resource {
	GDCLASS(DungeonRoomData, Resource);
	
public:
	Vector2 get_level_range();
	void set_level_range(Vector2 value);

	//Min Size
	int get_min_sizex();
	void set_min_sizex(int value);

	int get_min_sizey();
	void set_min_sizey(int value);

	int get_min_sizez();
	void set_min_sizez(int value);

	//Max Size
	int get_max_sizex();
	void set_max_sizex(int value);

	int get_max_sizey();
	void set_max_sizey(int value);

	int get_max_sizez();
	void set_max_sizez(int value);

	//Prop Data
	Ref<PropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<PropData> prop_data);
	void add_prop_data(const Ref<PropData> prop_data);
	void remove_prop_data(const int index);

	int get_prop_data_count() const;

	Vector<Variant> get_prop_datas();
	void set_prop_datas(const Vector<Variant> &prop_datas);

	//Environments
	Ref<EnvironmentData> get_environment_data(const int index) const;
	void set_environment_data(const int index, const Ref<EnvironmentData> environment_data);
	void add_environment_data(const Ref<EnvironmentData> environment_data);
	void remove_environment_data(const int index);

	int get_environment_data_count() const;

	Vector<Variant> get_environment_datas();
	void set_environment_datas(const Vector<Variant> &environment_datas);

	Ref<DungeonRoom> setup_room(int seed);

	//Entities
	Ref<EntityData> get_entity_data(const int index) const;
	void set_entity_data(const int index, const Ref<EntityData> entity_data);
	void add_entity_data(const Ref<EntityData> entity_data);
	void remove_entity_data(const int index);

	int get_entity_data_count() const;

	Vector<Variant> get_entity_datas();
	void set_entity_datas(const Vector<Variant> &entity_datas);

	DungeonRoomData();
	~DungeonRoomData();

protected:
	static void _bind_methods();

private:
	Vector2 _level_range;

	int _min_sizex;
	int _min_sizey;
	int _min_sizez;

	int _max_sizex;
	int _max_sizey;
	int _max_sizez;

	Vector<Ref<PropData> > _prop_datas;
	Vector<Ref<EntityData> > _entity_datas;
	Vector<Ref<EnvironmentData> > _environment_datas;
};

#endif
