#include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with the LCD display
#include <Keypad.h> // Include the Keypad library for interfacing with the keypad

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialize the LiquidCrystal library with the pins connected to the LCD

//Define Variables
unsigned long hours = 0;
unsigned long minutes = 0;
unsigned long seconds = 0;
unsigned long previousMillis = 0;
bool classEnded = false;
int currentPeriod = -1;

// Define keypad pins and keys
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect keypad ROW0, ROW1, ROW2, and ROW3 to these Arduino pins.
byte colPins[COLS] = {13, 10, A0, A1}; // Connect keypad COL0, COL1, COL2, and COL3 to these Arduino pins.

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define periods and their timings
String periodNames[50];
String periodTimings[50];

int numPeriods = 0;

// Define buzzer pin
const int buzzerPin = A2;

unsigned long startTime = 0;

void setup() {
    lcd.begin(16, 2); // Set up the LCD's number of columns and rows
    lcd.setCursor(2, 0);
    lcd.print("Smart School"); // Display a message on the LCD
    lcd.setCursor(5, 1);
    lcd.print("Bell");
    delay(2000);
    pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
	noTone(buzzerPin);
  
    // Get starting time from keypad input
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter start time:");
  	lcd.setCursor(0,1);
  	lcd.print("HHMM");
    getTimeFromKeypad();
  	getNumClasses();
  	getClassInfo();
}

void loop() {
    
  	updateTime();
  	displayTime();
  
  if (classEnded) {
      tone(buzzerPin, 1000,5000);
      classEnded = false; // Reset classEnded flag
      lcd.clear();
    }
}


// Function to print time in format hh:mm:ss on LCD
void updateTime() {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 1000) {
        // Increment seconds
        seconds++;

        // Update minutes and reset seconds if necessary
        if (seconds >= 60) {
            seconds = 0;
            minutes++;

            // Update hours and reset minutes if necessary
            if (minutes >= 60) {
                minutes = 0;
                hours++;

                // Reset hours if it reaches 24
                if (hours >= 24) {
                    hours = 0;
                }
            }
        }

        // Check if the current time matches any class start time
        for (int i = 0; i < numPeriods; i++) {
            int startHour = atoi(periodTimings[i].substring(0, 2).c_str());
            int startMinute = atoi(periodTimings[i].substring(2, 4).c_str());
            if (hours == startHour && minutes == startMinute && seconds == 0) {
                currentPeriod = i;
              	classEnded = true;
                break;
            }
        }

        // Check if the current time matches any class end time
        for (int i = 0; i < numPeriods; i++) {
            int endHour = atoi(periodTimings[i].substring(4, 6).c_str());
            int endMinute = atoi(periodTimings[i].substring(6, 8).c_str());
            if (hours == endHour && minutes == endMinute && seconds == 0) {
                currentPeriod = -1; // No class currently
                classEnded = true;
                break;
            }
        }

        // Save the current time for the next iteration
        previousMillis = currentMillis;
    }
}


// Function to get time from keypad input
void getTimeFromKeypad() {
    String timeStr = "";
    char key = '\0';

    while (key != '#') { // Wait until '#' is pressed to indicate end of input
        key = keypad.getKey();
        if (key) {
            lcd.setCursor(timeStr.length(), 1);
            lcd.print(key);
            timeStr += key;
            delay(200); // Debouncing delay
        }
    }
  	lcd.clear();

    // Parse the time string (format: HHMM)
    hours = (timeStr.substring(0, 2)).toInt();
    minutes = (timeStr.substring(2, 4)).toInt();
}

void displayTime() {
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    if (hours < 10) {
        lcd.print("0");
    }
    lcd.print(hours);
    lcd.print(":");
    if (minutes < 10) {
        lcd.print("0");
    }
    lcd.print(minutes);
    lcd.print(":");
    if (seconds < 10) {
        lcd.print("0");
    }
    lcd.print(seconds);

    lcd.setCursor(0, 1);
    if (currentPeriod != -1) {
        lcd.print("Class: ");
        lcd.print(periodNames[currentPeriod]);
    } else {
        lcd.print("No class");
    }
}


void getNumClasses(){
  lcd.setCursor(0,0);
  lcd.print("Enter no_class");
  String dum = "";
  char key = '\0';
  while (key != '#') { // Wait until '#' is pressed to indicate end of input
        key = keypad.getKey();
        if (key) {
            lcd.setCursor(dum.length(), 1);
            lcd.print(key);
            dum += key;
            delay(200); // Debouncing delay
        }
  numPeriods = dum.toInt();
  }
  lcd.clear();
}

void getClassInfo(){
  char key='\0';
  String Strname = "";
  String StrTime = "";
  for(int i =0;i < numPeriods;i++){
    Strname = "";
    lcd.setCursor(0,0);
    lcd.print("Enter Subject");
  	key='\0';
  	while (key != '#') { // Wait until '#' is pressed to indicate end of input
        key = keypad.getKey();
        if (key) {
            lcd.setCursor(Strname.length(), 1);
            lcd.print(key);
            Strname += key;
            delay(200); // Debouncing delay
		}
    }
    periodNames[i] = Strname;
    
    lcd.clear();
    StrTime = "";
    lcd.setCursor(0,0);
    lcd.print("Enter Time");
    lcd.setCursor(0,1);
    lcd.print("HHMMHHMM");
  	key='\0';
  	while (key != '#') { // Wait until '#' is pressed to indicate end of input
        key = keypad.getKey();
        if (key) {
            lcd.setCursor(StrTime.length(), 1);
            lcd.print(key);
            StrTime += key;
            delay(200); // Debouncing delay
		}
    }
    periodTimings[i] = StrTime.c_str();
    lcd.clear();
  }
}