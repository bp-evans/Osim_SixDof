#include <Eigen/Dense>
#include "RigidBody.hh"
#include "EarthModel.hh"
#include "rk4_integ.hh"
#include <cstdio>


int main()
{
    printf("Beginning apposim simulation...\n");
    
    // Set up basic rigid body for our first run through
    Eigen::Vector3d startPos(6778e3, 0, 0);
    Eigen::Vector3d startVel(0, std::sqrt(EARTH_GRAVITATIONAL_PARAMETER / 6778e3), 0);
    RigidBody* basicSatellite = new RigidBody(200, startVel, startPos, "test satellite");

    printf("First rigid body created with name: %s\n", basicSatellite->getName().c_str());
    return 0;
}