// Brandon Evans
// 11/24/2025

#include <Eigen/Dense>
#include <string>

/** 
*
* Rigid body is the base of all natural/artifical objects in orbit, will be inherited by more complex objects
* Parameters
*   
*/
class RigidBody 
{
    public:
        RigidBody(double mass, Eigen::Vector3d velocity, Eigen::Vector3d eciPos, std::string objName);
        ~RigidBody();

        double getMass() { return _mass; }

        Eigen::Vector3d getVelocity() { return _velocity; }

        Eigen::Vector3d getEciPos() { return _eciPos; }

        void updateState(double inMass, Eigen::Vector3d inVel, Eigen::Vector3d inEciPos);

        void activateBody();

        void deactivateBody();
        
    private:
        // Core member variables
        double _mass;
        Eigen::Vector3d _velocity;
        Eigen::Vector3d _eciPos;
        bool isActive;
        std::string _objName;
};