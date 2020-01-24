#pragma config(Sensor, S2,     ultrasonic,     sensorNone)
#pragma config(Sensor, S3,     light,          sensorEV3_Color)
#pragma config(Sensor, S4,     touch,          sensorEV3_Touch)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, encoder)

int lightVal;
int darkVal;
int sum;
int t;

void turnAround() {
	setMotorSpeed(left, -30);
	setMotorSpeed(right, 30);
	sleep(1150);
}

void autoThreshold() {
	while (SensorValue(touch) != 1) {
		displayBigTextLine(5, "Read Light Value");
	}

	lightVal = SensorValue(light);
	eraseDisplay();
	sleep(1000);

	while (SensorValue(touch) != 1) {
		displayBigTextLine(5, "Read Dark Value");
	}

	darkVal = SensorValue(light);
	eraseDisplay();

	sum = lightVal + darkVal;
	t = sum / 2;

	sleep(2000);
}

void go(int lines) {
	int countedLines = 0;
	int seenLight = 1;

	while (countedLines < lines) {
		setMotorSpeed(left, 30);
		setMotorSpeed(right, 30);

		if (SensorValue(light) <= t) {
			if (seenLight == 1) {
				countedLines = countedLines + 1;
				seenLight = 0;
			}
		}
		else {
			seenLight = 1;
		}
	}
}

task main()
{
	autoThreshold();

	go(1);
	turnAround();
	go(1);
	turnAround();
	go(2);
	turnAround();
	go(2);
	turnAround();
	go(3);
	turnAround();
	go(3);
	turnAround();
	go(4);
	turnAround();
	go(4);
}
