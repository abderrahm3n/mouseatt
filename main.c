#include<math.h>
#include<stdio.h>
#include<raylib.h>
#include <sys/types.h>

Vector2 map(Vector2 a,int width,int height){
  Vector2 l ;
  l.x = ((a.x+0.5)/2)*width;
  l.y = ((a.y+0.5)/2)*height;
  return l;
}

Vector2 unmap(Vector2 a,int width,int height){
  Vector2 l ;
  l.x = ((a.x/width)*2)-0.5;
  l.y = ((a.y/height)*2)-0.5;
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
  
  uint time = 0;
  SetTargetFPS(30);
  while(!WindowShouldClose()){
    Vector2 mousexy = (Vector2)unmap((Vector2) GetMousePosition(),screenwidth,screenheight);

    float dt = 0.1;
    for(int i = 0;i<n;i++){
      b[i].acc = getvect(mousexy,b[i].pos);
      b[i].speed.x += b[i].acc.x*dt;
      b[i].pos.x += b[i].speed.x*dt;
      b[i].speed.y += b[i].acc.y*dt;
      b[i].pos.y += b[i].speed.y*dt;
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
