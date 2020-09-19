const int row[] ={2,3,4,5,6,7,8,9}, col[] = {10,11,12,13,A5,A4,A3,A2};
int mat[8][8] ={0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0};
                
int pile[8][8] ={0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0};
int pi,pj;
byte shape;
 
void setup() {
  //randomSeed(0);
  pi=0;
  pj=3;
  shape = random(7);
for(int i=0; i<8; i++){
   pinMode(col[i], OUTPUT);
   pinMode(row[i], OUTPUT);
  }
  Serial.begin(9600);
}
void Displayall(int logic)    
{  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(col[c],LOW);//use thr column 
    //loop
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(row[r],logic);
      //digitalWrite(dat[r][c],R[r])  ;
    }    
  }  
}
void Display(int dat[8][8], int C[], int R[])    
{  
  for(int c = 0; c<8;c++)  
  {  
    digitalWrite(C[c],LOW);//use thr column 
    //loop
    for(int r = 0;r<8;r++)  
    {  
      digitalWrite(R[r],dat[r][c] || pile[r][c]);
      //digitalWrite(dat[r][c],R[r])  ;
    }  
    delay(1);  
    Clear(C, R);  //Remove empty display light
  }  
} 


void Clear(int C[], int R[])                    
{  
  for(int k = 0;k<8;k++)  
  {  
    digitalWrite(R[k],LOW);  
    digitalWrite(C[k],HIGH);  
  }  
}

void loop() {
// for(int i=0;i<6;i++){
//        Displayall(1);
//        delay(500);
//        Displayall(0);
//        delay(500);}
//     Serial.print(shape);
     int wt =0;
     for(int i=0;i<10;i++){
     int s1 = analogRead(A0);
     int s2 = analogRead(A1);
     if(s2<50){
      i+=9;}
      if(s2>600){
        if(wt ==0){wt = 1;}
        else
          wt =0;
        if(wt==1 ){
        switch(shape){
          case 0:
                if(spaceleft1(pi,pj,4)&&spaceright1(pi,pj,4))
                shape = 4;
                break;
          case 4:
                if(spaceleft1(pi,pj,0)&&spaceright1(pi,pj,0))
                  shape = 0;
                if(pj==0){
                 pj = pj+1;
                }
                if(pj==7){
                 pj = pj-1;
                }
                
                break;
          case 2:
                if(spaceleft1(pi,pj,5)&&spaceright1(pi,pj,5))
                shape=5;
                break;
          case 5:
                if(spaceleft1(pi,pj,2)&&spaceright1(pi,pj,2))
                shape = 2;
                break;
          case 3:
                if(spaceleft1(pi,pj,6)&&spaceright1(pi,pj,6))
                shape = 6;
                break;
          case 6:
                if(spaceleft1(pi,pj,3)&&spaceright1(pi,pj,3))
                shape = 3;
                if(pj==7){
                 pj = pj-1;
                }
                
                break;
          
          }}
        
        
      }
      if(s1 > 600 &&spaceright(pi,pj,shape)){
      pj = pj+1;
      }
     if(s1 < 100 && spaceleft(pi,pj,shape)){
      pj = pj-1;}
     
     Updatemat(pi,pj,shape,1);
     for(int i =0;i<10;i++)
     Display(mat,col,row);
     Updatemat(pi,pj,shape,0);
      }
     
     if(spacebelow(pi,pj,shape))
      pi++;
     else
      {Updatepile(pi,pj,shape);
      if(pi == 0){
        for(int i=0;i<6;i++){
        Displayall(1);
        delay(500);
        Displayall(0);
        delay(500);}
        restart();}
      pi =0;
      pj=3;
      shape = random(7);
      }
      checkcond();
     
}
void Updatepile(int pos1, int pos2, byte type){
  switch(type){
    case 0:
      pile[pos1][pos2] = 1;
      pile[pos1][pos2+1] = 1;
      pile[pos1][pos2-1] = 1;
      break;
    case 1:
      pile[pos1][pos2] = 1;
      pile[pos1][pos2+1]=1;
      pile[pos1-1][pos2]=1;
      pile[pos1-1][pos2+1]=1;
      break;
    case 2:
      pile[pos1][pos2+1]=1;
      pile[pos1-1][pos2]=1;
      pile[pos1-1][pos2+1]=1;
      pile[pos1-2][pos2]=1;
      break;
    case 3:
      pile[pos1][pos2+1] =1;
      pile[pos1-1][pos2]=1;
      pile[pos1-1][pos2+1]=1;
      pile[pos1-1][pos2-1]=1;
      break;
    case 4:
      pile[pos1][pos2] = 1;
      pile[pos1-1][pos2] = 1;
      pile[pos1-2][pos2] = 1;
      break;
    case 5:
      pile[pos1][pos2] = 1;
      pile[pos1][pos2-1]=1;
      pile[pos1-1][pos2]=1;
      pile[pos1-1][pos2+1]=1;
      break;
    case 6:
      pile[pos1][pos2]=1;
      pile[pos1][pos2-1]=1;
      pile[pos1-1][pos2]=1;
      pile[pos1-2][pos2]=1;
      break;
    }}

void Updatemat(int pos1,int pos2, byte type, byte val){
  switch(type){
    case 0:
      mat[pos1][pos2] = val;
      mat[pos1][pos2+1] = val;
      mat[pos1][pos2-1] = val;
      break;
    case 1:
      if(pos1!=0){
      mat[pos1][pos2] = val;
      mat[pos1][pos2+1]=val;
      mat[pos1-1][pos2]=val;
      mat[pos1-1][pos2+1]=val;}
      else{
      mat[pos1][pos2] = val;
      mat[pos1][pos2+1]=val;
        }
      break;
    case 2:
      if(pos1==0){
      mat[pos1][pos2+1]=val;}
      if(pos1==1){
      mat[pos1][pos2+1]=val;
      mat[pos1-1][pos2]=val;
      mat[pos1-1][pos2+1]=val;}
      if(pos1>1){
      mat[pos1][pos2+1]=val;
      mat[pos1-1][pos2]=val;
      mat[pos1-1][pos2+1]=val;
      mat[pos1-2][pos2]=val;}
      break;
    case 3:
      if(pos1==0)
        mat[pos1][pos2+1] =val;
      else{
      mat[pos1][pos2+1] =val;
      mat[pos1-1][pos2]=val;
      mat[pos1-1][pos2+1]=val;
      mat[pos1-1][pos2-1]=val;}
      break;
    case 4:
      if(pos1==0){
      mat[pos1][pos2]=val;}
      if(pos1==1){
      mat[pos1][pos2]=val;
      mat[pos1-1][pos2]=val;}
      if(pos1>1){
      mat[pos1][pos2]=val;
      mat[pos1-1][pos2]=val;
      mat[pos1-2][pos2]=val;}
      break;
    case 5:
      if(pos1==0){
      mat[pos1][pos2]=val;
      mat[pos1][pos2-1]=val;}
      if(pos1>0){
      mat[pos1][pos2]=val;
      mat[pos1][pos2-1]=val;
      mat[pos1-1][pos2]=val;
      mat[pos1-1][pos2+1]=val;}
      break;
    case 6:
      if(pos1==0){
      mat[pos1][pos2]=val;
      mat[pos1][pos2-1]=val;}
      if(pos1==1){
      mat[pos1][pos2]=val;
      mat[pos1][pos2-1]=val;
      mat[pos1-1][pos2]=val;}
      if(pos1>1){
      mat[pos1][pos2]=val;
      mat[pos1][pos2-1]=val;
      mat[pos1-1][pos2]=val;
      mat[pos1-2][pos2]=val;}
      break;
    }
  }
void restart(){
  //randomSeed(0);
  for (int i=0;i<8;i++){
    for(int j=0;j<8;j++)
        pile[i][j] =0;}}
        
void removeline(int j){
  for(int i=0;i<8;i++)
      pile[j][i] =0;
  for(int i=j-1; i>=0;i--)
  {   for(int z=0;z<8;z++)
        pile[i+1][z] = pile[i][z];}
  for(int i=0;i<8;i++)
      pile[0][i] =0;
  }
  
void checkcond(){
  
  for(int i=0;i<8;i++){
    int chk=0;
    for(int j=0;j<8;j++){
      if(pile[i][j] == 1)
        chk++;}
    if(chk == 8)
      {removeline(i);
      }}
     
  }
boolean spacebelow(int pi,int pj, byte type){
  switch(type){
    case 0:
      if(pile[pi+1][pj] == 0 && pile[pi+1][pj-1]==0 && pile[pi+1][pj+1]==0 && pi<7)
        return true;
      else
        return false;
      break;
    case 1:
      if(pile[pi+1][pj] == 0 && pile[pi+1][pj+1]==0 &&pi<7)
        return true;
      else
        return false;
      break;
    case 2:
      if(pile[pi+1][pj+1] == 0 && pile[pi][pj] ==0&& pi<7)
        return true;
      else
        return false;
      break;
    case 3:
      if(pile[pi+1][pj+1] == 0 && pile[pi][pj]==0&&pile[pi][pj-1]==0&&pi<7)
        return true;
      else
        return false;
      break;
    case 4:
      if(pile[pi+1][pj] == 0 && pi<7)
        return true;
      else
        return false;
      break;
    case 5:
      if(pile[pi+1][pj] == 0 && pile[pi+1][pj-1]==0 &&pile[pi][pj+1]==0&&pi<7)
        return true;
      else
        return false;
      break;
    case 6:
      if(pile[pi+1][pj-1] == 0 && pile[pi+1][pj] ==0&& pi<7)
        return true;
      else
        return false;
      break;
  }}
boolean spaceleft(int pi,int pj,byte type){
  switch(type){
    case 0:
      if(pile[pi][pj-2] == 0 &&pj>1)
        return true;
      else
        return false;
      break;
    case 1:
      if(pile[pi][pj-1] == 0 && pile[pi-1][pj-1]==0&&pj>0)
        return true;
      else
        return false;
      break;
    case 2:
      if(pile[pi][pj] == 0 && pile[pi-1][pj-1]==0 && pile[pi-2][pj-1]==0 && pj>0)
        return true;
      else
        return false;
      break;
    case 3:
      if(pile[pi][pj] == 0 && pile[pi-1][pj-2]==0 && pj>1)
        return true;
      else
        return false;
      break;
    case 4:
      if(pile[pi][pj-1] == 0 &&pile[pi-1][pj-1] == 0&&pile[pi-2][pj-1] == 0&&pj>0)
        return true;
      else
        return false;
      break;
    case 5:
      if(pile[pi][pj-2] == 0 && pile[pi-1][pj-1]==0&&pj>1)
        return true;
      else
        return false;
      break;
    case 6:
      if(pile[pi][pj-2] == 0 && pile[pi-1][pj-1]==0 && pile[pi-2][pj-1]==0 && pj>1)
        return true;
      else
        return false;
      break;
  
  }}

boolean spaceleft1(int pi,int pj,byte type){
  switch(type){
    case 0:
      if(pile[pi][pj-2] == 0 &&pj>0)
        return true;
      else
        return false;
      break;
    case 1:
      if(pile[pi][pj-1] == 0 && pile[pi-1][pj-1]==0&&pj>0)
        return true;
      else
        return false;
      break;
    case 2:
      if(pile[pi][pj] == 0 && pile[pi-1][pj-1]==0 && pile[pi-2][pj-1]==0 && pj>0)
        return true;
      else
        return false;
      break;
    case 3:
      if(pile[pi][pj] == 0 && pile[pi-1][pj-2]==0 && pj>0)
        return true;
      else
        return false;
      break;
    case 4:
      if(pile[pi][pj-1] == 0 &&pile[pi-1][pj-1] == 0&&pile[pi-2][pj-1] == 0&&pj>0)
        return true;
      else
        return false;
      break;
    case 5:
      if(pile[pi][pj-2] == 0 && pile[pi-1][pj-1]==0&&pj>0)
        return true;
      else
        return false;
      break;
    case 6:
      if(pile[pi][pj-2] == 0 && pile[pi-1][pj-1]==0 && pile[pi-2][pj-1]==0 && pj>0)
        return true;
      else
        return false;
      break;
  
  }}


boolean spaceright(int pi,int pj,byte type){
  switch(type){
    case 0:
      if(pile[pi][pj+2] == 0 && pj<6)
        return true;
      else
        return false;
      break;
    case 1:
      if(pile[pi][pj+2] == 0 && pile[pi-1][pj+2]==0 &&pj<6)
        return true;
      else
        return false;
      break;
    case 2:
      if(pile[pi][pj+2] == 0 && pile[pi-1][pj+2]==0 && pile[pi-2][pj]==0 &&pj<6)
        return true;
      else
        return false;
      break;
    case 3:
      if(pile[pi][pj+2] == 0 && pile[pi-1][pj+2]==0 &&pj<6)
        return true;
      else
        return false;
      break;
    case 4:
      if(pile[pi][pj+1] == 0 && pile[pi-1][pj+1] == 0 && pile[pi-2][pj+1] == 0 && pj<7)
        return true;
      else
        return false;
      break;
    case 5:
      if(pile[pi][pj+1] == 0 && pile[pi-1][pj+2]==0 &&pj<6)
        return true;
      else
        return false;
      break;
    case 6:
      if(pile[pi][pj+1] == 0 && pile[pi-1][pj+1]==0 && pile[pi-2][pj+1]==0 &&pj<7)
        return true;
      else
        return false;
      break;
  
  }}

 boolean spaceright1(int pi,int pj,byte type){
  switch(type){
    case 0:
      if(pile[pi][pj+2] == 0 && pj<7)
        return true;
      else
        return false;
      break;
    case 1:
      if(pile[pi][pj+2] == 0 && pile[pi-1][pj+2]==0 &&pj<7)
        return true;
      else
        return false;
      break;
    case 2:
      if(pile[pi][pj+2] == 0 && pile[pi-1][pj+2]==0 && pile[pi-2][pj]==0 &&pj<7)
        return true;
      else
        return false;
      break;
    case 3:
      if(pile[pi][pj+2] == 0 && pile[pi-1][pj+2]==0 &&pj<7)
        return true;
      else
        return false;
      break;
    case 4:
      if(pile[pi][pj+1] == 0 && pile[pi-1][pj+1] == 0 && pile[pi-2][pj+1] == 0 && pj<7)
        return true;
      else
        return false;
      break;
    case 5:
      if(pile[pi][pj+1] == 0 && pile[pi-1][pj+2]==0 &&pj<7)
        return true;
      else
        return false;
      break;
    case 6:
      if(pile[pi][pj+1] == 0 && pile[pi-1][pj+1]==0 && pile[pi-2][pj+1]==0 &&pj<7)
        return true;
      else
        return false;
      break;
  
  }}
