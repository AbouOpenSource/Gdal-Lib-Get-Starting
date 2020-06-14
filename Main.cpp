//
// Created by abou on 15/06/2020.
//

#include <iostream>
#include <gdal/ogr_geometry.h>
#include <functional>

std::vector<std::string> shapes {
    "LINESTRING(0 1,1 0,1 2,0 1)",
    "POINT(1 1)",
    "MULTIPOINT((1 1), (3 3))",
    "POLYGON((0 1,1 0,1 2,0 1))",
    "POLYGON((0.25 1,0.8 0.25,0.8 1.75,0.25 1))",
    "POLYGON((0.5 1.1,5 0,1.5 2,0.5 1))",

};
std::vector<OGRGeometry *> buildGeometries(){
    std::vector<OGRGeometry *> geometries;
    char *p;
    for (auto &shape: shapes) {
        p = (char*) shape.c_str();
        OGRGeometry *g;
        if(OGRGeometryFactory::createFromWkt(&p, nullptr, &g)!= -1){
        geometries.push_back(g);
        } else{
            std::cout << "Cannot create from : "<< shape<< std::endl;
        }
    }
    return geometries;
}

int main() {

    std::vector<OGRGeometry * > geometries = buildGeometries();
    std::map<std::string, std::function<int(const OGRGeometry&, OGRGeometry *)>> functions{
            {"Equals: ",&OGRGeometry::Equals},
            {"Crosses: ",&OGRGeometry::Crosses},
            {"Intersects: ",&OGRGeometry::Intersects},
            {"Contains: ",&OGRGeometry::Contains},
            {"Touches: ",&OGRGeometry::Touches},
            {"Overlaps: ",&OGRGeometry::Overlaps},


    };
    for (auto &item: functions) {
        std::cout<< item.first<< std::endl;
        for (int i = 0; i <geometries.size() ; ++i) {
            for (int j = 0; j < geometries.size(); ++j) {
                std::cout << item.second(*geometries[i],geometries[j]) << " ";
            }
            std::cout << std::endl;
        }
    }
    for (auto geometry: geometries) {
        OGRGeometryFactory::destroyGeometry(geometry);
    }
    return 0;
}
