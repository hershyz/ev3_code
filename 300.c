#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, driveRight, encoder)

task main()
{
	//Resets encoders at the beginning:
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	//Moves straight 1500 degrees:
	setMotorTarget(left, 1500, 50);
	setMotorTarget(right, 1500, 50);
	waitUntilMotorStop(left);
	waitUntilMotorStop(right);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	//Pin turn left:
	setMotorTarget(right, 355, 50);
	waitUntilMotorStop(right);
	resetMotorEncoder(right);

	//Moves straight 1450 degrees:
	setMotorTarget(left, 1350, 50);
	setMotorTarget(right, 1350, 50);
	waitUntilMotorStop(left);
	waitUntilMotorStop(right);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	//Pin turn left:
	setMotorTarget(right, 365, 50);
	waitUntilMotorStop(right);
	resetMotorEncoder(right);

	//Moves straight 1500 degrees:
	setMotorTarget(left, 1500, 50);
	setMotorTarget(right, 1500, 50);
	waitUntilMotorStop(left);
	waitUntilMotorStop(right);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	//Pin turn left:
	setMotorTarget(right, 370, 50);
	waitUntilMotorStop(right);
	resetMotorEncoder(right);

	//Moves straight 1275 degrees:
	setMotorTarget(left, 1275, 50);
	setMotorTarget(right, 1275, 50);
	waitUntilMotorStop(left);
	waitUntilMotorStop(right);
	resetMotorEncoder(left);
	resetMotorEncoder(right);

	//Pin turn left:
	setMotorTarget(right, 370, 50);
	waitUntilMotorStop(right);
	resetMotorEncoder(right);

	//Lap 1 Completed, Lap 2 using setMotorSync()
	//Moves straight:
	setMotorSync(left, right, 0, 50);
	sleep(2900);

	//Spin turn left:
	setMotorSync(left, right, -100, 50);
	sleep(360);

	//Moves straight:
	setMotorSync(left, right, 0, 50);
	sleep(3100);

	//Spin turn left:
	setMotorSync(left, right, -100, 50);
	sleep(360);

	//Moves straight:
	setMotorSync(left, right, 0, 50);
	sleep(3200);

	//Spin turn left:
	setMotorSync(left, right, -100, 50);
	sleep(360);

	//Moves straight:
	setMotorSync(left, right, 0, 50);
	sleep(3000);

	//Spin turn left:
	setMotorSync(left, right, -100, 50);
	sleep(380);
}
