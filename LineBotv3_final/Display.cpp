#include "Display.h"

// Constructor
Display::Display() {
    // Initialization can be done in init()
}

// Initialization
void Display::init() {
    matrix.begin();
    matrix.textFont(Font_5x7);   // size of chars
    matrix.textScrollSpeed(100); // scroll speed
    matrix.stroke(0xFF, 0, 0);   // Set colour (its red rn)
}

// Show status
void Display::showStatus(const char* status) {
    matrix.clear();  // Clear the display 
    matrix.beginText(4, 1, 0xFF, 0, 0); // Start position
    matrix.print(status);               // Display status
    matrix.endText();
}