Design and Implementation of a Smart School Bell System
=======================================================

Abstract
========

This project presents the development of a Smart School Bell System using Arduino microcontroller technology. The system automates the process of bell ringing in educational institutions by allowing users to input class schedules via a keypad interface. It utilizes an Arduino Uno microcontroller, a liquid crystal display (LCD), a keypad, and a buzzer to manage class timings and generate audible alerts. The system enhances operational efficiency and eliminates the need for manual bell ringing, offering a convenient solution for educational institutions.

I. Introduction
===============

The traditional method of manual bell ringing in schools can be inefficient and prone to errors. The Smart School Bell System aims to address these challenges by automating the process using Arduino technology. This report details the design and implementation of the system, highlighting its components, functionality, and benefits.

II. System Overview
===================

The Smart School Bell System consists of an Arduino Uno microcontroller, a liquid crystal display (LCD) for visual output, a keypad for user input, and a buzzer for generating sound alerts. The system allows users to input class schedules, which are then used to automate bell ringing according to predefined timings.

III. Hardware Components
========================

1.  Arduino Uno Microcontroller: The central processing unit responsible for executing program logic and interfacing with other hardware components.
    
2.  Liquid Crystal Display (LCD): Provides visual output for displaying current time and class information.
    
3.  Keypad: Enables user input for setting class schedules and system parameters.
    
4.  Buzzer: Generates audible alerts to notify students and staff of class start and end times.
    

IV. Software Components
=======================

1.  LiquidCrystal.h Library: Facilitates communication with the LCD display for displaying information.
    
2.  Keypad.h Library: Enables interfacing with the keypad for user input.
    
3.  Arduino Sketch: The main program logic written in C/C++ language, responsible for managing class schedules, updating time, and triggering bell alerts.
    

V. System Functionality
=======================

*   Users input class schedules via the keypad interface, including start and end times for each class.
    
*   The system continuously updates the current time and compares it with the predefined class timings.
    
*   When a class is about to start or end, the system triggers the buzzer to notify students and staff.
    
*   The LCD display shows the current time and the name of the ongoing class if applicable.
    

VI. Code Snippets
=================

Initialization and Library Inclusion
------------------------------------

    #include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with the LCD display
    #include <Keypad.h> // Include the Keypad library for interfacing with the keypad
    
    LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialize the LiquidCrystal library with the pins connected to the LCD

Variable Definitions
--------------------

    //Define Variables
    unsigned long hours = 0;
    unsigned long minutes = 0;
    unsigned long seconds = 0;
    unsigned long previousMillis = 0;
    bool classEnded = false;
    int currentPeriod = -1;

Keypad Setup
------------

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

Period Definitions
------------------

    // Define periods and their timings
    String periodNames[50];
    String periodTimings[50];
    int numPeriods = 0;

Buzzer Pin Definition
---------------------

    // Define buzzer pin
    const int buzzerPin = A2;

Setup Function
--------------

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

Loop Function
-------------

    void loop() {
        updateTime();
        displayTime();
      
        if (classEnded) {
            tone(buzzerPin, 1000,5000);
            classEnded = false; // Reset classEnded flag
            lcd.clear();
        }
    }

Time Update Function
--------------------

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

Time Input Function
-------------------

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

Display Time Function
---------------------

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

Number of Classes Input Function
--------------------------------

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

Class Information Input Function
--------------------------------

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

VII. Conclusion
===============

The Smart School Bell System offers an efficient and automated solution for managing class schedules and bell ringing in educational institutions. By eliminating manual intervention and enhancing operational efficiency, the system improves the overall learning environment for students and facilitates smooth functioning for school staff. Future enhancements may include additional features such as remote monitoring and scheduling capabilities to further enhance the system’s functionality.