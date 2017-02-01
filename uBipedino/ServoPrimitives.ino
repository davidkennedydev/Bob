void TiltRightUp(byte ang, byte sp){  
  //tilt right up
  for (int i=0; i<=ang; i+=5){
    Lfoot.write(LFcenter+i);
    Rfoot.write(RFcenter+i);
    delay(sp);
  }
}
void TiltRightDown(byte ang, byte sp){
  //tilt right down
  for (int i=ang; i>0; i-=5){
    Lfoot.write(LFcenter+i);
    Rfoot.write(RFcenter+i);
    delay(sp);
  }
}

void TiltLeftUp(byte ang, byte sp){
  //tilt left up
  for (int i=0; i<=ang; i+=5){
    Lfoot.write(LFcenter-i);
    Rfoot.write(RFcenter-i);
    delay(sp);
  }
}
void TiltLeftDown(byte ang, byte sp){
  //tilt left down
  for (int i=ang; i>0; i-=5){
    Lfoot.write(LFcenter-i);
    Rfoot.write(RFcenter-i);
    delay(sp);
  }
}

void LeftFootUp(char ang, byte sp){
  //tilt left up
  for (int i=0; i<=ang; i+=5){
    Lfoot.write(LFcenter-i);
    delay(sp);
  }
}
void LeftFootDown(byte ang, byte sp){
  //tilt left down
  for (int i=ang; i>0; i-=5){
    Lfoot.write(LFcenter-i);
    delay(sp);
  }
}

void RightFootUp(byte ang, byte sp){  
  //tilt right up
  for (int i=0; i<=ang; i+=5){
    Rfoot.write(RFcenter+i);
    delay(sp);
  }
}
void RightFootDown(byte ang, byte sp){
  //tilt right down
  for (int i=ang; i>0; i-=5){
    Rfoot.write(RFcenter+i);
    delay(sp);
  }
}

void SwingRight(byte ang, byte sp){
  //swing right
  for (int i=0; i<=ang; i+=5){
    Lleg.write(LLcenter-i);
    Rleg.write(RLcenter-i);
    delay(sp);
  }
}
void SwingRcenter(byte ang, byte sp){
  //swing r->center
  for (int i=ang; i>0; i-=5){
    Lleg.write(LLcenter-i);
    Rleg.write(RLcenter-i);
    delay(sp);
  }
}

void SwingLeft(byte ang, byte sp){
  //swing left
  for (byte i=0; i<=ang; i=i+5){
    Lleg.write(LLcenter+i);
    Rleg.write(RLcenter+i);
    delay(sp);
  }
}
void SwingLcenter(byte ang, byte sp){
  //swing l->center
  for (byte i=ang; i>0; i=i-5){
    Lleg.write(LLcenter+i);
    Rleg.write(RLcenter+i);
    delay(sp);
  }
}

void RightLegIn(byte ang, byte sp){
  //swing right
  for (int i=0; i<=ang; i+=5){
    Rleg.write(RLcenter-i);
    delay(sp);
  }
}
void RightLegIcenter(byte ang, byte sp){
  //swing r->center
  for (int i=ang; i>0; i-=5){
    Rleg.write(RLcenter-i);
    delay(sp);
  }
}

void RightLegOut(byte ang, byte sp){
  //swing right
  for (int i=0; i<=ang; i+=5){
    Rleg.write(RLcenter+i);
    delay(sp);
  }
}
void RightLegOcenter(byte ang, byte sp){
  //swing r->center
  for (int i=ang; i>0; i-=5){
    Rleg.write(RLcenter+i);
    delay(sp);
  }
}

void LeftLegIn(byte ang, byte sp){
  //swing left
  for (byte i=0; i<=ang; i=i+5){
    Lleg.write(LLcenter+i);
    delay(sp);
  }
}
void LeftLegIcenter(byte ang, byte sp){
  //swing l->center
  for (byte i=ang; i>0; i=i-5){
    Lleg.write(LLcenter+i);
    delay(sp);
  }
}

void LeftLegOut(byte ang, byte sp){
  //swing left
  for (byte i=0; i<=ang; i=i+5){
    Lleg.write(LLcenter-i);
    delay(sp);
  }
}
void LeftLegOcenter(byte ang, byte sp){
  //swing l->center
  for (byte i=ang; i>0; i=i-5){
    Lleg.write(LLcenter-i);
    delay(sp);
  }
}

