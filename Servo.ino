void keep_r() {
  stop();
  delay(50);
  smsv3(123, 4);
  stop();
  delay(200);
  smsv1(119, 2);
  stop();
  delay(200);
  smsv2(176, 4);
  stop();
  delay(300);
  smsv3(101, 1);
  stop();
  delay(300);
  smsv2(168, 2);
  stop();
  delay(100);
  smsv1(106, 1);
  stop();
  delay(150);
  smsv3(90, 2);
  stop();
  delay(50);
}


void keep_l() {
  stop();
  delay(50);
  smsv3(120, 4);
  stop();
  delay(200);
  smsv1(83, 2);
  stop();
  delay(200);
  smsv2(178, 3);
  stop();
  delay(300);
  smsv3(101, 1);
  stop();
  delay(300);
  smsv2(168, 2);
  stop();
  delay(100);
  smsv1(99, 1);
  stop();
  delay(150);
  smsv3(90, 2);
  stop();
  delay(50);
}


int PreviousAngle1 = 90;
void smsv1(int Angle, int Gap) {
  if (PreviousAngle1 < Angle) {
    for (int i = PreviousAngle1; i <= Angle; i++) {
      ms1.write(i);
      delay(Gap);
    }
  } else if (PreviousAngle1 > Angle) {
    for (int i = PreviousAngle1; i >= Angle; i--) {
      ms1.write(i);
      delay(Gap);
    }
  }

  PreviousAngle1 = Angle;
}

int PreviousAngle2 = 180;
void smsv2(int Angle, int Gap) {
  if (PreviousAngle2 < Angle) {
    for (int i = PreviousAngle2; i <= Angle; i++) {
      ms2.write(i);
      delay(Gap);
    }
  } else if (PreviousAngle2 > Angle) {
    for (int i = PreviousAngle2; i >= Angle; i--) {
      ms2.write(i);
      delay(Gap);
    }
  }

  PreviousAngle2 = Angle;
}

int PreviousAngle3 = 100;
void smsv3(int Angle, int Gap) {
  if (PreviousAngle3 < Angle) {
    for (int i = PreviousAngle3; i <= Angle; i++) {
      ms3.write(i);
      delay(Gap);
    }
  } else if (PreviousAngle3 > Angle) {
    for (int i = PreviousAngle3; i >= Angle; i--) {
      ms3.write(i);
      delay(Gap);
    }
  }
  PreviousAngle3 = Angle;
}