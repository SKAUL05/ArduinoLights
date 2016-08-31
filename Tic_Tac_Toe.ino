/*
2 3 4
5 6 7
8 9 10
*/
const int interval = 1000;
int prev = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}
void blankOut()
{
    for(int i=2;i<=10;i++)
      digitalWrite(i,LOW);
}
void coordinates(int value,int *i,int *j)
{
  switch(value)
  {
      case 1: *i = 0; *j = 0; break;
      case 2: *i = 0; *j = 1; break;
      case 3: *i = 0; *j = 2; break;
      case 4: *i = 1; *j = 0; break;
      case 5: *i = 1; *j = 1; break;
      case 6: *i = 1; *j = 2; break;
      case 7: *i = 2; *j = 0; break;
      case 8: *i = 2; *j = 1; break;
      case 9: *i = 2; *j = 2; break;
      default:  *i = *j = 0; break;
  }
}
int convert(int i,int j)
{
    return (j+(i*3))+2;
}
void blinkIt(int *prev,int arr[],int size)
{
  int curr = millis();
  if(curr-*prev>=interval)
  {
      *prev = curr;
      for(int i=0;i<size;i++)
      {
         digitalWrite(arr[i],!digitalRead(arr[i]));
      }
  }
}
void showIt(char ch,int p,int value)
{
  int i;
  blankOut();
  if(ch == 'r')
  {
    if(value == 1)
    {
      if( p == 0)
      {
        for(i=2;i<=4;i++)
        {
          digitalWrite(i,HIGH);
        }
      }
      else if(p == 1)
      {
        for(i=5;i<=7;i++)
        {
          digitalWrite(i,HIGH);
        }
      }
      else
      {
        for(i=8;i<=10;i++)
        {
          digitalWrite(i,HIGH);
        }
      }
      delay(5000);
    }
    else
    {
      for(int j=1;j<=5;j++)
      {
        if( p == 0)
        {
          for(i=2;i<=4;i++)
          {
              digitalWrite(i,HIGH);
          }
          delay(500);
          for(i=2;i<=4;i++)
          {
              digitalWrite(i,LOW);
          }
          delay(500);
        }
        else if(p == 1)
        {
          for(i=5;i<=7;i++)
          {
              digitalWrite(i,HIGH);
          }
          delay(500);
          for(i=5;i<=7;i++)
          {
              digitalWrite(i,LOW);
          }
          delay(500);
        }
        else
        {
          for(i=8;i<=10;i++)
          {
              digitalWrite(i,HIGH);
          }
          delay(500);
          for(i=8;i<=10;i++)
          {
              digitalWrite(i,LOW);
          }
          delay(500);
        }
      }
    }
  }
  else if(ch == 'c')
  {
    if(value == 1)
    {
      if( p == 0)
      {
        for(i=2;i<=8;i+=3)
        {
          digitalWrite(i,HIGH);
        }
      }
      else if(p == 1)
      {
        for(i=3;i<=9;i+=3)
        {
          digitalWrite(i,HIGH);
        }
      }
      else
      {
        for(i=4;i<=10;i+=3)
        {
          digitalWrite(i,HIGH);
        }
      }
      delay(5000);
    }
    else
    {
      for(int j=1;j<=5;j++)
      {
        if( p == 0)
        {
          for(i=2;i<=8;i+=3)
          {
              digitalWrite(i,HIGH);
          }
          delay(500);
          for(i=2;i<=8;i+=3)
          {
              digitalWrite(i,LOW);
          }
          delay(500);
        }
        else if(p == 1)
        {
          for(i=3;i<=9;i+=3)
          {
              digitalWrite(i,HIGH);
          }
          delay(500);
          for(i=3;i<=9;i+=3)
          {
              digitalWrite(i,LOW);
          }
          delay(500);
        }
        else
        {
          for(i=4;i<=10;i+=3)
          {
              digitalWrite(i,HIGH);
          }
          delay(500);
          for(i=4;i<=10;i+=3)
          {
              digitalWrite(i,LOW);
          }
          delay(500);
        }
      }
    }
  }
  else if(ch == 'p')
  {
    if(value == 1)
    {
        for(i=2;i<=10;i+=4)
        {
            digitalWrite(i,HIGH);
        }
        delay(5000);
    }
    else
    {
      for(int j=1;j<=5;j++)
      {
        for(i=2;i<=10;i+=4)
        {
            digitalWrite(i,HIGH);
        }
        delay(500);
        for(i=2;i<=10;i+=4)
        {
            digitalWrite(i,LOW);
        }
        delay(500);
      }
    }
  }
  else
  {
    if(value == 1)
    {
        for(i=4;i<=8;i+=2)
        {
            digitalWrite(i,HIGH);
        }
        delay(5000);
    }
    else
    {
      for(int j=1;j<=5;j++)
      {
        for(i=4;i<=8;i+=2)
        {
            digitalWrite(i,HIGH);
        }
        delay(500);
        for(i=4;i<=8;i+=2)
        {
            digitalWrite(i,LOW);
        }
        delay(500);
      }
    }
  }
}
boolean winner(int mat[3][3],int value)
{  
  int i,j;
  boolean flag = true;
  // Rows
  for(i=0;i<3;i++)
  {
      flag = true;
      for(j=0;j<3;j++)
      {
        if(mat[i][j] != value)
        {
            flag = false;
            break;
        }
      }
      if(flag == true)
      {
        showIt('r',i,value);
        return true;
      }
  }
  // Columns
  flag = true;
  for(i=0;i<3;i++)
  {
      flag = true;
      for(j=0;j<3;j++)
      {
        if(mat[j][i] != value)
        {
            flag = false;
            break;
        }
      }
      if(flag == true)
      {
        showIt('c',i,value);
        return true;
      }
  }
  // Principle Diagonal
  flag = true;
  for(i=0;i<3;i++)
  {
     if(mat[i][i]!=value)
     {
       flag = false;
       break;
     }
  }
  if(flag == true)
  {
    showIt('p',0,value);
    return true;
  }
  // Secondary Diagonal
  flag = true;
  for(i=0;i<3;i++)
  {
     if(mat[i][3-i-1]!=value)
     {
       flag = false;
       break;
     }
  }
  if(flag == true)
  {
    showIt('s',0,value);
    return true;
  }
  return false;
}
void loop()
{
  int value,i,j,count = 0;
  bool flag = true;
  int mat[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
  int arr[5],size = 0;
  while(count<9)
  {
      blinkIt(&prev,arr,size);
      value = Serial.parseInt();
      Serial.println(value);
      coordinates(value,&i,&j);
      if(value>=1 && value <= 9 && mat[i][j] == -1)
      {
        if(flag == true)
        {
            mat[i][j] = 1;
            digitalWrite(convert(i,j),HIGH);
            flag = !flag;
        }
        else
        {
            mat[i][j] = 0;
            arr[size++] = convert(i,j);
            flag = !flag;
        }
        count++;
        if(count>=5 && (winner(mat,1) == true || winner(mat,0) == true))
        {
          break;
        }
      }
  }
  blankOut();
}
