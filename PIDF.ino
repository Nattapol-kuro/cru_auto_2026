void readPrivateF() {
  int i;
  for (i = 0; i < 7; i++) {
    sensorValues[i] = analogRead(front_pin[i]);
  }
}



void readCalibratedF() {
  readPrivateF();

  for (int i = 0; i < 7; i++) {

    unsigned int calmin = MIN_SENSOR_F[i];
    unsigned int calmax = MAX_SENSOR_F[i];
    unsigned int denominator = calmax - calmin;

    long x = 0;

    if (denominator != 0) {
      x = ((long)(sensorValues[i] - calmin) * 1000) / denominator;
    }

    if (x < 0) x = 0;
    if (x > 1000) x = 1000;

    sensorValues[i] = 1000 - x;
  }
}


int readLineF(int keep_track, int noise_threshold) {
  unsigned char i, on_line = 0;
  unsigned long avg;          // this is for the weighted total, which is long
  unsigned int sum;           // this is for the denominator which is <= 64000
  static int last_value = 0;  // assume initially that the line is left.
  readCalibratedF();
  avg = 0;
  sum = 0;
  for (i = 0; i < 7; i++) {
    int value = sensorValues[i];  //////cambio de flanco
    if (value > keep_track) {
      on_line = 1;
    }
    if (value > noise_threshold) {  ///estaba en 50
      avg += (long)(value) * (i * 1000);
      sum += value;
    }
  }
  if (!on_line) {
    if (last_value < 3000)
      return 0;
    else
      return 6000;
  }
  last_value = avg / sum;
  return last_value;
}

void stdPID(int BaseSpeed, float Kp, float Kd) {
  Position = readLineF(220, 50);
  int error = Position - 3000;
  PIDValue = (Kp * error) + (Kd * (error - last_error));
  last_error = error;
  if (PIDValue > BaseSpeed) PIDValue = BaseSpeed;
  if (PIDValue < -BaseSpeed) PIDValue = -BaseSpeed;
  leftPower = BaseSpeed + PIDValue;
  rightPower = BaseSpeed - PIDValue;
  if (leftPower >= 255) leftPower = 255;
  if (leftPower < 0) leftPower = -120;
  if (rightPower >= 255) rightPower = 255;
  if (rightPower < 0) rightPower = -120;
  mc(leftPower, rightPower);
}

void stdPIDD(int BaseSpeed, float Kp, float Kd) {
  Position = readLineF(220, 50);
  int error = Position - 3000;
  PIDValue = (Kp * error) + (Kd * (error - last_error));
  last_error = error;
  if (PIDValue > BaseSpeed) PIDValue = BaseSpeed;
  if (PIDValue < -BaseSpeed) PIDValue = -BaseSpeed;
  leftPower = BaseSpeed + PIDValue;
  rightPower = BaseSpeed - PIDValue;
  if (leftPower >= 255) leftPower = 255;
  if (leftPower < 0) leftPower = -150;
  if (rightPower >= 255) rightPower = 255;
  if (rightPower < 0) rightPower = -150;
  mc(leftPower, rightPower);
}