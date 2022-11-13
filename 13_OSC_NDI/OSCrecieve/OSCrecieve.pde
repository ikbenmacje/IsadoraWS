/**
 * OSCrecieve
 * an example to demosntrate the recieving of OSC data from Isadora
 */
 
import oscP5.*;
import netP5.*;
  
OscP5 oscP5;

float diam = 20;
float x = 0;
float y = 0;

void setup() {
  size(400,400);
  frameRate(25);
  
  /* start oscP5, listening for incoming messages at port 1234 */
  oscP5 = new OscP5(this,1235);
 
}


void draw() {
  //background(0);
  noStroke();
  fill(0,10);
  rect(0,0,width,height);
  
  fill(255);
  circle(x,y,diam);
  
}




/* incoming osc message are forwarded to the oscEvent method. */
void oscEvent(OscMessage theOscMessage) {
  /* print the address pattern and the typetag of the received OscMessage */
  //print("### received an osc message.");
  //print(" addrpattern: "+theOscMessage.addrPattern());
  //println(" typetag: "+theOscMessage.typetag());
  
  // set the random diameter
  if(theOscMessage.addrPattern().equals("/random")){
    //println("hallo");
    diam = theOscMessage.get(0).floatValue();
  }
  
  // set the location of the ellipse
  if(theOscMessage.addrPattern().equals("/mouseXY")){
    x = theOscMessage.get(0).floatValue();
    y = theOscMessage.get(1).floatValue();
    
    /* 
      Values fromm isadora are between 0 - 100
      We want to change them to be between 0 - width for x
      and 0 - height for y
    */
    x = map(x,0,100,0,width);
    y = map(y,0,100,0,height);
    
    
  }
  
  
  
}
