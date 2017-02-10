#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "spline.h"

float maxAccel = 2000.0 // mm/s^2
float maxDecel = 4000.0 // mm/s^2
float maxVel = 5000.0 // mm/s

// At a given time, each wheel should be meeting one of these
struct PathInfo {
  float dis;
  float vel;
  float accel;
};

// Returns the current path info for TRAPEZOIDAL side
PathInfo getGenerallyFasterSide(float maxDist, float t) {
  //Assuming no crazy curves in spline, and giving reasonable headroom for acceleration + speed. We will tell program "max" is actually lower than max, since we are only programming for the left side. If the right side needs to turn faster than the right, the combination of a smaller max and a reasonable curvature will allow it to get ahead.
  //This means the left side will go "as fast as possible" in this model.
  float adjustedMaxVel = maxVel;
  
  float disToMaxVel = 0.5 * pow(maxVel, 2) / maxAccel;
  float disToZeroVel = 0.5 * pow(maxVel, 2) / maxDecel;
  if (disToMaxVel + disToZeroVel > maxDist) {
    // Don't get to full speed, so triangle instead of trapezoid
    // d_accel = v^2/(2*a_accel)
    // d_decel = v^2/(2*a_decel)
    // d_total = v^2/(2*a_accel) + v^2/(2*a_decel)
    // Rearranging for v gives
    // v = sqrt(2*d_total*a_accel*a_decel/(a_accel + a_decel))
    adjustedMaxVel = sqrt(2 * maxDist * maxAccel * maxDecel / (maxAccel + maxDecel));
    disToMaxVel = 0.5 * pow(adjustedMaxVel, 2) / maxAccel;
    disToZeroVel = 0.5 * pow(adjustedMaxVel, 2) / maxDecel;
  } 
  float timeToMaxVel = adjustedMaxVel / maxAccel;
  if (t <= timeToMaxVel) {
    float currentDis = 0.5 * maxAccel * pow(t, 2);
    float currentVel = maxAccel * t;
    return PathInfo{currentDis, currentVel, maxAccel};
  }
  float timeAtMaxVel = (maxDist - disToMaxVel - disToZeroVel) / adjustedMaxVel;
  if (t <= timeToMaxVel + timeAtMaxVel) {
    float currentDis = disToMaxVel + ((t - timeToMaxVel) * adjustedMaxVel);
    return PathInfo{currentDis, adjustedMaxVel, 0};
  }

  float timeDecelerating = t - timeToMaxVel - timeAtMaxVel;

  // x_f = x_i + vt + 0.5at^2
  float currentDis = disToMaxVel + (timeAtMaxVel * adjustedMaxVel)
    + (adjustedMaxVel * timeDecelerating)
    - (0.5 * maxDecel * pow(timeDecelerating, 2));
  float currentVel = adjustedMaxVel - (maxDecel * t);
  return PathInfo{currentDis, currentVel, -maxDecel};
}

PathInfo getGenerallySlowerSide(const tk::spline& s, float fastSideMaxDist, float t) {
  const float deltaT = 0.00001;
  PathInfo beforeFast = getGenerallyFasterSide(fastSideMaxDist, t - deltaT);
  PathInfo currentFast = getGenerallyFasterSide(fastSideMaxDist, t);
  PathInfo afterFast = getGenerallyFasterSide(fastSideMaxDist, t + deltaT);

  // Looking up where side should be according to spline
  float before = s(beforeFast.dis);
  float current = s(currentFast.dis);
  float after = s(afterFast.dis);

  // After and before are 2 deltaTs apart
  float currentVel = (after - before) / (2*deltaT);

  float beforeVel = (current - before) / deltaT;
  float afterVel = (after - current) / deltaT;
  float currentAccel = (afterVel - beforeVel) / deltaT;

  return PathInfo{current, currentVel, currentAccel};
}

int main(int argc, char** argv) {

  std::vector<double> leftWheel(5), rightWheel(5);
  leftWheel[0]=0; leftWheel[1]=520; leftWheel[2]=1100; leftWheel[3]=1450; leftWheel[4]=1545; // target points along path in mm
  rightWheel[0]=0; rightWheel[1]=500; rightWheel[2]=1000; rightWheel[3]=1250; rightWheel[4]=1345; // target points along path in mm

  tk::spline s;
  s.set_points(leftWheel,rightWheel);    // currently it is required that rightWheel is already sorted

  printf("Time, LD, LV, LA, RD, RV, RA\n", x, s(x));
  for (float t = 0; t < 5; t += 0.02) {
    PathInfo leftSide = getGenerallyFasterSide(leftWheel[4], t);
    PathInfo rightSide = getGenerallySlowerSide(rightWheel[4], t);
    printf("%f, %f, %f, %f, %f, %f, %f\n", t, leftSide.dis, leftSide.vel, leftSide.accel, rightSide.dis, rightSide.vel, rightSide.accel);
  }

  return 0;
}
