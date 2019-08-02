int start_pin = 2;
int finish_pin = 3;
unsigned long start_time = 0;
float run_time;

void setup()
{
  pinMode(start_pin, INPUT_PULLUP);
  pinMode(finish_pin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(start_pin), start, FALLING);
  attachInterrupt(digitalPinToInterrupt(finish_pin), finish, FALLING);

  Serial.begin(9600);
}

void start()
{
    if (start_time == 0)
    {
        start_time = millis();
        Serial.println("start triggered");
    }
}

void finish()
{
    if (start_time > 0)
    {
        start_time = millis() - start_time;
        run_time = (float)(start_time) / 1000;
        Serial.println(run_time,3);
        start_time = 0;
    }
}

void loop()
{
}
