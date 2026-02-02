// Brandon Evans
// 11/24/2025

#include <Eigen/Dense>

/** 
* EarthModel is a basic class to contain the for now basic information needed for gravitational calculations assuming Earth is a point source.
* Radius for now is only to allow for collision basic checking.
*   
*/
class EarthModel
{
    public:
        EarthModel();
        ~EarthModel();

        Eigen::Vector3d calcGravity(Eigen::Vector3d eciPos);
        bool checkCollision(const Eigen::Vector3d eciPos);

        double getEarthMass() { return _earthMass; }
        double getEarthRadius() { return _earthRadius; }
        double getGravConstant() { return _mu; }

    private:
        static const double _earthMass;      // kg
        static const double _earthRadius;    // m
        static const double _mu;             // m^3/s^2
};