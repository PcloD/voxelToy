#pragma once

#include "src/camera/cameraParameters.h"
#include "src/camera/cameraParameters.h"

class CameraController;

class Camera
{
public:
	Camera();
	~Camera();

	const CameraParameters& parameters() const { return m_parameters; }
	CameraController& controller() const { return *m_controller; }

	void enableDOF(bool enable);
	void setFocalLength(float length);
	void setFocalDistance(float distance);
	void setFilmSize(float filmW, float filmH);
	void setLensRadius(float radius);
	void setFStop(float fstop);

    // set target at supplied location, and move eye position proportionally to
    // the current orientation and distance to camera.
    void centerAt(const Imath::V3f& target);
    void setDistanceToTarget(float distance);

private:
	CameraParameters  m_parameters;
	CameraController* m_controller;
};
