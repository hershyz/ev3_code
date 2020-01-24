#pragma config(Sensor, S3,     light,          sensorEV3_Color)
#pragma config(Sensor, S2,     sonar,          sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void swingRight() {
	setMotorSpeed(left, 20);
	setMotorSpeed(right, 0);
}

void swingLeft() {
	setMotorSpeed(left, 0);
	setMotorSpeed(right, 20);
}

task main()
{
	while (SensorValue(sonar) > 10) {
		if (SensorValue(light) < 15) {
			swingLeft();
		}
		else {
			swingRight();
		}
	}
}