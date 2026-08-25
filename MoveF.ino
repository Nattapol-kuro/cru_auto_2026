void cross(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (sensorValues[0] < 700 && sensorValues[6] < 700) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void cross_navy(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (sensorValues[0] < 700 && sensorValues[6] < 700) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void cross_navy_t(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  long looptime = millis();
  while (millis() - looptime <= t) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  stop();
}

void cheks_l(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (sensorValues[0] < 700) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void cheks_ll(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (sensorValues[0] < 550) {
    readLineF(220, 50);
    stdPIDD(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void cheks_r(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (sensorValues[6] < 500) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void cheks_rr(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (sensorValues[6] < 700) {
    readLineF(220, 50);
    stdPIDD(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void t(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  long looptime = millis();
  while (millis() - looptime <= t) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
}

void tt(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  long looptime = millis();
  while (millis() - looptime <= t) {
    readLineF(220, 50);
    stdPIDD(Basespeed, Kp, Kd);
  }
}

void cheks_eye(int Basespeed, float Kp, float Kd, int range) {
  readLineF(220, 50);
  while (analogRead(62) < range) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  stop();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void scross(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (analogRead(66) > 500 && analogRead(63) > 350) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void scross_navy(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (analogRead(63) > 500 && analogRead(66) > 350) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void scheks_l(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (analogRead(66) > 500) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void scheks_ll(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (analogRead(66) > 500) {
    readLineF(220, 50);
    stdPIDD(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void scheks_r(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (analogRead(63) > 350) {
    readLineF(220, 50);
    stdPID(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}

void scheks_rr(int Basespeed, float Kp, float Kd, int t) {
  readLineF(220, 50);
  while (analogRead(63) > 350) {
    readLineF(220, 50);
    stdPIDD(Basespeed, Kp, Kd);
  }
  mct(Basespeed, Basespeed, t);
}