// Brandon Evans
// 2026-02-02

#include "rk4_integ.hh"


Eigen::Vector3d two_body_acceleration(const Eigen::Vector3d& posECEF) {
    const double pos_norm = posECEF.norm();
    if (pos_norm == 0.0) {
        return Eigen::Vector3d::Zero();
    }
    return -EARTH_GRAVITATIONAL_PARAMETER * posECEF / (pos_norm * pos_norm * pos_norm);
}

State derivative(const State& state) {
    State ds;
    ds.position = state.velocity;
    ds.velocity = two_body_acceleration(state.position);
    return ds;
}

State rk4(const State& s, double dt) {
    const State k1 = derivative(s);

    State s2;
    s2.position = s.position + 0.5 * dt * k1.position;
    s2.velocity = s.velocity + 0.5 * dt * k1.velocity;
    const State k2 = derivative(s2);

    State s3;
    s3.position = s.position + 0.5 * dt * k2.position;
    s3.velocity = s.velocity + 0.5 * dt * k2.velocity;
    const State k3 = derivative(s3);

    State s4;
    s4.position = s.position + dt * k3.position;
    s4.velocity = s.velocity + dt * k3.velocity;
    const State k4 = derivative(s4);

    State outState;
    outState.position = s.position + (dt / 6.0) * (k1.position + 2.0 * k2.position + 2.0 * k3.position + k4.position);
    outState.velocity = s.velocity + (dt / 6.0) * (k1.velocity + 2.0 * k2.velocity + 2.0 * k3.velocity + k4.velocity);

    return outState;
}
