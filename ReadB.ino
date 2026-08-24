void displayB() {
  while (1) {
    Serial.print(analogRead(69));
    Serial.print("\t");
    Serial.print(analogRead(68));
    Serial.print("\t");
    Serial.print(analogRead(67));
    Serial.print("\t");
    Serial.print("\n");
    delay(100);
  }
}

void displayValueB(int calibrateTime) {
  int readMin[3] = { 0, 0, 0 };
  int readMax[3] = { 0, 0, 0 };


  for (int sens = 0; sens < 3; sens++) {
    readMin[sens] = 0;
    readMax[sens] = 1000;
  }
  Serial.println("Press RUN To Calibrate");

  Serial.println("Calibrating");
  for (int j = 0; j < calibrateTime; j++) {
    readPrivateB();
    for (int i = 0; i < 3; i++) {
      // set the max we found THIS time
      if (j == 0 || readMax[i] < sensorValuesB[i])
        readMax[i] = sensorValuesB[i];
      // set the min we found THIS time
      if (j == 0 || readMin[i] > sensorValuesB[i])
        readMin[i] = sensorValuesB[i];
    }
    delay(2);
  }
  Serial.println("Calibrated");
  Serial.print("\n");
  Serial.print("int MAX_SENSOR_B[3] = {");
  int i;
  for (i = 0; i < 3; i++) {
    Serial.print(readMax[i]);
    if (i != 2) Serial.print(",");
    else Serial.println("};");
  }
  Serial.print("int MIN_SENSOR_B[3] = {");
  for (i = 0; i < 3; i++) {
    Serial.print(readMin[i]);
    if (i != 2) Serial.print(",");
    else Serial.println("};");
  }
}

void monitorSensorB() {
  while (1) {
    readCalibratedB();

    Serial.print("Pos = ");
    Serial.print(readLineB(220, 50));
    Serial.print("\t");

    for (int i = 0; i < 3; i++) {
      Serial.print(sensorValuesB[i]);
      Serial.print("\t");
    }

    Serial.println();
    delay(100);
  }
}