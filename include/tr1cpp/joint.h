#ifndef TR1CPP__JOINT_H
#define TR1CPP__JOINT_H

#include <tr1cpp/i2c.h>

#define ACTUATOR_TYPE_MOTOR 0
#define ACTUATOR_TYPE_SERVO 1

namespace tr1cpp
{
	class Joint
	{
		private:
			uint8_t _motorId = 0;
			uint8_t _actuatorType = 0;
			uint8_t _armSlave1Address = 0x72;
			uint8_t _armSlave2Address = 0x73;
			uint8_t _getSlaveAddress();
			uint8_t _minServoValue = 0;
			uint8_t _maxServoValue = 75;
			double _angleOffset = 0;
			double _previousEffort;
			void _prepareI2CWrite(uint8_t result[4], double effort);
			void _prepareI2CRead(uint8_t result[4]);
		public:
			Joint();
			Joint(uint8_t motorId);
			~Joint();
			void setMotorId(uint8_t motorId);
			void setAngleOffset(double angleOffset);
			void setActuatorType(uint8_t actuatorType);
			void setServoLimits(uint8_t minValue, uint8_t maxValue);
			int getActuatorType();
			void actuate(double effort);
			double readAngle();
	};
}

#endif
