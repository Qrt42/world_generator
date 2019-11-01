#ifndef biome_data_H
#define biome_data_H

#include "core/resource.h"

#include "../../fastnoise/fastnoise_noise_params.h"

#include "../main/planet.h"
#include "../data/biome_data.h"
#include "../../voxelman/world/environment_data.h"

class PlanetData : public Resource {
	GDCLASS(PlanetData, Resource);
	
public:
	int get_id() const;
	void set_id(const int value);

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

	//Environments
	Ref<EnvironmentData> get_environment_data(const int index) const;
	void set_environment_data(const int index, const Ref<EnvironmentData> environment_data);
	void add_environment_data(const Ref<EnvironmentData> environment_data);
	void remove_environment_data(const int index);

	int get_environment_data_count() const;

	Vector<Variant> get_environment_datas();
	void set_environment_datas(const Vector<Variant> &environment_datas);

	Ref<Planet> setup_planet(int seed);

	PlanetData();
	~PlanetData();

protected:
	static void _bind_methods();

private:
	int _id;

	Vector2 _level_range;

	Ref<FastnoiseNoiseParams> _humidity_noise_params;
	Ref<FastnoiseNoiseParams> _temperature_noise_params;
	Vector<Ref<BiomeData> > _biome_datas;
	Vector<Ref<EnvironmentData> > _environment_datas;
};

#endif
