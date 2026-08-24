void tll(int t) {
  mct(-250, 250, t);
  readLineF(220, 50);
  while (sensorValues[0] < 600) {
    readLineF(220, 50);
    mc(-200, 200);
  }
  stop();
}

void tl_360() {
  mct(-250, 250, 120);
  readLineF(220, 50);
  while (sensorValues[0] < 600) {
    readLineF(220, 50);
    mc(-150, 150);
  }
  stop();
}

void tl_navy() {
  mct(-150, 150, 160);
  readLineF(220, 50);
  while (sensorValues[2] < 690) {
    readLineF(220, 50);
    mc(-100, 100);
  }
  stop();
}

void trr(int t) {
  mct(200, -200, t);
  readLineF(220, 50);
  while (sensorValues[6] < 600) {
    readLineF(220, 50);
    mc(200, -200);
  }
  stop();
}

void trrr(int t) {
  mct(200, -200, t);
  readLineF(220, 50);
  while (sensorValues[6] < 600) {
    readLineF(220, 50);
    mc(150, -150);
  }
  stop();
}

void trb(int t) {
  mct(100, -100, t);
  while (analogRead(68) > 700) {
    mc(70, -70);
  }
  stop();
}

void tr(int t) {
  mct(150, -150, t);
  readLineF(220, 50);
  while (sensorValues[4] < 700) {
    readLineF(220, 50);
    mc(80, -800);
  }
  stop();
}

void tr3(int t) {
  mct(150, -150, t);
  readLineF(220, 50);
  while (sensorValues[3] < 600) {
    readLineF(220, 50);
    mc(80, -80);
  }
  stop();
}

void tl_360_slow() {
  mct(-150, 150, 160);
  readLineF(220, 50);
  while (sensorValues[2] < 700) {
    readLineF(220, 50);
    mc(-110, 110);
  }
  stop();
}

void tl(int t) {
  mct(-150, 150, t);
  readLineF(220, 50);
  while (sensorValues[2] < 400) {
    readLineF(220, 50);
    mc(-80, 80);
  }
  stop();
}
// void tr() {
//   mct(150, -150, 70);
//   readLineF(220, 50);
//   while (sensorValues[3] < 400) {
//     readLineF(220, 50);
//     mc(110, -110);
//   }
// }