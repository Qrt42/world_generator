#ifndef dungeon_data_H
#define dungeon_data_H

#include "core/resource.h"
#include "core/vector.h"
#include "core/math/vector2.h"

#include "../main/biome.h"
#include "dungeon_data.h"
#include "prop_data.h"
#include "../../voxelman/world/environment_data.h"
#include "../../entity_spell_system/entities/data/entity_data.h"

class BiomeData : public Resource {
	GDCLASS(BiomeData, Resource);
	
public:
	Vector2 get_level_range();
	void set_level_range(Vector2 value);

	Vector2 get_humidity_range();
	void set_humidity_range(Vector2 range);

	Vector2 get_temperature_range();
	void set_temperature_range(Vector2 range);

	//DungeonData
	Ref<DungeonData> get_dungeon_data(const int index) const;
	void set_dungeon_data(const int index, const Ref<DungeonData> dungeon_data);
	void add_dungeon_data(const Ref<DungeonData> dungeon_data);
	void remove_dungeon_data(const int index);

	int get_dungeon_data_count() const;

	Vector<Variant> get_dungeon_datas();
	void set_dungeon_datas(const Vector<Variant> &dungeon_datas);

	//PropData
	Ref<PropData> get_prop_data(const int index) const;
	void set_prop_data(const int index, const Ref<PropData> prop_data);
	void add_prop_data(const Ref<PropData> prop_data);
	void remove_prop_data(const int index);

	int get_prop_data_count() const;

	Vector<Variant> get_prop_datas();
	void set_prop_datas(const Vector<Variant> &prop_datas);

	//Entities
	Ref<EntityData> get_entity_data(const int index) const;
	void set_entity_data(const int index, const Ref<EntityData> entity_data);
	void add_entity_data(const Ref<EntityData> entity_data);
	void remove_entity_data(const int index);

	int get_entity_data_count() const;

	Vector<Variant> get_entity_datas();
	void set_entity_datas(const Vector<Variant> &entity_datas);

	//Environments
	Ref<EnvironmentData> get_environment_data(const int index) const;
	void set_environment_data(const int index, const Ref<EnvironmentData> environment_data);
	void add_environment_data(const Ref<EnvironmentData> environment_data);
	void remove_environment_data(const int index);

	int get_environment_data_count() const;

	Vector<Variant> get_environment_datas();
	void set_environment_datas(const Vector<Variant> &environment_datas);

	Ref<Biome> setup_biome(int seed);

	BiomeData();
	~BiomeData();

protected:
	static void _bind_methods();

private:
	Vector2 _level_range;

	Vector2 _humidity_range;
	Vector2 _temperature_range;

	Vector<Ref<DungeonData> > _dungeon_datas;
	Vector<Ref<PropData> > _prop_datas;
	Vector<Ref<EntityData> > _entity_datas;
	Vector<Ref<EnvironmentData> > _environment_datas;
};

#endif
