#ifndef ___CLASS_GYROSENSOR
#define ___CLASS_GYROSENSOR

class GyroSensor {
private:
	int mangle;
public:
	GyroSensor(int pwm = 0);
	~GyroSensor();
	int getAngle() const;
};

#endif // ___CLASS_GYROSENSOR
