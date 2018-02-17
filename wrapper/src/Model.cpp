// Model.cpp

#include "Model.h"

//Model Model::create() {
//Model  m;
//return m;
//}

Model Model::create(std::string path)
{
	Model m;
	m.create_from_file(path);
	return m;
}


Entities Model::entities() const
{
	Entities e(_ref);
	return e;
}

std::string Model::version_string() const
{
	int major{ 0 };
	int minor{ 0 };
	int build{ 0 };
	SUModelGetVersion(_ref, &major, &minor, &build);
	std::ostringstream os;
	os << major << "." << minor << "." << build;
	return os.str();
}

void Model::create_from_file(std::string filename)
{
	SUModelRef model = SU_INVALID;
	SUResult res = SU_ERROR_NONE;
	SUModelCreateFromFile(&model, filename.c_str());
	assert(res == SU_ERROR_NONE);
	_ref = model;
}

std::list<std::pair<std::string, int>> Model::stats()
{
	SUModelStatistics stats;
	SUModelGetStatistics(_ref, &stats);
	std::list<std::pair<std::string, int>> data{};
	data.push_back(std::make_pair("Edges", stats.entity_counts[SUModelStatistics::SUEntityType_Edge]));
	data.push_back(std::make_pair("Faces", stats.entity_counts[SUModelStatistics::SUEntityType_Face]));
	data.push_back(std::make_pair("Instances", stats.entity_counts[SUModelStatistics::SUEntityType_ComponentInstance]));
	data.push_back(std::make_pair("Groups", stats.entity_counts[SUModelStatistics::SUEntityType_Group]));
	data.push_back(std::make_pair("Images", stats.entity_counts[SUModelStatistics::SUEntityType_Image]));
	data.push_back(std::make_pair("Definitions", stats.entity_counts[SUModelStatistics::SUEntityType_ComponentDefinition]));
	data.push_back(std::make_pair("Layers", stats.entity_counts[SUModelStatistics::SUEntityType_Layer]));
	data.push_back(std::make_pair("Materials", stats.entity_counts[SUModelStatistics::SUEntityType_Material]));
	return data;
}

/*
SUModelStatistics stats = model.stats();
cout << "Edges: " << stats.entity_counts[SUModelStatistics::SUEntityType_Edge] << endl;
cout << "Faces: " << stats.entity_counts[SUModelStatistics::SUEntityType_Face] << endl;
cout << "Ins: " << stats.entity_counts[SUModelStatistics::SUEntityType_ComponentInstance] << endl;*/