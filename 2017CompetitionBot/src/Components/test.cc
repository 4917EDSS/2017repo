#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "spline.h"

double maxAccel = 3000.0; // mm/s^2
double maxDecel = 8000.0; // mm/s^2
double maxVel = 3000.0; // mm/s

// At a given time, each wheel should be meeting one of these
struct PathInfo {
  double dis;
  double vel;
  double accel;
};

// Returns the current path info for TRAPEZOIDAL side
PathInfo getGenerallyFasterSide(double maxDist, double t) {
  //Assuming no crazy curves in spline, and giving reasonable headroom for acceleration + speed. We will tell program "max" is actually lower than max, since we are only programming for the left side. If the right side needs to turn faster than the right, the combination of a smaller max and a reasonable curvature will allow it to get ahead.
  //This means the left side will go "as fast as possible" in this model.
  double adjustedMaxVel = maxVel;
  
  double disToMaxVel = 0.5 * pow(maxVel, 2) / maxAccel;
  double disToZeroVel = 0.5 * pow(maxVel, 2) / maxDecel;
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
  double timeToMaxVel = adjustedMaxVel / maxAccel;
  if (t <= timeToMaxVel) {
    double currentDis = 0.5 * maxAccel * pow(t, 2);
    double currentVel = maxAccel * t;
    return PathInfo{currentDis, currentVel, maxAccel};
  }
  double timeAtMaxVel = (maxDist - disToMaxVel - disToZeroVel) / adjustedMaxVel;
  if (t <= timeToMaxVel + timeAtMaxVel) {
    double currentDis = disToMaxVel + ((t - timeToMaxVel) * adjustedMaxVel);
    return PathInfo{currentDis, adjustedMaxVel, 0};
  }

  double timeDecelerating = t - timeToMaxVel - timeAtMaxVel;

  // x_f = x_i + vt + 0.5at^2
  double currentDis = disToMaxVel + (timeAtMaxVel * adjustedMaxVel)
    + (adjustedMaxVel * timeDecelerating)
    - (0.5 * maxDecel * pow(timeDecelerating, 2));
  double currentVel = adjustedMaxVel - (maxDecel * timeDecelerating);
  return PathInfo{currentDis, currentVel, -maxDecel};
}

PathInfo getGenerallySlowerSide(const tk::spline& s, double fastSideMaxDist, double t) {
  const double deltaT = 0.00001;
  PathInfo beforeFast = getGenerallyFasterSide(fastSideMaxDist, t - deltaT);
  PathInfo currentFast = getGenerallyFasterSide(fastSideMaxDist, t);
  PathInfo afterFast = getGenerallyFasterSide(fastSideMaxDist, t + deltaT);

  // Looking up where side should be according to spline
  double before = s(beforeFast.dis);
  double current = s(currentFast.dis);
  double after = s(afterFast.dis);

  // After and before are 2 deltaTs apart
  double currentVel = (after - before) / (2*deltaT);

  double beforeVel = (current - before) / deltaT;
  double afterVel = (after - current) / deltaT;
  double currentAccel = (afterVel - beforeVel) / deltaT;

  return PathInfo{current, currentVel, currentAccel};
}

int main(int argc, char** argv) {

  std::vector<double> leftWheel(7), rightWheel(7);
  leftWheel[0]=0; leftWheel[1]=500; leftWheel[2]=1200; leftWheel[3]=1600; leftWheel[4]=3000; leftWheel[5]=5000; leftWheel[6]=8000; // target points along path in mm
  rightWheel[0]=0; rightWheel[1]=100; rightWheel[2]=300; rightWheel[3]=1000; rightWheel[4]=3000; rightWheel[5]=4500; rightWheel[6]=7500; // target points along path in mm

  tk::spline s;
  s.set_points(leftWheel,rightWheel);    // currently it is required that leftWheel is already sorted

  printf("Time, LD, LV, LA, RD, RV, RA\n");
  for (double t = 0; t < 3; t += 0.02) {
    PathInfo leftSide = getGenerallyFasterSide(leftWheel[4], t);
    PathInfo rightSide = getGenerallySlowerSide(s, leftWheel[4], t);
    printf("%f, %f, %f, %f, %f, %f, %f\n", t, leftSide.dis, leftSide.vel, leftSide.accel, rightSide.dis, rightSide.vel, rightSide.accel);
  }

  return 0;
}
