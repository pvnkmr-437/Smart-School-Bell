   Design and Implementation of a Smart School Bell System html { line-height: 1.5; font-family: Georgia, serif; font-size: 20px; color: #1a1a1a; background-color: #fdfdfd; } body { margin: 0 auto; max-width: 36em; padding-left: 50px; padding-right: 50px; padding-top: 50px; padding-bottom: 50px; hyphens: auto; overflow-wrap: break-word; text-rendering: optimizeLegibility; font-kerning: normal; } @media (max-width: 600px) { body { font-size: 0.9em; padding: 1em; } h1 { font-size: 1.8em; } } @media print { body { background-color: transparent; color: black; font-size: 12pt; } p, h2, h3 { orphans: 3; widows: 3; } h2, h3, h4 { page-break-after: avoid; } } p { margin: 1em 0; } a { color: #1a1a1a; } a:visited { color: #1a1a1a; } img { max-width: 100%; } h1, h2, h3, h4, h5, h6 { margin-top: 1.4em; } h5, h6 { font-size: 1em; font-style: italic; } h6 { font-weight: normal; } ol, ul { padding-left: 1.7em; margin-top: 1em; } li > ol, li > ul { margin-top: 0; } blockquote { margin: 1em 0 1em 1.7em; padding-left: 1em; border-left: 2px solid #e6e6e6; color: #606060; } code { font-family: Menlo, Monaco, 'Lucida Console', Consolas, monospace; font-size: 85%; margin: 0; } pre { margin: 1em 0; overflow: auto; } pre code { padding: 0; overflow: visible; overflow-wrap: normal; } .sourceCode { background-color: transparent; overflow: visible; } hr { background-color: #1a1a1a; border: none; height: 1px; margin: 1em 0; } table { margin: 1em 0; border-collapse: collapse; width: 100%; overflow-x: auto; display: block; font-variant-numeric: lining-nums tabular-nums; } table caption { margin-bottom: 0.75em; } tbody { margin-top: 0.5em; border-top: 1px solid #1a1a1a; border-bottom: 1px solid #1a1a1a; } th { border-top: 1px solid #1a1a1a; padding: 0.25em 0.5em 0.25em 0.5em; } td { padding: 0.125em 0.5em 0.25em 0.5em; } header { margin-bottom: 4em; text-align: center; } #TOC li { list-style: none; } #TOC ul { padding-left: 1.3em; } #TOC > ul { padding-left: 0; } #TOC a:not(:hover) { text-decoration: none; } code{white-space: pre-wrap;} span.smallcaps{font-variant: small-caps;} div.columns{display: flex; gap: min(4vw, 1.5em);} div.column{flex: auto; overflow-x: auto;} div.hanging-indent{margin-left: 1.5em; text-indent: -1.5em;} ul.task-list{list-style: none;} ul.task-list li input\[type="checkbox"\] { width: 0.8em; margin: 0 0.8em 0.2em -1.6em; vertical-align: middle; } pre > code.sourceCode { white-space: pre; position: relative; } pre > code.sourceCode > span { display: inline-block; line-height: 1.25; } pre > code.sourceCode > span:empty { height: 1.2em; } .sourceCode { overflow: visible; } code.sourceCode > span { color: inherit; text-decoration: inherit; } div.sourceCode { margin: 1em 0; } pre.sourceCode { margin: 0; } @media screen { div.sourceCode { overflow: auto; } } @media print { pre > code.sourceCode { white-space: pre-wrap; } pre > code.sourceCode > span { text-indent: -5em; padding-left: 5em; } } pre.numberSource code { counter-reset: source-line 0; } pre.numberSource code > span { position: relative; left: -4em; counter-increment: source-line; } pre.numberSource code > span > a:first-child::before { content: counter(source-line); position: relative; left: -1em; text-align: right; vertical-align: baseline; border: none; display: inline-block; -webkit-touch-callout: none; -webkit-user-select: none; -khtml-user-select: none; -moz-user-select: none; -ms-user-select: none; user-select: none; padding: 0 4px; width: 4em; color: #aaaaaa; } pre.numberSource { margin-left: 3em; border-left: 1px solid #aaaaaa; padding-left: 4px; } div.sourceCode { } @media screen { pre > code.sourceCode > span > a:first-child::before { text-decoration: underline; } } code span.al { color: #ff0000; font-weight: bold; } /\* Alert \*/ code span.an { color: #60a0b0; font-weight: bold; font-style: italic; } /\* Annotation \*/ code span.at { color: #7d9029; } /\* Attribute \*/ code span.bn { color: #40a070; } /\* BaseN \*/ code span.bu { color: #008000; } /\* BuiltIn \*/ code span.cf { color: #007020; font-weight: bold; } /\* ControlFlow \*/ code span.ch { color: #4070a0; } /\* Char \*/ code span.cn { color: #880000; } /\* Constant \*/ code span.co { color: #60a0b0; font-style: italic; } /\* Comment \*/ code span.cv { color: #60a0b0; font-weight: bold; font-style: italic; } /\* CommentVar \*/ code span.do { color: #ba2121; font-style: italic; } /\* Documentation \*/ code span.dt { color: #902000; } /\* DataType \*/ code span.dv { color: #40a070; } /\* DecVal \*/ code span.er { color: #ff0000; font-weight: bold; } /\* Error \*/ code span.ex { } /\* Extension \*/ code span.fl { color: #40a070; } /\* Float \*/ code span.fu { color: #06287e; } /\* Function \*/ code span.im { color: #008000; font-weight: bold; } /\* Import \*/ code span.in { color: #60a0b0; font-weight: bold; font-style: italic; } /\* Information \*/ code span.kw { color: #007020; font-weight: bold; } /\* Keyword \*/ code span.op { color: #666666; } /\* Operator \*/ code span.ot { color: #007020; } /\* Other \*/ code span.pp { color: #bc7a00; } /\* Preprocessor \*/ code span.sc { color: #4070a0; } /\* SpecialChar \*/ code span.ss { color: #bb6688; } /\* SpecialString \*/ code span.st { color: #4070a0; } /\* String \*/ code span.va { color: #19177c; } /\* Variable \*/ code span.vs { color: #4070a0; } /\* VerbatimString \*/ code span.wa { color: #60a0b0; font-weight: bold; font-style: italic; } /\* Warning \*/

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