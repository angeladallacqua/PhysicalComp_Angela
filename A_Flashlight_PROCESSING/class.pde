class Ball{
  
  PVector amplitude; 
  PVector location;
  PVector speed;
  PVector angle;
  PVector velocity;
  
  Ball(float _locx,float _locy, float _speedx, float _speedy, float _ampx, float _ampy){
    location = new PVector(_locx, _locy);
    velocity = new PVector(_speedx, _speedy);
    amplitude = new PVector(_ampx, _ampy);
    angle = new PVector();
  }
  
void display(){
   float x = amplitude.x * cos(angle.x);
   float y = amplitude.y * sin(angle.y);
   
   angle.add(velocity);
   
   pushMatrix();
   translate(location.x,location.y);
   stroke(random(100,150),0,random(0,Value));
   fill(random(100,Value),0,random(0,255));
   line(0,0,x,y);
   ellipse(x,y,20,20);
   popMatrix();
    
    //angle += 0.1;
        }
   
   
}