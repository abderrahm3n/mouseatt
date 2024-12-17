#include<math.h>
#include<stdio.h>
#include<raylib.h>

Vector2 map(Vector2 a,int width,int height){
  Vector2 l ;
  l.x = ((a.x+0.5)/2)*width;
  l.y = ((a.y+0.5)/2)*height;
  return l;
}

Vector2 getvect(Vector2 a ,Vector2 b){
  Vector2 l;
  l.x = a.x-b.x;
  l.y = a.y-b.y;
  return l;
}

Vector2 addvect(Vector2 a ,Vector2 b){
  Vector2 l;
  l.x = a.x +b.x;
  l.y = a.y +b.y;
  return l;
}



struct ball{
  Vector2 pos; 
  Vector2 speed; 
  Vector2 acc ;
};

 int main(){
  int screenwidth = 800;
  int screenheight = 600;

  InitWindow(screenwidth,screenheight,"hello");
  int n = 3;
  int rad = 15;
  struct ball b[n];
  b[0].pos  = (Vector2){-0.5,0.5};
  b[1].pos = (Vector2){0.5,0.5};
  b[2].pos = (Vector2){0.,-0.5};
  
  b[0].speed = (Vector2){0.,0.};
  b[1].speed = (Vector2){0.,0.};
  b[2].speed = (Vector2){0.,0.};

  b[0].acc = (Vector2){0.,0.};
  b[1].acc = (Vector2){0.,0.};
  b[2].acc = (Vector2){0.,0.};
  

  SetTargetFPS(1);
  while(!WindowShouldClose()){
    Vector2 mousexy = GetMousePosition();

    for(int i = 0;i<n;i++){
      Vector2 tacc = mousexy;
      Vector2 tspeed = b[i].speed;
      b[i].speed = addvect(b[i].speed,getvect(b[i].acc,tacc));
      b[i].pos = addvect(b[i].pos,getvect(b[i].speed,tspeed));
    }


    BeginDrawing();
    ClearBackground(BLACK);
    for(int i = 0;i<n;i++){
      DrawCircleV(map(b[i].pos,screenwidth,screenheight),rad,RED);
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
