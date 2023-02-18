#define SHORT_DELAY 200
#define LONG_DELAY 500

void
setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void
short_signal()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(SHORT_DELAY);
  digitalWrite(LED_BUILTIN, LOW);
  delay(SHORT_DELAY);
}

void
long_signal()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LONG_DELAY);
  digitalWrite(LED_BUILTIN, LOW);
  delay(SHORT_DELAY);
}

void
morse(String *x)
{
  for (int i = 0;i < x->length();i++)
    switch(x->charAt(i))
    {
      case 'a' | 'A':
        short_signal();
        long_signal();
        break;
      case 'b' | 'B':
        long_signal();
        short_signal();
        short_signal();
        short_signal();
        break;
      case 'c' | 'C' :
        long_signal();
        short_signal();
        long_signal();
        short_signal();
        break;
      case 'd' | 'D' :
        long_signal();
        short_signal();
        short_signal();
        break;
      case 'e' | 'E' :
        short_signal();
        break;
      case 'f' | 'F' :
        short_signal();
        short_signal();
        long_signal();
        short_signal();
        break;
      case 'g' | 'G' :
        long_signal();
        long_signal();
        short_signal();
        break;
      case 'h' | 'H' :
        short_signal();
        short_signal();
        short_signal();
        short_signal();
        break;
      case 'i' | 'I' :
        short_signal();
        short_signal();
        break;
      case 'j' | 'J' :
        short_signal();
        long_signal();
        long_signal();
        long_signal();
        break;
      case 'k' | 'K' :
        long_signal();
        short_signal();
        long_signal();
        break;
      case 'l' | 'L' :
        short_signal();
        long_signal();
        short_signal();
        short_signal();
        break;
      case 'm' | 'M' :
        long_signal();
        long_signal();
        break;
      case 'n' | 'N' :
        long_signal();
        short_signal();
        break;
      case 'o' | 'O' :
        long_signal();
        long_signal();
        long_signal();
        break;
      case 'p' | 'P' :
        short_signal();
        long_signal();
        long_signal();
        short_signal();
        break;
      case 'q' | 'Q' :
        long_signal();
        long_signal();
        short_signal();
        long_signal();
        break;
      case 'r' | 'R' :
        short_signal();
        long_signal();
        short_signal();
        break;
      case 's' | 'S' :
        short_signal();
        short_signal();
        short_signal();
        break;
      case 't' | 'T' :
        long_signal();
        break;
      case 'u' | 'U' :
        short_signal();
        short_signal();
        long_signal();
        break;
      case 'v' | 'V' :
        short_signal();
        short_signal();
        short_signal();
        long_signal();
        break;
      case 'w' | 'W' :
        short_signal();
        long_signal();
        long_signal();
        break;
      case 'x' | 'X' :
        long_signal();
        short_signal();
        short_signal();
        long_signal();
        break;
      case 'y' | 'Y' :
        long_signal();
        short_signal();
        long_signal();
        long_signal();
        break;
      case 'z' | 'Z' :
        long_signal();
        long_signal();
        short_signal();
        short_signal();
        break;
    }
}

void
loop()
{
  while (Serial.available() == 0) {}     

  String input = Serial.readString();

  delay(1000);
  morse(&input);
}