void crossB(int Basespeed, float Kp, float Kd) {
  readLineB(220, 50);
  while (sensorValues[0] < 400 && sensorValues[4] < 400) {
    readLineB(220, 50);
    stdPIDB(Basespeed, Kp, Kd);
  }
}

void cheks_l_B(int Basespeed, float Kp, float Kd) {
  readLineB(220, 50);
  while (sensorValues[0] < 400) {
    readLineB(220, 50);
    stdPIDB(Basespeed, Kp, Kd);
  }
}

void cheks_r_B(int Basespeed, float Kp, float Kd) {
  readLineB(220, 50);
  while (sensorValues[4] < 400) {
    readLineB(220, 50);
    stdPIDB(Basespeed, Kp, Kd);
  }
}

void tb(int Basespeed, float Kp, float Kd, int t) {
  readLineB(200, 50);
  long looptime = millis();
  while (millis() - looptime <= t) {
    readLineB(200, 50);
    stdPIDB(Basespeed, Kp, Kd);
  }
}

void b(int speed) {
  bool L = analogRead(69) < 500;
  bool C = analogRead(68) < 500;
  bool R = analogRead(67) < 500;

  if (C) {
    mc(-speed, -speed);
  } else if (L) {
    mc(-(speed - 15), -(speed + 5));
  } else if (R) {
    mc(-(speed + 5), -(speed - 15));
  } else {
    mc(0, 0);
  }
}

void B_cross(int speed, int t) {
  while (1) {

    int R = analogRead(69);
    int C = analogRead(68);
    int L = analogRead(67);

    if (L > 900 && C > 900 && R > 900) {
      break;
    }
    if (C < 400) {
      mc(-speed, -speed);
    } else if (L < 400) {
      mc(-(speed - 17), -(speed + 7));
    } else if (R < 400) {
      mc(-(speed + 7), -(speed - 17));
    } else {
      mc(-speed, -speed);
    }
  }
  mct(-speed, -speed, t);
}
void bt(int speed, int time) {
  long looptime = millis();
  while (millis() - looptime <= time) {
    b(speed);
  }
}

void b_cross(int speed) {
  while (1) {

    int R = analogRead(69);
    int C = analogRead(68);
    int L = analogRead(67);

    if (L > 950 && C > 950 && R > 950) {
      break;
    }

    if (C < 645) {
      mc(-speed, -speed);
    } else if (L < 645) {
      mc(-(speed - 17), -(speed + 7));
    } else if (R < 645) {
      mc(-(speed + 7), -(speed - 17));
    } else {
      mc(-speed, -speed);
    }
  }
  yt(50);
  cross_navy_t(50, 0.018, 0.3, 220);
}

void b2_cross(int speed) {
  long looptime = millis();
  while (millis() - looptime <= 900) {

    int R = analogRead(69);
    int L = analogRead(67);

    if (L < 645) {
      mc(-(speed - 17), -(speed + 7));
    } else if (R < 645) {
      mc(-(speed + 7), -(speed - 17));
    } else {
      mc(-speed, -speed);
    }
  }
  stop();
}