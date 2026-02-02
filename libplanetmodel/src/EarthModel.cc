// Brandon Evans
// 11/24/2025

#include <Eigen/Dense>
#include <EarthModel.hh>

const double EarthModel::_earthMass = 5.972e24;      // kg
const double EarthModel::_earthRadius = 6371e3;      // m
const double EarthModel::_mu = 3.986004418e14;       // m^3/s^2 (μ = G*M)

// Calculate the acceleration in m/s^2 induced by gravity at a certain position in ECI coordinates
Eigen::Vector3d EarthModel::calcGravity(Eigen::Vector3d eciPos)
{
    double magPosVector = eciPos.norm(); // here our incoming position is used to get our total distance from center of the Earth
    return -(_mu * (magPosVector*magPosVector*magPosVector)) * eciPos; // calculate a = -(μ/|eciPos|^3) * eciPos
}

bool EarthModel::checkCollision(Eigen::Vector3d eciPos)
{
    double magPosVector = eciPos.norm(); // get the total distance of our current position from the center of the Earth
    if( magPosVector <= abs(_earthRadius) )
    {
        printf("Collision with Earth has occured!");
        return true;
    }
    else
    {
        return false;
    }
}

