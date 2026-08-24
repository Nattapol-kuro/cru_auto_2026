void display() {
  while (1) {
    Serial.print(analogRead(66));
    Serial.print("\t");
    Serial.print(analogRead(front_pin[0]));
    Serial.print("\t");
    Serial.print(analogRead(front_pin[1]));
    Serial.print("\t");
    Serial.print(analogRead(front_pin[2]));
    Serial.print("\t");
    Serial.print(analogRead(front_pin[3]));
    Serial.print("\t");
    Serial.print(analogRead(front_pin[4]));
    Serial.print("\t");
    Serial.print(analogRead(front_pin[5]));
    Serial.print("\t");
    Serial.print(analogRead(front_pin[6]));
    Serial.print("\t");
    Serial.print(analogRead(63));
    Serial.print("\t");
    Serial.print("\n");
    delay(100);
  }
}

void Read_eye() {
  while (1) {
    Serial.print(analogRead(62));
    Serial.print("\n");
    delay(100);
  }
}

void displayValueF(int calibrateTime) {
  int readMin[7] = { 0, 0, 0, 0, 0, 0, 0 };
  int readMax[7] = { 0, 0, 0, 0, 0, 0, 0 };


  for (int sens = 0; sens < 7; sens++) {
    readMin[sens] = 0;
    readMax[sens] = 1000;
  }
  Serial.println("Press RUN To Calibrate");

  Serial.println("Calibrating");
  for (int j = 0; j < calibrateTime; j++) {
    readPrivateF();
    for (int i = 0; i < 7; i++) {
      // set the max we found THIS time
      if (j == 0 || readMax[i] < sensorValues[i])
        readMax[i] = sensorValues[i];
      // set the min we found THIS time
      if (j == 0 || readMin[i] > sensorValues[i])
        readMin[i] = sensorValues[i];
    }
    delay(2);
  }
  Serial.println("Calibrated");
  Serial.print("\n");
  Serial.print("int MAX_SENSOR_F[7] = {");
  int i;
  for (i = 0; i < 7; i++) {
    Serial.print(readMax[i]);
    if (i != 6) Serial.print(",");
    else Serial.println("};");
  }
  Serial.print("int MIN_SENSOR_F[7] = {");
  for (i = 0; i < 7; i++) {
    Serial.print(readMin[i]);
    if (i != 6) Serial.print(",");
    else Serial.println("};");
  }
}

void monitorSensorF() {
  while (1) {
    readCalibratedF();

    Serial.print("Pos = ");
    Serial.print(readLineF(220, 50));
    Serial.print("\t");

    for (int i = 0; i < 7; i++) {
      Serial.print(sensorValues[i]);
      Serial.print("\t");
    }

    Serial.println();
    delay(100);
  }
}

void gujaarn() {
  while (1) {
    for (int i = 0; i < 7; i++) {
      //      if(i == 0) Serial.print(analogRead(8));
      /*else*/ Serial.print(analogRead(front_pin[i]));
      Serial.print("\t");
    }
    Serial.println("");
  }
}