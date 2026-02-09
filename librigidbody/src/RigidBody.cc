// Brandon Evans
// 11/24/2025

#include <Eigen/Dense>
#include "RigidBody.hh"

const int V3_SIZE = 3;

/** 
* 
* Rigid body is the base of all natural/artifical objects in orbit, will be inherited by more complex objects
* Parameters
*   
*/
RigidBody::RigidBody(double mass, Eigen::Vector3d velocity, Eigen::Vector3d eciPos, std::string objName) 
{
    _mass = mass;
    _velocity = velocity;
    _pos = eciPos;
    isActive = false;
    _objName = objName;
}

void RigidBody::activateBody() 
{
    isActive = true;
}

void RigidBody::deactivateBody()
{
    isActive = false;
}

void RigidBody::updateState(double inMass, Eigen::Vector3d inVel, Eigen::Vector3d inPos)
{
    _mass = inMass;
    for (int i = 0;i < V3_SIZE;i++)
    {
        _velocity(i) = inVel(i);
        _pos(i) = inPos(i);
    }
}