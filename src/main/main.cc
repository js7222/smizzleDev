#include <iostream> 
#include <iomanip> 
#include <boost/units/base_units/angle/radian.hpp> 
#include <boost/units/systems/si/io.hpp> 
#include <cmath>
#include <unistd.h>
#include <cstdio>
#include <pendulum.h>

int main() 
{ 
  typedef boost::units::quantity<boost::units::si::angular_velocity> AngularVelocity; 
  using boost::units::si::radians_per_second; 

  typedef boost::units::quantity<boost::units::si::plane_angle> Angle;
  using boost::units::si::radians;
  typedef boost::units::quantity<boost::units::si::time> Time;
  using boost::units::si::seconds;
  const Angle angle(2.0 * M_PI * radians);
  const Time time(16 * seconds);
  const AngularVelocity av = angle/time;
  
  const AngularVelocity delta(2.0 * M_PI * radians_per_second / 16.0); 
  const AngularVelocity j(2.0 * M_PI * radians_per_second); 
  std::cout << std::setprecision(20); 
  for (AngularVelocity i(0.0 * M_PI * radians_per_second); i<j; i+=delta) 
  { 
    std::cout << "sin(" << i << ") = " << std::sin(i.value()) << '\n'; 
  } 

  double thetaCurrent = M_PI / 4;
  double omegaCurrent = .0;
  double deltaT = .0001;

  while(true)
  {
//      std::cout << "thetaCurrent: " << thetaCurrent << " omegaCurrent: " << omegaCurrent << std::endl;
//      fflush(stdout);
//      double thetaNext = thetaCurrent + omegaCurrent * deltaT;
//      double omegaNext = omegaCurrent - thetaCurrent * deltaT;
//      thetaCurrent = thetaNext;
//      omegaCurrent = omegaNext;
//      usleep(100);
      break;
  }
  smizzle::pendulum::Pendulum::callThePendulum();

} 
