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

#include "planet_data.h"

#include "core/version.h"

#include "../main/planet.h"

int PlanetData::get_id() const {
	return _id;
}
void PlanetData::set_id(const int value) {
	_id = value;
}

Ref<Planet> PlanetData::get_planet() {
	return _planet;
}
void PlanetData::set_planet(const Ref<Planet> &planet) {
	_planet = planet;
}

Vector2 PlanetData::get_level_range() {
	return _level_range;
}
void PlanetData::set_level_range(Vector2 value) {
	_level_range = value;
}

#ifdef FASTNOISE_PRESENT
Ref<FastnoiseNoiseParams> PlanetData::get_humidity_noise_params() {
	return _humidity_noise_params;
}
void PlanetData::set_humidity_noise_params(Ref<FastnoiseNoiseParams> value) {
	_humidity_noise_params = value;
}

Ref<FastnoiseNoiseParams> PlanetData::get_temperature_noise_params() {
	return _temperature_noise_params;
}
void PlanetData::set_temperature_noise_params(Ref<FastnoiseNoiseParams> value) {
	_temperature_noise_params = value;
}
#endif

//Biomes
Ref<BiomeData> PlanetData::get_biome_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _biome_datas.size(), Ref<BiomeData>());

	return _biome_datas.get(index);
}
void PlanetData::set_biome_data(const int index, const Ref<BiomeData> biome_data) {
	ERR_FAIL_INDEX(index, _biome_datas.size());

	_biome_datas.set(index, biome_data);
}
void PlanetData::add_biome_data(const Ref<BiomeData> biome_data) {
	_biome_datas.push_back(biome_data);
}
void PlanetData::remove_biome_data(const int index) {
	ERR_FAIL_INDEX(index, _biome_datas.size());

	_biome_datas.remove(index);
}
int PlanetData::get_biome_data_count() const {
	return _biome_datas.size();
}

Vector<Variant> PlanetData::get_biome_datas() {
	Vector<Variant> r;
	for (int i = 0; i < _biome_datas.size(); i++) {
#if VERSION_MAJOR < 4
		r.push_back(_biome_datas[i].get_ref_ptr());
#else
		r.push_back(_biome_datas[i]);
#endif
	}
	return r;
}
void PlanetData::set_biome_datas(const Vector<Variant> &biome_datas) {
	_biome_datas.clear();
	for (int i = 0; i < biome_datas.size(); i++) {
		Ref<BiomeData> biome_data = Ref<BiomeData>(biome_datas[i]);

		_biome_datas.push_back(biome_data);
	}
}

#ifdef VOXELMAN_PRESENT
//Environments
Ref<EnvironmentData> PlanetData::get_environment_data(const int index) const {
	ERR_FAIL_INDEX_V(index, _environment_datas.size(), Ref<EnvironmentData>());

	return _environment_datas.get(index);
}
void PlanetData::set_environment_data(const int index, const Ref<EnvironmentData> environment_data) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.set(index, environment_data);
}
void PlanetData::add_environment_data(const Ref<EnvironmentData> environment_data) {
	_environment_datas.push_back(environment_data);
}
void PlanetData::remove_environment_data(const int index) {
	ERR_FAIL_INDEX(index, _environment_datas.size());

	_environment_datas.remove(index);
}
int PlanetData::get_environment_data_count() const {
	return _environment_datas.size();
}

Vector<Variant> PlanetData::get_environment_datas() {
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
void PlanetData::set_environment_datas(const Vector<Variant> &environment_datas) {
	_environment_datas.clear();
	for (int i = 0; i < environment_datas.size(); i++) {
		Ref<EnvironmentData> environment_data = Ref<EnvironmentData>(environment_datas[i]);

		_environment_datas.push_back(environment_data);
	}
}

////    Surfaces    ////
Ref<VoxelSurface> PlanetData::get_voxel_surface(const int index) const {
	ERR_FAIL_INDEX_V(index, _voxel_surfaces.size(), Ref<VoxelSurface>());

	return _voxel_surfaces.get(index);
}
void PlanetData::set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.set(index, voxel_surface);
}
void PlanetData::add_voxel_surface(const Ref<VoxelSurface> voxel_surface) {
	_voxel_surfaces.push_back(voxel_surface);
}
void PlanetData::remove_voxel_surface(const int index) {
	ERR_FAIL_INDEX(index, _voxel_surfaces.size());

	_voxel_surfaces.remove(index);
}
int PlanetData::get_voxel_surface_count() const {
	return _voxel_surfaces.size();
}

Vector<Variant> PlanetData::get_voxel_surfaces() {
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
void PlanetData::set_voxel_surfaces(const Vector<Variant> &voxel_surfaces) {
	_voxel_surfaces.clear();
	for (int i = 0; i < voxel_surfaces.size(); i++) {
		Ref<EnvironmentData> voxel_surface = Ref<EnvironmentData>(voxel_surfaces[i]);

		_voxel_surfaces.push_back(voxel_surface);
	}
}

#endif

Ref<Planet> PlanetData::instance() {
	Ref<Planet> planet;

	if (!_planet.is_valid()) {
		planet.instance();
	} else {
		planet = _planet->duplicate();
	}

	planet->set_data(Ref<PlanetData>(this));

	return planet;
}

PlanetData::PlanetData() {
	_id = 0;
}
PlanetData::~PlanetData() {
#ifdef FASTNOISE_PRESENT
	_humidity_noise_params.unref();
	_temperature_noise_params.unref();
#endif

	_biome_datas.clear();

#ifdef VOXELMAN_PRESENT
	_environment_datas.clear();
	_voxel_surfaces.clear();
	_liquid_voxel_surfaces.clear();
#endif
}

void PlanetData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_id"), &PlanetData::get_id);
	ClassDB::bind_method(D_METHOD("set_id", "value"), &PlanetData::set_id);
	ADD_PROPERTY(PropertyInfo(Variant::INT, "id"), "set_id", "get_id");

	ClassDB::bind_method(D_METHOD("get_planet"), &PlanetData::get_planet);
	ClassDB::bind_method(D_METHOD("set_planet", "value"), &PlanetData::set_planet);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "planet", PROPERTY_HINT_RESOURCE_TYPE, "Planet"), "set_planet", "get_planet");

	ClassDB::bind_method(D_METHOD("get_level_range"), &PlanetData::get_level_range);
	ClassDB::bind_method(D_METHOD("set_level_range", "value"), &PlanetData::set_level_range);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "level_range"), "set_level_range", "get_level_range");

#ifdef FASTNOISE_PRESENT
	ClassDB::bind_method(D_METHOD("get_humidity_noise_params"), &PlanetData::get_humidity_noise_params);
	ClassDB::bind_method(D_METHOD("set_humidity_noise_params", "value"), &PlanetData::set_humidity_noise_params);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "humidity_noise_params", PROPERTY_HINT_RESOURCE_TYPE, "FastnoiseNoiseParams"), "set_humidity_noise_params", "get_humidity_noise_params");

	ClassDB::bind_method(D_METHOD("get_temperature_noise_params"), &PlanetData::get_temperature_noise_params);
	ClassDB::bind_method(D_METHOD("set_temperature_noise_params", "value"), &PlanetData::set_temperature_noise_params);
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "temperature_noise_params", PROPERTY_HINT_RESOURCE_TYPE, "FastnoiseNoiseParams"), "set_temperature_noise_params", "get_temperature_noise_params");
#endif

	//Biomes
	ClassDB::bind_method(D_METHOD("get_biome_data", "index"), &PlanetData::get_biome_data);
	ClassDB::bind_method(D_METHOD("set_biome_data", "index", "data"), &PlanetData::set_biome_data);
	ClassDB::bind_method(D_METHOD("add_biome_data", "biome_data"), &PlanetData::add_biome_data);
	ClassDB::bind_method(D_METHOD("remove_biome_data", "index"), &PlanetData::remove_biome_data);
	ClassDB::bind_method(D_METHOD("get_biome_data_count"), &PlanetData::get_biome_data_count);

	ClassDB::bind_method(D_METHOD("get_biome_datas"), &PlanetData::get_biome_datas);
	ClassDB::bind_method(D_METHOD("set_biome_datas", "biome_datas"), &PlanetData::set_biome_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "biome_datas", PROPERTY_HINT_NONE, "17/17:BiomeData", PROPERTY_USAGE_DEFAULT, "BiomeData"), "set_biome_datas", "get_biome_datas");

#ifdef VOXELMAN_PRESENT
	//Environments
	ClassDB::bind_method(D_METHOD("get_environment_data", "index"), &PlanetData::get_environment_data);
	ClassDB::bind_method(D_METHOD("set_environment_data", "index", "data"), &PlanetData::set_environment_data);
	ClassDB::bind_method(D_METHOD("add_environment_data", "environment_data"), &PlanetData::add_environment_data);
	ClassDB::bind_method(D_METHOD("remove_environment_data", "index"), &PlanetData::remove_environment_data);
	ClassDB::bind_method(D_METHOD("get_environment_data_count"), &PlanetData::get_environment_data_count);

	ClassDB::bind_method(D_METHOD("get_environment_datas"), &PlanetData::get_environment_datas);
	ClassDB::bind_method(D_METHOD("set_environment_datas", "environment_datas"), &PlanetData::set_environment_datas);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "environment_datas", PROPERTY_HINT_NONE, "17/17:EnvironmentData", PROPERTY_USAGE_DEFAULT, "EnvironmentData"), "set_environment_datas", "get_environment_datas");

	//Surfaces
	ClassDB::bind_method(D_METHOD("get_voxel_surface", "index"), &PlanetData::get_voxel_surface);
	ClassDB::bind_method(D_METHOD("set_voxel_surface", "index", "data"), &PlanetData::set_voxel_surface);
	ClassDB::bind_method(D_METHOD("add_voxel_surface", "voxel_surface"), &PlanetData::add_voxel_surface);
	ClassDB::bind_method(D_METHOD("remove_voxel_surface", "index"), &PlanetData::remove_voxel_surface);
	ClassDB::bind_method(D_METHOD("get_voxel_surface_count"), &PlanetData::get_voxel_surface_count);

	ClassDB::bind_method(D_METHOD("get_voxel_surfaces"), &PlanetData::get_voxel_surfaces);
	ClassDB::bind_method(D_METHOD("set_voxel_surfaces", "voxel_surfaces"), &PlanetData::set_voxel_surfaces);
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "voxel_surfaces", PROPERTY_HINT_NONE, "17/17:VoxelSurface", PROPERTY_USAGE_DEFAULT, "VoxelSurface"), "set_voxel_surfaces", "get_voxel_surfaces");
#endif

	ClassDB::bind_method(D_METHOD("instance"), &PlanetData::instance);
}
