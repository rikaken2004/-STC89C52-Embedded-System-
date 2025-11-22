/**
 * Embedded System Lab - Multi-function Demo Program
 * Switch functions by uncommenting different #define
 */

#include <REG52.H>

// ==================== FUNCTION SELECTION ====================
// Uncomment ONLY ONE function at a time!

// #define BASIC_LED_BLINK       // Basic LED blinking
// #define DIGITAL_TUBE_TEST     // Digital tube test  
#define COMPLETE_SYSTEM         // Complete counting system
// #define HARDWARE_TESTS        // Hardware tests

// ==================== HARDWARE DEFINITIONS ====================
#ifdef COMPLETE_SYSTEM
sbit Button = P3^2;
sbit Motor_ENA = P3^3;
sbit Motor_IN1 = P3^4;
sbit Motor_IN2 = P3^5;
sbit Status_LED1 = P3^6;
sbit Status_LED2 = P3^7;
#endif

// Common anode digital tube segment table
unsigned char code SegTable[] = {
    0xC0, // 0
    0xF9, // 1
    0xA4, // 2
    0xB0, // 3
    0x99, // 4
    0x92, // 5
    0x82, // 6
    0xF8, // 7
    0x80, // 8
    0x90  // 9
};

// ==================== COMMON FUNCTIONS ====================
void DelayMS(unsigned int ms)
{
    unsigned int i, j;
    for(i = ms; i > 0; i--)
        for(j = 120; j > 0; j--);
}

// ==================== FUNCTION 1: BASIC LED BLINK ====================
#ifdef BASIC_LED_BLINK

void main(void)
{
    // Initialize
    P1 = 0xFF;  // Turn off all LEDs initially
    
    while(1)
    {
        P1 = 0x00;    // Turn on all LEDs (low level lights up)
        DelayMS(500); // Delay 500ms
        P1 = 0xFF;    // Turn off all LEDs
        DelayMS(500); // Delay 500ms
    }
}

#endif

// ==================== FUNCTION 2: DIGITAL TUBE TEST ====================
#ifdef DIGITAL_TUBE_TEST

void main(void)
{
    unsigned char count = 0;
    
    // Initialize ports
    P0 = 0xFF;
    P1 = 0xFF;
    P2 = 0xFF;
    
    while(1)
    {
        count++;
        if(count > 9) count = 0;
        
        // Display number on first digital tube
        P0 = 0x01;        // Select first digital tube
        P2 = SegTable[count];  // Display number
        DelayMS(5);
        
        // Display same number on second digital tube
        P0 = 0x02;        // Select second digital tube
        P1 = SegTable[count];  // Display number
        DelayMS(5);
        
        DelayMS(1000);    // Change every second
    }
}

#endif

// ==================== FUNCTION 3: COMPLETE COUNTING SYSTEM ====================
#ifdef COMPLETE_SYSTEM

void Motor_Forward(void)
{
    Motor_ENA = 1;
    Motor_IN1 = 1;
    Motor_IN2 = 0;
    Status_LED2 = 0;  // LED2 on indicates motor running
}

void Motor_Stop(void)
{
    Motor_ENA = 0;
    Motor_IN1 = 0;
    Motor_IN2 = 0;
    Status_LED2 = 1;  // LED2 off
}

void DisplayAllDigits(unsigned long total, unsigned char batch, unsigned char target)
{
    // 4-digit tube displays total count
    P0 = 0x10; P2 = SegTable[total/1000]; DelayMS(2);
    P0 = 0x20; P2 = SegTable[(total%1000)/100]; DelayMS(2);
    P0 = 0x40; P2 = SegTable[(total%100)/10]; DelayMS(2);
    P0 = 0x80; P2 = SegTable[total%10]; DelayMS(2);
    
    // First 2-digit tube displays batch count
    P0 = 0x01; P2 = SegTable[batch/10]; DelayMS(2);
    P0 = 0x02; P2 = SegTable[batch%10]; DelayMS(2);
    
    // Second 2-digit tube displays target value
    P0 = 0x04; P1 = SegTable[target/10]; DelayMS(2);
    P0 = 0x08; P1 = SegTable[target%10]; DelayMS(2);
}

void main(void)
{
    unsigned long total_count = 0;
    unsigned char batch_count = 0;
    unsigned char target_count = 5;
    bit button_state = 1;
    bit last_button = 1;
    unsigned int system_counter = 0;
    
    // Initialize
    Motor_Stop();
    Status_LED1 = 1;
    Status_LED2 = 1;
    P0 = 0x00;
    P1 = 0xFF;
    P2 = 0xFF;
    
    while(1)
    {
        system_counter++;
        
        // Button detection
        button_state = Button;
        if(button_state == 0 && last_button == 1)
        {
            DelayMS(20);
            if(Button == 0)
            {
                total_count++;
                batch_count++;
                if(total_count > 9999) total_count = 0;
                if(batch_count > 99) batch_count = 0;
                
                Status_LED1 = 0; DelayMS(100); Status_LED1 = 1;
                DelayMS(200);
            }
        }
        last_button = button_state;
        
        // Display update
        DisplayAllDigits(total_count, batch_count, target_count);
        
        // Batch completion check
        if(batch_count >= target_count)
        {
            Motor_Forward();
            DelayMS(2000);
            Motor_Stop();
            batch_count = 0;
            DelayMS(500);
        }
        
        // LED status indication
        if(system_counter % 800 == 0)
        {
            Status_LED1 = ~Status_LED1;
        }
        if(system_counter >= 1000)
        {
            system_counter = 0;
        }
        
        DelayMS(1);
    }
}

#endif

// ==================== FUNCTION 4: HARDWARE TESTS ====================
#ifdef HARDWARE_TESTS

void main(void)
{
    unsigned char i;
    
    // LED test: flowing light effect
    while(1)
    {
        for(i = 0; i < 8; i++)
        {
            P3 = ~(1 << i);  // Light up each LED in sequence
            DelayMS(200);
        }
    }
}

#endif
