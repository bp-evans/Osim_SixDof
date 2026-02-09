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

        Eigen::Vector3d getPos() { return _pos; }

        void updateState(double inMass, Eigen::Vector3d inVel, Eigen::Vector3d inPos);

        void activateBody();

        void deactivateBody();

        std::string getName() { return _objName; }
        
    private:
        // Core member variables
        double _mass;
        Eigen::Vector3d _velocity;
        Eigen::Vector3d _pos;
        bool isActive;
        std::string _objName;
};