// Brandon Evans
// 2026-02-02

#ifndef OSIM_RK4_INTEG_HH
#define OSIM_RK4_INTEG_HH

#include <Eigen/Dense>

// Earth gravitational parameter (mu = G * M) in m^3/s^2
constexpr double EARTH_GRAVITATIONAL_PARAMETER = 3.986004418e14;

struct State {
    Eigen::Vector3d position;
    Eigen::Vector3d velocity;
};

// Computes the derivative of the state for a two-body gravity model.
State derivative(const State& state);

// Performs a single step of the Runge-Kutta 4th order integration method.
State rk4(const State& s, double dt);

// Computes acceleration due to two-body gravity for a given ECEF position.
Eigen::Vector3d two_body_acceleration(const Eigen::Vector3d& posECEF);


#endif // OSIM_RK4_INTEG_HH