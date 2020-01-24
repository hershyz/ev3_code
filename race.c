#pragma config(Sensor, S1,     sonar,          sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, encoder)

void updateMotors(int speed) {
	speed = speed * -1;
	setMotorSpeed(left, speed);
	setMotorSpeed(right, speed);
}

void capSpeed(int speed, int ms) {
	updateMotors(speed);
	sleep(ms);
}

void accelerate() {
	int currentSpeed = 25;
	for (int leg = 0; leg < 3; leg++) {
		updateMotors(currentSpeed);
		sleep(250);
		currentSpeed = currentSpeed + 25;
	}
}

void decelerate() {
	int currentSpeed = 100;
	for (int leg = 0; leg < 4; leg++) {
		updateMotors(currentSpeed);
		sleep(250);
		currentSpeed = currentSpeed - 25;
	}
}

task main()
{
	accelerate();
	capSpeed(97, 4000);
	decelerate();

	updateMotors(0);
}
