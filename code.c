// Проект создан с задумкой на то что при вводе пароля
// серво открывает механизм, предположим кулисы. После
// чего на 7Segmente с буквы "c" что означает "Closed"
// и красного леда образовуется буква "L" что означает 
// "Launched" и загорается зеленый лед.
// После чего начинает проигрываться мелодия и вместе
// с этим играет подсветка.

#include <Servo.h>
#include <Keypad.h>
#define SEGMENT_A 7  //Segment A
#define SEGMENT_B 8   //Segment B
#define SEGMENT_C 9   //Segment C
#define SEGMENT_D 10  //Segment D
#define SEGMENT_E 11  //Segment E
#define SEGMENT_F 12  //Segment F
#define SEGMENT_G 13  //Segment G

Servo ServoMotor;
char* password = "123"; // Базовый пароль
int position = 0;
const int speakerPin = 0;
const byte ROWS = 4;
const byte COLS = 4;
const byte signals[10][7] = {
  {0, 0, 0, 0, 0, 0, 0},  // 0
  {1, 0, 0, 1, 1, 1, 1},  // 1
  {0, 0, 1, 0, 0, 1, 0},  // 2
  {0, 0, 0, 0, 1, 1, 0},  // 3
  {1, 0, 0, 1, 1, 0, 0},  // 4
  {0, 1, 0, 0, 1, 0, 0},  // 5
  {0, 1, 0, 0, 0, 0, 0},  // 6
  {0, 0, 0, 1, 1, 1, 1},  // 7
  {0, 0, 0, 0, 0, 0, 0},  // 8
  {0, 0, 0, 0, 1, 0, 0}  // 9
};
int digit = 0;
	char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = { 8, 7, 6, 9 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int RedpinLock = 12; // Красный LED - закрыто
int GreenpinUnlock = 13; // Зелёный LED - открыто

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

void beep(int ton, int time)
{
  tone(0, ton, time);
  delay(time + 20);
}

void setup()
{
pinMode(10, OUTPUT);
pinMode(1, OUTPUT);
pinMode(RedpinLock, OUTPUT);
pinMode(GreenpinUnlock, OUTPUT);
ServoMotor.attach(11);
LockedPosition(true);
}

void loop()
{
char key = keypad.getKey();
if (key == '*' || key == '#') // Клавиши блокировки
{
position = 0;
LockedPosition(true);
}
if (key == password[position]) 
{
position ++;
}
if (position == 3) // Устанавливаем количество цифр в пароле
{
LockedPosition(false);
}
delay(100);
}
void LockedPosition(int locked)
{
if (locked)
{
digitalWrite(RedpinLock, HIGH);
digitalWrite(GreenpinUnlock, LOW);
ServoMotor.write(90); // Начальная позиция замка
}
else
{
digitalWrite(RedpinLock, LOW);
digitalWrite(GreenpinUnlock, HIGH);
ServoMotor.write(180); // Позиция замка в разблокированном состоянии
beep(a, 500);
  	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
    beep(a, 500);
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 650);
	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
  
    delay(150);

	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
    beep(eH, 500);
    beep(eH, 500);
    beep(eH, 500);
 	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
    beep(fH, 350);
    beep(cH, 150);
    beep(gS, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 650);
	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
  
    delay(150);

	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
    beep(aH, 500);
    beep(a, 300);
    beep(a, 150);
    beep(aH, 400);
 	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
    beep(gSH, 200);
    beep(gH, 200);
    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);
	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
  
    delay(250);
	
  	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
    beep(aS, 250);
    beep(dSH, 400);
    beep(dH, 200);
  	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
    beep(cSH, 200);
    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250);
	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
  
    delay(250);
	
  	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
    beep(f, 125);
    beep(gS, 500);
    beep(f, 375);
    beep(a, 125);
  	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
    beep(cH, 500);
    beep(a, 375);
    beep(cH, 125);
    beep(eH, 650);
	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
	
  	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
    beep(aH, 500);
    beep(a, 300);
    beep(a, 150);
    beep(aH, 400);
  	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
    beep(gSH, 200);
    beep(gH, 200);
    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);
	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
  
    delay(250);
	
  	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
    beep(aS, 250);
    beep(dSH, 400);
    beep(dH, 200);
   	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
 	beep(cSH, 200);
    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250); 
	digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
  
    delay(250);
	
  	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
    beep(f, 250);
    beep(gS, 500);
    beep(f, 375);
    digitalWrite(10, LOW);
    digitalWrite(1, HIGH);
  	beep(cH, 125);
    beep(a, 500);
    beep(f, 375);
    beep(cH, 125);
    beep(a, 650);
	digitalWrite(10, HIGH);
    digitalWrite(1, LOW);
  noTone(10); 
    delay(10000);
}
}
