#include <iostream>
#include <gdal/ogr_geometry.h>
int main() {
   OGREnvelope envelope;
   OGRGeometry *geometry;
   char wkt[] = "MULTIPOINT(1 0,3 1,2 3,0 2)";
   char *p = (char*) wkt;
   if(OGRGeometryFactory::createFromWkt(&p, nullptr, &geometry) == OGRERR_NONE){
       geometry->getEnvelope(&envelope);
       std::cout << envelope.MaxX << envelope.MaxY << envelope.MinX << envelope.MinY << std::endl;
        OGRGeometryFactory::destroyGeometry(geometry);
   }
    return 0;
}
