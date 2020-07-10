/*
Copyright (c) 2019-2020 Péter Magyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "biome_data.h"

#include "core/version.h"

#include "../main/biome.h"

Ref<Biome> BiomeData::get_biome() {
	return _biome;
}
void BiomeData::set_biome(const Ref<Biome> &biome) {
	_biome = biome;
}

Vector2 BiomeData::get_level_range() {
	return _level_range;
}
void BiomeData::set_level_range(Vector2 value) {
	_level_range = value;
}

Vector2 BiomeData::get_humidity_range() {
	return _humidity_range;
}
void BiomeData::set_humidity_range(Vector2 range) {
	_humidity_range = range;
}

Vector2 BiomeData::get_temperature_range() {
	return _temperature_range;
}
void BiomeData::set_temperature_range(Vector2 range) {
	_temperature_range = range;
}

////    DungeonData    ////

Ref<DungeonData> BiomeData::get_dungeon_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _dungeon_datas.size(), Ref<DungeonData>());

	return _dungeon_datas.get(index);
}
void BiomeData::set_dungeon_data(const int index, const Ref<DungeonData> dungeon_data) {
	ERR_FAIL_INDEX(index, _dungeon_datas.size());

	_dungeon_datas.set(index, dungeon_data);
}
void BiomeData::add_dungeon_data(const Ref<DungeonData> dungeon_data) {
	_dungeon_datas.push_back(dungeon_data);
}
void BiomeData::remove_dungeon_data(const int index) {
	ERR_FAIL_INDEX(index, _dungeon_datas.size());

	_dungeon_datas.remove(index);
}

int BiomeData::get_dungeon_data_count() const {
	return _dungeon_datas.size();
}

Vector<Variant> BiomeData::get_dungeon_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _dungeon_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_dungeon_datas[i].get_ref_ptr());
#else
		r.push_back(_dungeon_datas[i]);
#endif
	}
	return r;
}
void BiomeData::set_dungeon_datas(const Vector<Variant> &dungeon_datas) {
	_dungeon_datas.clear();
	for (int i = 0; i < dungeon_datas.size(); i++) {
		Ref<DungeonData> dungeon_data = Ref<DungeonData>(dungeon_datas[i]);

		_dungeon_datas.push_back(dungeon_data);
	}
}

////    PROP DATA    ////

Ref<WorldGeneratorPropData> BiomeData::get_prop_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _prop_datas.size(), Ref<WorldGeneratorPropData>());

	return _prop_datas.get(index);
}
void BiomeData::set_prop_data(const int index, const Ref<WorldGeneratorPropData> prop_data) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.set(index, prop_data);
}
void BiomeData::add_prop_data(const Ref<WorldGeneratorPropData> prop_data) {
	_prop_datas.push_back(prop_data);
}
void BiomeData::remove_prop_data(const int index) {
	ERR_FAIL_INDEX(index, _prop_datas.size());

	_prop_datas.remove(index);
}

int BiomeData::get_prop_data_count() const {
	return _prop_datas.size();
}

Vector<Variant> BiomeData::get_prop_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _prop_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_prop_datas[i].get_ref_ptr());
#else
		r.push_back(_prop_datas[i]);
#endif
	}
	return r;
}
void BiomeData::set_prop_datas(const Vector<Variant> &prop_datas) {
	_prop_datas.clear();
	for (int i = 0; i < prop_datas.size(); i++) {
		Ref<WorldGeneratorPropData> prop_data = Ref<WorldGeneratorPropData>(prop_datas[i]);

		_prop_datas.push_back(prop_data);
	}
}

#ifdef ESS_PRESENT
//Entities
Ref<EntityData> BiomeData::get_entity_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _entity_datas.size(), Ref<EntityData>());

	return _entity_datas.get(index);
}
void BiomeData::set_entity_data(const int index, const Ref<EntityData> entity_data) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.set(index, entity_data);
}
void BiomeData::add_entity_data(const Ref<EntityData> entity_data) {
	_entity_datas.push_back(entity_data);
}
void BiomeData::remove_entity_data(const int index) {
	ERR_FAIL_INDEX(index, _entity_datas.size());

	_entity_datas.remove(index);
}

int BiomeData::get_entity_data_count() const {
	return _entity_datas.size();
}

Vector<Variant> BiomeData::get_entity_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _entity_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_entity_datas[i].get_ref_ptr());
#else
		r.push_back(_entity_datas[i]);
#endif
	}
	return r;
}
void BiomeData::set_entity_datas(const Vector<Variant> &entity_datas) {
	_entity_datas.clear();
	for (int i = 0; i < entity_datas.size(); i++) {
		Ref<EntityData> entity_data = Ref<EntityData>(entity_datas[i]);

		_entity_datas.push_back(entity_data);
	}
}

#endif

#ifdef VOXELMAN_PRESENT
//Environments
Ref<EnvironmentData> BiomeData::get_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _environment_datas.size(), Ref<EnvironmentData>());

	return _environment_datas.get(index);
}
void BiomeData::set_environment_data(const int index, const Ref<EnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.set(index, environment_data);
}
void BiomeData::add_environment_data(const Ref<EnvironmentData> environment_data) {
	_environment_datas.push_back(environment_data);
}
void BiomeData::remove_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.remove(index);
}
int BiomeData::get_environment_data_count() const {
	return _environment_datas.size();
}

Vector<Variant> BiomeData::get_environment_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _environment_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_environment_datas[i].get_ref_ptr());
#else
		r.push_back(_environment_datas[i]);
#endif
	}
	return r;
}
void BiomeData::set_environment_datas(const Vector<Variant> &environment_datas) {
	_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<EnvironmentData> environment_data = Ref<EnvironmentData>(environment_datas[i]);

		_environment_datas.push_back(environment_data);
	}
}

////    Surfaces    ////
Ref<VoxelSurface> BiomeData::get_voxel_surface(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_surfaces.size(), Ref<VoxelSurface>());

	return _voxel_surfaces.get(index);
}
void BiomeData::set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.set(index, voxel_surface);
}
void BiomeData::add_voxel_surface(const Ref<VoxelSurface> voxel_surface) {
	_voxel_surfaces.push_back(voxel_surface);
}
void BiomeData::remove_voxel_surface(const int index) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.remove(index);
}
int BiomeData::get_voxel_surface_count() const {
	return _voxel_surfaces.size();
}

Vector<Variant> BiomeData::get_voxel_surfaces() {
	Vector<Variant> r;
	for (int i = 0; i < _voxel_surfaces.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_voxel_surfaces[i].get_ref_ptr());
#else
		r.push_back(_voxel_surfaces[i]);
#endif
	}
	return r;
}
void BiomeData::set_voxel_surfaces(const Vector<Variant> &voxel_surfaces) {
	_voxel_surfaces.clear();
	for (int i = 0; i < voxel_surfaces.size(); i++) {
		Ref<EnvironmentData> voxel_surface = Ref<EnvironmentData>(voxel_surfaces[i]);

		_voxel_surfaces.push_back(voxel_surface);
	}
}

#endif

BiomeData::BiomeData() {
}
BiomeData::~BiomeData() {
	_dungeon_datas.clear();
	_prop_datas.clear();

#ifdef ESS_PRESENT
	_entity_datas.clear();
#endif

#ifdef VOXELMAN_PRESENT
	_environment_datas.clear();
	_voxel_surfaces.clear();
	_liquid_voxel_surfaces.clear();
#endif
}

void BiomeData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_biome"), &BiomeData::get_biome);
	ClassDB::bind_method(D_METHOD("set_biome", "value"), &BiomeData::set_biome);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "biome", PROPERTY_HINT_RESOURCE_TYPE, "Biome"), "set_biome", "get_biome");

	ClassDB::bind_method(D_METHOD("get_level_range"), &BiomeData::get_level_range);
	ClassDB::bind_method(D_METHOD("set_level_range", "value"), &BiomeData::set_level_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "level_range"), "set_level_range", "get_level_range");

	ClassDB::bind_method(D_METHOD("get_humidity_range"), &BiomeData::get_humidity_range);
	ClassDB::bind_method(D_METHOD("set_humidity_range", "value"), &BiomeData::set_humidity_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "humidity_range"), "set_humidity_range", "get_humidity_range");

	ClassDB::bind_method(D_METHOD("get_temperature_range"), &BiomeData::get_temperature_range);
	ClassDB::bind_method(D_METHOD("set_temperature_range", "value"), &BiomeData::set_temperature_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "temperature_range"), "set_temperature_range", "get_temperature_range");

	//DungeonDatas
	ClassDB::bind_method(D_METHOD("get_dungeon_data", "index"), &BiomeData::get_dungeon_data);
	ClassDB::bind_method(D_METHOD("set_dungeon_data", "index", "data"), &BiomeData::set_dungeon_data);
	ClassDB::bind_method(D_METHOD("add_dungeon_data", "dungeon_data"), &BiomeData::add_dungeon_data);
	ClassDB::bind_method(D_METHOD("remove_dungeon_data", "index"), &BiomeData::remove_dungeon_data);
	ClassDB::bind_method(D_METHOD("get_dungeon_data_count"), &BiomeData::get_dungeon_data_count);

	ClassDB::bind_method(D_METHOD("get_dungeon_datas"), &BiomeData::get_dungeon_datas);
	ClassDB::bind_method(D_METHOD("set_dungeon_datas", "dungeon_datas"), &BiomeData::set_dungeon_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "dungeon_datas", PROPERTY_HINT_NONE, "17/17:DungeonData", PROPERTY_USAGE_DEFAULT, "DungeonData"), "set_dungeon_datas", "get_dungeon_datas");

	//WorldGeneratorPropData
	ClassDB::bind_method(D_METHOD("get_prop_data", "index"), &BiomeData::get_prop_data);
	ClassDB::bind_method(D_METHOD("set_prop_data", "index", "data"), &BiomeData::set_prop_data);
	ClassDB::bind_method(D_METHOD("add_prop_data", "prop_data"), &BiomeData::add_prop_data);
	ClassDB::bind_method(D_METHOD("remove_prop_data", "index"), &BiomeData::remove_prop_data);
	ClassDB::bind_method(D_METHOD("get_prop_data_count"), &BiomeData::get_prop_data_count);

	ClassDB::bind_method(D_METHOD("get_prop_datas"), &BiomeData::get_prop_datas);
	ClassDB::bind_method(D_METHOD("set_prop_datas", "prop_datas"), &BiomeData::set_prop_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "prop_datas", PROPERTY_HINT_NONE, "17/17:WorldGeneratorPropData", PROPERTY_USAGE_DEFAULT, "WorldGeneratorPropData"), "set_prop_datas", "get_prop_datas");

#ifdef ESS_PRESENT
	//Entities
	ClassDB::bind_method(D_METHOD("get_entity_data", "index"), &BiomeData::get_entity_data);
	ClassDB::bind_method(D_METHOD("set_entity_data", "index", "data"), &BiomeData::set_entity_data);
	ClassDB::bind_method(D_METHOD("add_entity_data", "entity_data"), &BiomeData::add_entity_data);
	ClassDB::bind_method(D_METHOD("remove_entity_data", "index"), &BiomeData::remove_entity_data);
	ClassDB::bind_method(D_METHOD("get_entity_data_count"), &BiomeData::get_entity_data_count);

	ClassDB::bind_method(D_METHOD("get_entity_datas"), &BiomeData::get_entity_datas);
	ClassDB::bind_method(D_METHOD("set_entity_datas", "entity_datas"), &BiomeData::set_entity_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "entity_datas", PROPERTY_HINT_NONE, "17/17:EntityData", PROPERTY_USAGE_DEFAULT, "EntityData"), "set_entity_datas", "get_entity_datas");
#endif

#ifdef VOXELMAN_PRESENT
	//Environments
	ClassDB::bind_method(D_METHOD("get_environment_data", "index"), &BiomeData::get_environment_data);
	ClassDB::bind_method(D_METHOD("set_environment_data", "index", "data"), &BiomeData::set_environment_data);
	ClassDB::bind_method(D_METHOD("add_environment_data", "environment_data"), &BiomeData::add_environment_data);
	ClassDB::bind_method(D_METHOD("remove_environment_data", "index"), &BiomeData::remove_environment_data);
	ClassDB::bind_method(D_METHOD("get_environment_data_count"), &BiomeData::get_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_environment_datas"), &BiomeData::get_environment_datas);
	ClassDB::bind_method(D_METHOD("set_environment_datas", "environment_datas"), &BiomeData::set_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "environment_datas", PROPERTY_HINT_NONE, "17/17:EnvironmentData", PROPERTY_USAGE_DEFAULT, "EnvironmentData"), "set_environment_datas", "get_environment_datas");

	//Surfaces
	ClassDB::bind_method(D_METHOD("get_voxel_surface", "index"), &BiomeData::get_voxel_surface);
	ClassDB::bind_method(D_METHOD("set_voxel_surface", "index", "data"), &BiomeData::set_voxel_surface);
	ClassDB::bind_method(D_METHOD("add_voxel_surface", "voxel_surface"), &BiomeData::add_voxel_surface);
	ClassDB::bind_method(D_METHOD("remove_voxel_surface", "index"), &BiomeData::remove_voxel_surface);
	ClassDB::bind_method(D_METHOD("get_voxel_surface_count"), &BiomeData::get_voxel_surface_count);

	ClassDB::bind_method(D_METHOD("get_voxel_surfaces"), &BiomeData::get_voxel_surfaces);
	ClassDB::bind_method(D_METHOD("set_voxel_surfaces", "voxel_surfaces"), &BiomeData::set_voxel_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_surfaces", PROPERTY_HINT_NONE, "17/17:VoxelSurface", PROPERTY_USAGE_DEFAULT, "VoxelSurface"), "set_voxel_surfaces", "get_voxel_surfaces");
#endif
}
