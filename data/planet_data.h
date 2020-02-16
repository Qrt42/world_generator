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

#ifndef biome_data_H
#define biome_data_H

#include "core/resource.h"
#include "core/script_language.h"
#include "core/ustring.h"

#include "../../fastnoise/fastnoise_noise_params.h"

#include "../data/biome_data.h"
#include "../main/planet.h"

#ifdef VOXELMAN_PRESENT
#include "../../voxelman/library/voxel_surface.h"
#include "../../voxelman/world/environment_data.h"
#endif

class PlanetData : public Resource {
	GDCLASS(PlanetData, Resource);

public:
	int get_id() const;
	void set_id(const int value);

	String get_target_class_name();
	void set_target_class_name(String name);

	Ref<Script> get_target_script();
	void set_target_script(Ref<Script> script);

	Vector2 get_level_range();
	void set_level_range(Vector2 value);

	Ref<FastnoiseNoiseParams> get_humidity_noise_params();
	void set_humidity_noise_params(Ref<FastnoiseNoiseParams> value);

	Ref<FastnoiseNoiseParams> get_temperature_noise_params();
	void set_temperature_noise_params(Ref<FastnoiseNoiseParams> value);

	//Biomes
	Ref<BiomeData> get_biome_data(const int index) const;
	void set_biome_data(const int index, const Ref<BiomeData> biome_data);
	void add_biome_data(const Ref<BiomeData> biome_data);
	void remove_biome_data(const int index);
	int get_biome_data_count() const;

	Vector<Variant> get_biome_datas();
	void set_biome_datas(const Vector<Variant> &biome_datas);

#ifdef VOXELMAN_PRESENT
	//Environments
	Ref<EnvironmentData> get_environment_data(const int index) const;
	void set_environment_data(const int index, const Ref<EnvironmentData> environment_data);
	void add_environment_data(const Ref<EnvironmentData> environment_data);
	void remove_environment_data(const int index);
	int get_environment_data_count() const;

	Vector<Variant> get_environment_datas();
	void set_environment_datas(const Vector<Variant> &environment_datas);

	//Surfaces
	Ref<VoxelSurface> get_voxel_surface(const int index) const;
	void set_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface);
	void add_voxel_surface(const Ref<VoxelSurface> voxel_surface);
	void remove_voxel_surface(const int index);
	int get_voxel_surface_count() const;

	Vector<Variant> get_voxel_surfaces();
	void set_voxel_surfaces(const Vector<Variant> &voxel_surfaces);

	//Liquid Surfaces
	Ref<VoxelSurface> get_liquid_voxel_surface(const int index) const;
	void set_liquid_voxel_surface(const int index, const Ref<VoxelSurface> voxel_surface);
	void add_liquid_surface(const Ref<VoxelSurface> voxel_surface);
	void remove_liquid_voxel_surface(const int index);
	int get_liquid_voxel_surface_count() const;

	Vector<Variant> get_liquid_voxel_surfaces();
	void set_liquid_voxel_surfaces(const Vector<Variant> &voxel_surfaces);
#endif

	PlanetData();
	~PlanetData();

protected:
	static void _bind_methods();

private:
	int _id;

	String _target_class_name;
	Ref<Script> _target_script;

	Vector2 _level_range;

	Ref<FastnoiseNoiseParams> _humidity_noise_params;
	Ref<FastnoiseNoiseParams> _temperature_noise_params;
	Vector<Ref<BiomeData> > _biome_datas;

#ifdef VOXELMAN_PRESENT
	Vector<Ref<EnvironmentData> > _environment_datas;
	Vector<Ref<VoxelSurface> > _voxel_surfaces;
	Vector<Ref<VoxelSurface> > _liquid_voxel_surfaces;
#endif
};

#endif
